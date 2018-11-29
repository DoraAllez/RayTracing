#ifndef MATERIAL_HPP_
#define MATERIAL_HPP_

#include "glm/glm.hpp"
#include "intersection.h"

class Scene;
class Rayon;
class Material{

protected:
    /*
    glm::vec3 m_ambiante;
    glm::vec3 m_diffuse;
    double m_coefReflection;
    double m_puisSpeculaire;*/

public:
    Material(){};
    /*
	Material(glm::vec3 amb, glm::vec3 dif, double cof, double puSP)
    :m_ambiante(amb), m_diffuse(dif),m_coefReflection(cof), m_puisSpeculaire(puSP)
    {
        
	};
*/
	virtual glm::vec3 calculColor(Intersection I, Scene &s, Rayon *r, int rec){ return glm::vec3(0, 0, 0); };
    
    //void setMaterial(Material *mtl);
    virtual glm::vec3 getAmbiante(){return glm::vec3(0, 0, 0);};
    virtual glm::vec3 getDiffuse(){return glm::vec3(0, 0, 0);};
    virtual double getCofReflection(){return 0.0;};
    virtual double getPuisSpeculaire(){return 0.0;};


};

#endif
