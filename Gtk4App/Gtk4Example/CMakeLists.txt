add_executable(Gtk4Example0 example-0.c)
target_compile_options(Gtk4Example0 PRIVATE ${GTK4_CFLAGS_OTHER})
target_include_directories(Gtk4Example0 PRIVATE ${GTK4_INCLUDE_DIRS})
target_link_directories(Gtk4Example0 PRIVATE ${GTK4_LIBRARY_DIRS})
target_link_libraries(Gtk4Example0 PRIVATE ${GTK4_LIBRARIES})

add_executable(Gtk4Example1 example-1.c)
target_compile_options(Gtk4Example1 PRIVATE ${GTK4_CFLAGS_OTHER})
target_include_directories(Gtk4Example1 PRIVATE ${GTK4_INCLUDE_DIRS})
target_link_directories(Gtk4Example1 PRIVATE ${GTK4_LIBRARY_DIRS})
target_link_libraries(Gtk4Example1 PRIVATE ${GTK4_LIBRARIES})

add_executable(Gtk4Example2 example-2.c)
target_compile_options(Gtk4Example2 PRIVATE ${GTK4_CFLAGS_OTHER})
target_include_directories(Gtk4Example2 PRIVATE ${GTK4_INCLUDE_DIRS})
target_link_directories(Gtk4Example2 PRIVATE ${GTK4_LIBRARY_DIRS})
target_link_libraries(Gtk4Example2 PRIVATE ${GTK4_LIBRARIES})

add_executable(Gtk4Example3 example-3.c)
target_compile_options(Gtk4Example3 PRIVATE ${GTK4_CFLAGS_OTHER})
target_include_directories(Gtk4Example3 PRIVATE ${GTK4_INCLUDE_DIRS})
target_link_directories(Gtk4Example3 PRIVATE ${GTK4_LIBRARY_DIRS})
target_link_libraries(Gtk4Example3 PRIVATE ${GTK4_LIBRARIES})

add_executable(Gtk4Example4 example-4.c)
target_compile_options(Gtk4Example4 PRIVATE ${GTK4_CFLAGS_OTHER})
target_include_directories(Gtk4Example4 PRIVATE ${GTK4_INCLUDE_DIRS})
target_link_directories(Gtk4Example4 PRIVATE ${GTK4_LIBRARY_DIRS})
target_link_libraries(Gtk4Example4 PRIVATE ${GTK4_LIBRARIES})
# Copia il file interface.ui accanto all'eseguibile (necessario per l'app con Builder)
add_custom_command(TARGET Gtk4Example4 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${CMAKE_CURRENT_SOURCE_DIR}/example-4.ui"
            $<TARGET_FILE_DIR:Gtk4Example4>)