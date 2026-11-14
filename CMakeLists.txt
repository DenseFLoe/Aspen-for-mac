cmake_minimum_required(VERSION 3.21)
project(AspenPlusUIShell VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Qt6 6.5 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

qt_add_executable(AspenPlusUIShell
    src/main.cpp
    src/UiShell.cpp
    src/UiShell.h
)
qt_add_resources(AspenPlusUIShell "ui_catalog"
    PREFIX "/"
    FILES ui/aspen-plus.json ui/shell.qss
)
target_link_libraries(AspenPlusUIShell PRIVATE Qt6::Widgets)
set_target_properties(AspenPlusUIShell PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
    MACOSX_BUNDLE_GUI_IDENTIFIER "org.aspenformac.uishell"
    MACOSX_BUNDLE_BUNDLE_NAME "Aspen Plus UI Shell"
    MACOSX_BUNDLE_SHORT_VERSION_STRING "${PROJECT_VERSION}"
)
if(MSVC)
    target_compile_options(AspenPlusUIShell PRIVATE /utf-8)
endif()
