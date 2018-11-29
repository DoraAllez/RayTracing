
#ifndef _GEOMETRIC_MODEL_H
#define _GEOMETRIC_MODEL_H

#include "glm/glm.hpp"
#include <vector>
#include "OBJLoader.h"


struct Face
{
	int s1,s2,s3;
};

class GeometricModel
{
	public:
		GeometricModel();
		GeometricModel(std::string gname);
		~GeometricModel();
		int nb_vertex;
		int nb_faces;
		std::vector < glm::vec3 > listVertex;
		std::vector <Face> listFaces;
		std::vector <Face> listCoordFaces;
		std::vector <glm::vec3> listNormals;
		std::vector < glm::vec3 > listCoords;
		std::vector < glm::vec4 > listTangents;
        OBJLoader* loader;
		std::string m_Name;


};


#endif
