cmake_minimum_required(VERSION 3.1)

project(ConstexprLowerUpperString)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

install(DIRECTORY include/ DESTINATION include/${PROJECT_NAME})