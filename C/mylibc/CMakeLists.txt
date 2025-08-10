set(MYLIBC_HEADERS
    include/mylibc.h
    include/export.h
    include/num.h
    include/str.h
    include/utils.h
)

set(MYLIBC_SOURCES
    src/num.c
    src/str.c
    src/utils.c
)

# ===========================
# 📦 Libreria dinamica (.dll/.so)
# ===========================

# Crea la libreria condivisa (DLL su Windows) a partire dai sorgenti num.c e str.c
add_library(mylibc_shared SHARED ${MYLIBC_SOURCES} ${MYLIBC_HEADERS})
add_library(mylibc::shared ALIAS mylibc_shared)

set_target_properties(mylibc_shared PROPERTIES
  OUTPUT_NAME "mylibc"
  POSITION_INDEPENDENT_CODE ON
  VERSION 1.0.0                 # solo shared
  SOVERSION 1                   # solo shared
)

# Imposta la directory corrente come include directory pubblica
target_include_directories(mylibc_shared PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Definisce la macro che abilita l'esportazione dei simboli durante la compilazione della DLL
target_compile_definitions(mylibc_shared 
    PRIVATE MYLIBC_EXPORTS
    PRIVATE MYLIBC_SHARED
)

# ===========================
# 📦 Libreria statica (.a/.lib)
# ===========================

add_library(mylibc_static STATIC ${MYLIBC_SOURCES} ${MYLIBC_HEADERS})
add_library(mylibc::static ALIAS mylibc_static)

# Rinominare solo su Windows
set_target_properties(mylibc_static PROPERTIES
  OUTPUT_NAME $<IF:$<PLATFORM_ID:Windows>,mylibc_static,mylibc>
  POSITION_INDEPENDENT_CODE ON
)

# Imposta la directory corrente come include directory pubblica
target_include_directories(mylibc_static PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# ===========================
# 🔩 Output ordinato
# ===========================

set_target_properties(mylibc_shared PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin   # .dll
  LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib   # .so
  ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib   # import .lib
)
set_target_properties(mylibc_static PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib   # .a / .lib
)

# ===========================
# 🎛️ Opzioni per abilitare/disabilitare build
# ===========================

option(MYLIBC_BUILD_SHARED "Build shared library" ON)
option(MYLIBC_BUILD_STATIC "Build static library" ON)

if(NOT MYLIBC_BUILD_SHARED)
  set_target_properties(mylibc_shared PROPERTIES EXCLUDE_FROM_ALL ON)
endif()
if(NOT MYLIBC_BUILD_STATIC)
  set_target_properties(mylibc_static PROPERTIES EXCLUDE_FROM_ALL ON)
endif()

# ===========================
# 📦 Installazione
# ===========================

include(GNUInstallDirs)

install(TARGETS mylibc_shared mylibc_static
  EXPORT mylibc-targets
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT mylibc-targets
  NAMESPACE mylibc::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/mylibc
)
