# In The Name Of God
# ========================================
# [] File Name : CMakeLists.txt
#
# [] Creation Date : 08-04-2015
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================
add_executable (Chapat-db.out main.c common.c net.c message.c users.c
	asprintf.c events.c)

# Add personal c flags
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -O0 -g -std=gnu11 ")
set (CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS} -DDEBUG")

find_package (PkgConfig)
pkg_check_modules (LIBPQ REQUIRED libpq)
include_directories (${LIBPQ_INCLUDE_DIRS})
link_directories (${LIBPQ_LIBRARY_DIRS})
target_link_libraries (Chapat-db.out ${LIBPQ_LIBRARIES})

include_directories ("${Chapat_SOURCE_DIR}/common")
target_link_libraries (Chapat-db.out KLib)
