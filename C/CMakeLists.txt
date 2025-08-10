# cmake_minimum_required(VERSION 3.16)

# # Nome del progetto
# project(LibraryC VERSION 0.1.0 LANGUAGES C)

# # Impostazione dello standard C17
# set(CMAKE_C_STANDARD 17)
# set(CMAKE_C_STANDARD_REQUIRED ON)
# set(CMAKE_C_EXTENSIONS OFF)

# Aggiunta delle sottodirectory: libreria e app
add_subdirectory(mylibc)
add_subdirectory(appc1)
add_subdirectory(appc2)
