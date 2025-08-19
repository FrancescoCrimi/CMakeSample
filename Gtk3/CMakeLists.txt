#--------------------------------------
# Trova pkg-config per individuare GTK3
#--------------------------------------
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)


#-----------------
# Includi cartelle
#-----------------
add_subdirectory(Lib)
add_subdirectory(App1)
add_subdirectory(App2)
