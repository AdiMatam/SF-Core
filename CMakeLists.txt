add_library (
    Core 
    STATIC
    Animation.cpp
    BaseScreen.cpp
    ButtonTextPair.cpp
    Helpers.cpp
    Image.cpp
    OriginFunc.cpp
    RoundedRectangle.cpp
    WindowManager.cpp
)

target_compile_definitions(Core PUBLIC SFML_STATIC TGUI_STATIC)
target_precompile_headers(Core PUBLIC ${CMAKE_SOURCE_DIR}/Core/Pch.hpp)
target_include_directories(Core PUBLIC ${CMAKE_SOURCE_DIR}/SFML-TGUI/include)