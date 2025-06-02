# Crea l'eseguibile "capp1" a partire da main.c
add_executable(capp1 main.c)

# Collega l'eseguibile alla libreria condivisa "clib"
target_link_libraries(capp1 PRIVATE clib)

# Comando post-build per copiare la DLL nella directory dell'eseguibile (solo su Windows)
if(WIN32)
  add_custom_command(TARGET capp1 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "$<TARGET_FILE:clib>"
      "$<TARGET_FILE_DIR:capp1>"
    COMMENT "Copia la DLL di clib nella directory di capp1"
  )
endif()
