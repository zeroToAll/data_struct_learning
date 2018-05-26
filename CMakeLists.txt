cmake_minimum_required(VERSION 3.9)
project(day12)

set(CMAKE_CXX_STANDARD 11)

add_executable(day12 main.cpp)
add_executable(day13 xianxingbiao/seqlist.h xianxingbiao/seqlist.c xianxingbiao/test1.c)
add_executable(mylist1 mylist/linklist.h mylist/linklist.c mylist/listTest.c )
add_executable(dlinklist1 dlinklist/dlinklist.h dlinklist/dlinklist.c)
add_executable(mystack mystack/seqstack.h mystack/seqstack.c)