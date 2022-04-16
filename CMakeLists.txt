add_library (
    SF-Core 
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

target_compile_definitions(SF-Core PUBLIC SFML_STATIC TGUI_STATIC)
target_precompile_headers(SF-Core PUBLIC ${CMAKE_SOURCE_DIR}/SF-Core/Pch.hpp)
target_include_directories(SF-Core PUBLIC ${CMAKE_SOURCE_DIR}/SFML-TGUI/include)