#ifndef SURFACE_H 
#define SURFACE_H

#include <glad/glad.h>
#include <glm/glm.hpp>

class Surface
{
	public:
		Surface();
		~Surface();

		void DrawSurface();

	private:
		GLuint VAO, VBO, EBO;
		
};
#endif
