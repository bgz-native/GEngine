#pragma once

#include "GEngine/Core/Core.h"

namespace GEngine
{

enum class DataType
{
	None = 0,
	Float, Float2, Float3, Float4,
	Mat3, Mat4,
	Int, Int2, Int3, Int4,
	Bool
};

static uint32_t GetDataTypeSize(DataType type)
{
	switch (type)
	{
	case DataType::Float:	return 4;
	case DataType::Float2:	return 4 * 2;
	case DataType::Float3:	return 4 * 3;
	case DataType::Float4:	return 4 * 4;
	case DataType::Mat3:	return 4 * 3 * 3;
	case DataType::Mat4:	return 4 * 4 * 4;
	case DataType::Int:		return 4;
	case DataType::Int2:	return 4 * 2;
	case DataType::Int3:	return 4 * 3;
	case DataType::Int4:	return 4 * 4;
	case DataType::Bool:	return 1;
	}

	LOGE("Unknown Shader Type!!");

	return 0;
}

struct BufferElement
{
	std::string name;
	DataType type;
	uint32_t size;
	uint32_t offset;
	bool normalized;

	BufferElement(DataType dataType, const std::string& elementName, bool isNormalized = false)
		: type(dataType), name(elementName), size(GetDataTypeSize(dataType)), offset(0), normalized(isNormalized) {}

	uint32_t GetElementCount() const
	{
		switch (type)
		{
			case DataType::Float:	return 1;
			case DataType::Float2:	return 2;
			case DataType::Float3:	return 3;
			case DataType::Float4:	return 4;
			case DataType::Mat3:	return 3 * 3;
			case DataType::Mat4:	return 4 * 4;
			case DataType::Int:		return 1;
			case DataType::Int2:	return 2;
			case DataType::Int3:	return 3;
			case DataType::Int4:	return 4;
			case DataType::Bool:	return 1;

			default: break;
		}
	}

};

class BufferLayout 
{
public:
	BufferLayout() {}

	BufferLayout(const std::initializer_list<BufferElement>& bufferElements) 
		: m_elements(bufferElements) 
	{
		CalculateOffsetAndStride();
	}

	inline uint32_t GetStride() const { return m_stride; }
	inline const std::vector<BufferElement> GetElements() const { return m_elements; }

	std::vector<BufferElement>::iterator begin() { return m_elements.begin(); }
	std::vector<BufferElement>::iterator end() { return m_elements.end(); }
	std::vector<BufferElement>::const_iterator begin() const { return m_elements.begin(); }
	std::vector<BufferElement>::const_iterator end() const { return m_elements.end(); }

private:
	void CalculateOffsetAndStride()
	{
		uint32_t offset = 0;
		m_stride = 0;

		for (auto& element : m_elements)
		{
			element.offset = offset;
			offset += element.size;
			m_stride += element.size;
		}
	}

private:
	std::vector<BufferElement> m_elements;
	uint32_t m_stride = 0;

};


class VertexBuffer
{
public:
	virtual ~VertexBuffer() {}

	virtual void Bind() const = 0;
	virtual void UnBind() const = 0;

	virtual const BufferLayout& GetLayout() const = 0;
	virtual void SetLayout(const BufferLayout& layout) = 0;

	static VertexBuffer* Create(float* vertices, uint32_t size);
};

class IndexBuffer
{
public:
	virtual ~IndexBuffer() {}

	virtual void Bind() const = 0;
	virtual void UnBind() const = 0;

	virtual uint32_t GetCount() const = 0;

	static IndexBuffer* Create(uint32_t* indices, uint32_t size);
};





}