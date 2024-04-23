#ifndef CHARACTER_H
#define CHARACTER_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GLFW/glfw3.h>

class Character
{
	public:
		
		glm::vec3 Position;
		glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, -1.0f);

		Character(glm::vec3 position);
		~Character();

		void DrawCharacter();

		float speed = 0.1f;
		void Inputs(GLFWwindow* window);

	private:
		GLuint VAO, VBO, EBO;
	
	
};
#endif // !CHARACTER_H
