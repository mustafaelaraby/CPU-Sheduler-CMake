cmake_minimum_required(VERSION 3.20)

set(CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

# Set the output directory for executables to a 'bin' directory
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Collect all .cpp files in the src directory
file(GLOB_RECURSE SRC_FILES "src/*.cpp")
file(GLOB_RECURSE LIB_FILES "libs/*.cpp")



# Print source and library files for verification
message("=============================================================")

message(STATUS "SRC Files:")
foreach(SRC_FILE ${SRC_FILES})
    message(STATUS ${SRC_FILE})
endforeach()

message(STATUS "LIB Files:")
foreach(LIB_FILE ${LIB_FILES})
    message(STATUS ${LIB_FILE})
endforeach()

message("=============================================================")




project(Process_Sheduler
    VERSION 1.1.1
    DESCRIPTION "HELLOAPP is deprecated and will be removed in a future release"
    LANGUAGES CXX
)



add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/libs/Data_Structures)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/libs/helpers)

# add_library(helpers_library STATIC ${LIB_FILES})

add_executable(Scheduler  main.cpp ${SRC_FILES} )
target_include_directories(Scheduler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/libs/helpers
                                            ${CMAKE_CURRENT_SOURCE_DIR}/libs/Data_Structures)

# Create an executable target for your application
target_link_libraries(Scheduler PUBLIC DS_LIB HELPERS)

# Add a custom clean target
add_custom_target(clean_all
    COMMAND ${CMAKE_BUILD_TOOL} clean
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target clean
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/bin
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Clean all build artifacts"
)

# Make clean_all the default target
add_dependencies(clean_all Scheduler)

# Make clean_all target visible in CMake GUIs (e.g., cmake-gui, ccmake)
set_target_properties(clean_all PROPERTIES FOLDER "CMakeTargets")

# Set it as the default build target
set_directory_properties(PROPERTIES
    ADDITIONAL_MAKE_CLEAN_FILES "${CMAKE_BINARY_DIR}/bin"
)