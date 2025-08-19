#---------
# Sorgenti
#---------
set(GTK4APP2_SOURCE
    main.c
)


#----------------
# Crea eseguibile
#----------------
add_executable(Gtk4App2 ${GTK4APP2_SOURCE})


#-----------------------------------------
# Aggiungi la libreria Gtk4 via pkg-config
#-----------------------------------------
target_compile_options(Gtk4App2 PRIVATE ${GTK4_CFLAGS_OTHER})
target_include_directories(Gtk4App2 PRIVATE ${GTK4_INCLUDE_DIRS})
target_link_directories(Gtk4App2 PRIVATE ${GTK4_LIBRARY_DIRS})
target_link_libraries(Gtk4App2 PRIVATE ${GTK4_LIBRARIES})


#------------------------------------------------
# Su Windows per evitare l'apertura della console
#------------------------------------------------
if(WIN32)
    if(MSVC)
        # Per MSVC, impostando questa proprietà il linker usa /SUBSYSTEM:WINDOWS
        set_target_properties(Gtk4App2 PROPERTIES WIN32_EXECUTABLE TRUE)
    else()
        # Per GCC/MinGW, il flag "-mwindows" impedisce l'apertura della console
        set_target_properties(Gtk4App2 PROPERTIES LINK_FLAGS "-mwindows")
    endif()
endif()

