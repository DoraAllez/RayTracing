#include "image.h"
#include <stdio.h>
#include <stdlib.h>  
#include "png/lodepng.h"
#include <math.h>

void encodeOneStep(const char* filename, std::vector<unsigned char>& image, unsigned width, unsigned height)
{
	//Encode the image
	unsigned error = lodepng::encode(filename, image, width, height);

	//if there's an error, display it
  	if(error) std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;
}

Image::Image(const int h,const  int l)
{
	hauteur = h;
	largeur =l;
	pixels = new glm::vec3[largeur * hauteur];
}



Image::~Image()
{
	delete pixels;
}

void Image::Save(std::string name)
{
	std::cout<<"Saving:"<<name<<"..."<<std::endl;
	unsigned width = largeur, height = hauteur;
	std::vector<unsigned char> image;
  	image.resize(width * height * 4);
  	for(unsigned y = 0; y < height; y++)
  		for(unsigned x = 0; x < width; x++)
  		{
  			glm::vec3 tmp = pixels[x+largeur*y];
  			/*tmp.x = glm::max(glm::min(1.0f,tmp.x),0.0f);
  			tmp.y = glm::max(glm::min(1.0f,tmp.y),0.0f);
  			tmp.z = glm::max(glm::min(1.0f,tmp.z),0.0f);
    		image[4 * width * y + 4 * x + 0] = (unsigned char)(round(tmp.x*255.0));
    		image[4 * width * y + 4 * x + 1] = (unsigned char)(round(tmp.y*255.0));
    		image[4 * width * y + 4 * x + 2] = (unsigned char)(round(tmp.z*255.0));
    		image[4 * width * y + 4 * x + 3] = 255;*/
            tmp.x = glm::max(glm::min(255.0f,tmp.x),0.0f);
            tmp.y = glm::max(glm::min(255.0f,tmp.y),0.0f);
            tmp.z = glm::max(glm::min(255.0f,tmp.z),0.0f);
            image[4 * width * y + 4 * x + 0] = (unsigned char)(round(tmp.x));
            image[4 * width * y + 4 * x + 1] = (unsigned char)(round(tmp.y));
            image[4 * width * y + 4 * x + 2] = (unsigned char)(round(tmp.z));
            image[4 * width * y + 4 * x + 3] = 255;
            
  		}
		encodeOneStep(name.c_str(), image, width, height);
	std::cout<<"Done!"<<std::endl;
}



Image::Image(std::string name)
{

	std::vector<unsigned char> image; //the raw pixels
	unsigned width, height;
	std::cout<<"Loading:"<<name.c_str()<<std::endl;
	unsigned error = lodepng::decode( image, width, height,name.c_str());

	//if there's an error, display it
  	if(error) std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;
  	hauteur = height;
	largeur = width;
	pixels = new glm::vec3[largeur * hauteur];
	for(unsigned y = 0; y < height; y++)
  		for(unsigned x = 0; x < width; x++)
  		{
  			pixels[x+largeur*y] = glm::vec3(image[4 * width * y + 4 * x + 0]/255.0,image[4 * width * y + 4 * x + 1]/255.0,image[4 * width * y + 4 * x + 2]/255.0);
  		}
}	

int Image::getHauteur()
{
	return hauteur;
}
int Image::getLargeur()
{
	return largeur;
}

void Image::setPixel(int x,int y, glm::vec3 c)
{
	pixels[x+largeur*y]=c;

}
