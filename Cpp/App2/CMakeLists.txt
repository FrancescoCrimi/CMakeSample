#----------------
# Crea eseguibile
#----------------
add_executable(CppApp2 main.cpp)


#-----------------------------------
# Collega l'eseguibile alla libreria
#-----------------------------------
target_link_libraries(CppApp2 PRIVATE MyLibCpp::shared)


#------------------------------------------------------------
# Copia la libreria condivisa nella directory dell'eseguibile
#------------------------------------------------------------
if(WIN32)
 	add_custom_command(TARGET CppApp2 POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_if_different
		"$<TARGET_FILE:MyLibCpp::shared>"
		"$<TARGET_FILE_DIR:CppApp2>"
		COMMENT "Copia la DLL di MyLibCpp nella directory di CppApp2"
	)
endif()
