#----------------
# Crea eseguibile
#----------------
add_executable(wxWidgetsApp main.cpp)


#-----------------------------------------------
# Aggiungi la libreria wxWidgets via CMake Taget
#-----------------------------------------------
find_package(wxWidgets CONFIG REQUIRED)
target_link_libraries(wxWidgetsApp PRIVATE wx::core wx::base)
