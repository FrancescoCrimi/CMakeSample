# cmake_minimum_required(VERSION 3.16)

# # Nome del progetto
# project(LibraryCpp VERSION 0.1.0 LANGUAGES CXX)

# # Imposta lo standard C++
# set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_EXTENSIONS OFF)

# Aggiunta delle sottodirectory: libreria e app
add_subdirectory(cpplib)
add_subdirectory(cppapp1)
add_subdirectory(cppapp2)
