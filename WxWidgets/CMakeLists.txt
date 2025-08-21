#----------------
# Crea eseguibile
#----------------
add_executable(WxApp main.cpp)

if(WIN32)

#-----------------------------------
# Aggiungi wxWidgets via CMake Taget
#-----------------------------------
find_package(wxWidgets CONFIG REQUIRED)
target_link_libraries(WxApp PRIVATE wx::core wx::base)

else()

#--------------------------------------------------
# Aggiungi wxWidgets via modulo CMake FindwxWidgets
#--------------------------------------------------
# 1. Trova wx-config e popola le variabili:
#    wxWidgets_FOUND
#    wxWidgets_LIBRARIES
#    wxWidgets_INCLUDE_DIRS
#    wxWidgets_DEFINITIONS
find_package(wxWidgets REQUIRED COMPONENTS core base)

# 3. Applica wxWidgets *solo* a mywxapp
target_include_directories(WxApp PRIVATE
    ${wxWidgets_INCLUDE_DIRS})

target_compile_definitions(WxApp PRIVATE
    ${wxWidgets_DEFINITIONS})

target_link_libraries(WxApp PRIVATE
    ${wxWidgets_LIBRARIES})

endif()


#------------------------------------------------
# Su Windows per evitare l'apertura della console
#------------------------------------------------
if(WIN32)
    if(MSVC)
        # Per MSVC, impostando questa proprietà il linker usa /SUBSYSTEM:WINDOWS
        set_target_properties(WxApp PROPERTIES WIN32_EXECUTABLE TRUE)
    else()
        # Per GCC/MinGW, il flag "-mwindows" impedisce l'apertura della console
        set_target_properties(WxApp PROPERTIES LINK_FLAGS "-mwindows")
    endif()
endif()
