#ifndef InitializeGL_HPP
#define InitializeGL_HPP

#include <string>

#include "glad/glad.h"
#include "GLFW/glfw3.h"



#define gumWindow GLFWwindow*
// Just load up opengl and ignore the silly abstractions
#define runGL_4_6_Core(verMajor, verMinor) glfwInit(); glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, (verMajor)); glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, (verMinor)); glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE)



class StateOfProgram
{
	public:
		bool visualFrame;

		StateOfProgram()
		{
			visualFrame = false;
		}
};


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
gumWindow GlInitializer(std::string title);

#endif

