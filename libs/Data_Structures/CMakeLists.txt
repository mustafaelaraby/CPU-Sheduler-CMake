cmake_minimum_required(VERSION 3.22)

set(CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE DS_FILES "./*.**")

add_library(DS_LIB ${DS_FILES})
