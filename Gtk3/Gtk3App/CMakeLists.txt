#---------
# Sorgenti
#---------
set(GTK3APP_SOURCE
    manual_window.c
    builder_window.c
    main_window.c
    main.c
)


#----------------
# Crea eseguibile
#----------------
add_executable(Gtk3App ${GTK3APP_SOURCE})


#-----------------------------------------
# Aggiungi la libreria Gtk3 via pkg-config
#-----------------------------------------
target_compile_options(Gtk3App PRIVATE ${GTK3_CFLAGS_OTHER})
target_include_directories(Gtk3App PRIVATE ${GTK3_INCLUDE_DIRS})
target_link_directories(Gtk3App PRIVATE ${GTK3_LIBRARY_DIRS})
target_link_libraries(Gtk3App PRIVATE ${GTK3_LIBRARIES})


#-------------------------------------------
# Collega l'eseguibile alla libreria Gtk3Lib
#-------------------------------------------
target_link_libraries(Gtk3App PRIVATE Gtk3Lib)


#------------------------------------------------
# Su Windows per evitare l'apertura della console
#------------------------------------------------
if(WIN32)
    if(MSVC)
        # Per MSVC, impostando questa proprietà il linker usa /SUBSYSTEM:WINDOWS
        set_target_properties(Gtk3App PROPERTIES WIN32_EXECUTABLE TRUE)
    else()
        # Per GCC/MinGW, il flag "-mwindows" impedisce l'apertura della console
        set_target_properties(Gtk3App PROPERTIES LINK_FLAGS "-mwindows")
    endif()
endif()


#-------------------------------------------------------------------------------------
# Copia il file interface.ui nella directory dell'eseguibile 
#-------------------------------------------------------------------------------------
add_custom_command(TARGET Gtk3App POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${CMAKE_CURRENT_SOURCE_DIR}/interface.ui"
    $<TARGET_FILE_DIR:Gtk3App>
)
