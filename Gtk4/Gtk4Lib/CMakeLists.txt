#---------
# Sorgenti
#---------
set(MYDIALOG_SOURCE
    dialog.c
)


#------------------------
# Crea libreria condivisa
#------------------------
add_library(Gtk4Lib SHARED ${MYDIALOG_SOURCE})


#-----------------------------------------
# Aggiungi la libreria Gtk4 via pkg-config
#-----------------------------------------
target_compile_options(Gtk4Lib PRIVATE ${GTK4_CFLAGS_OTHER})
target_include_directories(Gtk4Lib PRIVATE ${GTK4_INCLUDE_DIRS})
target_link_directories(Gtk4Lib PRIVATE ${GTK4_LIBRARY_DIRS})
target_link_libraries(Gtk4Lib PRIVATE ${GTK4_LIBRARIES})


#-------------------------------
# Imposta macro per l'export dll
#-------------------------------
target_compile_definitions(Gtk4Lib PRIVATE MYLIBRARY_EXPORTS)


#---------------------------------------------
# Imposta la directory include per la libreria
#---------------------------------------------
target_include_directories(Gtk4Lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
