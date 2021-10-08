#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "mesh.hpp"
#include "ezdef.hpp"
#include "db.hpp"
#include "Console.hpp"
#include "InitializeGL.hpp"
#include "gShaders.hpp"
#include "importOBJ.hpp"
#include "GraphicalObjects.hpp"
#include "camera.hpp"



#define whileWinNotClosed(x) while(!glfwWindowShouldClose((x)))

int main()
{
	GLFWwindow* window;
	ifn(window = GlInitializer("Lady!"))
	{
		return -1;
	}

	std::string pathobj = "O:\\EmilyGL\\Emily\\LadySource\\testMesh\\test.obj";

	//tmesh t = getOBJMESH(pathobj);
	//t.details(3);


	//t.colordat = { glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f),glm::vec3(0.0f, 0.0f, 1.0f) };


	
	rmesh r;
	r.SetUpVertRenderer();

	
	Shader gshader(hope_Vert, hope_Frag, "DIRECT");


	


	//t.SetUpMeshRender();




	whileWinNotClosed(window)
	{



		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		glUseProgram(gshader.ID);
		glBindVertexArray(r.VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		//glBindVertexArray(vao); 
		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0);


		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	r.delBuffers();
	glDeleteProgram(gshader.ID);

	glfwTerminate();

	return 0;
};