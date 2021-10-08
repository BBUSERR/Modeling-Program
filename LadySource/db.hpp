#pragma once

#include <string>
#include <glm/glm.hpp>
#include <chrono>

#include <vector>

void db(std::string message);

void db(std::string message, int numMessage0);

void db(std::string message, int numMessage0, int numMessage1);

void db_(std::string message);

void db_(std::string message, int numMessage0);

void db_(std::string message, int numMessage0, int numMessage1);

// prints vector
void pvec(glm::vec3);
// prints vector2
void pvec(glm::vec2);

std::vector<glm::vec3> FloatarrayToVec3Vector(float *items);