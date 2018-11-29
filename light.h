#ifndef __Raytracer__Light__
#define __Raytracer__Light__

#include "glm/glm.hpp"

class Light {
	protected:
		glm::vec3 position;
		glm::vec3 couleur;
	public:
		Light();
		~Light();
		void setPosition(glm::vec3 p);
		void setColor(glm::vec3 c);
		glm::vec3 getPosition();
		glm::vec3 getColor();
	};
#endif