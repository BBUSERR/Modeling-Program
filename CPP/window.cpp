#include "window.hpp"
#include "ezdef.hpp"
#include "Console.hpp"

#include <conio.h>
#define initializeDBG true
#define initializeDBG2 true

void additionalGlCalls();
void additionalGLDepthCall();

void window::initializeWindow()
{
	window::initializeWindow(1920, 1080);
}
void window::initializeWindow(int width, int height)
{
	runGL_4_6_Core(4, 6);
	win = glfwCreateWindow(width, height, "Modeling Program", null, null);
	this->width = width;
	this->height = height;
	ifn(win)
	{
		Console("Window cannot be inititalized");
		exitError("Cannot initialize Window");
	}
	glfwSetFramebufferSizeCallback(win, framebuffer_size_callback);
	glfwMakeContextCurrent(win);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		Console("Failure to Initialize glad properly");
		exitError("Cannot initialize Glad linkage");
	}
	glfwSetKeyCallback(win, key_callback);
	if (initializeDBG)
		additionalGLDepthCall();
	if (initializeDBG2)
		additionalGlCalls();
	printf("Renderer: %s\n", glGetString(GL_RENDERER));
	printf("GL Version: %s\n\n", glGetString(GL_VERSION));
	return;
};

bool window::shouldntClose()
{
	return !glfwWindowShouldClose(win);
}

void window::swapBuffer()
{
	glfwSwapBuffers(win);
}

void additionalGlCalls()
{
	glEnable(GL_CULL_FACE); // cull face
	glCullFace(GL_BACK); // cull back face
	glFrontFace(GL_CCW); // GL_CCW for counter clock-wise

}
void additionalGLDepthCall()
{
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
}
void framebuffer_size_callback(GLFWwindow* win, int width, int height)
{

}
void key_callback(GLFWwindow* win, int key, int scancode, int action, int mods)
{
	bool moveflag = false;

	if (glfwGetKey(win, GLFW_KEY_ESCAPE))
	{
		glfwSetWindowShouldClose(win, true);
	}
	if (glfwGetKey(win, GLFW_KEY_KP_0))
	{

	}
	if (glfwGetKey(win, GLFW_KEY_W))
	{

		moveflag = true;
	}
	if (glfwGetKey(win, GLFW_KEY_S))
	{

		moveflag = true;
	}
	if (glfwGetKey(win, GLFW_KEY_A))
	{

		moveflag = true;
	}
	if (glfwGetKey(win, GLFW_KEY_D))
	{

		moveflag = true;
	}
	if (glfwGetKey(win, GLFW_KEY_Q))
	{

		moveflag = true;
	}
	if (glfwGetKey(win, GLFW_KEY_E))
	{

		moveflag = true;
	}
	if (glfwGetKey(win, GLFW_KEY_LEFT))
	{

		moveflag = true;
	}
	if (glfwGetKey(win, GLFW_KEY_RIGHT))
	{

		moveflag = true;
	}
	if (glfwGetKey(win, GLFW_KEY_UP))
	{

		moveflag = true;
	}
	if (glfwGetKey(win, GLFW_KEY_DOWN))
	{

		moveflag = true;
	}
	if (glfwGetKey(win, GLFW_KEY_Z))
	{

		moveflag = true;
	}

	if (glfwGetKey(win, GLFW_KEY_C))
	{

		moveflag = true;
	}

	if (moveflag == true)
	{
		return;
	}
	return;
}