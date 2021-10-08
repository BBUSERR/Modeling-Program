#include "db.hpp"
#include "ezdef.hpp"
void db(std::string message)
{
	show message fin;
}
void db(std::string message, int numMessage0)
{
	show message spc numMessage0 fin;
}
void db(std::string message, int numMessage0, int numMessage1)
{
	show message spc numMessage0 spc numMessage1 fin;
}

void db_(std::string message)
{
	show message;
}
void db_(std::string message, int numMessage0)
{
	show message spc numMessage0;
}
void db_(std::string message, int numMessage0, int numMessage1)
{
	show message spc numMessage0 spc numMessage1;
}

void pvec(glm::vec3 message)
{
	show message.x spc message.y spc message.z fin;
}
// prints vector2
void pvec(glm::vec2 message)
{
	show message.x spc message.y fin;
}
std::vector<glm::vec3> FloatarrayToVec3Vector(float* items)
{
	std::vector<glm::vec3> data;

	return data;
}
