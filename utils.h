#pragma once

#include "SmartFinGUI.h"

void SaveSettings();

void LoadSettings();

void loadFile(const std::string& filePath);

void cleanup(GLFWwindow* window);