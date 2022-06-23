cmake_minimum_required(VERSION 3.17)
project(linux_programming C)

set(CMAKE_C_STANDARD 99)

#add_executable(linux_programming main.c file/file.c)
add_executable(linux_programming memory/memory1.c)

ADD_SUBDIRECTORY(file memory)

