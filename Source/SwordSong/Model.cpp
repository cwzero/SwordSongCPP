#include "SwordSong/Model.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace SwordSong {
	Model::Model() {

	}

	Model::~Model() {

	}

	void Model::Initialize() {
		float a = 1.0f / 16.0f;
		float x = 0.0f, y = 0.0f;

		float x1 = x*a, x2 = (x+1.0f)*a, y1 = y*a, y2 = (y+1.0f)*a;

		float xr = 32.0f/1536.0f, yr = 32.0f/834.0f;

		float vertices[] = {
        	 xr,  yr, 0.0f, x2, y1, // top right
        	 xr, -yr, 0.0f, x2, y2, // bottom right
        	-xr, -yr, 0.0f, x1, y2, // bottom left
        	-xr,  yr, 0.0f, x1, y1  // top left 
		};

		unsigned int indices[] = {  // note that we start from 0!
			0, 1, 3,  // first Triangle
			1, 2, 3   // second Triangle
		};

		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);

		glBindVertexArray(VAO);
		// 2. copy our vertices array in a vertex buffer for OpenGL to use
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		// 3. copy our index array in a element buffer for OpenGL to use
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
		
	    // position attribute
    	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    	glEnableVertexAttribArray(0);
    	// texture coord attribute
    	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    	glEnableVertexAttribArray(1);

    	glBindBuffer(GL_ARRAY_BUFFER, 0); 
		glBindVertexArray(0);
	}

	void Model::Render() {
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);		
	}
}