#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include "image.h"
#include "camera.h"
#include "objet.h"
#include "glm/glm.hpp"
#include "phong.h"
#include "light.h"
#include "sphere.h"
#include "plan.h"
#include "triangle.h"
#include "OBJLoader.h"
#include "GeometricModel.h"
#include "bunny.h"

int main( int argc, char *argv[] ) 
{
	const int h = 480;
	const int l = 640;

    const float r = 1; //rayon de sphere = 1
    //glm::vec3 position = glm::vec3(0.5, -0.2, 4.0);
    //glm::vec3 position = glm::vec3(2.5, -0.2, 3);
    glm::vec3 position = glm::vec3(2.5, -3, 6);
    glm::vec3 varColor = glm::vec3(255, 255, 255);
    
	Camera myCamera;
	Scene scene;
    
    const glm::vec3 amb = glm::vec3(0.1, 0.1, 0.1);
    //const glm::vec3 dif = glm::vec3(0.1, 0.1, 0.1);
    const glm::vec3 dif = glm::vec3(0.0382, 0.0272, 0.0119);
    const double cof = 0.9;
    const double puSP = 100;
    Phong *phg = new Phong(amb, dif, cof, puSP);
    
    const glm::vec3 G_amb = glm::vec3(0.1, 0.1, 0.1);
    const glm::vec3 G_dif = glm::vec3(0.1, 0.1, 0.4);
    const double G_cof = 0;
    const double G_puSP = 100;
    Phong *G_phg = new Phong(G_amb, G_dif, G_cof, G_puSP);
    
    const glm::vec3 p_amb = glm::vec3(0.001, 0.001, 0.001);
    const glm::vec3 p_dif = glm::vec3(0.2, 0.2, 0.5);
    const double p_cof = 0.5;
    const double p_puSP = 128;
    Phong *p_phg = new Phong(p_amb, p_dif, p_cof, p_puSP);
    
    const glm::vec3 p_amb2 = glm::vec3(0.5, 0.5, 1);
    const glm::vec3 p_dif2 = glm::vec3(0.5, 0.5, 1);
    const double p_cof2 = 0;
    const double p_puSP2 = 128;
    Phong *p_phg2 = new Phong(p_amb2, p_dif2, p_cof2, p_puSP2);
    
    const glm::vec3 p_amb3 = glm::vec3(1, 0.5, 0.5);
    const glm::vec3 p_dif3 = glm::vec3(1, 0.5, 0.5);
    const double p_cof3 = 0;
    const double p_puSP3 = 128;
    Phong *p_phg3 = new Phong(p_amb3, p_dif3, p_cof3, p_puSP3);
    
    Sphere *sphere = new Sphere(r, position, varColor, phg);
    //sphere->material = material;
    
    Sphere *sphere2 = new Sphere(0.1, glm::vec3(-2.5, 0.5, 2.5), glm::vec3(255, 255, 255), phg);
    //sphere2->material = material;
    
    Sphere *sphere3 = new Sphere(0.1, glm::vec3(2.5, -3, 4.5), glm::vec3(255, 255, 255), G_phg);

    
    //pour Triangle
    glm::vec3 p1 = glm::vec3(-2.5, 0.5, 1.5);
    glm::vec3 p2 = glm::vec3(-2.5, 0, 2.5);
    glm::vec3 p3 = glm::vec3(-2, -0.5, 1.5);
    Triangle * triangle = new Triangle(p1, p2, p3, phg);
    //triangle->material = material;
    
    //pour bunny
    Bunny *bunny = new Bunny("./Bunny.obj", glm::vec3(0, -2, 3.5));
    
    //pour Plan
    Plan *plan1 = new Plan(glm::vec3(0, 0, 8), normalize(glm::vec3(0, 0, 1)), glm::vec3(255, 255, 255));
    plan1->material = p_phg;
    
    Plan *plan2 = new Plan(glm::vec3(0, 4, 0), normalize(glm::vec3(0, 1, 0)), glm::vec3(255, 255, 255));
    plan2->material = p_phg3;
    
    Plan *plan3 = new Plan(glm::vec3(0, -4, 0), normalize(glm::vec3(0, 1, 0)), glm::vec3(255, 255, 255));
    plan3->material = p_phg3;
    
    Plan *plan4 = new Plan(glm::vec3(4, 0, 0), normalize(glm::vec3(1, 0, 0)), glm::vec3(255, 255, 255));
    plan4->material = p_phg2;
    
    Plan *plan5 = new Plan(glm::vec3(-4, 0, 0), normalize(glm::vec3(1, 0, 0)), glm::vec3(255, 255, 255));
    plan5->material = p_phg2;
    
    Plan *plan6 = new Plan(glm::vec3(0, 0, -1), normalize(glm::vec3(0, 0, 1)), glm::vec3(255, 255, 255));
    plan6->material = p_phg3;
    /*
    std::ostringstream lightNameSS;
    std::string lightName;
    for(int i = 0; i < 100 ; i++)
    {
        lightNameSS << "light" << i;
        lightName = lightNameSS.str();
        Light * lightName = new Light;
        lightName->setColor(glm::vec3(255, 255, 255));
        lightName->setPosition(glm::vec3(1+(i*0.001), 4+(i*0.001), 4));
        //lightName->setPosition(glm::vec3(1, 4, 4));//(1, 3, -1));

        scene.addLight(lightName);
    }*/
    
    Light * light = new Light;
    light->setColor(glm::vec3(255, 255, 255));
    light->setPosition(glm::vec3(-1, 3.9, 0));//(1, 3, -1));
    
    
/*
    string filename = "./BunnyLow.obj";
    GeometricModel *model = new GeometricModel(filename);
    Face tri;
  
    tri = model->listCoordFaces.at(0);
    std::cout << "Face "  << tri.s1 << " " << tri.s2 << " " << tri.s3 << std::endl;
    tri = model->listCoordFaces.at(1);
    std::cout << "Face "  << tri.s1 << " " << tri.s2 << " " << tri.s3 << std::endl;
    tri = model->listCoordFaces.at(2);
    std::cout << "Face "  << tri.s1 << " " << tri.s2 << " " << tri.s3 << std::endl;
    
    
    glm::vec3 vec;
    vec = model->listVertex.at(0);
    std::cout << "Vertex "  << vec[0] << " " << vec[1]<< " " << vec[2] << std::endl;
    */

    scene.addObjet(sphere);
    scene.addObjet(sphere2);
    scene.addObjet(sphere3);
    scene.addObjet(plan1);
    scene.addObjet(plan2);
    scene.addObjet(plan3);
    scene.addObjet(plan4);
    scene.addObjet(plan5);
    scene.addObjet(plan6);
    scene.addObjet(triangle);
    scene.addObjet(bunny);
    scene.addLight(light);
    std::cout << "number of object  "  << scene.Objets.size() << std::endl;
    
   
	Image myImage =* new Image(h,l);

	myCamera.Calculer_image(myImage, scene, 10);

	myImage.Save("out.png");

	return 0;
}
