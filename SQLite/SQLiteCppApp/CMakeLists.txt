#----------------
# Crea eseguibile
#----------------
add_executable(SQLiteCppApp main.cpp)


#---------------------------------------------
# Aggiungi la libreria SQLite3 via CMake Taget
#---------------------------------------------
find_package(SQLiteCpp CONFIG REQUIRED)
target_link_libraries(SQLiteCppApp PRIVATE SQLiteCpp)
