#include "camera.h"
#include <stdio.h>
#include <stdlib.h>
#include "image.h"

void Camera::Haut(const glm::vec3 & h) 
{
	haut = h - (dir * (dir * h));
	if (glm::length(haut) != 0.0)
		haut = glm::normalize(haut);	
}

void Camera::Calculer_image(Image & im, Scene &sc, int complexite) const {
	glm::vec3 foyer; // Foyer optique de la camera
	glm::vec3 droite; // Vecteur partant sur la droite dans le plan de l'ecran
	float dx, dy; // dimension des macro-pixels
	int x, y; // Position dans l'image du pixel en cours de calcul
	glm::vec3 hg; // Position du pixel au centre du premier macro-pixel de l'ecran (en haut a gauche)
	glm::vec3 pt, pt_alias; // Position de l'intersection entre le rayon a lancer et l'ecran
	Rayon ray, ray_alias; // Rayon a lancer    ajouter ray_alias pour anti-aliasing
	glm::vec3 res, res_alias;
	//glm::vec3 vect; // Vecteur directeur du rayon a lancer


	// On calcule la position du foyer de la camera
	foyer = centre - (dir * dist);
	std::cout << "centre zj : " << foyer.x << " " << foyer.y <<" " << foyer.z << std::endl;
	std::cout << "centre zj : " << haut.x << " " << haut.y <<" " << haut.z << std::endl; 
	// On calcule le vecteur unitaire "droite" du plan
	droite = glm::cross(dir,haut);
	std::cout << "centre zj : " << droite.x << " " << droite.y <<" " << droite.z << std::endl;

	// On calcule le deltaX et le deltaY
    std::cout << "imlager" << im.getLargeur() << " " << im.getHauteur() << std::endl;
    
	dx = largeur / im.getLargeur();
	dy = hauteur / im.getHauteur();
    std::cout << "dx dy" << dx << " " << dy << std::endl;
	// On calcule la position du premier point de l'ecran que l'on calculera
	hg = centre + (droite * ((dx / 2) - (largeur / 2))) + (haut * ((hauteur / 2) - (dy / 2)));
    std::cout << "premier point : " << hg.x << " " << hg.y <<" " << hg.z << std::endl;
	// Pour chaque pixel de l'image a calculer
	for (y = 0; y < im.getHauteur(); y++) {
		for (x = 0; x < im.getLargeur(); x++) {
			// On calcule la position dans l'espace de ce point
			pt = hg + (droite * (dx * x)) - (haut * (dy * y));
			pt.x = pt.x - (dx/ 2.0);	
			pt.y = pt.y - (dy /2.0);
/*
			// On prepare le rayon qui part du foyer et qui passe par ce point
			ray.Orig(pt);
			vect = pt - foyer;
			vect = glm::normalize(vect);
			ray.Vect(vect);

			res = ray.Lancer(sc, complexite);
            //std::cout << "res camera" << res.x << " " << res.y << " " << res.z << std::endl;
  */
            // anti-aliasing begin
            
            for(int i = -1; i < 2; i++)
            {
                for(int j = -1; j < 2; j++)
                {
                    pt_alias.x = pt.x + (i * (dx/2.0)) ;
                    pt_alias.y = pt.y - (j * (dy/2.0)) ;
                    pt_alias.z = pt.z;
                    ray_alias.Orig(pt_alias);
                    ray_alias.Vect(glm::normalize(pt_alias - foyer));
                    res_alias = ray_alias.Lancer(sc, complexite);
                    res = res + res_alias;
                    
                }
            }
            
            res = res / 9.0f;

            //anti-aliasing end
            
            im.setPixel(x,y, res);
		}
	}
}
