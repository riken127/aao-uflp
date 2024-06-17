# Minimum required CMake version
cmake_minimum_required(VERSION 3.0)

# Project name
project(Algorithms)

# Add your algorithms library
# add_library(algorithms cool_algorithm.cpp super_fun_algorithm.cpp)
add_library(algorithms
    src/algorithms/Algorithm.hpp
    src/algorithms/CrowSearchAlgorithm.cpp 
    src/algorithms/CrowSearchAlgorithm.hpp
    src/algorithms/HillClimbingAlgorithm.cpp
    src/algorithms/HillClimbingAlgorithm.hpp
)
add_library(misc 
    src/misc/Parseable.hpp
    src/misc/ORLibParser.hpp
    src/misc/ORLibParser.cpp
    src/misc/MParser.hpp
    src/misc/MParser.cpp
)

# Add executable targets for your tests
add_executable(hill_climbing_algorithm_test_capa src/tests/hill_climbing_algorithm/hill_climbing_algorithm_test_capa.cpp)
add_executable(hill_climbing_algorithm_test_capb src/tests/hill_climbing_algorithm/hill_climbing_algorithm_test_capb.cpp)
add_executable(hill_climbing_algorithm_test_capc src/tests/hill_climbing_algorithm/hill_climbing_algorithm_test_capc.cpp)
add_executable(hill_climbing_algorithm_test_mr1 src/tests/hill_climbing_algorithm/hill_climbing_algorithm_test_mr1.cpp)
add_executable(hill_climbing_algorithm_test_mr2 src/tests/hill_climbing_algorithm/hill_climbing_algorithm_test_mr2.cpp)
add_executable(hill_climbing_algorithm_test_mr3 src/tests/hill_climbing_algorithm/hill_climbing_algorithm_test_mr3.cpp)
add_executable(hill_climbing_algorithm_test_mr4 src/tests/hill_climbing_algorithm/hill_climbing_algorithm_test_mr4.cpp)
add_executable(hill_climbing_algorithm_test_mr5 src/tests/hill_climbing_algorithm/hill_climbing_algorithm_test_mr5.cpp)

# Add more test executables as needed

# Link your algorithms library to the test executables
# target_link_libraries(test_algorithm1 PRIVATE algorithms)
target_link_libraries(hill_climbing_algorithm_test_capa PRIVATE algorithms)
target_link_libraries(hill_climbing_algorithm_test_capa PRIVATE misc)
target_link_libraries(hill_climbing_algorithm_test_capb PRIVATE algorithms)
target_link_libraries(hill_climbing_algorithm_test_capb PRIVATE misc)
target_link_libraries(hill_climbing_algorithm_test_capc PRIVATE algorithms)
target_link_libraries(hill_climbing_algorithm_test_capc PRIVATE misc)
target_link_libraries(hill_climbing_algorithm_test_mr1 PRIVATE algorithms)
target_link_libraries(hill_climbing_algorithm_test_mr1 PRIVATE misc)
target_link_libraries(hill_climbing_algorithm_test_mr2 PRIVATE algorithms)
target_link_libraries(hill_climbing_algorithm_test_mr2 PRIVATE misc)
target_link_libraries(hill_climbing_algorithm_test_mr3 PRIVATE algorithms)
target_link_libraries(hill_climbing_algorithm_test_mr3 PRIVATE misc)
target_link_libraries(hill_climbing_algorithm_test_mr4 PRIVATE algorithms)
target_link_libraries(hill_climbing_algorithm_test_mr4 PRIVATE misc)
target_link_libraries(hill_climbing_algorithm_test_mr5 PRIVATE algorithms)
target_link_libraries(hill_climbing_algorithm_test_mr5 PRIVATE misc)

# Link more test executables as needed
enable_testing()
# Register tests with CTest
add_test(Name HillClimbingAlgorithmTestCapA
         COMMAND hill_climbing_algorithm_test_capa)
add_test(Name HillClimbingAlgorithmTestCapB
         COMMAND hill_climbing_algorithm_test_capb)
add_test(Name HillClimbingAlgorithmTestCapC
         COMMAND hill_climbing_algorithm_test_capc)
add_test(Name HillClimbingAlgorithmTestMr1
         COMMAND hill_climbing_algorithm_test_mr1)
add_test(Name HillClimbingAlgorithmTestMr2
         COMMAND hill_climbing_algorithm_test_mr2)
add_test(Name HillClimbingAlgorithmTestMr3
         COMMAND hill_climbing_algorithm_test_mr3)
add_test(Name HillClimbingAlgorithmTestMr4
         COMMAND hill_climbing_algorithm_test_mr4)
add_test(Name HillClimbingAlgorithmTestMr5
         COMMAND hill_climbing_algorithm_test_mr5)
#add_test(NAME TestAlgorithm2 COMMAND test_algorithm2)
# Add more tests as needed

# Set source and build directories
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")
set(BUILD_DIR "${CMAKE_SOURCE_DIR}/build")

# Check if CMakeSettings.json exists
if(EXISTS "${CMAKE_BINARY_DIR}/CMakeSettings.json")
    # Read the CMakeSettings.json file
    file(READ "${CMAKE_BINARY_DIR}/CMakeSettings.json" CMAKE_SETTINGS_JSON)

    # Parse CMakeSettings.json to extract configurations
    string(REGEX MATCHALL "\"name\" *: *\"[^\"]+\"" CONFIG_NAMES ${CMAKE_SETTINGS_JSON})

    # Iterate over configuration names
    foreach(CONFIG_NAME ${CONFIG_NAMES})
        # Extract configuration name
        string(REGEX REPLACE "\"name\" *: *\"([^\"]+)\"" "\\1" CONFIG_NAME ${CONFIG_NAME})

        # Check if the configuration name matches any desired configuration
        if(CONFIG_NAME MATCHES "^x64-.*-GCC$")
            # Set compiler and build flags for GCC configurations
            set(CMAKE_CXX_COMPILER g++)
            set(CMAKE_CXX_STANDARD 17)
            set(CMAKE_BUILD_TYPE Debug)
            set(CMAKE_EXPORT_COMPILE_COMMANDS YES)

            # Set build and install directories for GCC configurations
            set(BUILD_CONFIG_DIR "${BUILD_DIR}/${CONFIG_NAME}")
            set(INSTALL_CONFIG_DIR "${CMAKE_SOURCE_DIR}/out/install/${CONFIG_NAME}")
        elseif(CONFIG_NAME MATCHES "^x64-.*-Clang$")
            # Set compiler and build flags for Clang configurations
            set(CMAKE_CXX_COMPILER clang++)
            set(CMAKE_CXX_STANDARD 17)
            set(CMAKE_BUILD_TYPE Debug)
            set(CMAKE_EXPORT_COMPILE_COMMANDS YES)

            # Set build and install directories for Clang configurations
            set(BUILD_CONFIG_DIR "${BUILD_DIR}/${CONFIG_NAME}")
            set(INSTALL_CONFIG_DIR "${CMAKE_SOURCE_DIR}/out/install/${CONFIG_NAME}")
        elseif(CONFIG_NAME MATCHES "^x64-.*-MSVC$")
            # Set build and install directories for MSVC configurations
            set(BUILD_CONFIG_DIR "${BUILD_DIR}/${CONFIG_NAME}")
            set(INSTALL_CONFIG_DIR "${CMAKE_SOURCE_DIR}/out/install/${CONFIG_NAME}")
        endif()

        # Ensure the build and install directories exist
        file(MAKE_DIRECTORY ${BUILD_CONFIG_DIR})
        file(MAKE_DIRECTORY ${INSTALL_CONFIG_DIR})

        # Set build root and install root for each configuration
        set_property(TARGET hill_climbing_algorithm_test_capa PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET hill_climbing_algorithm_test_capb PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET hill_climbing_algorithm_test_capc PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET hill_climbing_algorithm_test_mr1 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET hill_climbing_algorithm_test_mr2 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET hill_climbing_algorithm_test_mr3 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET hill_climbing_algorithm_test_mr4 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET hill_climbing_algorithm_test_mr5 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})


    endforeach()
endif()