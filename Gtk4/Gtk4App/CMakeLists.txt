set(GTK4APP_SOURCE
    manual_window.c
    builder_window.c
    main_window.c
    main.c)

add_executable(Gtk4App ${GTK4APP_SOURCE})

target_compile_options(Gtk4App PRIVATE ${GTK4_CFLAGS_OTHER})
target_include_directories(Gtk4App PRIVATE ${GTK4_INCLUDE_DIRS})
target_link_directories(Gtk4App PRIVATE ${GTK4_LIBRARY_DIRS})
target_link_libraries(Gtk4App PRIVATE ${GTK4_LIBRARIES})

target_link_libraries(Gtk4App PRIVATE Gtk4Lib)

if(WIN32)
    if(MSVC)
        set_target_properties(Gtk4App PROPERTIES WIN32_EXECUTABLE TRUE)
    else()
        set_target_properties(Gtk4App PROPERTIES LINK_FLAGS "-mwindows")
    endif()
endif()

# Copia il file interface.ui accanto all'eseguibile (necessario per l'app con Builder)
add_custom_command(TARGET Gtk4App POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${CMAKE_CURRENT_SOURCE_DIR}/interface.ui"
            $<TARGET_FILE_DIR:Gtk4App>)

# Comando post-build per copiare la DLL nella directory dell'eseguibile (solo su Windows)
if(WIN32)
  add_custom_command(TARGET Gtk4App POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "$<TARGET_FILE:Gtk4Lib>"
      "$<TARGET_FILE_DIR:Gtk4App>"
    COMMENT "Copia la DLL di Gtk4Lib nella directory di Gtk4App"
  )
endif()
