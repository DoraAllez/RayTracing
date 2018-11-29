#include "light.h"

Light::Light()
{

}

Light::~Light()
{

}

void Light::setPosition(glm::vec3 p)
{
	position = p;
}

void Light::setColor(glm::vec3 c)
{
	couleur = c;
}

glm::vec3 Light::getPosition()
{
	return position;
}
glm::vec3 Light::getColor()
{
	return couleur;
}