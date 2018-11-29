#ifndef PHONG_HPP_
#define PHONG_HPP_
#include "material.h"


class Phong: public Material
{
private:
    glm::vec3 m_ambiante;
    glm::vec3 m_diffuse;
    double m_coefReflection;
    double m_puisSpeculaire;
 

public:
    Phong(){};
    Phong(glm::vec3 amb, glm::vec3 dif, double cof, double puSP)
    :m_ambiante(amb), m_diffuse(dif),m_coefReflection(cof), m_puisSpeculaire(puSP)
    {
        
    };
  
    glm::vec3 calculColor(Intersection I, Scene &s, Rayon *r, int rec) ;//override;
    glm::vec3 getAmbiante() ;//override;
    glm::vec3 getDiffuse() ;//override;
    double getCofReflection() ;//override;
    double getPuisSpeculaire() ;//override;
    


};

#endif
