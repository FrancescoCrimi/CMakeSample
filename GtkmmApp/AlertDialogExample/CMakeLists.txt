add_executable(AlertDialogExample main.cpp examplewindow.cpp)

# Includi le directory di include e link in base a quanto trovato da pkg-config
target_compile_options(AlertDialogExample PRIVATE ${GTKMM4_CFLAGS_OTHER})
target_include_directories(AlertDialogExample PRIVATE ${GTKMM4_INCLUDE_DIRS})
target_link_directories(AlertDialogExample PRIVATE ${GTKMM4_LIBRARY_DIRS})

target_link_libraries(AlertDialogExample ${GTKMM4_LIBRARIES})


# Aggiungi flag disabilita deprecated
target_compile_options(AlertDialogExample PRIVATE -Wdeprecated-declarations)
# target_compile_definitions(AlertDialogExample PRIVATE GTKMM_DISABLE_DEPRECATED)

# Se siamo in ambiente Windows, per evitare l'apertura della console:
if(WIN32)
    if(MSVC)
        # Per MSVC, impostando questa proprietà il linker usa /SUBSYSTEM:WINDOWS
        set_target_properties(AlertDialogExample PROPERTIES WIN32_EXECUTABLE TRUE)
    else()
        # Per GCC/MinGW, il flag "-mwindows" impedisce l'apertura della console
        set_target_properties(AlertDialogExample PROPERTIES LINK_FLAGS "-mwindows")
    endif()
endif()
