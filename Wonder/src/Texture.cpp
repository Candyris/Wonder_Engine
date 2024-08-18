#include "Texture.h"
#include <iostream>
Texture::Texture(const char* Path)
{
	glGenTextures(1,&ID);
	glBindTexture(GL_TEXTURE_2D, ID);
	int width, height, nrChannel;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(Path, &width, &height, &nrChannel, 0);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	GLenum format = 0;
	if (data)
	{
		
		if(format == 1)
		{
			format = GL_RED;

		}
		if(format == 2)
		{
			format = GL_RG;
		}
		if (format == 3)
		{
			format = GL_RGB;
		}
		if (format == 4)
		{
			format = GL_RGBA;
		}
	}
	else
	{
		std::cout<<std::string("[TEXTURE] : TEXTURE::LOAD : Failed to Load Image\n[PATH] : " + std::string(Path))<<std::endl;
	}
	glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(data);
}

void Texture::activate(unsigned int TextureUnit)
{
	glActiveTexture(TextureUnit);
}

void Texture::bind() 
{
	glBindTexture(GL_TEXTURE_2D, ID);
}
