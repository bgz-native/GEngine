#pragma once

#include "GEngine/Renderer/VertexArray.h"

namespace GEngine
{

class OpenGLVertexArray : public VertexArray
{
public:
	OpenGLVertexArray();
	virtual ~OpenGLVertexArray() {}

	virtual void Bind() const override;
	virtual void UnBind() const override;

	virtual void AddVertexBuffer(const VertexBuffer* vertexBuffer) override;
	virtual void SetIndexBuffer(const IndexBuffer* indexBuffer) override;

	virtual const IndexBuffer* GetIndexBuffer() const { return m_indexBuffer; }

private:
	std::vector<const VertexBuffer*> m_vertexBuffers;
	const IndexBuffer* m_indexBuffer;

	uint32_t m_rendererId;
};


}