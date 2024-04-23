#include <glad/glad.h>
#include <iostream>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shaderClass.h"
#include "Camera.h"
#include "Surface.h"
#include "Objects.h"
#include "Character.h"

using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height); 
void processInput(GLFWwindow* window); 

const unsigned int width = 800;
const unsigned int height = 800;


int main()
{
	glfwInit(); //Initialize GLFW

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//glfw window creation
	GLFWwindow* window = glfwCreateWindow(width, height, "Compulsory 3", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	//Initialize GLAD
	gladLoadGL();

	//Set the viewport
	glViewport(0, 0, width, height);

	Shader shaderProgram("default.vert", "default.frag");

	Surface surface1;

	Objects objects1;
	Objects objects2;
	
	Character character1(glm::vec3(0.0f, 0.0f, 0.0f));



	//Camera
	Camera camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));
	
	while (!glfwWindowShouldClose(window)) // Check if the window should close
	{
		processInput(window);


		//Render
		glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		shaderProgram.Activate();

		//glm::mat4 model = glm::mat4(1.0f);
		//glm::mat4 view = glm::mat4(1.0f);
		//glm::mat4 projection = glm::mat4(1.0f);

		camera.Inputs(window);
		camera.Matrix(45.0f, 0.1f, 100.0f, shaderProgram, "camMatrix");

		//Flat surface
		surface1.DrawSurface();

		//Objects
		objects1.DrawObjects();
		objects2.DrawObjects();

		//Character
		character1.Inputs(window);
		character1.DrawCharacter(); 


		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	shaderProgram.Delete();

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);


}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	std::cout << "Window resized with " << width << "Height" << height << std::endl;
}