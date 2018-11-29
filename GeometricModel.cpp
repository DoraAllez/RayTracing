#include <iostream>
#include "GeometricModel.h"
#include "OBJLoader.h"
using namespace std;


OBJLoader* loader = new OBJLoader();


GeometricModel::GeometricModel()
{
	nb_vertex = 0;
	nb_faces = 0;
};
GeometricModel::GeometricModel(std::string name)
{
	nb_vertex = 0;
	nb_faces = 0;
	m_Name = name;
	loader->loadModel(name,this);	
};
GeometricModel::~GeometricModel()
{

};
