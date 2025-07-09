# Crea una libreria statica con i sorgenti comuni
add_library(Gtk3Lib STATIC
    dialog.c
)
target_compile_options(Gtk3Lib PRIVATE ${GTK3_CFLAGS_OTHER})
target_include_directories(Gtk3Lib PRIVATE ${GTK3_INCLUDE_DIRS})
target_link_directories(Gtk3Lib PRIVATE ${GTK3_LIBRARY_DIRS})
target_link_libraries(Gtk3Lib PRIVATE ${GTK3_LIBRARIES})

# Imposta la directory include per la libreria.
target_include_directories(Gtk3Lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
