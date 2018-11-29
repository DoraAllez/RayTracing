//
//  plan.cpp
//  TP0Sphere
//
//  Created by zhJ on 2018/10/8.
//  Copyright © 2018年 zhJ. All rights reserved.
//

#include "plan.h"


Plan::Plan(glm::vec3 position, glm::vec3 normal, glm::vec3 Color)
{
    m_pos = position;
    m_norl = normal;
    color = Color;
    
}


bool Plan::calculIntersection(Rayon * r,std::vector<Intersection> *I)
{
    glm::vec3 rOrg = r -> Orig();
    glm::vec3 rVect = r -> Vect();
    
    if(glm::dot(m_norl, rVect) == 0)
        return false;
    else
    {
        double t = (glm::dot(m_norl, m_pos) - glm::dot(m_norl, rOrg)) / (glm::dot(m_norl, rVect));
        
        glm::vec3 vt = glm::vec3(t,t,t);
        glm::vec3 inst = rOrg + vt * rVect;
        
        float dst = glm::distance(inst,r->Orig());
        Intersection intersection;
        intersection.dist = dst;
        intersection.pointIs = inst;
        intersection.normal = m_norl;
        intersection.obj = this;
        I->push_back(intersection);
    }
    
    return true;
}
