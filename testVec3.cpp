#include <iostream>
#include "glm/glm.hpp"

int main(int argc, char *argv[])
{
    glm::vec3 amb = glm::vec3(0.1, 0.2, 0.1);
	glm::vec3 test = glm::vec3(1,2,3);

	glm::vec3 rst = amb*test;
    std::cout << rst.x << " " << rst.y << " " << rst.z << std::endl;
}
