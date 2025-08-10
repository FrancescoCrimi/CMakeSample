cmake_minimum_required(VERSION 3.15) # O una versione più recente che preferisci

# Dichiara che il monorepo userà sia il C che il C++.
# Questo inizializza i compilatori appropriati.
project(CMakeSample LANGUAGES C CXX)

# Impostazioni globali (opzionale, ma consigliato per coerenza)
# Verranno applicate a tutti i sottoprogetti, a meno che non vengano sovrascritte.

# Standard C (es. C11, C17, C99)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF) # Disabilita estensioni specifiche del compilatore

# Standard C++ (es. C++17, C++20)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) # Disabilita estensioni specifiche del compilatore

# Posiziona il codice indipendente (utile per librerie condivise, ma buona pratica in generale)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# # Gestione delle opzioni di compilazione (warnings, ottimizzazione, debug)
# if(CMAKE_BUILD_TYPE STREQUAL "Debug")
#     add_compile_options(-Wall -Wextra -g) # Abilita tutti i warning, warning extra, info di debug
# else()
#     add_compile_options(-Wall -Wextra -O3) # Abilita tutti i warning, warning extra, ottimizzazione massima
# endif()

# Aggiungi le sottodirectory per ogni tuo progetto.
# L'ordine può essere importante se ci sono dipendenze:
# le librerie dovrebbero essere aggiunte prima degli eseguibili che le usano.

add_subdirectory(C)
add_subdirectory(Cpp)
# add_subdirectory(Gtk3)
# add_subdirectory(Gtk4)
# add_subdirectory(Gtkmm4)
# add_subdirectory(SQLite)
