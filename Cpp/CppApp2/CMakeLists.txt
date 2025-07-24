
# File sorgente per l'eseguibile
set(CPPAPP2_SOURCES
    main.cpp
)

# Crea l'eseguibile che utilizza la libreria
add_executable(CppApp2 ${CPPAPP2_SOURCES})

# Collega l'applicazione alla libreria condivisa "CppLib"
target_link_libraries(CppApp2 PRIVATE CppLib)

# Copia la DLL (o .so) nella cartella dell'eseguibile dopo la build (solo su Windows o se necessario)
if(WIN32)
  add_custom_command(TARGET CppApp2 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "$<TARGET_FILE:CppLib>"
      "$<TARGET_FILE_DIR:CppApp2>"
    COMMENT "Copia la DLL di CppLib nella directory di CppApp2"
  )
endif()
