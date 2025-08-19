cmake_minimum_required(VERSION 3.21)
project(CMakeSample VERSION 1.0.0 LANGUAGES C CXX)
include(cmake/Settings.cmake)

# # Gestione delle opzioni di compilazione (warnings, ottimizzazione, debug)
# if(CMAKE_BUILD_TYPE STREQUAL "Debug")
#     add_compile_options(-Wall -Wextra -g) # Abilita tutti i warning, warning extra, info di debug
# else()
#     add_compile_options(-Wall -Wextra -O3) # Abilita tutti i warning, warning extra, ottimizzazione massima
# endif()

#-----------------
# Includi cartelle
#-----------------
add_subdirectory(C)
add_subdirectory(Cpp)
add_subdirectory(Gtk3)
add_subdirectory(Gtk4)
# add_subdirectory(Gtkmm4)
add_subdirectory(SQLite)
