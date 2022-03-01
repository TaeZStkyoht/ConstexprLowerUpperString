cmake_minimum_required(VERSION 3.1)

project(ConstexprLowerUpperString)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

option(BUILD_EXAMPLES "build examples" ON)

if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

install(DIRECTORY include/ DESTINATION include/${PROJECT_NAME})
