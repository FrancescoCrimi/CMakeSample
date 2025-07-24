# File sorgente per la libreria
set(CLIB_SOURCES
    num.c
    str.c
    utils.c
)

# Crea la libreria condivisa (DLL su Windows) a partire dai sorgenti num.c e str.c
add_library(CLib SHARED ${CLIB_SOURCES})

# Definisce la macro che abilita l'esportazione dei simboli durante la compilazione della DLL
target_compile_definitions(CLib PRIVATE CLIB_EXPORTS)

# Imposta la directory corrente come include directory pubblica
target_include_directories(CLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
