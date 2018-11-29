#include <iostream>
#include "glm/glm.hpp"

int main()
{
	glm::vec3 a = glm::vec3(2,2,2);
	glm::vec3 b = glm::vec3(1, 2, 3);

	glm::vec3 t = a * b;
	std::cout << t.x <<" " << t.y << " " << t.z << std::endl;

	return 0;
}
