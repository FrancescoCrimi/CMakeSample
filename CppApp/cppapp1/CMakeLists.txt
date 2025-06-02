
# File sorgente per l'eseguibile
set(CPPAPP1_SOURCES
    main.cpp
)

# Crea l'eseguibile che utilizza la libreria
add_executable(cppapp1 ${CPPAPP1_SOURCES})

# Collega l'applicazione alla libreria condivisa "cpplib"
target_link_libraries(cppapp1 PRIVATE cpplib)

# Copia la DLL (o .so) nella cartella dell'eseguibile dopo la build (solo su Windows o se necessario)
if(WIN32)
  add_custom_command(TARGET cppapp1 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "$<TARGET_FILE:cpplib>"
      "$<TARGET_FILE_DIR:cppapp1>"
    COMMENT "Copia la DLL di cpplib nella directory di cppapp1"
  )
endif()
