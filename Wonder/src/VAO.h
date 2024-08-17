#pragma once

class VAO
{
public:
	unsigned int ID;
	VAO();
	~VAO();
	void bind();
	void unbind();
	void linkAttrib(unsigned int index, int size, unsigned int  type, int stride, const void* pointer);
};