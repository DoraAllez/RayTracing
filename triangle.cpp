//
//  triangle.cpp
//  TP0Sphere
//
//  Created by zhJ on 19/11/2018.
//  Copyright © 2018 zhJ. All rights reserved.
//

#include "triangle.h"
#define EPSILON 0.000001

Triangle::Triangle(glm::vec3 p1, glm::vec3 p2, glm::vec3 p3, Material* m)
: p1(p1),p2(p2),p3(p3)
{
    this->material = m;
}

//int Triangle::intersect_triangle(glm::vec3 orig, glm::vec3 dir, double *t, double *u, double *v)

bool Triangle::calculIntersection(Rayon * r, std::vector<Intersection> *I)
{
    glm::vec3 orig = r->Orig();
    glm::vec3 dir = r->Vect();
    Intersection intersection;
    
    glm::vec3 edge1;
    glm::vec3 edge2;
    glm::vec3 normal_tri;
    glm::vec3 pvec, tvec, qvec;
    double det = 0, inv_det = 0;
    double t = 0, u = 0, v = 0;
    
    
    edge1 = this->p2 - this->p1;
    edge2 = this->p3 - this->p1;
    //normal_tri = glm::cross(edge1, edge2);
    
    pvec = glm::cross(dir, edge2);
    det = glm::dot(edge1, pvec);
    
    if((det < EPSILON) && (det > -EPSILON))
        return false;
    
    inv_det = 1.0 / det;
    //calculate the distance from point1 to orig
    tvec = orig - this->p1;
    u = glm::dot(tvec, pvec) * inv_det;
    
    if( (u < 0.0) || (u > 1.0))
        return false;
    
    qvec = glm::cross(tvec, edge1);
    v = glm::dot(dir, qvec) * inv_det;
    if( (v < 0.0) || ((v + u) > 1.0))
        return false;
    t = glm::dot(edge2, qvec) * inv_det;
    
    glm::vec3 coef_t = glm::vec3(t,t,t);
    glm::vec3 pIs = orig + (coef_t * dir);
    intersection.pointIs = pIs;
    intersection.dist = glm::distance(orig, pIs);
    intersection.normal = glm::cross((this->p2 - pIs),(this->p3 - pIs));
    intersection.obj = this;
    I->push_back(intersection);
    
    return true;
    
}



glm::vec3 Triangle::get_Normal()
{
 
    glm::vec3 edge1;
    glm::vec3 edge2;
    edge1 = this->p2 - this->p1;
    edge2 = this->p3 - this->p1;
    return glm::cross(edge1, edge2);
    
    /*
    double a = 0, b = 0, c = 0;
    glm::vec3 norl;
    a = ( (this->p2.y-this->p1.y)*(this->p3.z-this->p1.z)-(this->p2.z-this->p1.z)*(this->p3.y-this->p1.y) );
    b = ( (this->p2.z-this->p1.z)*(this->p3.x-this->p1.x)-(this->p2.x-this->p1.x)*(this->p3.z-this->p1.z) );
    c = ( (this->p2.x-this->p1.x)*(this->p3.y-this->p1.y)-(this->p2.y-this->p1.y)*(this->p3.x-this->p1.x) );
    
    return norl = glm::vec3(a,b,c);
     */
}

void Triangle::set_sommet(glm::vec3 p1,glm::vec3 p2,glm::vec3 p3)
{
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
}

