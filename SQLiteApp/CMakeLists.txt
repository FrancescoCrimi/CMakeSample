# cmake_minimum_required(VERSION 3.16)

# # Nome del progetto
# project(SQLiteApp VERSION 1.0 LANGUAGES C)

# # Imposta la versione di C
# set(CMAKE_C_STANDARD 17)
# set(CMAKE_C_STANDARD_REQUIRED True)

# Aggiungi i file sorgenti
add_executable(SQLiteApp main.c database_manager.c)

# # Specifica i percorsi per sqlite e Linka le librerie via CMake
# find_package(unofficial-sqlite3 CONFIG REQUIRED)
# target_link_libraries(SQLiteApp PRIVATE unofficial::sqlite3::sqlite3)

# Trova pkg-config (necessario per recuperare i flag di GTK4)
find_package(PkgConfig REQUIRED)
pkg_check_modules(SQLITE3 REQUIRED sqlite3)

# Linka le librerie 
target_compile_options(SQLiteApp PRIVATE ${SQLITE3_CFLAGS_OTHER})
target_include_directories(SQLiteApp PRIVATE ${SQLITE3_INCLUDE_DIRS})
target_link_directories(SQLiteApp PRIVATE ${SQLITE3_LIBRARY_DIRS})
target_link_libraries(SQLiteApp PRIVATE ${SQLITE3_LIBRARIES})
