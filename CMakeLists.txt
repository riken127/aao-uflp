# Maintainer: riken127 <henriquenoronha05@gmail.com>

cmake_minimum_required(VERSION 3.16)

project(Algorithms LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(project_warnings INTERFACE)
if(MSVC)
    target_compile_options(project_warnings INTERFACE /W4 /permissive-)
else()
    target_compile_options(project_warnings INTERFACE -Wall -Wextra -Wpedantic)
endif()

add_library(algorithms
    src/algorithms/CrowSearchAlgorithm.cpp
    src/algorithms/GRASP.cpp
    src/algorithms/HillClimbingAlgorithm.cpp
    src/algorithms/SimulatedAnnealingAlgorithm.cpp
)
target_include_directories(algorithms PUBLIC src)
target_link_libraries(algorithms PUBLIC project_warnings)

add_library(misc
    src/misc/MParser.cpp
    src/misc/ORLibParser.cpp
)
target_include_directories(misc PUBLIC src)
target_link_libraries(misc PUBLIC project_warnings)

enable_testing()

function(add_uflp_test target source test_name)
    add_executable(${target} ${source})
    target_link_libraries(${target} PRIVATE algorithms misc project_warnings)
    add_test(NAME ${test_name} COMMAND ${target})
endfunction()

set(UFLP_INSTANCES capa capb capc mr1 mr2 mr3 mr4 mr5)

foreach(instance IN LISTS UFLP_INSTANCES)
    add_uflp_test(
        hill_climbing_algorithm_test_${instance}
        src/tests/hill_climbing_algorithm/hill_climbing_algorithm_test_${instance}.cpp
        HillClimbingAlgorithmTest_${instance}
    )

    add_uflp_test(
        GRASP_algorithm_test_${instance}
        src/tests/GRASP_algorithm/GRASP_algorithm_test_${instance}.cpp
        GRASPAlgorithmTest_${instance}
    )

    add_uflp_test(
        simulated_annealing_test_${instance}
        src/tests/simulated_annealing_algorithm/simulated_annealing_test_${instance}.cpp
        SimulatedAnnealingTest_${instance}
    )

    add_uflp_test(
        binary_crow_search_test_${instance}
        src/tests/binary_crow_search_algorithm/binary_crow_search_test_${instance}.cpp
        BinaryCrowSearchTest_${instance}
    )
endforeach()
