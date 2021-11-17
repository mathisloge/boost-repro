cmake_minimum_required(VERSION 3.15)
project(boostrepro)
find_package(Boost REQUIRED COMPONENTS filesystem)


add_executable(testcreate main_create.cpp)
set_target_properties(testcreate PROPERTIES 
    CXX_EXTENSIONS OFF 
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

add_executable(simpletest main.cpp)

set_target_properties(simpletest PROPERTIES 
    CXX_EXTENSIONS OFF 
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)
target_link_libraries(simpletest PUBLIC Boost::filesystem)
add_dependencies(simpletest testcreate)


include(CTest)

add_test(NAME single COMMAND  $<TARGET_FILE:simpletest>)
