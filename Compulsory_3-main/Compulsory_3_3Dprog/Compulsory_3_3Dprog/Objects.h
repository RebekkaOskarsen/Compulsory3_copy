#ifndef OBJECTS_H
#define OBJECTS_H

#include <glad/glad.h>
#include <glm/glm.hpp>

class Objects
{
	public:
		Objects();
		~Objects();

		void DrawObjects();

	private:
		GLuint VAO, VBO, EBO;

};
#endif
