#----------------
# Crea eseguibile
#----------------
add_executable(AppCpp1 main.cpp)


#-----------------------------------
# Collega l'eseguibile alla libreria
#-----------------------------------
target_link_libraries(AppCpp1 PRIVATE MyLibCpp::shared)


#------------------------------------------------------------
# Copia la libreria condivisa nella directory dell'eseguibile
#------------------------------------------------------------
if(WIN32)
	add_custom_command(TARGET AppCpp1 POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_if_different
		"$<TARGET_FILE:MyLibCpp::shared>"
		"$<TARGET_FILE_DIR:AppCpp1>"
		COMMENT "Copia la DLL di MyLibCpp nella directory di AppCpp1"
	)
endif()
