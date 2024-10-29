#include "RenderImgui.h"
#include "utils.h"

bool initImGui(GLFWwindow* window) {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");
    ImGui::StyleColorsDark();

    return true;
}

void renderUI() {
    ImGui::Begin("UI", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);

    // Inputs

    /// Campos de entrada
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

    /// Nome dos campos


    if (ImGui::Button("Carregar Arquivo")) {
        loadFile("caminho/do/arquivo.sav");
    }

    if (ImGui::Button("Submit")) {
        // Processar entrada
        std::cout << "Dados enviados!" << std::endl;
    }

    // Cores

    ImGuiStyle& style = ImGui::GetStyle();
    ImVec4* colors = style.Colors;

    /// Fundo principal e borda
    colors[ImGuiCol_WindowBg] = ImVec4(0.13f, 0.14f, 0.15f, 1.0f);
    colors[ImGuiCol_Border] = ImVec4(0.43f, 0.43f, 0.5f, 0.5f);

    /// Texto
    colors[ImGuiCol_Text] = ImVec4(0.95f, 0.96f, 0.98f, 1.0f);
    colors[ImGuiCol_TextDisabled] = ImVec4(0.5f, 0.5f, 0.5f, 1.0f);

    /// Botões
    colors[ImGuiCol_Button] = ImVec4(0.18f, 0.3f, 0.58f, 1.0f);
    colors[ImGuiCol_ButtonHovered] = ImVec4(0.26f, 0.4f, 0.68f, 1.0f);
    colors[ImGuiCol_ButtonActive] = ImVec4(0.06f, 0.26f, 0.53f, 1.0f);

    /// Fundo dos campos de entrada
    colors[ImGuiCol_FrameBg] = ImVec4(0.16f, 0.16f, 0.17f, 1.0f);
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.2f, 0.25f, 0.3f, 1.0f);
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.18f, 0.24f, 0.4f, 1.0f);

    /// Sliders
    colors[ImGuiCol_SliderGrab] = ImVec4(0.28f, 0.56f, 1.0f, 1.0f);
    colors[ImGuiCol_SliderGrabActive] = ImVec4(0.38f, 0.66f, 1.0f, 1.0f);

    /// Barras de rolagem
    colors[ImGuiCol_ScrollbarBg] = ImVec4(0.1f, 0.1f, 0.1f, 1.0f);
    colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.3f, 0.3f, 0.3f, 1.0f);
    colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.4f, 0.4f, 0.4f, 1.0f);
    colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.5f, 0.5f, 0.5f, 1.0f);

    /// Separadores
    colors[ImGuiCol_Separator] = ImVec4(0.28f, 0.28f, 0.28f, 1.0f);
    colors[ImGuiCol_SeparatorHovered] = ImVec4(0.38f, 0.38f, 0.38f, 1.0f);
    colors[ImGuiCol_SeparatorActive] = ImVec4(0.47f, 0.47f, 0.47f, 1.0f);

    /// Título da janela
    colors[ImGuiCol_TitleBg] = ImVec4(0.09f, 0.09f, 0.09f, 1.0f);
    colors[ImGuiCol_TitleBgActive] = ImVec4(0.16f, 0.16f, 0.16f, 1.0f);
    colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.05f, 0.05f, 0.05f, 0.75f);

    ImGui::End();
}