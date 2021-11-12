#ifndef gmesh_HPP
#define gmesh_HPP

#include "ezdef.hpp"
#include "glm/glm.hpp"
#include "glad/glad.h"
using namespace glm;

class bufferObject
{
	public:
		void bind(vector<vec3> verts, vector<vec3> norm, vector<GLuint> indices);
	private:
		GLuint VAO, VBO, EBO;
};

class mesh
{
	public:
		mesh();
		unsigned int numverts();
		unsigned int numindices();
		void bind();

	private:
		vector<vec3> verts;
		vector<vec3> norm;
		vector<GLuint> indices;
		// 3d components
		mat4x4 mscale;
		mat4x4 mrot;
		mat4x4 mtrans;
		
		// later
		vector<vec3> col;
		vector<vec2> UV;
		
};

#endif // gmesh_HPP
