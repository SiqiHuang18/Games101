#include <iostream>
#include <vector>

#include "CGL/vector2D.h"

#include "mass.h"
#include "rope.h"
#include "spring.h"

namespace CGL {

    Rope::Rope(Vector2D start, Vector2D end, int num_nodes, float node_mass, float k, vector<int> pinned_nodes)
    {
        // TODO (Part 1): Create a rope starting at `start`, ending at `end`, and containing `num_nodes` nodes.
        
     
        Vector2D delta = (end - start)/(num_nodes-1);


        for(int i=0; i < num_nodes; i++){
         
            masses.push_back ( new Mass(start + i*delta, node_mass, false));
            masses[i] -> velocity = Vector2D(0,0);
            if( i > 0)
                springs.push_back ( new Spring(masses[i-1],masses[i],k)); 
        }

         for (auto &i : pinned_nodes)
            masses[i] -> pinned = true;
    }

    void Rope::simulateEuler(float delta_t, Vector2D gravity)
    {
        for (auto &s : springs)
        {
            // TODO (Part 2): Use Hooke's law to calculate the force on a node
            Vector2D delta = s->m2->position - s->m1->position;
            Vector2D force_2to1 = - (s->k * delta / delta.norm() * (delta.norm() - s->rest_length));
            
            s->m1->forces += - force_2to1; 
            s->m2->forces += force_2to1; 

        }

        for (auto &m : masses)
        {
            if (!m->pinned)
            {
                // TODO (Part 2): Add the force due to gravity, then compute the new velocity and position
           
                m->forces += m->mass * gravity;
                Vector2D acceleration = m->forces / m->mass ; 
                // // // Explicit Euler
                // // // Vector2D old_velocity = m->velocity;
                // // // m->velocity += acceleration * delta_t;
                // // // m->position += old_velocity * delta_t;
                // // Semi-implicit Euler
                m->velocity += acceleration * delta_t;
                m->position += m->velocity * delta_t;
                // TODO (Part 2): Add global damping 
              
                

            }

            // Reset all forces on each mass
            m->forces = Vector2D(0, 0);
        }
    }

    void Rope::simulateVerlet(float delta_t, Vector2D gravity)
    {
        for (auto &s : springs)
        {
            // TODO (Part 3): Simulate one timestep of the rope using explicit Verlet （solving constraints)
            Vector2D delta = s->m2->position - s->m1->position;
            Vector2D force_2to1 = - (s->k * delta / delta.norm() * (delta.norm() - s->rest_length));
            
            s->m1->forces += - force_2to1; 
            s->m2->forces += force_2to1; 

            // correct position
            if (delta.norm() > 1.1 * s->rest_length){    
                Vector2D correction = s->rest_length * delta/delta.norm() - delta;
                if(s->m1->pinned){
                    s->m2->position += correction;
                }
                else{
                s->m1->position -= 0.5 * correction;
                s->m2->position += 0.5 * correction; 
                }
            }

        }

        for (auto &m : masses)
        {
            if (!m->pinned)
            {
                m->forces += m->mass * gravity;
                Vector2D acceleration = m->forces/m->mass; 

                Vector2D temp_position = m->position;
                // // TODO: Set the new position of the rope mass   Add global Verlet damping
                m->position = temp_position + (1-0.00005) * (temp_position - m->last_position) + acceleration *  delta_t * delta_t;
                m->last_position = temp_position;
           
            }
             m->forces = Vector2D(0, 0);
        }
    }
}
