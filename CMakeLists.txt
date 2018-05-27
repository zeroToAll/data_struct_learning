cmake_minimum_required(VERSION 3.9)
project(day12)

set(CMAKE_CXX_STANDARD 11)

add_executable(day12 main.cpp)
add_executable(day13 xianxingbiao/seqlist.h xianxingbiao/seqlist.c xianxingbiao/test1.c)
add_executable(mylist1 mylist/linklist.h mylist/linklist.c mylist/listTest.c )
add_executable(dlinklist1 dlinklist/dlinklist.h dlinklist/dlinklist.c)
add_executable(mystack mystack/seqstack.h mystack/seqstack.c mystack/stack_test.c mystack/seqlist.h mystack/seqlist.c)
add_executable(linkstack linkstack/linklist.h linkstack/linklist.c linkstack/linkstack.h linkstack/linkstack.c linkstack/link_stack_test.c)
add_executable(stackdemo stack_demo/infix_To_suffix.c stack_demo/linklist.h stack_demo/linklist.c stack_demo/linkstack.h stack_demo/linkstack.c)