cmake_minimum_required(VERSION 3.26)
project(HW_04_01)


set(CMAKE_CXX_STANDARD 20)

add_executable(HW_04_01 main.cpp
        ListNode.cpp)


add_subdirectory(../../Catch2 Catch2-build)
add_executable(HW_04_01_test
        ListNode.cpp
        hw_test.cpp)
target_link_libraries(HW_04_01_test PRIVATE Catch2::Catch2)