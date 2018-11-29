#include "rayon.h"
#include "objet.h"
#include "phong.h" //zj
#include "light.h" //zj
#include <algorithm>

glm::vec3 Rayon::Lancer(Scene &sc,int current) const
{
	glm::vec3 res = glm::vec3(0);//retourne noir de base
	if (current == 0) return res;
	Objet *obj;
	int intersect = 0;
    float coeffOmbre = 0.0, coeffRefl = 0.0;//secRayonDist = 0.0, RDis1 = 0.0, RDis2 = 0.0;
    glm::vec3 tmpVec;
    float markDist;
	std::vector<Intersection> *I = new std::vector<Intersection>();
	Intersection intersection;
    //Intersection intersection_end;
	Rayon *r=new Rayon();
	r->Orig(orig);
	r->Vect(vect);
  
    //Phong *phg = new Phong();
    
	for (int i = 0; i < sc.Objets.size(); i++)
	{
		obj = sc.Objets[i];
        
		if(obj->calculIntersection(r, I))
		{
			intersect += 1;
		}
	}
    
    
	if(intersect)
	{
        std::sort(I->begin(), I->end());
        for(int j = 0; j < intersect; j++)
        {
            intersection = I->at(j);
            tmpVec = glm::normalize(intersection.pointIs - orig);
            markDist = glm::dot(tmpVec, vect);
            if (glm::dot(tmpVec,vect) > 0)//(intersection.dist != 0) //tmpVec == vect
                break;
        }
        
        //intersection = I->at(0);
        
        //coeffRefl = intersection.obj->material->getCofReflection();
        res = intersection.obj->material->calculColor(intersection, sc, r, current);
       /*
        if (current == 0)
            return res;
        
        if(coeffRefl > 0)
        {
            Rayon refRayon;
            refRayon.Orig(intersection.pointIs);
            refRayon.Vect(glm::normalize(vect - (2 * glm::dot(vect, intersection.normal) * intersection.normal )));
            //refRayon.Vect(glm::normalize(sc.Lights.at(0)->getPosition() - (2 * glm::dot(sc.Lights.at(0)->getPosition(), intersection.normal) * intersection.normal )));
            
            res += coeffRefl * refRayon.Lancer(sc, current - 1);
            
            
        }
     */
    
        //res = intersection.obj->material->calculColor(intersection, sc, r, 1);
        /*Rayon secdRayon;
        secdRayon.Orig(intersection.pointIs);
        secdRayon.Vect(glm::normalize(sc.Lights.at(0)->getPosition() - intersection.pointIs));
        
        coeffOmbre = secdRayon.calOmbre(sc, 1 );
        
        res = res * coeffOmbre;*/
        //res = coeffOmbre * phg->calculColor(intersection, sc, r, 1);
        
        
       // }
        
        //std::cout << "rayon" << res.x << " " << res.y << " " << res.z << std::endl;
		//res = intersection.obj->color;
		//res = intersection.normal;
    
	}
    
	delete I;
    delete r;
    //delete phg;
	return res;
}

float Rayon::calOmbre(Scene &sc,int current) const
{
    //glm::vec3 res = glm::vec3(0);//retourne noir de base
    if (current == 0) return 1;
    Objet *obj;
    int intersect = 0;
    float secRayonDist = 0.0, RDis1 = 0.0, RDis2 = 0.0;
    std::vector<Intersection> *I = new std::vector<Intersection>();
    Intersection intersection;
    //Intersection intersection_end;
    Rayon *r=new Rayon();
    r->Orig(orig);
    r->Vect(vect);
    
    //Phong *phg = new Phong();
    
    for (int i = 0; i < sc.Objets.size(); i++)
    {
        obj = sc.Objets[i];
        
        if(obj->calculIntersection(r, I))
        {
            intersect += 1;
        }
    }
    

        std::sort(I->begin(), I->end());
        secRayonDist = glm::distance(orig, sc.Lights.at(0)->getPosition());
        
        for(int j = 0; j < intersect; j++)
        {
            intersection = I->at(j);
            RDis1 = glm::distance(intersection.pointIs, sc.Lights.at(0)->getPosition());
            RDis2 = glm::distance(orig, intersection.pointIs);
            if(((RDis2 + RDis1) == secRayonDist) && (RDis1 != secRayonDist) )
            {
                delete I;
                delete r;
                //delete phg;
                return 0.6;
            }
            
            
        }
        delete I;
        delete r;
        //delete phg;
        return 1;
    
}
