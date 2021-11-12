#include "gmesh.hpp"
#include "gbs.hpp"

mesh::mesh()
{
	mscale = mat4x4(1.0);
	mrot = mat4x4(1.0);
	mtrans = mat4x4(1.0);
}
void bufferObject::bind(vector<vec3> verts, vector<vec3> norm, vector<GLuint> indices)
{
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, verts.size() * sizeof(glm::vec3), &verts[0], GL_STATIC_DRAW);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), 0);
	glEnableVertexAttribArray(0);
}

void mesh::bind()
{
	bufferObject bo;
	bo.bind(verts, norm, indices);
	BO.push_back(bo);
};

unsigned int mesh::numverts()
{
	return verts.size();
}
unsigned int mesh::numindices()
{
	return indices.size();
}