#ifndef INTERSECTION_HPP
#define INTERSECTION_HPP
#include "glm/glm.hpp"

class Objet;
class Intersection
{
public:
	Intersection();
	~Intersection();
	float dist; // La distance à l'origine de l'intersection
    glm::vec3 pointIs;
	glm::vec3 normal;
	Objet *obj;		// l'objet intersecté


	// Opérateur de tri des intersections
	int operator <(const Intersection & i) const {
		return dist < i.dist;
	}
	int operator >(const Intersection & i) const {
		return dist > i.dist;
	}
};



#endif
