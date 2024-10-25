#include "utils.h"


void SaveSettings() {

}

void LoadSettings() {

}

void loadFile(const std::string& filePath) {
    std::cout << "Carregando arquivo: " << filePath << std::endl;
    // Adicionar logica de carregamento
}

void cleanup(GLFWwindow* window) {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();
}
