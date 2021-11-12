
#ifndef window_HPP
#define window_HPP
#include "glad/glad.h"
#include "GLFW/glfw3.h"



#define runGL_4_6_Core(verMajor, verMinor) glfwInit(); glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, (verMajor)); glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, (verMinor));  glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE ); glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); glfwWindowHint( GLFW_SAMPLES, 4 );

class window
{
	public:
		void initializeWindow(int width, int height);
		void initializeWindow();

		bool shouldntClose();

		void swapBuffer();
	private:
		GLFWwindow* win;
		int width, height;
};

void framebuffer_size_callback(GLFWwindow* win, int width, int height);
void key_callback(GLFWwindow* win, int key, int scancode, int action, int mods);


#endif // window_HPP
