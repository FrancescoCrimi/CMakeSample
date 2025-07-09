# cmake_minimum_required(VERSION 3.15)
# project(Gtk3App VERSION 1.0 LANGUAGES C)

# # Imposta la versione di C
# set(CMAKE_C_STANDARD 17)
# set(CMAKE_C_STANDARD_REQUIRED True)

# Richiede pkg-config per individuare GTK3
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

add_subdirectory(Gtk3Lib)
add_subdirectory(Gtk3App)
