#include "SmartUI.h"
#include "RenderImgui.h"
#include "RenderGLFW.h"
#include "utils.h"

int main() {    

    initGLFW();
    GLFWwindow* window = glfwCreateWindow(1280, 720, "SmartFinGUI", nullptr, nullptr);
    if (!window) {
        std::cerr << "Erro: Falha ao criar janela GLFW!" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);

    initImGui(window);
    glfWindow(window);

    cleanup(window);
    return 0;
}

