//
// Created by rui ding on 2025/7/10.
//

#include "Hazel/renderer/Texture.h"

#include "Hazel/renderer/Renderer.h"
#include "platform/opengl/OpenGLTexture.h"

namespace Hazel
{
    Ref<Texture2D> Texture2D::Create(const std::string& path)
    {
        switch (Renderer::GetAPI())
        {
            case RendererAPI::API::None:
            {
                HZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
                return nullptr;
            }
            case RendererAPI::API::OpenGL:
                return std::make_shared<OpenGLTexture2D>(path);
        }
        HZ_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }
}