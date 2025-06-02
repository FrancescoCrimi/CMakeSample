# cmake_minimum_required(VERSION 3.16)
# project(Gtk4App VERSION 1.0 LANGUAGES C)

# # Usa lo standard C17
# set(CMAKE_C_STANDARD 17)
# set(CMAKE_C_STANDARD_REQUIRED ON)
# set(CMAKE_C_EXTENSIONS OFF)

# Trova pkg-config (necessario per recuperare i flag di GTK4)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED gtk4)

# if (CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
#   set(CMAKE_C_FLAGS_DEBUG "-Wall -Wextra -Wpedantic -g")
#   set(CMAKE_C_FLAGS_RELEASE "-O3 -DNDEBUG")
# elseif (MSVC)
#   set(CMAKE_C_FLAGS_DEBUG "/W4 /Zi")
#   set(CMAKE_C_FLAGS_RELEASE "/O2 /DNDEBUG")
# endif()

# Includi le cartelle dei due eseguibili
add_subdirectory(Gtk4Builder)
add_subdirectory(Gtk4Manual)
add_subdirectory(Gtk4MyDialog)

add_subdirectory(Gtk4Example)
