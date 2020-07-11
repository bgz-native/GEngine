#pragma once

#include "Buffer.h"

namespace GEngine
{

class VertexArray
{
public:
	virtual ~VertexArray() {}

	virtual void Bind() const = 0;
	virtual void UnBind() const = 0;

	virtual void AddVertexBuffer (const VertexBuffer* vertexBuffer) = 0;
	virtual void SetIndexBuffer  (const IndexBuffer* indexBuffer)   = 0;

	virtual const IndexBuffer* GetIndexBuffer() const = 0;

	static VertexArray* Create();
};

}