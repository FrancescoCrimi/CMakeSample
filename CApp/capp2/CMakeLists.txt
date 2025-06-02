# Crea l'eseguibile "capp2" a partire da main.c
add_executable(capp2 main.c)

# Collega l'eseguibile alla libreria dinamica "clib"
target_link_libraries(capp2 PRIVATE clib)

# Post-build: copia la DLL nella directory dell'eseguibile (solo su Windows)
if(WIN32)
  add_custom_command(TARGET capp2 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "$<TARGET_FILE:clib>"
      "$<TARGET_FILE_DIR:capp2>"
    COMMENT "Copia la DLL di clib nella directory di capp2"
  )
endif()
