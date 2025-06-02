# cmake_minimum_required(VERSION 3.16)
# project(GtkmmApp VERSION 1.0 LANGUAGES CXX)

# # Imposta lo standard C++17 (richiesto) e obbliga l’uso di questo standard
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Usa pkg-config per trovare gtkmm4 (versione 4.18)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM4 REQUIRED gtkmm-4.0)


# Includi le cartelle dei due eseguibili
add_subdirectory(GtkmmApp)
add_subdirectory(AlertDialogExample)
