#include "Shader.h"
#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
// Error Types



enum ERROR {VERTEX,FRAGMENT,PROGRAM};
struct ShaderCode
{
	std::string vertex;
	std::string fragment;
};
static std::string readFile(const char* filePath);
static ShaderCode PaseShader(const char* filepath);
static void ShaderError(ERROR errorType, unsigned int ID);

Shader::Shader(const char* VertexPath, const char* FragmentPath)
{
	
		// fileHandling
		std::string vString = readFile(VertexPath);
		std::string fString = readFile(FragmentPath);

		const char* vRaw = vString.c_str();
		const char* fRaw = fString.c_str();
		// Shader compile
		unsigned int vs = glCreateShader(GL_VERTEX_SHADER);
		unsigned int fs = glCreateShader(GL_FRAGMENT_SHADER);

		glShaderSource(vs, 1, &vRaw, nullptr);
		glShaderSource(fs, 1, &fRaw, nullptr);

		glCompileShader(vs);
		glCompileShader(fs);

		// error
		ShaderError(ERROR::VERTEX, vs);
		ShaderError(ERROR::FRAGMENT, fs);
		// Program
		ID = glCreateProgram();
		glAttachShader(ID, vs);
		glAttachShader(ID, fs);
		glLinkProgram(ID);
		// error 
		ShaderError(ERROR::PROGRAM, ID);
	
}

Shader::Shader(const char* ShaderPath)
{
	// fileHandling
	ShaderCode shaderSource = PaseShader(ShaderPath);
	std::string vString = shaderSource.vertex;
	std::string fString = shaderSource.fragment;

	const char* vRaw = vString.c_str();
	const char* fRaw = fString.c_str();
	// Shader compile
	unsigned int vs = glCreateShader(GL_VERTEX_SHADER);
	unsigned int fs = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vs, 1, &vRaw, nullptr);
	glShaderSource(fs, 1, &fRaw, nullptr);

	glCompileShader(vs);
	glCompileShader(fs);

	// error
	ShaderError(ERROR::VERTEX, vs);
	ShaderError(ERROR::FRAGMENT, fs);
	// Program
	ID = glCreateProgram();
	glAttachShader(ID, vs);
	glAttachShader(ID, fs);
	glLinkProgram(ID);
	// error 
	ShaderError(ERROR::PROGRAM, ID);

}

Shader::~Shader()
{
	glDeleteShader(ID);
}

void Shader::use() const 
{
	glUseProgram(ID);
}

void Shader::setUniformI(const char* name, const int& value)
{
	glUniform1i(GetUniformLocation(name), value);
}

void Shader::setUniformF(const char* name, const float& value)
{
	glUniform1f(GetUniformLocation(name), value);
}

void Shader::setUniformVec3(const char* name, const glm::vec3& value)
{
	glUniform3fv(GetUniformLocation(name),1, &value[0]);
}
void Shader::setUniformVec3(const char* name, const float& v1, const float& v2, const float& v3)
{
	glUniform3f(GetUniformLocation(name), v1,v2,v3);
}

void Shader::setUniformMat4(const char* name, const glm::mat4& value)
{
	glUniformMatrix4fv(GetUniformLocation(name),1,GL_FALSE,&value[0][0]);
}

int Shader::GetUniformLocation(const std::string& name)
{
	if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
	{
		return m_UniformLocationCache[name];
	}
	int location = glGetUniformLocation(ID, name.c_str());
	if (location == -1)
	{
		std::cout<<std::string("[Initialize Error] : HADER::UNIFORM::LOCATION : failed to find : " + name)<<std::endl;
	}
	m_UniformLocationCache[name] = location;
	return location;
}

static std::string readFile(const char* filePath)
{
	std::stringstream ss;
	std::ifstream stream(filePath);
	if (!stream.is_open())
	{
		throw std::string("Failed to Load File \n[File_Path] : " + std::string(filePath));
	}
	ss << stream.rdbuf();
	stream.close();
	return ss.str();
}

ShaderCode PaseShader(const char* filepath)
{

	ShaderCode code;
	std::fstream stream(filepath);
	if (!stream.is_open())
	{
		throw std::string("Failed to Load File : " + std::string(filepath));
	}
	std::string line;
	const int vertex = 0;
	const int fragment = 1;
	int selected = -1;
	while (std::getline(stream, line))
	{
		if ("#vertex shader" == line)
		{
			selected = vertex;
			continue;
		}
		else if ("#fragment shader" == line)
		{
			selected = fragment;
			continue;

		}
		switch (selected)
		{
		case vertex:
			code.vertex += line + '\n';
			break;
		case fragment:
			code.fragment += line + '\n';
			break;
		}
	}
	stream.close();
	return code;
}

static void ShaderError(ERROR errorType, unsigned int ID)
{
	switch (errorType)
	{	
	int result;
	char infoLog [512];
	case ERROR::VERTEX :
		glGetShaderiv(ID, GL_COMPILE_STATUS, &result);
		if (!result)
		{
			glGetShaderInfoLog(ID, 512, nullptr, infoLog);
			throw std::string("OPENGL::SHADER::VERTEX : Failed to Compiled \n[Shader Error] : " + std::string(infoLog));
		}
	break;
	case ERROR::FRAGMENT :
		glGetShaderiv(ID, GL_COMPILE_STATUS, &result);
		if (!result)
		{
			glGetShaderInfoLog(ID,512,nullptr,infoLog);
			throw std::string("OPENGL::SHADER::FRAGMENT : Failed to Compiled \n[Shader Error] : " + std::string(infoLog));
		}
	break;
	case ERROR::PROGRAM :
		glGetProgramiv(ID, GL_COMPILE_STATUS, &result);
		if (!result)
		{
			glGetProgramInfoLog(ID, 512, nullptr, infoLog);
			throw std::string("OPENGL::PROGRAM : Failed in Linking \n[Program Error] : " + std::string(infoLog));
		}
	break;
	}
}
