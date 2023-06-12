
#include <iostream>
#include <cstdio>
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
#include "Sprite.h"
#include "StaticSprite.h"
#include "BatchRenderer2D.h"
#include <vector>
#include <time.h>
#include "Timer.h"
#include<GL/glew.h>
#include "TileLayer.h"
#include "Layer.h"
#include "Group.h"
#include <FreeImage.h>
#include "Texture.h"



int main() {
	

	Sparky::Graphics::Window window(800, 600, "Sparky!");
	 
	//std::vector<Sparky::Graphics::Renderable2D*> sprites;
	Sparky::Graphics::Shader* shader= new Sparky::Graphics::Shader("source/shaders/basic.vert", "source/shaders/basic.frag");

	//Layer 1
	srand(time(NULL));
	Sparky::Graphics::TileLayer background(shader);
	for (float y = -9.0f; y < 9.0f; ++y) {
		for (float x = -16.0f; x < 16.0f; ++x) {
			background.add(new Sparky::Graphics::Sprite(x, y, 0.9f, 0.9f, Sparky::Maths::Vec4(((rand() % 1000) / 1000.0f), 0, 1, 1)));
		}
	}

	
	
	
	glActiveTexture(GL_TEXTURE0);
	Sparky::Graphics::Texture texture("test.png");
	texture.bind();


	shader->enable();
	shader->setUniform1i("tex", 0);
	shader->setUniformMat4("pr_matrix", Sparky::Maths::Matrix4::orthographic(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f));

	
	double x, y;
	Sparky::Utils::Timer time;
	float  timer = 0;
	unsigned int fps=0;
	while (!window.closed()) {
		fps++;
		window.clear();
		window.getMousePosition(x, y);
		//Light source to mouse (i know it's a little off)
		shader->setUniform2f("light_pos", Sparky::Maths::Vec2( (float) (x * 32.0f/960.0f -16.0f +2.4f) , (float)(9.0f -y*18.0f/ 540.0f ) ) );
		background.render();
	    
		
		window.tick();
		//fps counter
		if ((time.elapsed() - timer) >= 1) {
			printf("%d \n",fps);
			timer += 1.0f;
			fps = 0;
		}
	}
}


/*int main() {
	const char* filename = "test.png";
	//image format
	FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
	//pointer to the image, once loaded
	FIBITMAP* dib(0);
	//pointer to the image data
	BYTE* bits(0);
	//image width and height
	unsigned int width(0), height(0);
	//OpenGL's image ID to map to
	GLuint gl_texID;

	//check the file signature and deduce its format
	fif = FreeImage_GetFileType(filename, 0);
	//if still unknown, try to guess the file format from the file extension
	if (fif == FIF_UNKNOWN)
		fif = FreeImage_GetFIFFromFilename(filename);
	//if still unkown, return failure
	if (fif == FIF_UNKNOWN)
		return false;

	//check that the plugin has reading capabilities and load the file
	if (FreeImage_FIFSupportsReading(fif))
		dib = FreeImage_Load(fif, filename);
	//if the image failed to load, return failure
	if (!dib)
		return false;

	//retrieve the image data
	bits = FreeImage_GetBits(dib);
	//get the image width and height
	width = FreeImage_GetWidth(dib);
	height = FreeImage_GetHeight(dib);
	//if this somehow one of these failed (they shouldn't), return failure
	if ((bits == 0) || (width == 0) || (height == 0))
		return false;


	std::cout << width << " , " << height << std::endl;
	FreeImage_Unload(dib);
	return 0;
}*/
