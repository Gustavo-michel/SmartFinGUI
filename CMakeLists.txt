cmake_minimum_required (VERSION 3.8)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("SmartFinGUI")

set(SOURCES
	"SmartFinGUI/SmartUI.cpp" 
	"SmartFinGUI/SmartUI.h" 
	"vendor/imgui/backends/imgui_impl_glfw.cpp"
    "vendor/imgui/backends/imgui_impl_opengl3.cpp"
	"vendor/imgui/imgui.cpp"
    "vendor/imgui/imgui_draw.cpp"
    "vendor/imgui/imgui_tables.cpp"
    "vendor/imgui/imgui_widgets.cpp"
	"SmartFinGUI/RenderImgui.cpp"
	"SmartFinGUI/RenderImgui.h"
	"SmartFinGUI/RenderGLFW.cpp" 
	"SmartFinGUI/RenderGLFW.h" 
	"SmartFinGUI/utils.cpp" 
	"SmartFinGUI/utils.h"
)

add_executable (SmartUI ${SOURCES} )

find_package(imgui CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)

target_include_directories(SmartUI PRIVATE ${PROJECT_SOURCE_DIR}/vendor/imgui)
target_include_directories(SmartUI PRIVATE ${PROJECT_SOURCE_DIR}/vendor/imgui/backends)

target_link_libraries(SmartUI PRIVATE glfw OpenGL::GL)