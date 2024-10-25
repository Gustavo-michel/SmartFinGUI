#pragma once

#include "SmartUI.h"

void SaveSettings();

void LoadSettings();

void loadFile(const std::string& filePath);

void cleanup(GLFWwindow* window);