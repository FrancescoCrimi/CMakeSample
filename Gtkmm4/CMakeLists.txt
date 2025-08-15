#----------------------------------------
# Trova pkg-config per individuare GTKMM4
#----------------------------------------
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM4 REQUIRED gtkmm-4.0)


#-----------------
# Includi cartelle
#-----------------
add_subdirectory(Gtkmm4App)
