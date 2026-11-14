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
    src/IconCatalog.cpp
    src/IconCatalog.h
    src/ComponentWorkspace.cpp
    src/ComponentWorkspace.h
    src/LightTheme.h
    src/RecoveredWorkspace.cpp
    src/RecoveredWorkspace.h
)
file(GLOB RECOVERED_UI_FILES CONFIGURE_DEPENDS RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "ui/recovered/*.json")
list(FILTER RECOVERED_UI_FILES EXCLUDE REGEX "/(buttons|unresolved|sources|summary|scan-errors|scan-files|coverage|validation)\\.json$")
qt_add_resources(AspenPlusUIShell "ui_catalog"
    PREFIX "/"
    FILES ui/aspen-plus.json ui/components.json ui/shell.qss ui/icons/aspen-v15.png ui/icons/manifest.json ${RECOVERED_UI_FILES}
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

include(CTest)
if(BUILD_TESTING)
    find_package(Qt6 REQUIRED COMPONENTS Test)
    qt_add_executable(UiSmokeTest
        tests/UiSmokeTest.cpp src/UiShell.cpp src/UiShell.h
        src/IconCatalog.cpp src/IconCatalog.h
        src/ComponentWorkspace.cpp src/ComponentWorkspace.h
        src/LightTheme.h
        src/RecoveredWorkspace.cpp src/RecoveredWorkspace.h
    )
    target_include_directories(UiSmokeTest PRIVATE src)
    target_link_libraries(UiSmokeTest PRIVATE Qt6::Widgets Qt6::Test)
    qt_add_resources(UiSmokeTest "test_ui_catalog"
        PREFIX "/"
        FILES ui/aspen-plus.json ui/components.json ui/shell.qss ui/icons/aspen-v15.png ui/icons/manifest.json ${RECOVERED_UI_FILES}
    )
    if(MSVC)
        target_compile_options(UiSmokeTest PRIVATE /utf-8)
    endif()
    add_test(NAME ui-smoke COMMAND UiSmokeTest)
    set_tests_properties(ui-smoke PROPERTIES ENVIRONMENT "QT_QPA_PLATFORM=offscreen" TIMEOUT 300)
endif()
