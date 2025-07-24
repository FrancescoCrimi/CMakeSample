# Crea l'eseguibile "capp1" a partire da main.c
add_executable(CApp1 main.c)

# Collega l'eseguibile alla libreria condivisa "CLib"
target_link_libraries(CApp1 PRIVATE CLib)

# Comando post-build per copiare la DLL nella directory dell'eseguibile (solo su Windows)
if(WIN32)
  add_custom_command(TARGET CApp1 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "$<TARGET_FILE:CLib>"
      "$<TARGET_FILE_DIR:CApp1>"
    COMMENT "Copia la DLL di CLib nella directory di CApp1"
  )
endif()
