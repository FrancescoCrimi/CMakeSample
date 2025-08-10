# Crea l'eseguibile "appc2" a partire da main.c
add_executable(appc2 main.c)

# Collega l'eseguibile alla libreria statica "mylibc"
target_link_libraries(appc2 PRIVATE mylibc::static)
