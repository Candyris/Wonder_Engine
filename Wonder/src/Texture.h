#pragma once
#include <stb/stb_image.h>
#include <glad/glad.h>
#include <string>
class Texture 
{
public:
	unsigned int ID;
	Texture(const char* Path, int format); // format  = {GL_RGB / GL_RGBA}
	void activate(unsigned int TextureUnit);
	void bind() ;
};