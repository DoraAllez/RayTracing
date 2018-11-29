//
//  plan.hpp
//  TP0Sphere
//
//  Created by zhJ on 2018/10/8.
//  Copyright © 2018年 zhJ. All rights reserved.
//

#ifndef plan_hpp
#define plan_hpp

#include <stdio.h>
#include "objet.h"
#include "rayon.h"

class Plan : public Objet
{
public:
    Plan();
    Plan(glm::vec3 position, glm::vec3 normal, glm::vec3 Color);
    bool calculIntersection(Rayon * ,std::vector<Intersection> *I);
    
private:
    glm::vec3 m_pos;
    glm::vec3 m_norl;

    
};


#endif /* plan_hpp */
