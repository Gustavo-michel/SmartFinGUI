#pragma once

#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>


bool initImGui(GLFWwindow* window);

void SaveSettings();

void LoadSettings();

void loadFile(const std::string& filePath);

void renderUI();

void cleanup(GLFWwindow* window);

