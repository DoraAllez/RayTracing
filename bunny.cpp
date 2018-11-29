#include "bunny.h"
#include "phong.h"
#include "GeometricModel.h"

Bunny::Bunny(string sourceFile, glm::vec3 position)
{
    Face face;
    Triangle tri;
    glm::vec3 p1, p2, p3;
    int i = 0;
    this->sourceName = sourceFile; //"./BunnyLow.obj";
    GeometricModel *model = new GeometricModel(this->sourceName);
    this->nb_face = model->nb_faces;
    
    //material
    const glm::vec3 amb = glm::vec3(0.1, 0.2, 0.1);
    const glm::vec3 dif = glm::vec3(0.5, 0.2, 0.8);
    const double cof = 0.5;
    const double puSP = 128;
    Phong *phg = new Phong(amb, dif, cof, puSP);
     
    
    for(i = 0; i < model->nb_faces; i++ )
    {
        face = model->listFaces.at(i);
        p1 = 10.0f * model->listVertex.at(face.s1) + position;
        p2 = 10.0f * model->listVertex.at(face.s2) + position;
        p3 = 10.0f * model->listVertex.at(face.s3) + position;
        tri.set_sommet(p1, p2, p3);
        tri.material = phg;
        this->triList.push_back(tri);
    }
    
}

bool Bunny::calculIntersection(Rayon * r,std::vector<Intersection> *I)
{
    int i = 0;
    bool return_val = false;
    for(i = 0; i < this->nb_face; i++)
    {
        return_val = return_val || (this->triList.at(i).calculIntersection(r, I));
    }
    return return_val;
}
