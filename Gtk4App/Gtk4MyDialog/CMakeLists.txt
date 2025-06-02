set(MYDIALOG_SOURCE
    dialog.c
)

add_library(Gtk4MyDialog SHARED ${MYDIALOG_SOURCE})

target_compile_options(Gtk4MyDialog PRIVATE ${GTK4_CFLAGS_OTHER})
target_include_directories(Gtk4MyDialog PRIVATE ${GTK4_INCLUDE_DIRS})
target_link_directories(Gtk4MyDialog PRIVATE ${GTK4_LIBRARY_DIRS})
target_link_libraries(Gtk4MyDialog PRIVATE ${GTK4_LIBRARIES})

target_compile_definitions(Gtk4MyDialog PRIVATE MYLIBRARY_EXPORTS)

target_include_directories(Gtk4MyDialog PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
