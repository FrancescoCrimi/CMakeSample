#----------------
# Crea eseguibile
#----------------
add_executable(capp1 main.c)


#-----------------------------------
# Collega l'eseguibile alla libreria
#-----------------------------------
target_link_libraries(capp1 PRIVATE mylibc::shared)


#------------------------------------------------------------
# Copia la libreria condivisa nella directory dell'eseguibile
#------------------------------------------------------------
if(WIN32)
	add_custom_command(TARGET capp1 POST_BUILD
    	COMMAND ${CMAKE_COMMAND} -E copy_if_different
    	"$<TARGET_FILE:mylibc::shared>"
    	"$<TARGET_FILE_DIR:capp1>"
    	COMMENT "Copia la DLL di mylibc nella directory di capp1"
	)
endif()
