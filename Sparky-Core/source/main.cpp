
#include <iostream>
#include "Window.h"
#include "Vec2.h"
#include "Vec3.h"
#include "Vec4.h"
#include "Matrix4.h"
#include "FileUtils.h"
#include "Shader.h"
#include  "VertexArray.h"
#include  "VertexBuffer.h"
#include  "IndexBuffer.h"
#include "Renderer2D.h"
#include "Renderable2D.h"
#include "Simple2DRenderer.h"

#include<GL/glew.h>
int main() {
	
	Sparky::Graphics::Window window(800, 600, "Joshua Muthii");
	
	
	//light blue (I think)
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	//Creates program with compiled and linked shaders
	Sparky::Graphics::Shader shader("source/shaders/basic.vert", "source/shaders/basic.frag");
#if 0
		GLuint triangleVertexBufferID;
	GLfloat vertices[] =
	{
		0,0,0,
		8,0,0,
		0,3,0,
		0,3,0,
		8,3,0,
		8,0,0,

	};
	unsigned int squareIndexBuffer[] = {
	0,1,2,
	2,3,0
	};
	//Creates a buffer for graphics card
	glGenBuffers(1, &triangleVertexBufferID);
	//Selecting Buffer for state machine
		//GL_ARRAY_BUFFER is used for vertex attributes
	glBindBuffer(GL_ARRAY_BUFFER, triangleVertexBufferID);
	//Selecting size and contents of Buffer in selected Buffer
	//copying data into GPU Buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	//Creating a pointer that will be abe to read data
		//index of attribute, number of dimensions of attribute, normalize?,stride of attribute, position of attribute in vertex
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), ((void*)0));
	//enable the index we want to enable
	glEnableVertexAttribArray(0);

	//index buffer
	unsigned int indexBuffer;
	//glGenBuffers(1, &indexBuffer);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(squareIndexBuffer), squareIndexBuffer, GL_STATIC_DRAW);

	//projection matrix
#else
	

#endif
	Sparky::Maths::Matrix4 ortho = Sparky::Maths::Matrix4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
	//Setting Uniforms
	shader.enable();
	shader.setUniformMat4("pr_matrix", ortho);
	shader.setUniform4f("u_Color", { 1.0f,0.0f,1.0f,1.0f });
	shader.setUniform2f("light_pos", Sparky::Maths::Vec2(4.0f, 1.5f));
	//
	Sparky::Graphics::Renderable2D sprite(Sparky::Maths::Vec3(5,5,0),Sparky::Maths::Vec2(4,4), Sparky::Maths::Vec4(1,0,1,1),shader);
	Sparky::Graphics::Renderable2D sprite2(Sparky::Maths::Vec3(7, 1, 0), Sparky::Maths::Vec2(2, 3), Sparky::Maths::Vec4(0.2f, 0, 1, 1), shader);
	Sparky::Graphics::Simple2DRenderer renderer;
	double x, y;
	while (!window.closed()) {
		window.clear();
		window.getMousePosition(x, y);

		shader.setUniform2f("light_pos", Sparky::Maths::Vec2(   ((float) x * 16.0f/960.0f)+1.0f ,9.0f -(float)y*9.0f/ 540.0f ));
		renderer.submit(&sprite);
		renderer.submit(&sprite2);
		renderer.flush();

		window.tick();
	}
}
