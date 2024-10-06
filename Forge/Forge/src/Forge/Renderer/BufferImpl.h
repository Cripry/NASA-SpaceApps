//
// Created by toor on 2024-09-23.
//

#ifndef BUFFERIMPL_H
#define BUFFERIMPL_H


#include "Buffer.h"
#include <vector>
#include <glad/glad.h>
#include <glm/glm.hpp>

namespace Forge {


//========================================
//  Vertex Buffer
//========================================


class VertexBuffer : public Buffer
{
public:
    VertexBuffer(const void* data, uint32_t count);
    ~VertexBuffer();

    void Bind() const override;
    void Unbind() const override;


    const BufferLayout& GetLayout()
    {
        return m_Layout;
    }
    void SetLayout(const BufferLayout& layout)
    {
        m_Layout = layout;
    }

private:
    unsigned int m_RendererID;
    BufferLayout m_Layout;
};


//========================================
//  Index Buffer
//========================================


class IndexBuffer : public Buffer
{
public:
    IndexBuffer(uint32_t* data, uint32_t count);
    ~IndexBuffer();

    IndexBuffer(const IndexBuffer&) = delete;
    IndexBuffer& operator=(const IndexBuffer&) = delete;

    void Bind() const override;
    void Unbind() const override;

    inline unsigned int GetCount() const
    {
        return m_Count;
    }

private:
    unsigned int m_RendererID;
    unsigned int m_Count;
};


//========================================
//  Vertex Array Buffer
//========================================


class VertexArrayBuffer : public Buffer
{
public:
    VertexArrayBuffer();
    ~VertexArrayBuffer();

    void Bind() const override;
    void Unbind() const override;

    void AddVertexBuffer(std::shared_ptr<VertexBuffer>& vertexBuffer);
    void SetIndexBuffer(std::shared_ptr<IndexBuffer>& indexBuffer);

    const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const
    {
        return m_IndexBuffer;
    }

private:
    std::vector<std::shared_ptr<VertexBuffer>> m_VertexBuffers;
    std::shared_ptr<IndexBuffer> m_IndexBuffer;
    unsigned int m_RendererID;
};

}  // namespace Forge


#endif
