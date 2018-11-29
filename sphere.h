#ifndef SPHERE_HPP_
#define SPHERE_HPP_

#include <stdio.h>
#include <stdlib.h>
#include "objet.h"


class Sphere: public Objet
{
public:
    Sphere();
    Sphere(float r, glm::vec3 position, glm::vec3 varColor, Material* m );
    bool calculIntersection(Rayon * ,std::vector<Intersection> *I);
    
private:
    glm::vec3 m_position;
    float m_rayon;
    
};





#endif
