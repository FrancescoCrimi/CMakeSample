#---------
# Sorgenti
#---------
set(GTKMM4APP_SOURCE
    main.cpp
    MainWindow.cpp
    ManualWindow.cpp
    BuilderWindow.cpp
)


#----------------
# Crea eseguibile
#----------------
add_executable(Gtkmm4App ${GTKMM4APP_SOURCE})


# # Includi le directory di include e link Globale in base a quanto trovato da pkg-config
# include_directories(${GTKMM4_INCLUDE_DIRS})
# link_directories(${GTKMM4_LIBRARY_DIRS})
# add_definitions(${GTKMM4_CFLAGS_OTHER})
# target_link_libraries(Gtkmm4App ${GTKMM4_LIBRARIES})

# Includi le directory di include e link in base a quanto trovato da pkg-config
target_compile_options(Gtkmm4App PRIVATE ${GTKMM4_CFLAGS_OTHER})
target_include_directories(Gtkmm4App PRIVATE ${GTKMM4_INCLUDE_DIRS})
target_link_directories(Gtkmm4App PRIVATE ${GTKMM4_LIBRARY_DIRS})
target_link_libraries(Gtkmm4App PRIVATE ${GTKMM4_LIBRARIES})


# Aggiungi flag disabilita deprecated
target_compile_options(Gtkmm4App PRIVATE -Wdeprecated-declarations)
# target_compile_definitions(Gtkmm4App PRIVATE GTKMM_DISABLE_DEPRECATED)


#------------------------------------------------
# Su Windows per evitare l'apertura della console
#------------------------------------------------
if(WIN32)
    if(MSVC)
        # Per MSVC, impostando questa proprietà il linker usa /SUBSYSTEM:WINDOWS
        set_target_properties(Gtkmm4App PROPERTIES WIN32_EXECUTABLE TRUE)
    else()
        # Per GCC/MinGW, il flag "-mwindows" impedisce l'apertura della console
        set_target_properties(Gtkmm4App PROPERTIES LINK_FLAGS "-mwindows")
    endif()
endif()


#-----------------------------------------------------------
# Copia il file interface.ui nella directory dell'eseguibile
#-----------------------------------------------------------
add_custom_command(TARGET Gtkmm4App POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_CURRENT_SOURCE_DIR}/interface.ui
    $<TARGET_FILE_DIR:Gtkmm4App>
)
