# cmake_minimum_required(VERSION 3.16)
# project(SQLiteCppApp VERSION 1.0 LANGUAGES CXX)

# # Imposta lo standard C++17 richiesto
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Trova la libreria SQLiteCpp tramite pkg-config.
# Se stai utilizzando vcpkg, assicurati di integrare il toolchain di vcpkg.
find_package(SQLiteCpp CONFIG REQUIRED)

# Crea l'eseguibile partendo dal file main.cpp
add_executable(SQLiteCppApp main.cpp)

# Collega la libreria SQLiteCpp all'eseguibile
target_link_libraries(SQLiteCppApp PRIVATE SQLiteCpp)
