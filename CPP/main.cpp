#include "ezdef.hpp"
#include "window.hpp"
#include "gbs.hpp"



int main()
{
	win.initializeWindow();

	while (win.shouldntClose())
	{
		glfwPollEvents();
		win.swapBuffer();
	}

	glfwTerminate();
	return 0;
}