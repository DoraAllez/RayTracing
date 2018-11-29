#include "scene.h"
#include <stdio.h>

Scene::Scene()
{

}

void Scene::addObjet(Objet*o)
{
	Objets.push_back(o);
}

void Scene::addLight(Light*l)
{
	Lights.push_back(l);
}

Scene::~Scene()
{

}