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
    src/algorithms/GRASP.cpp
    src/algorithms/GRASP.hpp
        src/algorithms/SimulatedAnnealingAlgorithm.cpp
        src/algorithms/SimulatedAnnealingAlgorithm.h
)

add_library(misc 
    src/misc/Parseable.hpp
    src/misc/ORLibParser.hpp
    src/misc/ORLibParser.cpp
    src/misc/MParser.hpp
    src/misc/MParser.cpp
)

# Add executable targets for your tests
add_executable(GRASP_algorithm_test_capa src/tests/GRASP_algorithm/GRASP_algorithm_test_capa.cpp)
add_executable(GRASP_algorithm_test_capb src/tests/GRASP_algorithm/GRASP_algorithm_test_capb.cpp)
add_executable(GRASP_algorithm_test_capc src/tests/GRASP_algorithm/GRASP_algorithm_test_capc.cpp)
add_executable(GRASP_algorithm_test_mr1 src/tests/GRASP_algorithm/GRASP_algorithm_test_mr1.cpp)
add_executable(GRASP_algorithm_test_mr2 src/tests/GRASP_algorithm/GRASP_algorithm_test_mr2.cpp)
add_executable(GRASP_algorithm_test_mr3 src/tests/GRASP_algorithm/GRASP_algorithm_test_mr3.cpp)
add_executable(GRASP_algorithm_test_mr4 src/tests/GRASP_algorithm/GRASP_algorithm_test_mr4.cpp)
add_executable(GRASP_algorithm_test_mr5 src/tests/GRASP_algorithm/GRASP_algorithm_test_mr5.cpp)

add_executable(greedy_algorithm_test_1 src/tests/greedy_algorithm/greedy_algorithm_test_1.cpp)
add_executable(greedy_algorithm_test_2 src/tests/greedy_algorithm/greedy_algorithm_test_2.cpp)
add_executable(greedy_algorithm_test_3 src/tests/greedy_algorithm/greedy_algorithm_test_3.cpp)
add_executable(simulated_annealing_test_capa src/tests/simulated_annealing_algorithm/simulated_annealing_test_capa.cpp)
add_executable(simulated_annealing_test_capb src/tests/simulated_annealing_algorithm/simulated_annealing_test_capb.cpp)
add_executable(simulated_annealing_test_capc src/tests/simulated_annealing_algorithm/simulated_annealing_test_capc.cpp)
add_executable(simulated_annealing_test_mr1 src/tests/simulated_annealing_algorithm/simulated_annealing_test_mr1.cpp)
add_executable(simulated_annealing_test_mr2 src/tests/simulated_annealing_algorithm/simulated_annealing_test_mr2.cpp)
add_executable(simulated_annealing_test_mr3 src/tests/simulated_annealing_algorithm/simulated_annealing_test_mr3.cpp)
add_executable(simulated_annealing_test_mr4 src/tests/simulated_annealing_algorithm/simulated_annealing_test_mr4.cpp)
add_executable(simulated_annealing_test_mr5 src/tests/simulated_annealing_algorithm/simulated_annealing_test_mr5.cpp)
# Add more test executables as needed

# Link your algorithms library to the test executables
# target_link_libraries(test_algorithm1 PRIVATE algorithms)
target_link_libraries(GRASP_algorithm_test_capa PRIVATE algorithms)
target_link_libraries(GRASP_algorithm_test_capa PRIVATE misc)
target_link_libraries(GRASP_algorithm_test_capb PRIVATE algorithms)
target_link_libraries(GRASP_algorithm_test_capb PRIVATE misc)
target_link_libraries(GRASP_algorithm_test_capc PRIVATE algorithms)
target_link_libraries(GRASP_algorithm_test_capc PRIVATE misc)
target_link_libraries(GRASP_algorithm_test_mr1 PRIVATE algorithms)
target_link_libraries(GRASP_algorithm_test_mr1 PRIVATE misc)
target_link_libraries(GRASP_algorithm_test_mr2 PRIVATE algorithms)
target_link_libraries(GRASP_algorithm_test_mr2 PRIVATE misc)
target_link_libraries(GRASP_algorithm_test_mr3 PRIVATE algorithms)
target_link_libraries(GRASP_algorithm_test_mr3 PRIVATE misc)
target_link_libraries(GRASP_algorithm_test_mr4 PRIVATE algorithms)
target_link_libraries(GRASP_algorithm_test_mr4 PRIVATE misc)
target_link_libraries(GRASP_algorithm_test_mr5 PRIVATE algorithms)
target_link_libraries(GRASP_algorithm_test_mr5 PRIVATE misc)

target_link_libraries(simulated_annealing_test_capa PRIVATE algorithms)
target_link_libraries(simulated_annealing_test_capa PRIVATE misc)
target_link_libraries(simulated_annealing_test_capb PRIVATE algorithms)
target_link_libraries(simulated_annealing_test_capb PRIVATE misc)
target_link_libraries(simulated_annealing_test_capc PRIVATE algorithms)
target_link_libraries(simulated_annealing_test_capc PRIVATE misc)
target_link_libraries(simulated_annealing_test_mr1 PRIVATE algorithms)
target_link_libraries(simulated_annealing_test_mr1 PRIVATE misc)
target_link_libraries(simulated_annealing_test_mr2 PRIVATE algorithms)
target_link_libraries(simulated_annealing_test_mr2 PRIVATE misc)
target_link_libraries(simulated_annealing_test_mr3 PRIVATE algorithms)
target_link_libraries(simulated_annealing_test_mr3 PRIVATE misc)
target_link_libraries(simulated_annealing_test_mr4 PRIVATE algorithms)
target_link_libraries(simulated_annealing_test_mr4 PRIVATE misc)
target_link_libraries(simulated_annealing_test_mr5 PRIVATE algorithms)
target_link_libraries(simulated_annealing_test_mr5 PRIVATE misc)

# Link more test executables as needed
enable_testing()
# Register tests with CTest
add_test(Name GRASPAlgorithmTestCapA
         COMMAND GRASP_algorithm_test_capa)
add_test(Name GRASPAlgorithmTestCapB
         COMMAND GRASP_algorithm_test_capb)
add_test(Name GRASPAlgorithmTestCapC
         COMMAND GRASP_algorithm_test_capc)
add_test(Name GRASPAlgorithmTestMr1
         COMMAND GRASP_algorithm_test_mr1)
add_test(Name GRASPAlgorithmTestMr2
         COMMAND GRASP_algorithm_test_mr2)
add_test(Name GRASPAlgorithmTestMr3
         COMMAND GRASP_algorithm_test_mr3)
add_test(Name GRASPAlgorithmTestMr4
         COMMAND GRASP_algorithm_test_mr4)
add_test(Name GRASPAlgorithmTestMr5
         COMMAND GRASP_algorithm_test_mr5)
add_test(NAME SimulatedAnnealingTestCapA
         COMMAND simulated_annealing_test_capa)
add_test(NAME SimulatedAnnealingTestCapB
        COMMAND simulated_annealing_test_capb)
add_test(NAME SimulatedAnnealingTestCapC
        COMMAND simulated_annealing_test_capc)
add_test(NAME SimulatedAnnealingTestMR1
        COMMAND simulated_annealing_test_mr1)
add_test(NAME SimulatedAnnealingTestMR2
        COMMAND simulated_annealing_test_mr2)
add_test(NAME SimulatedAnnealingTestMR3
        COMMAND simulated_annealing_test_mr3)
add_test(NAME SimulatedAnnealingTestMR4
        COMMAND simulated_annealing_test_mr4)
add_test(NAME SimulatedAnnealingTestMR5
        COMMAND simulated_annealing_test_mr5)

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
        set_property(TARGET GRASP_algorithm_test_capa PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET GRASP_algorithm_test_capb PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET GRASP_algorithm_test_capc PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET GRASP_algorithm_test_mr1 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET GRASP_algorithm_test_mr2 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET GRASP_algorithm_test_mr3 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET GRASP_algorithm_test_mr4 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET GRASP_algorithm_test_mr5 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET simulated_annealing_test_capa PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET simulated_annealing_test_capb PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET simulated_annealing_test_capc PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET simulated_annealing_test_mr1 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET simulated_annealing_test_mr2 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET simulated_annealing_test_mr3 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET simulated_annealing_test_mr4 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET simulated_annealing_test_mr5 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
    endforeach()
endif()
