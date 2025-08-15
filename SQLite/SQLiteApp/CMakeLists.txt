#----------------
# Crea eseguibile
#----------------
add_executable(SQLiteApp main.c database_manager.c)


#---------------------------------------------
# Aggiungi la libreria SQLite3 via CMake Taget
#---------------------------------------------
# find_package(unofficial-sqlite3 CONFIG REQUIRED)
# target_link_libraries(SQLiteApp PRIVATE unofficial::sqlite3::sqlite3)


#---------------------------------------------
# Aggiungi la libreria SQLite3 via pkg-config
#---------------------------------------------
find_package(PkgConfig REQUIRED)
pkg_check_modules(SQLITE3 REQUIRED sqlite3)

target_compile_options(SQLiteApp PRIVATE ${SQLITE3_CFLAGS_OTHER})
target_include_directories(SQLiteApp PRIVATE ${SQLITE3_INCLUDE_DIRS})
target_link_directories(SQLiteApp PRIVATE ${SQLITE3_LIBRARY_DIRS})
target_link_libraries(SQLiteApp PRIVATE ${SQLITE3_LIBRARIES})


#---------------------
# Installa eseguibile
#---------------------
install(TARGETS SQLiteApp
        RUNTIME DESTINATION bin
)
