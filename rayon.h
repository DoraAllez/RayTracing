#ifndef __Raytracer__ray__
#define __Raytracer__ray__
#include "glm/glm.hpp"
#include "scene.h"
#include "intersection.h"

class Rayon {
protected:

	glm::vec3 orig;
	glm::vec3 vect; 

public:
	Rayon() {	}

	glm::vec3 Orig() const {
		return orig;
	}
	glm::vec3 Vect() const {
		return vect;
	}


	void Orig(const glm::vec3 & o) {
		orig = o;
	}
	void Vect(const glm::vec3 & v) {
		vect = glm::normalize(v);
	}

	glm::vec3 Lancer(Scene &sc,int current) const;
    float calOmbre(Scene &sc,int current) const;
};	
#endif
