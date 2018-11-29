#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <iostream>
#include "intersection.h"
#include <vector>
#include "material.h"
#include "glm/glm.hpp"


class Rayon;
class Objet
{
 protected:


  
 public:
	 
	 Objet(){};

     virtual bool calculIntersection(Rayon * ,std::vector<Intersection> *I){return false;};
	 glm::vec3 color;
	 Material *material;
};


#endif 