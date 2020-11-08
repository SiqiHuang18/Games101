//
// Created by Göksu Güvendiren on 2019-05-14.
//

#include "Scene.hpp"


void Scene::buildBVH() {
    printf(" - Generating BVH...\n\n");
    this->bvh = new BVHAccel(objects, 1, BVHAccel::SplitMethod::NAIVE);
}

Intersection Scene::intersect(const Ray &ray) const
{
    return this->bvh->Intersect(ray);
}

void Scene::sampleLight(Intersection &pos, float &pdf) const
{
    float emit_area_sum = 0;
    for (uint32_t k = 0; k < objects.size(); ++k) {
        if (objects[k]->hasEmit()){
            emit_area_sum += objects[k]->getArea();
        }
    }
    float p = get_random_float() * emit_area_sum;
    emit_area_sum = 0;
    for (uint32_t k = 0; k < objects.size(); ++k) {
        if (objects[k]->hasEmit()){
            emit_area_sum += objects[k]->getArea();
            if (p <= emit_area_sum){
                objects[k]->Sample(pos, pdf);
                break;
            }
        }
    }
}

bool Scene::trace(
        const Ray &ray,
        const std::vector<Object*> &objects,
        float &tNear, uint32_t &index, Object **hitObject)
{
    *hitObject = nullptr;
    for (uint32_t k = 0; k < objects.size(); ++k) {
        float tNearK = kInfinity;
        uint32_t indexK;
        Vector2f uvK;
        if (objects[k]->intersect(ray, tNearK, indexK) && tNearK < tNear) {
            *hitObject = objects[k];
            tNear = tNearK;
            index = indexK;
        }
    }


    return (*hitObject != nullptr);
}

// Implementation of Path Tracing
Vector3f Scene::castRay(const Ray &ray, int depth) const
{
    // Russian Rouelette probability
  
    // precision for ray light interesection
    const float EPSILON = 0.01;
    Vector3f L_dir(0,0,0);
    Vector3f L_indir(0,0,0);

    Intersection intersection = intersect(ray);
    if(!intersection.happened)
        return L_dir;

    Material *m = intersection.m;
    Vector3f N = intersection.normal;
    Vector3f pos = intersection.coords;
    Intersection light_pos;
    
    Vector3f wo = normalize(-ray.direction);

    if (m->hasEmission())
        return m->getEmission();
    
    // sample light 
    
    float pdf_light;
    sampleLight(light_pos,pdf_light);

    Vector3f x = light_pos.coords;
    Vector3f NN = light_pos.normal;
    Vector3f emit = light_pos.emit;
    
    Vector3f ws =  normalize(x - pos);
    light_pos.distance = (x - pos).norm();
    
    
    // Cast a ray to check if there is block between light and inƒetersection
    Ray light_ray(pos, ws);
    Intersection block = intersect(light_ray);

    // light not blocked, radiance from light source
    if (light_pos.distance - block.distance < EPSILON){ // not blocked
        L_dir = emit * m->eval(wo, ws, N) * dotProduct(ws, N) * dotProduct(-ws, NN) / ((x-pos).norm() * (x-pos).norm()) / pdf_light;
    }
    
    
    
    float P_RR = get_random_float(); 
    if (P_RR > RussianRoulette)
        return L_dir;
        
    // radiance from other reflectors
    // sample a direction
    Vector3f wi = m -> sample(wo, N);
    Ray next_ray(pos, wi);
    Intersection no_emit_inter = intersect(next_ray);
    if (no_emit_inter.happened && !(no_emit_inter.m -> hasEmission()))
        L_indir = castRay(next_ray, depth+1) * m->eval(wo, wi, N) * dotProduct(wi, N) / m->pdf(wo, wi, N) / RussianRoulette;
    

    return L_dir + L_indir;

        
}

    