#pragma once
#include <string>

namespace GEngine
{

class Shader
{
public:
	Shader(const std::string& vertexSourceString, const std::string& fragmentSourceString);
	~Shader();

	void Bind() const;
	void UnBind() const;

private:
	uint32_t m_rendererId;
};

}