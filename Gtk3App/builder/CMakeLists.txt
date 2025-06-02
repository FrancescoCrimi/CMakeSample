add_executable(Gtk3Builder window.c main.c)

target_compile_options(Gtk3Builder PRIVATE ${GTK3_CFLAGS_OTHER})
target_include_directories(Gtk3Builder PRIVATE ${GTK3_INCLUDE_DIRS})
target_link_directories(Gtk3Builder PRIVATE ${GTK3_LIBRARY_DIRS})
target_link_libraries(Gtk3Builder PRIVATE ${GTK3_LIBRARIES})

# Collega l'eseguibile alla libreria Gtk3Common
target_link_libraries(Gtk3Builder PRIVATE Gtk3Common)

if(WIN32)
    if(MSVC)
        set_target_properties(Gtk3Builder PROPERTIES WIN32_EXECUTABLE TRUE)
    else()
        set_target_properties(Gtk3Builder PROPERTIES LINK_FLAGS "-mwindows")
    endif()
endif()

# Copia il file interface.ui accanto all'eseguibile (necessario per l'app con Builder)
add_custom_command(TARGET Gtk3Builder POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${CMAKE_CURRENT_SOURCE_DIR}/interface.ui"
            $<TARGET_FILE_DIR:Gtk3Builder>)
