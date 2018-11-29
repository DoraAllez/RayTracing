//
//  triangle.hpp
//  TP0Sphere
//
//  Created by zhJ on 19/11/2018.
//  Copyright © 2018 zhJ. All rights reserved.
//

#ifndef triangle_h
#define triangle_h

#include <stdio.h>
#include "glm/glm.hpp"
#include "rayon.h"
#include "objet.h"

class Triangle: public Objet
{
public:
    Triangle(){};
    Triangle(glm::vec3 p1, glm::vec3 p2, glm::vec3 p3, Material* m);
    //~Triangle();
    
    bool calculIntersection(Rayon * ,std::vector<Intersection> *I);
    //int intersect_triangle(glm::vec3 orig, glm::vec3 dir, double *t, double *u, double *v);
    //calcule le normal de triangle
    glm::vec3 get_Normal();
    void set_sommet(glm::vec3 ,glm::vec3 ,glm::vec3 );
    
private:
    glm::vec3 p1;
    glm::vec3 p2;
    glm::vec3 p3;

};



#endif /* triangle_hpp */
