#include "SmartFinGUI.h"

int main() {
    if (!glfwInit())
        return -1;

    GLFWwindow* window = glfwCreateWindow(1280, 720, "SmartFinGUI", nullptr, nullptr);
    if (!window) {
        cleanup(window);
        return -1;
    }

    glfwMakeContextCurrent(window);

    initImGui(window);

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        int width, height;
        glfwGetWindowSize(window, &width, &height);
        ImGui::SetWindowSize(ImVec2((float)width, (float)height));


        renderUI();

        ImGui::Render();
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    cleanup(window);
    return 0;
}

bool initImGui(GLFWwindow* window) {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");
    ImGui::StyleColorsDark();
    return true;
}

void SaveSettings() {

}

void LoadSettings() {

}

void loadFile(const std::string& filePath) {
    std::cout << "Carregando arquivo: " << filePath << std::endl;
    // Adicionar logica de carregamento
}

void renderUI() {
    ImGui::Begin("UI");

    // Campos de entrada
    static int inputCount = 0;
    static std::vector<float> inputValues(0, 0.0f);

    ImGui::Text("Escolha quantos campos deseja:");
    ImGui::SliderInt("Numero de Campos", &inputCount, 1, 20);

    if (inputValues.size() != inputCount) {
        inputValues.resize(inputCount, 0.0f);
    }

    for (int i = 0; i < inputCount; i++) {
        bool isInteger = (std::floor(inputValues[i]) == inputValues[i]);

        const char* format = isInteger ? "%.1f" : "%.6f";

        ImGui::InputFloat(("Campo " + std::to_string(i + 1)).c_str(), &inputValues[i], 0.0f, 0.0f, format);
    }

    // Nome dos campos


    if (ImGui::Button("Carregar Arquivo")) {
        loadFile("caminho/do/arquivo.sav");
    }

    if (ImGui::Button("Submit")) {
        // Processar entrada
        std::cout << "Dados enviados!" << std::endl;
    }

    ImGui::End();
}


void cleanup(GLFWwindow* window) {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();
}


