# Crea l'eseguibile che utilizza la libreria
add_executable(AppCpp2 main.cpp)

# Collega l'applicazione alla libreria condivisa "MyLibCpp"
target_link_libraries(AppCpp2 PRIVATE MyLibCpp::shared)

# Copia la DLL (o .so) nella cartella dell'eseguibile dopo la build (solo su Windows o se necessario)
if(WIN32)
  add_custom_command(TARGET AppCpp2 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "$<TARGET_FILE:MyLibCpp::shared>"
      "$<TARGET_FILE_DIR:AppCpp2>"
    COMMENT "Copia la DLL di MyLibCpp nella directory di AppCpp2"
  )
endif()
