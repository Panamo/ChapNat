# In The Name Of God
# ========================================
# [] File Name : CMakeLists.txt
#
# [] Creation Date : 08-04-2015
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================
add_executable (Chapat-connection.out main.c chobj.c common.c command.c
    message.c net.c resolve.c sockets.c users.c)

find_package (PkgConfig)
pkg_check_modules (GLIB REQUIRED glib-2.0)
include_directories (${GLIB_INCLUDE_DIRS})
link_directories (${GLIB_LIBRARY_DIRS})
target_link_libraries(Chapat-connection.out ${GLIB_LIBRARIES})

