#---------
# Sorgenti
#---------
set(GTK4APP_SOURCE
    manual_window.c
    builder_window.c
    main_window.c
    main.c)


#----------------
# Crea eseguibile
#----------------
add_executable(Gtk4App ${GTK4APP_SOURCE})


#-----------------------------------------
# Aggiungi la libreria Gtk4 via pkg-config
#-----------------------------------------
target_compile_options(Gtk4App PRIVATE ${GTK4_CFLAGS_OTHER})
target_include_directories(Gtk4App PRIVATE ${GTK4_INCLUDE_DIRS})
target_link_directories(Gtk4App PRIVATE ${GTK4_LIBRARY_DIRS})
target_link_libraries(Gtk4App PRIVATE ${GTK4_LIBRARIES})


#------------------------------------
# Aggiungi la libreria condivisa Gtk4Lib
#------------------------------------
target_link_libraries(Gtk4App PRIVATE Gtk4Lib)


#------------------------------------------------
# Su Windows per evitare l'apertura della console
#------------------------------------------------
if(WIN32)
    if(MSVC)
        # Per MSVC, impostando questa proprietà il linker usa /SUBSYSTEM:WINDOWS
        set_target_properties(Gtk4App PROPERTIES WIN32_EXECUTABLE TRUE)
    else()
        # Per GCC/MinGW, il flag "-mwindows" impedisce l'apertura della console
        set_target_properties(Gtk4App PROPERTIES LINK_FLAGS "-mwindows")
    endif()
endif()


#-----------------------------------------------------------
# Copia il file interface.ui nella directory dell'eseguibile
#-----------------------------------------------------------
add_custom_command(TARGET Gtk4App POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
	"${CMAKE_CURRENT_SOURCE_DIR}/interface.ui"
	$<TARGET_FILE_DIR:Gtk4App>
)


#--------------------------------------------------------------------
# Copia la libreria condivisa Gtk4Lib nella directory dell'eseguibile
#--------------------------------------------------------------------
if(WIN32)
	add_custom_command(TARGET Gtk4App POST_BUILD
    	COMMAND ${CMAKE_COMMAND} -E copy_if_different
      	"$<TARGET_FILE:Gtk4Lib>"
      	"$<TARGET_FILE_DIR:Gtk4App>"
		COMMENT "Copia la DLL di Gtk4Lib nella directory di Gtk4App"
	)
endif()
