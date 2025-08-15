#----------------
# Crea eseguibile
#----------------
add_executable(appc1 main.c)


#-----------------------------------
# Collega l'eseguibile alla libreria
#-----------------------------------
target_link_libraries(appc1 PRIVATE mylibc::shared)


#------------------------------------------------------------
# Copia la libreria condivisa nella directory dell'eseguibile
#------------------------------------------------------------
if(WIN32)
	add_custom_command(TARGET appc1 POST_BUILD
    	COMMAND ${CMAKE_COMMAND} -E copy_if_different
    	"$<TARGET_FILE:mylibc::shared>"
    	"$<TARGET_FILE_DIR:appc1>"
    	COMMENT "Copia la DLL di mylibc nella directory di appc1"
	)
endif()
