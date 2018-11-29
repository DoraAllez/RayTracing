//
//  sphere.cpp
//  TP0Sphere
//
//  Created by zhJ on 2018/9/16.
//  Copyright © 2018年 zhJ. All rights reserved.
//


#include "sphere.h"
#include "rayon.h"
#include <math.h>

Sphere::Sphere(float r, glm::vec3 position, glm::vec3 varColor, Material* m)
{
    m_rayon = r;
    m_position = position;
    color = varColor;
    material = m;
    //std::cout << "color" << "" << color.x << std::endl;
}

bool Sphere::calculIntersection(Rayon * r,std::vector<Intersection> *I)
{
    //glm::vec3 startPointR = r->Orig();
    //glm::vec3 vecPosition = startPointR - m_position;
    float dst = 0.0;
    double xo = r->Orig().x;
    double yo = r->Orig().y;
    double zo = r->Orig().z;
    
    double xv = r->Vect().x;
    double yv = r->Vect().y;
    double zv = r->Vect().z;
    
    double xp = m_position.x;
    double yp = m_position.y;
    double zp = m_position.z;
    
    double a = xv*xv + yv*yv + zv*zv; //pow((xv*xv + yv*yv + zv*zv),2);
    double b = (2*(xv*(xo-xp))) + (2*(yv*(yo-yp))) + (2*(zv*(zo-zp)));
    double c = (pow((xo-xp),2) + pow((yo-yp),2) + pow((zo-zp),2) - this->m_rayon);
    
    double delta = pow(b,2) - (4*a*c);
    
    //std::cout << "delta" << "" << delta << std::endl;
    /*
    double x1 = vecPosition.x;
    double y1 = vecPosition.y;
    double z1 = vecPosition.z;
    double modVecPosition =sqrt(x1*x1 + y1*y1 + z1*z1);
    
    double angleCop = acos((x0*x1 + y0*y1 + z0*z1) / sqrt((x0*x0 + y0*y0 + z0*z0) * (x1*x1 + y1*y1 + z1*z1)));
    double disR = sin(angleCop) * modVecPosition;
    
    //std::cout << "into calculIntersection"<< " " << sin(angleCop) << " " << disR << std::endl;
    
    //glm::vec3 checkRay = r.orig();
    //std::cout << r->Orig().x << " " << r->Orig().y <<" " << r->Orig().z << std::endl;
    //std::cout << checkRay.x << std::endl;
    if(disR > 1)   */
    
    if(delta < 0)
    {
        return false;
    }
    else if (delta == 0)
    {
        double t = (-b )/(2*a);
        glm::vec3 vecInst = glm::vec3(xo+t*xv,yo+t*yv,zo+t*zv);
        glm::vec3 inst = glm::normalize(vecInst - m_position);//vecInst - m_position;m_position - vecInst
        dst = glm::distance(vecInst,r->Orig());
        Intersection intersection;
        intersection.dist = dst;
        intersection.pointIs = vecInst;
        intersection.normal = inst;
        intersection.obj = this;
        I->push_back(intersection);
        
        return true;
    }
    else
    {
        double t1 = (-b - sqrt(delta) )/(2*a);
        double t2 = (-b + sqrt(delta) )/(2*a);
        
        glm::vec3 vecInst1 = glm::vec3(xo+t1*xv,yo+t1*yv,zo+t1*zv);
        glm::vec3 inst1 = glm::normalize(vecInst1 - m_position);
        dst = glm::distance(vecInst1,r->Orig());
        Intersection intersection1;
        intersection1.dist = dst;
        intersection1.pointIs = vecInst1;
        intersection1.normal = inst1;
        intersection1.obj = this;
        I->push_back(intersection1);
        
        glm::vec3 vecInst2 = glm::vec3(xo+t2*xv,yo+t2*yv,zo+t2*zv);
        glm::vec3 inst2 = glm::normalize(vecInst1 - m_position);
        dst = glm::distance(vecInst2,r->Orig());
        Intersection intersection2;
        intersection2.dist = dst;
        intersection2.pointIs = vecInst2;
        intersection2.normal = inst2;
        intersection2.obj = this;
        I->push_back(intersection2);
        
        return true;
    }
    
}

