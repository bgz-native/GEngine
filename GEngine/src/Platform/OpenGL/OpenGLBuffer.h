#pragma once

#include "GEngine/Renderer/Buffer.h"

namespace GEngine
{

class OpenGLVertexBuffer : public VertexBuffer
{
public:
	OpenGLVertexBuffer(float* vertices, uint32_t size);
	virtual ~OpenGLVertexBuffer();

	virtual void Bind() const override;
	virtual void UnBind() const override;

	virtual const BufferLayout& GetLayout() const override
	{
		return m_layout;
	}
	virtual void SetLayout(const BufferLayout& layout) override
	{
		m_layout = layout;
	}

private:
	uint32_t m_rendererId;
	BufferLayout m_layout;
};


class OpenGLIndexBuffer : public IndexBuffer
{
public:
	OpenGLIndexBuffer(uint32_t* indices, uint32_t count);
	virtual ~OpenGLIndexBuffer();

	virtual void Bind() const;
	virtual void UnBind() const;

	virtual uint32_t GetCount() const { return m_count; }
private:
	uint32_t m_rendererId;
	uint32_t m_count;

};

}