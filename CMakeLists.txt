cmake_minimum_required(VERSION 3.15)
project(boostrepro)
find_package(Boost REQUIRED COMPONENTS filesystem)


add_executable(callable main_interprocess.cpp)
set_target_properties(callable PROPERTIES 
    CXX_EXTENSIONS OFF 
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
target_link_libraries(callable PUBLIC Boost::filesystem)

add_executable(simpletest main_testcase.cpp)
set_target_properties(simpletest PROPERTIES 
    CXX_EXTENSIONS OFF 
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
target_link_libraries(simpletest PUBLIC Boost::filesystem)
add_dependencies(simpletest callable)


include(CTest)

add_test(NAME single COMMAND  $<TARGET_FILE:simpletest> WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

file(COPY test-data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
