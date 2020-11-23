#include <nanogui/nanogui.h>

#include "../clothMesh.h"
#include "../misc/sphere_drawing.h"
#include "sphere.h"

using namespace nanogui;
using namespace CGL;

void Sphere::collide(PointMass &pm) {
  // TODO (Part 3): Handle collisions with spheres.
  Vector3D last_position = pm.position;
  Vector3D ray_dir = last_position - origin;
  Vector3D unit_dir = ray_dir/ray_dir.norm();
  // if pointmass inside or on the sphere 
  if(ray_dir.norm()*ray_dir.norm() <= radius2){
    Vector3D tangent_pt = origin + unit_dir*radius;
    Vector3D corection = tangent_pt - last_position;
    pm.position += corection * (1-friction);

  }
  

}



void Sphere::render(GLShader &shader) {
  // We decrease the radius here so flat triangles don't behave strangely
  // and intersect with the sphere when rendered
  m_sphere_mesh.draw_sphere(shader, origin, radius * 0.92);
}
