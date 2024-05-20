# Minimum required CMake version
cmake_minimum_required(VERSION 3.0)

# Project name
project(Algorithms)

# Add your algorithms library
# add_library(algorithms cool_algorithm.cpp super_fun_algorithm.cpp)
add_library(algorithms
    src/algorithms/Algorithm.hpp
    src/algorithms/GeneticAlgorithm.hpp
    src/algorithms/GreedyAlgorithm.cpp
    src/algorithms/GreedyAlgorithm.hpp
)

# Add executable targets for your tests
add_executable(does_it_run_test src/tests/does_it_run_test.cpp)
add_executable(greedy_algorithm_test src/tests/greedy_algorithm_test.cpp)
# Add more test executables as needed

# Link your algorithms library to the test executables
target_link_libraries(greedy_algorithm_test PRIVATE algorithms)
# Link more test executables as needed

enable_testing()
# Register tests with CTest
add_test(NAME DoesItRun 
         COMMAND does_it_run_test)
add_test(NAME GreedyAlgorithmTest
		 COMMAND greedy_algorithm_test) 
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
        set_property(TARGET does_it_run_test PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
    endforeach()
endif()
