#--------------------------------------
# Trova pkg-config per individuare GTK4
#--------------------------------------
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED gtk4)


# if (CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
#   set(CMAKE_C_FLAGS_DEBUG "-Wall -Wextra -Wpedantic -g")
#   set(CMAKE_C_FLAGS_RELEASE "-O3 -DNDEBUG")
# elseif (MSVC)
#   set(CMAKE_C_FLAGS_DEBUG "/W4 /Zi")
#   set(CMAKE_C_FLAGS_RELEASE "/O2 /DNDEBUG")
# endif()


#-----------------
# Includi cartelle
#-----------------
add_subdirectory(Gtk4Lib)
add_subdirectory(Gtk4App)
add_subdirectory(App2Gtk4)
