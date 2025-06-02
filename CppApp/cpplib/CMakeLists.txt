# File sorgente per la libreria
set(CPPLIB_SOURCES
    Num.cpp
    Str.cpp
    Utils.cpp
)

# Crea una libreria condivisa (DLL)
add_library(cpplib SHARED ${CPPLIB_SOURCES})

# Definisce la macro CPPLIB_EXPORTS per abilitare __declspec(dllexport)
target_compile_definitions(cpplib PRIVATE CPPLIB_EXPORTS)

# Rende pubblica la directory corrente per poter includere "xxx.hpp"
target_include_directories(cpplib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
