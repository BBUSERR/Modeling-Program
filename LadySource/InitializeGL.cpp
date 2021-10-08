#include "InitializeGL.hpp"

#include "ezdef.hpp"
#include "Console.hpp"

#define initializeDBG false
#define initializeDBG2 true

StateOfProgram sop;

void framebuffer_size_callback(gumWindow window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}
void key_callback(gumWindow window, int key, int scancode, int action, int mods)
{

	if (action == GLFW_PRESS)
	{
		switch (key)
		{
			case GLFW_KEY_ESCAPE:
				glfwSetWindowShouldClose(window, true);
				break;
			case GLFW_KEY_KP_0:
				glPolygonMode(GL_FRONT_AND_BACK, sop.visualFrame ? GL_FILL : GL_LINE);
				sop.visualFrame = !sop.visualFrame;
				break;
		}
	}
}

void additionalGlCalls()
{
	glEnable(GL_CULL_FACE); // cull face
	glCullFace(GL_BACK); // cull back face
	glFrontFace(GL_CW); // GL_CCW for counter clock-wise
	//glEnable(GL_DEPTH_TEST);
}
void additionalGLDepthCall()
{
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
}

gumWindow GlInitializer(std::string title)
{

	runGL_4_6_Core(4, 6);

	gumWindow window = glfwCreateWindow(1020, 1020, title.c_str(), null, null);
	ifn(window)
	{
		show  "Failed to create GLFW window" fin;
		glfwTerminate();
		return null;
	}
	

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		ConsoleMessage("Failure to Initialize glad properly");
		return null;
	}

	glfwSetKeyCallback(window, key_callback);
	if (initializeDBG)
		additionalGlCalls();
	if (initializeDBG2)
		additionalGLDepthCall();

	printf("Renderer: %s\n", glGetString(GL_RENDERER));
	printf("GL Version: %s\n\n", glGetString(GL_VERSION));

	return window;
}
/*
	Proccesses input into window
*/

