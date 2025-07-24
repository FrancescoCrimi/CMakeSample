# Crea l'eseguibile "capp2" a partire da main.c
add_executable(CApp2 main.c)

# Collega l'eseguibile alla libreria dinamica "CLib"
target_link_libraries(CApp2 PRIVATE CLib)

# Post-build: copia la DLL nella directory dell'eseguibile (solo su Windows)
if(WIN32)
  add_custom_command(TARGET CApp2 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "$<TARGET_FILE:CLib>"
      "$<TARGET_FILE_DIR:CApp2>"
    COMMENT "Copia la DLL di CLib nella directory di CApp2"
  )
endif()
