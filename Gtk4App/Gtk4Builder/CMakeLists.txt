set(BUILDER_SOURCE
    window.c
    main.c
)

add_executable(Gtk4Builder ${BUILDER_SOURCE})

target_compile_options(Gtk4Builder PRIVATE ${GTK4_CFLAGS_OTHER})
target_include_directories(Gtk4Builder PRIVATE ${GTK4_INCLUDE_DIRS})
target_link_directories(Gtk4Builder PRIVATE ${GTK4_LIBRARY_DIRS})
target_link_libraries(Gtk4Builder PRIVATE ${GTK4_LIBRARIES})

target_link_libraries(Gtk4Builder PRIVATE Gtk4MyDialog)

if(WIN32)
    if(MSVC)
        set_target_properties(Gtk4Builder PROPERTIES WIN32_EXECUTABLE TRUE)
    else()
        set_target_properties(Gtk4Builder PROPERTIES LINK_FLAGS "-mwindows")
    endif()
endif()

# Copia il file interface.ui accanto all'eseguibile (necessario per l'app con Builder)
add_custom_command(TARGET Gtk4Builder POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${CMAKE_CURRENT_SOURCE_DIR}/interface.ui"
            $<TARGET_FILE_DIR:Gtk4Builder>)

# Comando post-build per copiare la DLL nella directory dell'eseguibile (solo su Windows)
if(WIN32)
  add_custom_command(TARGET Gtk4Builder POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "$<TARGET_FILE:Gtk4MyDialog>"
      "$<TARGET_FILE_DIR:Gtk4Builder>"
    COMMENT "Copia la DLL di Gtk4MyDialog nella directory di Gtk4Builder"
  )
endif()
