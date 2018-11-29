#ifndef bunny_h
#define bunny_h


#include <string>
#include "triangle.h"

class Bunny: public Objet
{
public:
    Bunny(std::string, glm::vec3 position);
    
    bool calculIntersection(Rayon * ,std::vector<Intersection> *I);
    
protected:
    std::string sourceName;
    int nb_face;
    std::vector<Triangle> triList;
    glm::vec3 m_position;
};


#endif /* bunny_h */
