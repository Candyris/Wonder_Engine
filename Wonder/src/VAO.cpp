#include "VAO.h"
#include <glad/glad.h>

VAO::VAO()
{
	glGenVertexArrays(1,&ID);
}

VAO::~VAO()
{
	glDeleteVertexArrays(1,&ID);
}

void VAO::bind()
{
	glBindVertexArray(ID);
}

void VAO::unbind()
{
	glBindVertexArray(0);
}

void VAO::linkAttrib(unsigned int index, int size,unsigned int  type, int stride, const void* pointer)
{
	glVertexAttribPointer(index,size,type, GL_FALSE,stride,(const void*)pointer);
	glEnableVertexAttribArray(index);
}
