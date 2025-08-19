#---------
# Sorgenti
#---------
set(APP2GTK4_SOURCE
    main.c
)


#----------------
# Crea eseguibile
#----------------
add_executable(App2Gtk4 ${APP2GTK4_SOURCE})


#-----------------------------------------
# Aggiungi la libreria Gtk4 via pkg-config
#-----------------------------------------
target_compile_options(App2Gtk4 PRIVATE ${GTK4_CFLAGS_OTHER})
target_include_directories(App2Gtk4 PRIVATE ${GTK4_INCLUDE_DIRS})
target_link_directories(App2Gtk4 PRIVATE ${GTK4_LIBRARY_DIRS})
target_link_libraries(App2Gtk4 PRIVATE ${GTK4_LIBRARIES})


#------------------------------------------------
# Su Windows per evitare l'apertura della console
#------------------------------------------------
if(WIN32)
    if(MSVC)
        # Per MSVC, impostando questa proprietà il linker usa /SUBSYSTEM:WINDOWS
        set_target_properties(App2Gtk4 PROPERTIES WIN32_EXECUTABLE TRUE)
    else()
        # Per GCC/MinGW, il flag "-mwindows" impedisce l'apertura della console
        set_target_properties(App2Gtk4 PROPERTIES LINK_FLAGS "-mwindows")
    endif()
endif()

