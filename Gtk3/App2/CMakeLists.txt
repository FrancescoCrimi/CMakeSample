#---------
# Sorgenti
#---------
set(GTK3APP2_SOURCE
    main.c
)


#----------------
# Crea eseguibile
#----------------
add_executable(Gtk3App2 ${GTK3APP2_SOURCE})


#-----------------------------------------
# Aggiungi la libreria Gtk3 via pkg-config
#-----------------------------------------
target_compile_options(Gtk3App2 PRIVATE ${GTK3_CFLAGS_OTHER})
target_include_directories(Gtk3App2 PRIVATE ${GTK3_INCLUDE_DIRS})
target_link_directories(Gtk3App2 PRIVATE ${GTK3_LIBRARY_DIRS})
target_link_libraries(Gtk3App2 PRIVATE ${GTK3_LIBRARIES})


#------------------------------------------------
# Su Windows per evitare l'apertura della console
#------------------------------------------------
if(WIN32)
    if(MSVC)
        # Per MSVC, impostando questa proprietà il linker usa /SUBSYSTEM:WINDOWS
        set_target_properties(Gtk3App1 PROPERTIES WIN32_EXECUTABLE TRUE)
    else()
        # Per GCC/MinGW, il flag "-mwindows" impedisce l'apertura della console
        set_target_properties(Gtk3App1 PROPERTIES LINK_FLAGS "-mwindows")
    endif()
endif()
