add_executable(Gtk3Manual window.c main.c)

target_compile_options(Gtk3Manual PRIVATE ${GTK3_CFLAGS_OTHER})
target_include_directories(Gtk3Manual PRIVATE ${GTK3_INCLUDE_DIRS})
target_link_directories(Gtk3Manual PRIVATE ${GTK3_LIBRARY_DIRS})
target_link_libraries(Gtk3Manual PRIVATE ${GTK3_LIBRARIES})

# Collega l'eseguibile alla libreria Gtk3Common
target_link_libraries(Gtk3Manual PRIVATE Gtk3Common)

if(WIN32)
    if(MSVC)
        set_target_properties(Gtk3Manual PROPERTIES WIN32_EXECUTABLE TRUE)
    else()
        set_target_properties(Gtk3Manual PROPERTIES LINK_FLAGS "-mwindows")
    endif()
endif()
