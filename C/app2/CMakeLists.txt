#----------------
# Crea eseguibile
#----------------
add_executable(capp2 main.c)


#-----------------------------------
# Collega l'eseguibile alla libreria
#-----------------------------------
target_link_libraries(capp2 PRIVATE mylibc::static)
