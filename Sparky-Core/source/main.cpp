
#include <iostream>
#include "Window.h"
#include "Vec2.h"
#include "Vec3.h"
#include "Vec4.h"
#include "Matrix4.h"
#include "FileUtils.h"
#include "Shader.h"
#include<GL/glew.h>
int main() {
	
	Sparky::Graphics::Window window(800, 600, "Joshua Muthii");
	
	
	//light blue (I think)
	glClearColor(.2, .3, .8, 1.0);
	//Creates program with compiled and linked shaders
	Sparky::Graphics::Shader shader("source/shaders/basic.vert","source/shaders/basic.frag");
	
	GLuint triangleVertexBufferID;
	GLfloat vertices[] =
	{
		-0.5f,-0.5f, //0
		 0.5f,-0.5f, //1
		 0.5f, 0.5f, //2
		 -0.5, 0.5 //3

	};
	unsigned int squareIndexBuffer[]={
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
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),vertices, GL_STATIC_DRAW);
	//Creating a pointer that will be abe to read data
		//index of attribute, number of dimensions of attribute, normalize?, size of attribute, position of attribute in vertex
	glVertexAttribPointer(0,2, GL_FLOAT, GL_FALSE, sizeof(float)*2,  0);
	//enable the index we want to enable
	glEnableVertexAttribArray(0);

	//index buffer
	unsigned int indexBuffer;
	glGenBuffers(1, &indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(squareIndexBuffer), squareIndexBuffer, GL_STATIC_DRAW);

	//projection matrix
	Sparky::Maths::Matrix4 ortho = Sparky::Maths::Matrix4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
	shader.enable();


	glUniformMatrix4fv(glGetUniformLocation(shader.m_ShaderID, "pr_matrix"), 1, GL_FALSE, ortho.elements);
	glUniform4f(glGetUniformLocation(shader.m_ShaderID, "u_Color") ,1.0f,0.0f,1.0f,1.0f);
	
	while (!window.closed()) {
		window.clear();
		//Primitve shape, number of vertixes we want to use, , 
		glDrawElements(GL_TRIANGLES, 4,GL_UNSIGNED_INT,nullptr);
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		window.tick();
	}
}
