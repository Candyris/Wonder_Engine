#pragma once
#include <glm/glm.hpp>
#include <unordered_map>
#include <string>
class Shader
{
public:
	unsigned int ID =0 ;
	Shader(const char* VertexPath, const char* FragmentPath);
	Shader(const char* ShaderPath);
	~Shader();
	void use() const;
public:
// uniform
	void setUniformI(const char* name,const int& value);
	void setUniformF(const char* name,const float& value);
	void setUniformVec3(const char* name,const glm::vec3& value);
	void setUniformVec3(const char* name, const float& v1, const float& v2, const float& v3);
	void setUniformMat4(const char* name, const glm::mat4& value);
private:
	std::unordered_map<std::string, int> m_UniformLocationCache;
	int GetUniformLocation(const std::string& name);
};