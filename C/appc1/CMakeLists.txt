# Crea l'eseguibile "appc1" a partire da main.c
add_executable(appc1 main.c)

# Collega l'eseguibile alla libreria condivisa "mylibc"
target_link_libraries(appc1 PRIVATE mylibc::shared)

# Post-build: copia la DLL nella directory dell'eseguibile (solo su Windows)
if(WIN32)
  add_custom_command(TARGET appc1 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "$<TARGET_FILE:mylibc::shared>"
      "$<TARGET_FILE_DIR:appc1>"
    COMMENT "Copia la DLL di mylibc nella directory di appc1"
  )
endif()
