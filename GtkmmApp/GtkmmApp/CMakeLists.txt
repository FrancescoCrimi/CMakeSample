add_executable(GtkmmApp
    main.cpp
    MainHubWindow.cpp
    ManualWindow.cpp
    BuilderWindow.cpp)


# # Includi le directory di include e link Globale in base a quanto trovato da pkg-config
# include_directories(${GTKMM4_INCLUDE_DIRS})
# link_directories(${GTKMM4_LIBRARY_DIRS})
# add_definitions(${GTKMM4_CFLAGS_OTHER})
# target_link_libraries(GtkmmApp ${GTKMM4_LIBRARIES})

# Includi le directory di include e link in base a quanto trovato da pkg-config
target_compile_options(GtkmmApp PRIVATE ${GTKMM4_CFLAGS_OTHER})
target_include_directories(GtkmmApp PRIVATE ${GTKMM4_INCLUDE_DIRS})
target_link_directories(GtkmmApp PRIVATE ${GTKMM4_LIBRARY_DIRS})
target_link_libraries(GtkmmApp PRIVATE ${GTKMM4_LIBRARIES})


# Aggiungi flag disabilita deprecated
target_compile_options(GtkmmApp PRIVATE -Wdeprecated-declarations)
# target_compile_definitions(GtkmmApp PRIVATE GTKMM_DISABLE_DEPRECATED)


# Se siamo in ambiente Windows, per evitare l'apertura della console:
if(WIN32)
    if(MSVC)
        # Per MSVC, impostando questa proprietà il linker usa /SUBSYSTEM:WINDOWS
        set_target_properties(GtkmmApp PROPERTIES WIN32_EXECUTABLE TRUE)
    else()
        # Per GCC/MinGW, il flag "-mwindows" impedisce l'apertura della console
        set_target_properties(GtkmmApp PROPERTIES LINK_FLAGS "-mwindows")
    endif()
endif()

# Copia il file interface.ui nella stessa cartella dell'eseguibile (necessario a runtime)
add_custom_command(TARGET GtkmmApp POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
          ${CMAKE_CURRENT_SOURCE_DIR}/interface.ui
          $<TARGET_FILE_DIR:GtkmmApp>
)
