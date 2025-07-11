//
// Created by rui ding on 2025/7/9.
//

#include "platform/opengl/OpenGLRendererAPI.h"

#include <glad/glad.h>

namespace Hazel
{
    void OpenGLRendererAPI::Init()
    {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }

    void OpenGLRendererAPI::SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
    {
        glViewport(x, y, width, height);
    }

    void OpenGLRendererAPI::SetClearColor(const glm::vec4 color)
    {
        glClearColor(color.x, color.y, color.z, color.w);
    }

    void OpenGLRendererAPI::Clear()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void OpenGLRendererAPI::DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray)
    {
        glDrawElements(GL_TRIANGLES, vertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT,
                       reinterpret_cast<const void*>(static_cast<uintptr_t>(0)));
    }
}