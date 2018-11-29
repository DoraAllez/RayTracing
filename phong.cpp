#include <algorithm>
#include <math.h>
#include "phong.h"
#include "light.h"
#include "scene.h"
#include "objet.h"
#include "rayon.h"


//glm::vec3 Phong::calculColor(Intersection I, Scene &s, Rayon *r, int rec)
glm::vec3 Phong::calculColor(Intersection I, Scene &s, Rayon *r, int rec)
{
    glm::vec3 res, resPh, resRefl, resRefra;
    Light *light;
    
    std::vector<Light*> lights = s.Lights;
    /*
    glm::vec3 ambiante = I.obj->material->getAmbiante();
    glm::vec3 diffuse = I.obj->material->getDiffuse();
    double coefReflection = I.obj->material->getCofReflection();
    double puisSpeculaire = I.obj->material->getPuisSpeculaire();
*/
    glm::vec3 ambiante = m_ambiante;
    glm::vec3 diffuse = m_diffuse;
    double coefReflection = m_coefReflection;
    double puisSpeculaire = m_puisSpeculaire;
    
    glm::vec3 N2 = I.normal;
    if(glm::dot(I.normal,(r -> Vect() - I.pointIs)) < 0)
        N2 = -I.normal;
    
    I.pointIs += 1e-5f * N2;//0.01f * N2;//1e-5f * N2;
    
    for (int i = 0; i < lights.size(); i++)
    {
        light = lights[i];
        //:std::cout << " light i" << i << std::endl;
        glm::vec3 colLig = light -> getColor();
        glm::vec3 posLig = light -> getPosition();
        
        glm::vec3 N = glm::normalize(I.normal);
        glm::vec3 L = glm::normalize(posLig - I.pointIs);
        glm::vec3 V = glm::normalize((r -> Vect()) - I.pointIs);
        glm::vec3 R = glm::normalize(glm::reflect(L, N));//I.pointIs - posLig
       /*
        glm::vec3 N2 = N;
        if(glm::dot(N,V) < 0)
            N2 = -N;
        
        I.pointIs += 0.001f * N2;//1e-5f * N2;
        */
        glm::vec3 ambianteRes = ambiante*colLig;
        
        double nDot = glm::dot(N, L);
        double nMac = glm::max(nDot, 0.0);
        glm::vec3 nCross = diffuse*colLig;
        glm::vec3 diffuseRes = glm::vec3(nMac*nCross.x, nMac*nCross.y, nMac*nCross.z);
        
        nDot = glm::dot(-V, R);
        nMac = glm::pow(glm::max(nDot, 0.0), puisSpeculaire);
        glm::vec3  puisSpeculaireRes = glm::vec3(nMac*colLig.x, nMac*colLig.y, nMac*colLig.z);
        
        resPh =  ambianteRes + diffuseRes + puisSpeculaireRes;
        
        //pour reflection
        if(m_coefReflection)
        {
            Rayon refRayon;
            refRayon.Orig(I.pointIs);
            //refRayon.Vect(glm::normalize(r->Vect() - (2 * glm::dot(r->Vect(), I.normal) * I.normal )));
            //refRayon.Vect(glm::normalize(-r->Vect() - (2 * glm::dot(-r->Vect(), I.normal) * I.normal )));
            refRayon.Vect(glm::reflect(r->Vect(), I.normal));
            //refRayon.Vect(glm::normalize(s.Lights.at(0)->getPosition() - (2 * glm::dot(s.Lights.at(0)->getPosition(), I.normal) * I.normal )));
            
            //resRefl += glm::vec3(m_coefReflection) * refRayon.Lancer(s, rec - 1);
            resRefl = refRayon.Lancer(s, rec - 1);
        }
        
        //pour refraction
        /*
        if(1.0 - m_coefReflection)
        {
            Rayon refraRayon;
            refraRayon.Orig(I.pointIs);
            refraRayon.Vect(glm::refract(r->Vect(), I.normal, 1.5f));
            resRefra = 0.2f * refraRayon.Lancer(s, 1);
        }
        */
        float coeffOmbre = 0.0;
        Rayon secdRayon;
        secdRayon.Orig(I.pointIs);
        secdRayon.Vect(glm::normalize(s.Lights.at(0)->getPosition() - I.pointIs));
        
        coeffOmbre = secdRayon.calOmbre(s, 1 );
        
        //res =  resPh;
        //res =  glm::vec3(coeffOmbre * (1.0 - m_coefReflection)) * resPh  +  glm::vec3(m_coefReflection) * resRefl;
        //res = glm::vec3(coeffOmbre) * resPh +  glm::vec3(m_coefReflection) * resRefl + glm::vec3(1.0 - m_coefReflection) * resRefra;
        res = glm::vec3(coeffOmbre) * resPh +  glm::vec3(m_coefReflection) * resRefl;
    }
     
    
    return res;
}


glm::vec3 Phong::getAmbiante()
{
    return m_ambiante;
}

glm::vec3 Phong::getDiffuse()
{
    return m_diffuse;
}

double Phong::getCofReflection()
{
    return m_coefReflection;
}
double Phong::getPuisSpeculaire()
{
    return m_puisSpeculaire;
}
