#----------------
# Crea eseguibile
#----------------
add_executable(appc2 main.c)


#-----------------------------------
# Collega l'eseguibile alla libreria
#-----------------------------------
target_link_libraries(appc2 PRIVATE mylibc::static)
