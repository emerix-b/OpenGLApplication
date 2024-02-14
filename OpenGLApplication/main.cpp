#include <stdio.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>


//Window dimensions
const GLint WIDTH = 800, HEIGHT = 600;

int main()
{
	//Initialise GLFW
	if (!glfwInit())
	{
		printf("GLFW initialisation faild!");
		glfwTerminate();
		return 1;
	}

	// Setup GLFW window properties
	//OpenGL version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//Core profile = no backward compatibility
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//Allow forward compatibility
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Test Window", NULL, NULL);
	if (!mainWindow)
	{
		printf("GLFW window creation failed!");
		glfwTerminate();
		return 1;
	}

	// Ger buffer size information
	int bufferWidth, bufferHeight;
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

	// Set context for GLFW to use 
	glfwMakeContextCurrent(mainWindow);

	// Allow modern ectension featuers
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		printf("GLEW window creation failed!");
		glfwDestroyWindow(mainWindow);
		glfwTerminate;
		return 1;
	}

	// Setup Viewport size
	glViewport(0, 0, bufferWidth, bufferHeight);

	// loop until window closed 
	while (!glfwWindowShouldClose(mainWindow)) 
	{
		// Get + Handle user input events
		glfwPollEvents();

		// Clear window
		glClearColor(0.42f, 0.02f, 0.23f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		glfwSwapBuffers(mainWindow);
		
	}


	return 0;
}