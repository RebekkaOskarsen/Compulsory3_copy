
#include "Character.h"


Character::Character(glm::vec3 position)
{
	Position = position;

	VAO = 0;
	VBO = 0;
	EBO = 0;

	//cube
	GLfloat charactervertices[] =
	{
	//positions   /		 colors //
	// Front face
   0.2f, 0.0f, 0.1f,    0.0f, 0.0f, 1.0f, // Bottom-left
	0.4f, 0.0f, 0.1f,    0.0f, 0.0f, 1.0f, // Bottom-right
	0.4f, 0.2f, 0.1f,    0.0f, 0.0f, 1.0f, // Top-right
	0.2f, 0.2f, 0.1f,    0.0f, 0.0f, 1.0f, // Top-left

	// Back face
	0.2f, 0.0f, -0.1f,   0.0f, 0.0f, 1.0f, // Bottom-left
	0.4f, 0.0f, -0.1f,   0.0f, 0.0f, 1.0f, // Bottom-right
	0.4f, 0.2f, -0.1f,   0.0f, 0.0f, 1.0f, // Top-right
	0.2f, 0.2f, -0.1f,   0.0f, 0.0f, 1.0f, // Top-left

	// Top face
	0.4f, 0.2f, 0.1f,   0.0f, 0.0f, 1.0f, // Top-right
	0.2f, 0.2f, 0.1f,   0.0f, 0.0f, 1.0f, // Top-left
	0.4f, 0.2f, -0.1f,   0.0f, 0.0f, 1.0f, // Bottom-right
	0.2f, 0.2f, -0.1f,   0.0f, 0.0f, 1.0f, // Bottom-left

	// Bottom face
	0.2f, 0.0f, 0.1f,   0.0f, 0.0f, 1.0f, // Top-left
	0.4f, 0.0f, 0.1f,   0.0f, 0.0f, 1.0f, // Top-right
	0.4f, 0.0f, -0.1f,   0.0f, 0.0f, 1.0f, // Bottom-right
	0.2f, 0.0f, -0.1f,   0.0f, 0.0f, 1.0f, // Bottom-left

	// Right face
	0.4f, 0.0f, 0.1f,   0.0f, 0.0f, 1.0f, // Bottom-right
	0.4f, 0.2f, 0.1f,   0.0f, 0.0f, 1.0f, // Top-right
	0.4f, 0.2f, -0.1f,   0.0f, 0.0f, 1.0f, // Top-left
	0.4f, 0.0f, -0.1f,   0.0f, 0.0f, 1.0f, // Bottom-left

	// Left face
	0.2f, 0.0f, 0.1f,   0.0f, 0.0f, 1.0f, // Bottom-left
	0.2f, 0.2f, 0.1f,   0.0f, 0.0f, 1.0f, // Top-left
	0.2f, 0.2f, -0.1f,   0.0f, 0.0f, 1.0f, // Top-right
	0.2f, 0.0f, -0.1f,   0.0f, 0.0f, 1.0f, // Bottom-right
	};

	GLuint characterindices[] =
	{
		// Front face
		0, 1, 2,
		2, 3, 0,

		// Back face
		4, 5, 6,
		6, 7, 4,

		// Top face
		8, 9, 10,
		10, 11, 8,

		// Bottom face
		12, 13, 14,
		14, 15, 12,

		// Right face
		16, 17, 18,
		18, 19, 16,

		// Left face
		20, 21, 22,
		22, 23, 20

	};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(charactervertices), charactervertices, GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(characterindices), characterindices, GL_STATIC_DRAW);

	//position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	//color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);

}

Character::~Character()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

void Character::DrawCharacter()
{

	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void Character::Inputs(GLFWwindow* window)
{	

	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
		Position += speed * Orientation;

	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
		Position -= speed * Orientation;

	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
		Position -= glm::normalize(glm::cross(Orientation)) * speed;

	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		Position += glm::normalize(glm::cross(Orientation)) * speed;

}
