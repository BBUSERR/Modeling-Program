#pragma once

#ifndef mesh_HPP
#define mesh_HPP

#include "glm/glm.hpp"
#include <vector>
#include <string>
#include "glad/glad.h"

#include "ezdef.hpp"
#include "db.hpp"

// Not a fan of typedef exactly due to overhead.
#define BufferObject unsigned int
#define VertexShader unsigned int
#define FragmentShader unsigned int

typedef struct TransformMatrix
{
	glm::mat4x4 ScaleMat;
	glm::mat4x4 RotaMat;
	glm::mat4x4 TranslateMat;
}TransformMatrix;

class TMat
{
	public:
		glm::mat4x4 ScaleMat;
		glm::mat4x4 RotaMat;
		glm::mat4x4 TranslateMat;
		glm::mat4x4 TempMat;

		TMat
		(
		);
};
class mesh
{
	public:
		TransformMatrix TMat;
		std::vector<glm::vec3> verts;
		std::vector<glm::vec3> norms;
		char faceColor;
		char wireColor;
		bool renderMesh;
		mesh()
		{
			TMat.ScaleMat = glm::mat4x4(1.0f);
			TMat.RotaMat = glm::mat4x4(1.0f);
			TMat.TranslateMat = glm::mat4x4(1.0f);
			faceColor = 0;
			wireColor = 0;
			renderMesh = false;
		}
		void render()
		{

		}
};

class tmesh
{
	public:
		std::vector<glm::vec3> verts;
		std::vector<unsigned int> indices; // Really Faces. Provide Runtime Bonus in initialization.
		std::vector<glm::vec3> colordat;
		std::string name;

		GLuint VAO;
		GLuint VBO;
		GLuint EBO;

		void showVerts()
		{
			show "Mesh:" spc name spc "verts" fin;
			for_all(thing, verts)
			{
				pvec(thing);
			}
			return;
		}
		void showIndices(int lineSet = 3)
		{
			show "Mesh:" spc name spc "indices" fin;
			int offset = 0;

			for_all(thing, indices)
			{
				show thing << ' ';
				offset++;
				if (offset >= lineSet)
				{
					nxtLN;
					offset = 0;
				}
			}
		}
		// fixes indices
		void adjustIndices(const int additive = -1)
		{
			for (int i = 0; i < indices.size(); i++)
			{
				indices.at(i) += additive;
			}
		}

		void details(int lineSet = 3)
		{
			int offset = 0;
			show "Mesh Details For:" spc name fin;
			show "verts:" fin;
			for_all(thing, verts)
			{
				pvec(thing);
			}
			show "Total Verts registered:" spc verts.size() fin;
			show "Indices:" fin;
			if (indices.size() != 0)
			{
				for_all(thing, indices)
				{
					show thing << ' ';
					offset++;
					if (offset >= lineSet)
					{
						nxtLN;
						offset = 0;
					}
				}
			}
			show "Total Indices registered:" spc indices.size() fin;

			show "End of" spc name  spc"Details" fin;
		}

		void SetUpMeshRender()
		{



			glGenVertexArrays(1, &(VAO));
			glBindVertexArray(VAO);




			glGenBuffers(1, &(VBO));
			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER, verts.size() * sizeof(verts), &verts[0], GL_STATIC_DRAW);




			glGenBuffers(1, &(EBO));
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, (indices).size() * sizeof(indices), &indices[0], GL_STATIC_DRAW);



			// 0 TO 2 IS SAID ON THAT FIRST LINE.
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), 0);
			glEnableVertexAttribArray(0);
		}
		void SetUpVertRender()
		{

		}
		void delBuffers()
		{
			glDeleteVertexArrays(1, &VAO);
			glDeleteBuffers(1, &VBO);
			glDeleteBuffers(1, &EBO);
		}
};

// another type of test mesh;
class rmesh
{
	public:
		std::vector<GLfloat> verts;
		std::vector<GLfloat> colors;

		GLuint VAO;
		GLuint VBO;
		GLuint cVBO;
		GLuint EBO;
	rmesh()
	{

		float vertices[] = {
			 0.0,  0.5, 0.0,
			  0.5, -0.5, 0.0,
			-0.5, -0.5, 0.0 };
		float colours[] = {
		1.0f, 0.0f,  0.0f,
		0.0f, 1.0f,  0.0f,
		0.0f, 0.0f,  1.0f
		};



		for_all(things, vertices)
		{
			verts.push_back(things);
		};

		for_all(things, colours)
		{
			colors.push_back(things);
		}


	}
	void SetUpVertRenderer()
	{
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, verts.size() * sizeof(float), &verts[0], GL_STATIC_DRAW);
		
		glGenBuffers(1, &cVBO);
		glBindBuffer(GL_ARRAY_BUFFER, cVBO);
		glBufferData(GL_ARRAY_BUFFER, colors.size() * sizeof(float), &colors[0], GL_STATIC_DRAW);


		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
		glBindBuffer(GL_ARRAY_BUFFER, cVBO);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);

		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
	};
	void delBuffers()
	{
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
	};
};

#endif