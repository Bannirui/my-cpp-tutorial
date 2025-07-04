//
// Created by dingrui on 25-6-22.
//

#pragma once

#include "Hazel/Event/ApplicationEvent.h"
#include "Hazel/Window.h"
#include "Hazel/imgui/ImGuiLayer.h"
#include "Layer.h"
#include "LayerStack.h"

namespace Hazel
{
    class Application
    {
       public:
        Application();
        virtual ~Application();
        void Run();
        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

        inline Window&             GetWindow() { return *m_Window; }
        inline static Application& Get() { return *s_Instance; }

       private:
        std::unique_ptr<Window> m_Window;
        ImGuiLayer*             m_ImGuiLayer;
        bool                    m_Running = true;
        bool                    OnWindowClose(WindowCloseEvent& e);
        LayerStack              m_LayerStack;

       private:
        static Application* s_Instance;
    };

    // for entry point
    Application* CreateApplication();
}  // namespace Hazel
