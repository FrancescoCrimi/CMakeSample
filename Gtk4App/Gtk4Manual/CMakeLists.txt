set(MANUAL_SOURCE
    window.c
    main.c
)

add_executable(Gtk4Manual ${MANUAL_SOURCE})

target_compile_options(Gtk4Manual PRIVATE ${GTK4_CFLAGS_OTHER})
target_include_directories(Gtk4Manual PRIVATE ${GTK4_INCLUDE_DIRS})
target_link_directories(Gtk4Manual PRIVATE ${GTK4_LIBRARY_DIRS})
target_link_libraries(Gtk4Manual PRIVATE ${GTK4_LIBRARIES})

target_link_libraries(Gtk4Manual PRIVATE Gtk4MyDialog)

if(WIN32)
    if(MSVC)
        set_target_properties(Gtk4Manual PROPERTIES WIN32_EXECUTABLE TRUE)
    else()
        set_target_properties(Gtk4Manual PROPERTIES LINK_FLAGS "-mwindows")
    endif()
endif()

# Comando post-build per copiare la DLL nella directory dell'eseguibile (solo su Windows)
if(WIN32)
  add_custom_command(TARGET Gtk4Manual POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "$<TARGET_FILE:Gtk4MyDialog>"
      "$<TARGET_FILE_DIR:Gtk4Manual>"
    COMMENT "Copia la DLL di Gtk4MyDialog nella directory di Gtk4Manual"
  )
endif()
