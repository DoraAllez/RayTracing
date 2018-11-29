#ifndef __Raytracer__scene__
#define __Raytracer__scene__

#include <stdio.h>
#include <stdlib.h>
#include <vector>

class Objet;
class Light;
class Scene
{
	protected:
 	public:
		std::vector<Objet*> Objets;
		std::vector<Light*> Lights;
 		Scene();
 		void addObjet(Objet*o);
 		void addLight(Light*l);
 		~Scene();
};
#endif