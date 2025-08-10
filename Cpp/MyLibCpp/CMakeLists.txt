set(MYLIBCPP_HEADERS
    include/export.hpp
    include/MyLibCpp.hpp
    include/Num.hpp
    include/Str.hpp
    include/Utils.hpp
)

set(MYLIBCPP_SOURCES
    src/Num.cpp
    src/Str.cpp
    src/Utils.cpp
)

# ----------------------
# Libreria Condivisa
# ----------------------

# Crea una libreria condivisa
add_library(MyLibCpp_shared SHARED ${MYLIBCPP_SOURCES} ${MYLIBCPP_HEADERS})
add_library(MyLibCpp::shared ALIAS MyLibCpp_shared)

# Imposta nome libreria condivisa
set_target_properties(MyLibCpp_shared PROPERTIES
  OUTPUT_NAME "MyLibCpp"
  POSITION_INDEPENDENT_CODE ON
  VERSION 1.0.0                 # solo shared
  SOVERSION 1                   # solo shared
)

# Rende pubblica la directory corrente per poter includere "xxx.hpp"
target_include_directories(MyLibCpp_shared PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Definisce la macro MYLIBCPP_EXPORTS per abilitare __declspec(dllexport)
target_compile_definitions(MyLibCpp_shared
    PRIVATE MYLIBCPP_EXPORTS
)

# ----------------------
# Libreria Statica
# ----------------------
