#----------------
# Crea eseguibile
#----------------
add_executable(SQLiteCppApp main.cpp)


#-----------------------------------------------
# Aggiungi la libreria SQLiteCpp via CMake Taget
#-----------------------------------------------
find_package(SQLiteCpp CONFIG REQUIRED)
target_link_libraries(SQLiteCppApp PRIVATE SQLiteCpp)
