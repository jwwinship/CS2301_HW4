cmake_minimum_required(VERSION 3.17)
project(CS2301_HW4 C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(CS2301_HW4
        src/CS2301_HW4.c
        src/LinkedList.c
        src/LinkedList.h
        src/production.c
        src/production.h
        src/tests.c
        src/tests.h
        src/TMSName.h src/AdjMat.c src/AdjMat.h src/Room.c src/Room.h)
