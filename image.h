#ifndef __Raytracer__image__
#define __Raytracer__image__

#include "glm/glm.hpp"
#include <iostream>
#include <string>

class Image {
	protected:
		int hauteur; // position de l'oeil
		int largeur; // Largeur de l'ecran
		glm::vec3 *pixels;
	public:
		Image(const int h,const int l);
		Image(std::string name);
		int getHauteur();
		int getLargeur();
		void Save(std::string name);
		~Image();
		void setPixel(int x,int y, glm::vec3 c);
	};
#endif