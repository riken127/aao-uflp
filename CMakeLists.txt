# Minimum required CMake version
cmake_minimum_required(VERSION 3.0)

# Project name
project(Algorithms)

# Add your algorithms library
# add_library(algorithms cool_algorithm.cpp super_fun_algorithm.cpp)
add_library(algorithms
    src/algorithms/Algorithm.hpp
    src/algorithms/HillClimbingAlgorithm.cpp
    src/algorithms/HillClimbingAlgorithm.hpp
    src/algorithms/GRASP.cpp
    src/algorithms/GRASP.hpp
    src/algorithms/CrowSearchAlgorithm.cpp 
    src/algorithms/CrowSearchAlgorithm.hpp
    src/algorithms/SimulatedAnnealingAlgorithm.cpp
    src/algorithms/SimulatedAnnealingAlgorithm.hpp
)

add_library(misc 
    src/misc/Parseable.hpp
    src/misc/ORLibParser.hpp
    src/misc/ORLibParser.cpp
    src/misc/MParser.hpp
    src/misc/MParser.cpp
    src/misc/AlgorithmLogger.h
    src/misc/AlgorithmLogger.cpp
)

# Add executable targets for your tests
add_executable(hill_climbing_algorithm_test_capa src/tests/hill_climbing_algorithm/hill_climbing_algorithm_test_capa.cpp)
add_executable(hill_climbing_algorithm_test_capb src/tests/hill_climbing_algorithm/hill_climbing_algorithm_test_capb.cpp)
add_executable(hill_climbing_algorithm_test_capc src/tests/hill_climbing_algorithm/hill_climbing_algorithm_test_capc.cpp)
add_executable(hill_climbing_algorithm_test_cap71 src/tests/hill_climbing_algorithm/hill_climbing_algorithm_test_cap71.cpp)
add_executable(hill_climbing_algorithm_test_cap72 src/tests/hill_climbing_algorithm/hill_climbing_algorithm_test_cap72.cpp)
add_executable(hill_climbing_algorithm_test_cap73 src/tests/hill_climbing_algorithm/hill_climbing_algorithm_test_cap73.cpp)
add_executable(hill_climbing_algorithm_test_cap74 src/tests/hill_climbing_algorithm/hill_climbing_algorithm_test_cap74.cpp)
add_executable(hill_climbing_algorithm_test_cap101 src/tests/hill_climbing_algorithm/hill_climbing_algorithm_test_cap101.cpp)
add_executable(hill_climbing_algorithm_test_cap102 src/tests/hill_climbing_algorithm/hill_climbing_algorithm_test_cap102.cpp)
add_executable(hill_climbing_algorithm_test_cap103 src/tests/hill_climbing_algorithm/hill_climbing_algorithm_test_cap103.cpp)
add_executable(hill_climbing_algorithm_test_cap104 src/tests/hill_climbing_algorithm/hill_climbing_algorithm_test_cap104.cpp)
add_executable(hill_climbing_algorithm_test_cap131 src/tests/hill_climbing_algorithm/hill_climbing_algorithm_test_cap131.cpp)
add_executable(hill_climbing_algorithm_test_cap132 src/tests/hill_climbing_algorithm/hill_climbing_algorithm_test_cap132.cpp)
add_executable(hill_climbing_algorithm_test_cap133 src/tests/hill_climbing_algorithm/hill_climbing_algorithm_test_cap133.cpp)
add_executable(hill_climbing_algorithm_test_cap134 src/tests/hill_climbing_algorithm/hill_climbing_algorithm_test_cap134.cpp)
add_executable(hill_climbing_algorithm_test_mr1 src/tests/hill_climbing_algorithm/hill_climbing_algorithm_test_mr1.cpp)
add_executable(hill_climbing_algorithm_test_mr2 src/tests/hill_climbing_algorithm/hill_climbing_algorithm_test_mr2.cpp)
add_executable(hill_climbing_algorithm_test_mr3 src/tests/hill_climbing_algorithm/hill_climbing_algorithm_test_mr3.cpp)
add_executable(hill_climbing_algorithm_test_mr4 src/tests/hill_climbing_algorithm/hill_climbing_algorithm_test_mr4.cpp)
add_executable(hill_climbing_algorithm_test_mr5 src/tests/hill_climbing_algorithm/hill_climbing_algorithm_test_mr5.cpp)
add_executable(hill_climbing_algorithm_test_mo1 src/tests/hill_climbing_algorithm/hill_climbing_algorithm_test_mo1.cpp)
add_executable(hill_climbing_algorithm_test_mo2 src/tests/hill_climbing_algorithm/hill_climbing_algorithm_test_mo2.cpp)
add_executable(hill_climbing_algorithm_test_mo3 src/tests/hill_climbing_algorithm/hill_climbing_algorithm_test_mo3.cpp)
add_executable(hill_climbing_algorithm_test_mo4 src/tests/hill_climbing_algorithm/hill_climbing_algorithm_test_mo4.cpp)
add_executable(hill_climbing_algorithm_test_mo5 src/tests/hill_climbing_algorithm/hill_climbing_algorithm_test_mo5.cpp)
add_executable(hill_climbing_algorithm_test_mp1 src/tests/hill_climbing_algorithm/hill_climbing_algorithm_test_mp1.cpp)
add_executable(hill_climbing_algorithm_test_mp2 src/tests/hill_climbing_algorithm/hill_climbing_algorithm_test_mp2.cpp)
add_executable(hill_climbing_algorithm_test_mp3 src/tests/hill_climbing_algorithm/hill_climbing_algorithm_test_mp3.cpp)
add_executable(hill_climbing_algorithm_test_mp4 src/tests/hill_climbing_algorithm/hill_climbing_algorithm_test_mp4.cpp)
add_executable(hill_climbing_algorithm_test_mp5 src/tests/hill_climbing_algorithm/hill_climbing_algorithm_test_mp5.cpp)
add_executable(hill_climbing_algorithm_test_mq1 src/tests/hill_climbing_algorithm/hill_climbing_algorithm_test_mq1.cpp)
add_executable(hill_climbing_algorithm_test_mq2 src/tests/hill_climbing_algorithm/hill_climbing_algorithm_test_mq2.cpp)
add_executable(hill_climbing_algorithm_test_mq3 src/tests/hill_climbing_algorithm/hill_climbing_algorithm_test_mq3.cpp)
add_executable(hill_climbing_algorithm_test_mq4 src/tests/hill_climbing_algorithm/hill_climbing_algorithm_test_mq4.cpp)
add_executable(hill_climbing_algorithm_test_mq5 src/tests/hill_climbing_algorithm/hill_climbing_algorithm_test_mq5.cpp)


add_executable(GRASP_algorithm_test_capa src/tests/GRASP_algorithm/GRASP_algorithm_test_capa.cpp)
add_executable(GRASP_algorithm_test_capb src/tests/GRASP_algorithm/GRASP_algorithm_test_capb.cpp)
add_executable(GRASP_algorithm_test_capc src/tests/GRASP_algorithm/GRASP_algorithm_test_capc.cpp)
add_executable(GRASP_algorithm_test_cap71 src/tests/GRASP_algorithm/GRASP_algorithm_test_cap71.cpp)
add_executable(GRASP_algorithm_test_cap72 src/tests/GRASP_algorithm/GRASP_algorithm_test_cap72.cpp)
add_executable(GRASP_algorithm_test_cap73 src/tests/GRASP_algorithm/GRASP_algorithm_test_cap73.cpp)
add_executable(GRASP_algorithm_test_cap74 src/tests/GRASP_algorithm/GRASP_algorithm_test_cap74.cpp)
add_executable(GRASP_algorithm_test_cap101 src/tests/GRASP_algorithm/GRASP_algorithm_test_cap101.cpp)
add_executable(GRASP_algorithm_test_cap102 src/tests/GRASP_algorithm/GRASP_algorithm_test_cap102.cpp)
add_executable(GRASP_algorithm_test_cap103 src/tests/GRASP_algorithm/GRASP_algorithm_test_cap103.cpp)
add_executable(GRASP_algorithm_test_cap104 src/tests/GRASP_algorithm/GRASP_algorithm_test_cap104.cpp)
add_executable(GRASP_algorithm_test_cap131 src/tests/GRASP_algorithm/GRASP_algorithm_test_cap131.cpp)
add_executable(GRASP_algorithm_test_cap132 src/tests/GRASP_algorithm/GRASP_algorithm_test_cap132.cpp)
add_executable(GRASP_algorithm_test_cap133 src/tests/GRASP_algorithm/GRASP_algorithm_test_cap133.cpp)
add_executable(GRASP_algorithm_test_cap134 src/tests/GRASP_algorithm/GRASP_algorithm_test_cap134.cpp)
add_executable(GRASP_algorithm_test_mr1 src/tests/GRASP_algorithm/GRASP_algorithm_test_mr1.cpp)
add_executable(GRASP_algorithm_test_mr2 src/tests/GRASP_algorithm/GRASP_algorithm_test_mr2.cpp)
add_executable(GRASP_algorithm_test_mr3 src/tests/GRASP_algorithm/GRASP_algorithm_test_mr3.cpp)
add_executable(GRASP_algorithm_test_mr4 src/tests/GRASP_algorithm/GRASP_algorithm_test_mr4.cpp)
add_executable(GRASP_algorithm_test_mr5 src/tests/GRASP_algorithm/GRASP_algorithm_test_mr5.cpp)
add_executable(GRASP_algorithm_test_mo1 src/tests/GRASP_algorithm/GRASP_algorithm_test_mo1.cpp)
add_executable(GRASP_algorithm_test_mo2 src/tests/GRASP_algorithm/GRASP_algorithm_test_mo2.cpp)
add_executable(GRASP_algorithm_test_mo3 src/tests/GRASP_algorithm/GRASP_algorithm_test_mo3.cpp)
add_executable(GRASP_algorithm_test_mo4 src/tests/GRASP_algorithm/GRASP_algorithm_test_mo4.cpp)
add_executable(GRASP_algorithm_test_mo5 src/tests/GRASP_algorithm/GRASP_algorithm_test_mo5.cpp)
add_executable(GRASP_algorithm_test_mp1 src/tests/GRASP_algorithm/GRASP_algorithm_test_mp1.cpp)
add_executable(GRASP_algorithm_test_mp2 src/tests/GRASP_algorithm/GRASP_algorithm_test_mp2.cpp)
add_executable(GRASP_algorithm_test_mp3 src/tests/GRASP_algorithm/GRASP_algorithm_test_mp3.cpp)
add_executable(GRASP_algorithm_test_mp4 src/tests/GRASP_algorithm/GRASP_algorithm_test_mp4.cpp)
add_executable(GRASP_algorithm_test_mp5 src/tests/GRASP_algorithm/GRASP_algorithm_test_mp5.cpp)
add_executable(GRASP_algorithm_test_mq1 src/tests/GRASP_algorithm/GRASP_algorithm_test_mq1.cpp)
add_executable(GRASP_algorithm_test_mq2 src/tests/GRASP_algorithm/GRASP_algorithm_test_mq2.cpp)
add_executable(GRASP_algorithm_test_mq3 src/tests/GRASP_algorithm/GRASP_algorithm_test_mq3.cpp)
add_executable(GRASP_algorithm_test_mq4 src/tests/GRASP_algorithm/GRASP_algorithm_test_mq4.cpp)
add_executable(GRASP_algorithm_test_mq5 src/tests/GRASP_algorithm/GRASP_algorithm_test_mq5.cpp)

add_executable(simulated_annealing_test_capa src/tests/simulated_annealing_algorithm/simulated_annealing_test_capa.cpp)
add_executable(simulated_annealing_test_capb src/tests/simulated_annealing_algorithm/simulated_annealing_test_capb.cpp)
add_executable(simulated_annealing_test_capc src/tests/simulated_annealing_algorithm/simulated_annealing_test_capc.cpp)
add_executable(simulated_annealing_test_cap71 src/tests/simulated_annealing_algorithm/simulated_annealing_test_cap71.cpp)
add_executable(simulated_annealing_test_cap72 src/tests/simulated_annealing_algorithm/simulated_annealing_test_cap72.cpp)
add_executable(simulated_annealing_test_cap73 src/tests/simulated_annealing_algorithm/simulated_annealing_test_cap73.cpp)
add_executable(simulated_annealing_test_cap74 src/tests/simulated_annealing_algorithm/simulated_annealing_test_cap74.cpp)
add_executable(simulated_annealing_test_cap101 src/tests/simulated_annealing_algorithm/simulated_annealing_test_cap101.cpp)
add_executable(simulated_annealing_test_cap102 src/tests/simulated_annealing_algorithm/simulated_annealing_test_cap102.cpp)
add_executable(simulated_annealing_test_cap103 src/tests/simulated_annealing_algorithm/simulated_annealing_test_cap103.cpp)
add_executable(simulated_annealing_test_cap104 src/tests/simulated_annealing_algorithm/simulated_annealing_test_cap104.cpp)
add_executable(simulated_annealing_test_cap131 src/tests/simulated_annealing_algorithm/simulated_annealing_test_cap131.cpp)
add_executable(simulated_annealing_test_cap132 src/tests/simulated_annealing_algorithm/simulated_annealing_test_cap132.cpp)
add_executable(simulated_annealing_test_cap133 src/tests/simulated_annealing_algorithm/simulated_annealing_test_cap133.cpp)
add_executable(simulated_annealing_test_cap134 src/tests/simulated_annealing_algorithm/simulated_annealing_test_cap134.cpp)
add_executable(simulated_annealing_test_mr1 src/tests/simulated_annealing_algorithm/simulated_annealing_test_mr1.cpp)
add_executable(simulated_annealing_test_mr2 src/tests/simulated_annealing_algorithm/simulated_annealing_test_mr2.cpp)
add_executable(simulated_annealing_test_mr3 src/tests/simulated_annealing_algorithm/simulated_annealing_test_mr3.cpp)
add_executable(simulated_annealing_test_mr4 src/tests/simulated_annealing_algorithm/simulated_annealing_test_mr4.cpp)
add_executable(simulated_annealing_test_mr5 src/tests/simulated_annealing_algorithm/simulated_annealing_test_mr5.cpp)
add_executable(simulated_annealing_test_mo1 src/tests/simulated_annealing_algorithm/simulated_annealing_test_mo1.cpp)
add_executable(simulated_annealing_test_mo2 src/tests/simulated_annealing_algorithm/simulated_annealing_test_mo2.cpp)
add_executable(simulated_annealing_test_mo3 src/tests/simulated_annealing_algorithm/simulated_annealing_test_mo3.cpp)
add_executable(simulated_annealing_test_mo4 src/tests/simulated_annealing_algorithm/simulated_annealing_test_mo4.cpp)
add_executable(simulated_annealing_test_mo5 src/tests/simulated_annealing_algorithm/simulated_annealing_test_mo5.cpp)
add_executable(simulated_annealing_test_mp1 src/tests/simulated_annealing_algorithm/simulated_annealing_test_mp1.cpp)
add_executable(simulated_annealing_test_mp2 src/tests/simulated_annealing_algorithm/simulated_annealing_test_mp2.cpp)
add_executable(simulated_annealing_test_mp3 src/tests/simulated_annealing_algorithm/simulated_annealing_test_mp3.cpp)
add_executable(simulated_annealing_test_mp4 src/tests/simulated_annealing_algorithm/simulated_annealing_test_mp4.cpp)
add_executable(simulated_annealing_test_mp5 src/tests/simulated_annealing_algorithm/simulated_annealing_test_mp5.cpp)
add_executable(simulated_annealing_test_mq1 src/tests/simulated_annealing_algorithm/simulated_annealing_test_mq1.cpp)
add_executable(simulated_annealing_test_mq2 src/tests/simulated_annealing_algorithm/simulated_annealing_test_mq2.cpp)
add_executable(simulated_annealing_test_mq3 src/tests/simulated_annealing_algorithm/simulated_annealing_test_mq3.cpp)
add_executable(simulated_annealing_test_mq4 src/tests/simulated_annealing_algorithm/simulated_annealing_test_mq4.cpp)
add_executable(simulated_annealing_test_mq5 src/tests/simulated_annealing_algorithm/simulated_annealing_test_mq5.cpp)

add_executable(binary_crow_search_test_capa src/tests/binary_crow_search_algorithm/binary_crow_search_test_capa.cpp)
add_executable(binary_crow_search_test_capb src/tests/binary_crow_search_algorithm/binary_crow_search_test_capb.cpp)
add_executable(binary_crow_search_test_capc src/tests/binary_crow_search_algorithm/binary_crow_search_test_capc.cpp)
add_executable(binary_crow_search_test_cap71 src/tests/binary_crow_search_algorithm/binary_crow_search_test_cap71.cpp)
add_executable(binary_crow_search_test_cap72 src/tests/binary_crow_search_algorithm/binary_crow_search_test_cap72.cpp)
add_executable(binary_crow_search_test_cap73 src/tests/binary_crow_search_algorithm/binary_crow_search_test_cap73.cpp)
add_executable(binary_crow_search_test_cap74 src/tests/binary_crow_search_algorithm/binary_crow_search_test_cap74.cpp)
add_executable(binary_crow_search_test_cap101 src/tests/binary_crow_search_algorithm/binary_crow_search_test_cap101.cpp)
add_executable(binary_crow_search_test_cap102 src/tests/binary_crow_search_algorithm/binary_crow_search_test_cap102.cpp)
add_executable(binary_crow_search_test_cap103 src/tests/binary_crow_search_algorithm/binary_crow_search_test_cap103.cpp)
add_executable(binary_crow_search_test_cap104 src/tests/binary_crow_search_algorithm/binary_crow_search_test_cap104.cpp)
add_executable(binary_crow_search_test_cap131 src/tests/binary_crow_search_algorithm/binary_crow_search_test_cap131.cpp)
add_executable(binary_crow_search_test_cap132 src/tests/binary_crow_search_algorithm/binary_crow_search_test_cap132.cpp)
add_executable(binary_crow_search_test_cap133 src/tests/binary_crow_search_algorithm/binary_crow_search_test_cap133.cpp)
add_executable(binary_crow_search_test_cap134 src/tests/binary_crow_search_algorithm/binary_crow_search_test_cap134.cpp)
add_executable(binary_crow_search_test_mr1 src/tests/binary_crow_search_algorithm/binary_crow_search_test_mr1.cpp)
add_executable(binary_crow_search_test_mr2 src/tests/binary_crow_search_algorithm/binary_crow_search_test_mr2.cpp)
add_executable(binary_crow_search_test_mr3 src/tests/binary_crow_search_algorithm/binary_crow_search_test_mr3.cpp)
add_executable(binary_crow_search_test_mr4 src/tests/binary_crow_search_algorithm/binary_crow_search_test_mr4.cpp)
add_executable(binary_crow_search_test_mr5 src/tests/binary_crow_search_algorithm/binary_crow_search_test_mr5.cpp)
add_executable(binary_crow_search_test_mo1 src/tests/binary_crow_search_algorithm/binary_crow_search_test_mo1.cpp)
add_executable(binary_crow_search_test_mo2 src/tests/binary_crow_search_algorithm/binary_crow_search_test_mo2.cpp)
add_executable(binary_crow_search_test_mo3 src/tests/binary_crow_search_algorithm/binary_crow_search_test_mo3.cpp)
add_executable(binary_crow_search_test_mo4 src/tests/binary_crow_search_algorithm/binary_crow_search_test_mo4.cpp)
add_executable(binary_crow_search_test_mo5 src/tests/binary_crow_search_algorithm/binary_crow_search_test_mo5.cpp)
add_executable(binary_crow_search_test_mp1 src/tests/binary_crow_search_algorithm/binary_crow_search_test_mp1.cpp)
add_executable(binary_crow_search_test_mp2 src/tests/binary_crow_search_algorithm/binary_crow_search_test_mp2.cpp)
add_executable(binary_crow_search_test_mp3 src/tests/binary_crow_search_algorithm/binary_crow_search_test_mp3.cpp)
add_executable(binary_crow_search_test_mp4 src/tests/binary_crow_search_algorithm/binary_crow_search_test_mp4.cpp)
add_executable(binary_crow_search_test_mp5 src/tests/binary_crow_search_algorithm/binary_crow_search_test_mp5.cpp)
add_executable(binary_crow_search_test_mq1 src/tests/binary_crow_search_algorithm/binary_crow_search_test_mq1.cpp)
add_executable(binary_crow_search_test_mq2 src/tests/binary_crow_search_algorithm/binary_crow_search_test_mq2.cpp)
add_executable(binary_crow_search_test_mq3 src/tests/binary_crow_search_algorithm/binary_crow_search_test_mq3.cpp)
add_executable(binary_crow_search_test_mq4 src/tests/binary_crow_search_algorithm/binary_crow_search_test_mq4.cpp)
add_executable(binary_crow_search_test_mq5 src/tests/binary_crow_search_algorithm/binary_crow_search_test_mq5.cpp)
# Link your algorithms library to the test executables
# target_link_libraries(test_algorithm1 PRIVATE algorithms)
target_link_libraries(GRASP_algorithm_test_capa PRIVATE algorithms)
target_link_libraries(GRASP_algorithm_test_capa PRIVATE misc)
target_link_libraries(GRASP_algorithm_test_capb PRIVATE algorithms)
target_link_libraries(GRASP_algorithm_test_capb PRIVATE misc)
target_link_libraries(GRASP_algorithm_test_capc PRIVATE algorithms)
target_link_libraries(GRASP_algorithm_test_capc PRIVATE misc)
target_link_libraries(GRASP_algorithm_test_cap71 PRIVATE algorithms misc)
target_link_libraries(GRASP_algorithm_test_cap72 PRIVATE algorithms misc)
target_link_libraries(GRASP_algorithm_test_cap73 PRIVATE algorithms misc)
target_link_libraries(GRASP_algorithm_test_cap74 PRIVATE algorithms misc)
target_link_libraries(GRASP_algorithm_test_cap101 PRIVATE algorithms misc)
target_link_libraries(GRASP_algorithm_test_cap102 PRIVATE algorithms misc)
target_link_libraries(GRASP_algorithm_test_cap103 PRIVATE algorithms misc)
target_link_libraries(GRASP_algorithm_test_cap104 PRIVATE algorithms misc)
target_link_libraries(GRASP_algorithm_test_cap131 PRIVATE algorithms misc)
target_link_libraries(GRASP_algorithm_test_cap132 PRIVATE algorithms misc)
target_link_libraries(GRASP_algorithm_test_cap133 PRIVATE algorithms misc)
target_link_libraries(GRASP_algorithm_test_cap134 PRIVATE algorithms misc)
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
target_link_libraries(GRASP_algorithm_test_mo1 PRIVATE algorithms misc)
target_link_libraries(GRASP_algorithm_test_mo2 PRIVATE algorithms misc)
target_link_libraries(GRASP_algorithm_test_mo3 PRIVATE algorithms misc)
target_link_libraries(GRASP_algorithm_test_mo4 PRIVATE algorithms misc)
target_link_libraries(GRASP_algorithm_test_mo5 PRIVATE algorithms misc)
target_link_libraries(GRASP_algorithm_test_mp1 PRIVATE algorithms misc)
target_link_libraries(GRASP_algorithm_test_mp2 PRIVATE algorithms misc)
target_link_libraries(GRASP_algorithm_test_mp3 PRIVATE algorithms misc)
target_link_libraries(GRASP_algorithm_test_mp4 PRIVATE algorithms misc)
target_link_libraries(GRASP_algorithm_test_mp5 PRIVATE algorithms misc)
target_link_libraries(GRASP_algorithm_test_mq1 PRIVATE algorithms misc)
target_link_libraries(GRASP_algorithm_test_mq2 PRIVATE algorithms misc)
target_link_libraries(GRASP_algorithm_test_mq3 PRIVATE algorithms misc)
target_link_libraries(GRASP_algorithm_test_mq4 PRIVATE algorithms misc)
target_link_libraries(GRASP_algorithm_test_mq5 PRIVATE algorithms misc)

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
target_link_libraries(simulated_annealing_test_cap71 PRIVATE algorithms)
target_link_libraries(simulated_annealing_test_cap71 PRIVATE misc)
target_link_libraries(simulated_annealing_test_cap72 PRIVATE algorithms)
target_link_libraries(simulated_annealing_test_cap72 PRIVATE misc)
target_link_libraries(simulated_annealing_test_cap73 PRIVATE algorithms)
target_link_libraries(simulated_annealing_test_cap73 PRIVATE misc)
target_link_libraries(simulated_annealing_test_cap74 PRIVATE algorithms)
target_link_libraries(simulated_annealing_test_cap74 PRIVATE misc)
target_link_libraries(simulated_annealing_test_cap101 PRIVATE algorithms)
target_link_libraries(simulated_annealing_test_cap101 PRIVATE misc)
target_link_libraries(simulated_annealing_test_cap102 PRIVATE algorithms)
target_link_libraries(simulated_annealing_test_cap102 PRIVATE misc)
target_link_libraries(simulated_annealing_test_cap103 PRIVATE algorithms)
target_link_libraries(simulated_annealing_test_cap103 PRIVATE misc)
target_link_libraries(simulated_annealing_test_cap104 PRIVATE algorithms)
target_link_libraries(simulated_annealing_test_cap104 PRIVATE misc)
target_link_libraries(simulated_annealing_test_cap131 PRIVATE algorithms)
target_link_libraries(simulated_annealing_test_cap131 PRIVATE misc)
target_link_libraries(simulated_annealing_test_cap132 PRIVATE algorithms)
target_link_libraries(simulated_annealing_test_cap132 PRIVATE misc)
target_link_libraries(simulated_annealing_test_cap133 PRIVATE algorithms)
target_link_libraries(simulated_annealing_test_cap133 PRIVATE misc)
target_link_libraries(simulated_annealing_test_cap134 PRIVATE algorithms)
target_link_libraries(simulated_annealing_test_cap134 PRIVATE misc)
target_link_libraries(simulated_annealing_test_mo1 PRIVATE algorithms)
target_link_libraries(simulated_annealing_test_mo1 PRIVATE misc)
target_link_libraries(simulated_annealing_test_mo2 PRIVATE algorithms)
target_link_libraries(simulated_annealing_test_mo2 PRIVATE misc)
target_link_libraries(simulated_annealing_test_mo3 PRIVATE algorithms)
target_link_libraries(simulated_annealing_test_mo3 PRIVATE misc)
target_link_libraries(simulated_annealing_test_mo4 PRIVATE algorithms)
target_link_libraries(simulated_annealing_test_mo4 PRIVATE misc)
target_link_libraries(simulated_annealing_test_mo5 PRIVATE algorithms)
target_link_libraries(simulated_annealing_test_mo5 PRIVATE misc)
target_link_libraries(simulated_annealing_test_mp1 PRIVATE algorithms)
target_link_libraries(simulated_annealing_test_mp1 PRIVATE misc)
target_link_libraries(simulated_annealing_test_mp2 PRIVATE algorithms)
target_link_libraries(simulated_annealing_test_mp2 PRIVATE misc)
target_link_libraries(simulated_annealing_test_mp3 PRIVATE algorithms)
target_link_libraries(simulated_annealing_test_mp3 PRIVATE misc)
target_link_libraries(simulated_annealing_test_mp4 PRIVATE algorithms)
target_link_libraries(simulated_annealing_test_mp4 PRIVATE misc)
target_link_libraries(simulated_annealing_test_mp5 PRIVATE algorithms)
target_link_libraries(simulated_annealing_test_mp5 PRIVATE misc)
target_link_libraries(simulated_annealing_test_mq1 PRIVATE algorithms)
target_link_libraries(simulated_annealing_test_mq1 PRIVATE misc)
target_link_libraries(simulated_annealing_test_mq2 PRIVATE algorithms)
target_link_libraries(simulated_annealing_test_mq2 PRIVATE misc)
target_link_libraries(simulated_annealing_test_mq3 PRIVATE algorithms)
target_link_libraries(simulated_annealing_test_mq3 PRIVATE misc)
target_link_libraries(simulated_annealing_test_mq4 PRIVATE algorithms)
target_link_libraries(simulated_annealing_test_mq4 PRIVATE misc)
target_link_libraries(simulated_annealing_test_mq5 PRIVATE algorithms)
target_link_libraries(simulated_annealing_test_mq5 PRIVATE misc)

target_link_libraries(hill_climbing_algorithm_test_capa PRIVATE algorithms)
target_link_libraries(hill_climbing_algorithm_test_capa PRIVATE misc)
target_link_libraries(hill_climbing_algorithm_test_capb PRIVATE algorithms)
target_link_libraries(hill_climbing_algorithm_test_capb PRIVATE misc)
target_link_libraries(hill_climbing_algorithm_test_capc PRIVATE algorithms)
target_link_libraries(hill_climbing_algorithm_test_capc PRIVATE misc)
target_link_libraries(hill_climbing_algorithm_test_cap71 PRIVATE algorithms misc)
target_link_libraries(hill_climbing_algorithm_test_cap72 PRIVATE algorithms misc)
target_link_libraries(hill_climbing_algorithm_test_cap73 PRIVATE algorithms misc)
target_link_libraries(hill_climbing_algorithm_test_cap74 PRIVATE algorithms misc)
target_link_libraries(hill_climbing_algorithm_test_cap101 PRIVATE algorithms misc)
target_link_libraries(hill_climbing_algorithm_test_cap102 PRIVATE algorithms misc)
target_link_libraries(hill_climbing_algorithm_test_cap103 PRIVATE algorithms misc)
target_link_libraries(hill_climbing_algorithm_test_cap104 PRIVATE algorithms misc)
target_link_libraries(hill_climbing_algorithm_test_cap131 PRIVATE algorithms misc)
target_link_libraries(hill_climbing_algorithm_test_cap132 PRIVATE algorithms misc)
target_link_libraries(hill_climbing_algorithm_test_cap133 PRIVATE algorithms misc)
target_link_libraries(hill_climbing_algorithm_test_cap134 PRIVATE algorithms misc)
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
target_link_libraries(hill_climbing_algorithm_test_mo1 PRIVATE algorithms misc)
target_link_libraries(hill_climbing_algorithm_test_mo2 PRIVATE algorithms misc)
target_link_libraries(hill_climbing_algorithm_test_mo3 PRIVATE algorithms misc)
target_link_libraries(hill_climbing_algorithm_test_mo4 PRIVATE algorithms misc)
target_link_libraries(hill_climbing_algorithm_test_mo5 PRIVATE algorithms misc)
target_link_libraries(hill_climbing_algorithm_test_mp1 PRIVATE algorithms misc)
target_link_libraries(hill_climbing_algorithm_test_mp2 PRIVATE algorithms misc)
target_link_libraries(hill_climbing_algorithm_test_mp3 PRIVATE algorithms misc)
target_link_libraries(hill_climbing_algorithm_test_mp4 PRIVATE algorithms misc)
target_link_libraries(hill_climbing_algorithm_test_mp5 PRIVATE algorithms misc)
target_link_libraries(hill_climbing_algorithm_test_mq1 PRIVATE algorithms misc)
target_link_libraries(hill_climbing_algorithm_test_mq2 PRIVATE algorithms misc)
target_link_libraries(hill_climbing_algorithm_test_mq3 PRIVATE algorithms misc)
target_link_libraries(hill_climbing_algorithm_test_mq4 PRIVATE algorithms misc)
target_link_libraries(hill_climbing_algorithm_test_mq5 PRIVATE algorithms misc)

target_link_libraries(binary_crow_search_test_capa PRIVATE algorithms)
target_link_libraries(binary_crow_search_test_capa PRIVATE misc)
target_link_libraries(binary_crow_search_test_capb PRIVATE algorithms)
target_link_libraries(binary_crow_search_test_capb PRIVATE misc)
target_link_libraries(binary_crow_search_test_capc PRIVATE algorithms)
target_link_libraries(binary_crow_search_test_capc PRIVATE misc)
target_link_libraries(binary_crow_search_test_cap71 PRIVATE algorithms)
target_link_libraries(binary_crow_search_test_cap71 PRIVATE misc)
target_link_libraries(binary_crow_search_test_cap72 PRIVATE algorithms)
target_link_libraries(binary_crow_search_test_cap72 PRIVATE misc)
target_link_libraries(binary_crow_search_test_cap73 PRIVATE algorithms)
target_link_libraries(binary_crow_search_test_cap73 PRIVATE misc)
target_link_libraries(binary_crow_search_test_cap74 PRIVATE algorithms)
target_link_libraries(binary_crow_search_test_cap74 PRIVATE misc)
target_link_libraries(binary_crow_search_test_cap101 PRIVATE algorithms)
target_link_libraries(binary_crow_search_test_cap101 PRIVATE misc)
target_link_libraries(binary_crow_search_test_cap102 PRIVATE algorithms)
target_link_libraries(binary_crow_search_test_cap102 PRIVATE misc)
target_link_libraries(binary_crow_search_test_cap103 PRIVATE algorithms)
target_link_libraries(binary_crow_search_test_cap103 PRIVATE misc)
target_link_libraries(binary_crow_search_test_cap104 PRIVATE algorithms)
target_link_libraries(binary_crow_search_test_cap104 PRIVATE misc)
target_link_libraries(binary_crow_search_test_cap131 PRIVATE algorithms)
target_link_libraries(binary_crow_search_test_cap131 PRIVATE misc)
target_link_libraries(binary_crow_search_test_cap132 PRIVATE algorithms)
target_link_libraries(binary_crow_search_test_cap132 PRIVATE misc)
target_link_libraries(binary_crow_search_test_cap133 PRIVATE algorithms)
target_link_libraries(binary_crow_search_test_cap133 PRIVATE misc)
target_link_libraries(binary_crow_search_test_cap134 PRIVATE algorithms)
target_link_libraries(binary_crow_search_test_cap134 PRIVATE misc)
target_link_libraries(binary_crow_search_test_mr1 PRIVATE algorithms)
target_link_libraries(binary_crow_search_test_mr1 PRIVATE misc)
target_link_libraries(binary_crow_search_test_mr2 PRIVATE algorithms)
target_link_libraries(binary_crow_search_test_mr2 PRIVATE misc)
target_link_libraries(binary_crow_search_test_mr3 PRIVATE algorithms)
target_link_libraries(binary_crow_search_test_mr3 PRIVATE misc)
target_link_libraries(binary_crow_search_test_mr4 PRIVATE algorithms)
target_link_libraries(binary_crow_search_test_mr4 PRIVATE misc)
target_link_libraries(binary_crow_search_test_mr5 PRIVATE algorithms)
target_link_libraries(binary_crow_search_test_mr5 PRIVATE misc)
target_link_libraries(binary_crow_search_test_mo1 PRIVATE algorithms)
target_link_libraries(binary_crow_search_test_mo1 PRIVATE misc)
target_link_libraries(binary_crow_search_test_mo2 PRIVATE algorithms)
target_link_libraries(binary_crow_search_test_mo2 PRIVATE misc)
target_link_libraries(binary_crow_search_test_mo3 PRIVATE algorithms)
target_link_libraries(binary_crow_search_test_mo3 PRIVATE misc)
target_link_libraries(binary_crow_search_test_mo4 PRIVATE algorithms)
target_link_libraries(binary_crow_search_test_mo4 PRIVATE misc)
target_link_libraries(binary_crow_search_test_mo5 PRIVATE algorithms)
target_link_libraries(binary_crow_search_test_mo5 PRIVATE misc)
target_link_libraries(binary_crow_search_test_mp1 PRIVATE algorithms)
target_link_libraries(binary_crow_search_test_mp1 PRIVATE misc)
target_link_libraries(binary_crow_search_test_mp2 PRIVATE algorithms)
target_link_libraries(binary_crow_search_test_mp2 PRIVATE misc)
target_link_libraries(binary_crow_search_test_mp3 PRIVATE algorithms)
target_link_libraries(binary_crow_search_test_mp3 PRIVATE misc)
target_link_libraries(binary_crow_search_test_mp4 PRIVATE algorithms)
target_link_libraries(binary_crow_search_test_mp4 PRIVATE misc)
target_link_libraries(binary_crow_search_test_mp5 PRIVATE algorithms)
target_link_libraries(binary_crow_search_test_mp5 PRIVATE misc)
target_link_libraries(binary_crow_search_test_mq1 PRIVATE algorithms)
target_link_libraries(binary_crow_search_test_mq1 PRIVATE misc)
target_link_libraries(binary_crow_search_test_mq2 PRIVATE algorithms)
target_link_libraries(binary_crow_search_test_mq2 PRIVATE misc)
target_link_libraries(binary_crow_search_test_mq3 PRIVATE algorithms)
target_link_libraries(binary_crow_search_test_mq3 PRIVATE misc)
target_link_libraries(binary_crow_search_test_mq4 PRIVATE algorithms)
target_link_libraries(binary_crow_search_test_mq4 PRIVATE misc)
target_link_libraries(binary_crow_search_test_mq5 PRIVATE algorithms)
target_link_libraries(binary_crow_search_test_mq5 PRIVATE misc)
# Link more test executables as needed
enable_testing()
# Register tests with CTest
add_test(NAME GRASPAlgorithmTestCapA
         COMMAND GRASP_algorithm_test_capa)
add_test(NAME GRASPAlgorithmTestCapB
         COMMAND GRASP_algorithm_test_capb)
add_test(NAME GRASPAlgorithmTestCapC
         COMMAND GRASP_algorithm_test_capc)
         add_test(NAME GRASPAlgorithmTestCap71
         COMMAND GRASP_algorithm_test_cap71)
add_test(NAME GRASPAlgorithmTestCap72
         COMMAND GRASP_algorithm_test_cap72)
add_test(NAME GRASPAlgorithmTestCap73
         COMMAND GRASP_algorithm_test_cap73)
add_test(NAME GRASPAlgorithmTestCap74
         COMMAND GRASP_algorithm_test_cap74)
add_test(NAME GRASPAlgorithmTestCap101
         COMMAND GRASP_algorithm_test_cap101)
add_test(NAME GRASPAlgorithmTestCap102
         COMMAND GRASP_algorithm_test_cap102)
add_test(NAME GRASPAlgorithmTestCap103
         COMMAND GRASP_algorithm_test_cap103)
add_test(NAME GRASPAlgorithmTestCap104
         COMMAND GRASP_algorithm_test_cap104)
add_test(NAME GRASPAlgorithmTestCap131
         COMMAND GRASP_algorithm_test_cap131)
add_test(NAME GRASPAlgorithmTestCap132
         COMMAND GRASP_algorithm_test_cap132)
add_test(NAME GRASPAlgorithmTestCap133
         COMMAND GRASP_algorithm_test_cap133)
add_test(NAME GRASPAlgorithmTestCap134
         COMMAND GRASP_algorithm_test_cap134)
add_test(NAME GRASPAlgorithmTestMr1
         COMMAND GRASP_algorithm_test_mr1)
add_test(NAME GRASPAlgorithmTestMr2
         COMMAND GRASP_algorithm_test_mr2)
add_test(NAME GRASPAlgorithmTestMr3
         COMMAND GRASP_algorithm_test_mr3)
add_test(NAME GRASPAlgorithmTestMr4
         COMMAND GRASP_algorithm_test_mr4)
add_test(NAME GRASPAlgorithmTestMr5
         COMMAND GRASP_algorithm_test_mr5)
         add_test(NAME GRASPAlgorithmTestMo1
         COMMAND GRASP_algorithm_test_mo1)
add_test(NAME GRASPAlgorithmTestMo2
         COMMAND GRASP_algorithm_test_mo2)
add_test(NAME GRASPAlgorithmTestMo3
         COMMAND GRASP_algorithm_test_mo3)
add_test(NAME GRASPAlgorithmTestMo4
         COMMAND GRASP_algorithm_test_mo4)
add_test(NAME GRASPAlgorithmTestMo5
         COMMAND GRASP_algorithm_test_mo5)
add_test(NAME GRASPAlgorithmTestMp1
         COMMAND GRASP_algorithm_test_mp1)
add_test(NAME GRASPAlgorithmTestMp2
         COMMAND GRASP_algorithm_test_mp2)
add_test(NAME GRASPAlgorithmTestMp3
         COMMAND GRASP_algorithm_test_mp3)
add_test(NAME GRASPAlgorithmTestMp4
         COMMAND GRASP_algorithm_test_mp4)
add_test(NAME GRASPAlgorithmTestMp5
         COMMAND GRASP_algorithm_test_mp5)
add_test(NAME GRASPAlgorithmTestMq1
         COMMAND GRASP_algorithm_test_mq1)
add_test(NAME GRASPAlgorithmTestMq2
         COMMAND GRASP_algorithm_test_mq2)
add_test(NAME GRASPAlgorithmTestMq3
         COMMAND GRASP_algorithm_test_mq3)
add_test(NAME GRASPAlgorithmTestMq4
         COMMAND GRASP_algorithm_test_mq4)
add_test(NAME GRASPAlgorithmTestMq5
         COMMAND GRASP_algorithm_test_mq5)

add_test(NAME SimulatedAnnealingTestCapA
         COMMAND simulated_annealing_test_capa)
add_test(NAME SimulatedAnnealingTestCapB
        COMMAND simulated_annealing_test_capb)
add_test(NAME SimulatedAnnealingTestCapC
        COMMAND simulated_annealing_test_capc)
add_test(NAME SimulatedAnnealingTestCap71
         COMMAND simulated_annealing_test_cap71)
add_test(NAME SimulatedAnnealingTestCap72
         COMMAND simulated_annealing_test_cap72)
add_test(NAME SimulatedAnnealingTestCap73
         COMMAND simulated_annealing_test_cap73)
add_test(NAME SimulatedAnnealingTestCap74
         COMMAND simulated_annealing_test_cap74)
add_test(NAME SimulatedAnnealingTestCap101
         COMMAND simulated_annealing_test_cap101)
add_test(NAME SimulatedAnnealingTestCap102
         COMMAND simulated_annealing_test_cap102)
add_test(NAME SimulatedAnnealingTestCap103
         COMMAND simulated_annealing_test_cap103)
add_test(NAME SimulatedAnnealingTestCap104
         COMMAND simulated_annealing_test_cap104)
add_test(NAME SimulatedAnnealingTestCap131
         COMMAND simulated_annealing_test_cap131)
add_test(NAME SimulatedAnnealingTestCap132
         COMMAND simulated_annealing_test_cap132)
add_test(NAME SimulatedAnnealingTestCap133
         COMMAND simulated_annealing_test_cap133)
add_test(NAME SimulatedAnnealingTestCap134
         COMMAND simulated_annealing_test_cap134)
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
add_test(NAME SimulatedAnnealingTestMo1
         COMMAND simulated_annealing_test_mo1)
add_test(NAME SimulatedAnnealingTestMo2
         COMMAND simulated_annealing_test_mo2)
add_test(NAME SimulatedAnnealingTestMo3
         COMMAND simulated_annealing_test_mo3)
add_test(NAME SimulatedAnnealingTestMo4
         COMMAND simulated_annealing_test_mo4)
add_test(NAME SimulatedAnnealingTestMo5
         COMMAND simulated_annealing_test_mo5)
add_test(NAME SimulatedAnnealingTestMp1
         COMMAND simulated_annealing_test_mp1)
add_test(NAME SimulatedAnnealingTestMp2
         COMMAND simulated_annealing_test_mp2)
add_test(NAME SimulatedAnnealingTestMp3
         COMMAND simulated_annealing_test_mp3)
add_test(NAME SimulatedAnnealingTestMp4
         COMMAND simulated_annealing_test_mp4)
add_test(NAME SimulatedAnnealingTestMp5
         COMMAND simulated_annealing_test_mp5)
add_test(NAME SimulatedAnnealingTestMq1
         COMMAND simulated_annealing_test_mq1)
add_test(NAME SimulatedAnnealingTestMq2
         COMMAND simulated_annealing_test_mq2)
add_test(NAME SimulatedAnnealingTestMq3
         COMMAND simulated_annealing_test_mq3)
add_test(NAME SimulatedAnnealingTestMq4
         COMMAND simulated_annealing_test_mq4)
add_test(NAME SimulatedAnnealingTestMq5
         COMMAND simulated_annealing_test_mq5)

add_test(NAME HillClimbingAlgorithmTestCapA
        COMMAND hill_climbing_algorithm_test_capa)
add_test(NAME HillClimbingAlgorithmTestCapB
        COMMAND hill_climbing_algorithm_test_capb)
add_test(NAME HillClimbingAlgorithmTestCapC
        COMMAND hill_climbing_algorithm_test_capc)
        add_test(NAME HillClimbingAlgorithmTestCap71
        COMMAND hill_climbing_algorithm_test_cap71)
add_test(NAME HillClimbingAlgorithmTestCap72
        COMMAND hill_climbing_algorithm_test_cap72)
add_test(NAME HillClimbingAlgorithmTestCap73
        COMMAND hill_climbing_algorithm_test_cap73)
add_test(NAME HillClimbingAlgorithmTestCap74
        COMMAND hill_climbing_algorithm_test_cap74)
add_test(NAME HillClimbingAlgorithmTestCap101
        COMMAND hill_climbing_algorithm_test_cap101)
add_test(NAME HillClimbingAlgorithmTestCap102
        COMMAND hill_climbing_algorithm_test_cap102)
add_test(NAME HillClimbingAlgorithmTestCap103
        COMMAND hill_climbing_algorithm_test_cap103)
add_test(NAME HillClimbingAlgorithmTestCap104
        COMMAND hill_climbing_algorithm_test_cap104)
add_test(NAME HillClimbingAlgorithmTestCap131
        COMMAND hill_climbing_algorithm_test_cap131)
add_test(NAME HillClimbingAlgorithmTestCap132
        COMMAND hill_climbing_algorithm_test_cap132)
add_test(NAME HillClimbingAlgorithmTestCap133
        COMMAND hill_climbing_algorithm_test_cap133)
add_test(NAME HillClimbingAlgorithmTestCap134
        COMMAND hill_climbing_algorithm_test_cap134)
add_test(NAME HillClimbingAlgorithmTestMr1
        COMMAND hill_climbing_algorithm_test_mr1)
add_test(NAME HillClimbingAlgorithmTestMr2
        COMMAND hill_climbing_algorithm_test_mr2)
add_test(NAME HillClimbingAlgorithmTestMr3
        COMMAND hill_climbing_algorithm_test_mr3)
add_test(NAME HillClimbingAlgorithmTestMr4
        COMMAND hill_climbing_algorithm_test_mr4)
add_test(NAME HillClimbingAlgorithmTestMr5
        COMMAND hill_climbing_algorithm_test_mr5)
        add_test(NAME HillClimbingAlgorithmTestMo1
        COMMAND hill_climbing_algorithm_test_mo1)
add_test(NAME HillClimbingAlgorithmTestMo2
        COMMAND hill_climbing_algorithm_test_mo2)
add_test(NAME HillClimbingAlgorithmTestMo3
        COMMAND hill_climbing_algorithm_test_mo3)
add_test(NAME HillClimbingAlgorithmTestMo4
        COMMAND hill_climbing_algorithm_test_mo4)
add_test(NAME HillClimbingAlgorithmTestMo5
        COMMAND hill_climbing_algorithm_test_mo5)
add_test(NAME HillClimbingAlgorithmTestMp1
        COMMAND hill_climbing_algorithm_test_mp1)
add_test(NAME HillClimbingAlgorithmTestMp2
        COMMAND hill_climbing_algorithm_test_mp2)
add_test(NAME HillClimbingAlgorithmTestMp3
        COMMAND hill_climbing_algorithm_test_mp3)
add_test(NAME HillClimbingAlgorithmTestMp4
        COMMAND hill_climbing_algorithm_test_mp4)
add_test(NAME HillClimbingAlgorithmTestMp5
        COMMAND hill_climbing_algorithm_test_mp5)
add_test(NAME HillClimbingAlgorithmTestMq1
        COMMAND hill_climbing_algorithm_test_mq1)
add_test(NAME HillClimbingAlgorithmTestMq2
        COMMAND hill_climbing_algorithm_test_mq2)
add_test(NAME HillClimbingAlgorithmTestMq3
        COMMAND hill_climbing_algorithm_test_mq3)
add_test(NAME HillClimbingAlgorithmTestMq4
        COMMAND hill_climbing_algorithm_test_mq4)
add_test(NAME HillClimbingAlgorithmTestMq5
        COMMAND hill_climbing_algorithm_test_mq5)

add_test(NAME BinaryCrowSearchTestCapA
        COMMAND binary_crow_search_test_capa)
add_test(NAME BinaryCrowSearchTestCapB
        COMMAND binary_crow_search_test_capb)
add_test(NAME BinaryCrowSearchTestCapC
        COMMAND binary_crow_search_test_capc)
add_test(NAME BinaryCrowSearchTestCap71
        COMMAND binary_crow_search_test_cap71)
add_test(NAME BinaryCrowSearchTestCap72
        COMMAND binary_crow_search_test_cap72)
add_test(NAME BinaryCrowSearchTestCap73
        COMMAND binary_crow_search_test_cap73)
add_test(NAME BinaryCrowSearchTestCap74
        COMMAND binary_crow_search_test_cap74)
add_test(NAME BinaryCrowSearchTestCap101
        COMMAND binary_crow_search_test_cap101)
add_test(NAME BinaryCrowSearchTestCap102
        COMMAND binary_crow_search_test_cap102)
add_test(NAME BinaryCrowSearchTestCap103
        COMMAND binary_crow_search_test_cap103)
add_test(NAME BinaryCrowSearchTestCap104
        COMMAND binary_crow_search_test_cap104)
add_test(NAME BinaryCrowSearchTestCap131
        COMMAND binary_crow_search_test_cap131)
add_test(NAME BinaryCrowSearchTestCap132
        COMMAND binary_crow_search_test_cap132)
add_test(NAME BinaryCrowSearchTestCap133
        COMMAND binary_crow_search_test_cap133)
add_test(NAME BinaryCrowSearchTestCap134
        COMMAND binary_crow_search_test_cap134)
add_test(NAME BinaryCrowSearchTestMr1
        COMMAND binary_crow_search_test_mr1)
add_test(NAME BinaryCrowSearchTestMr2
        COMMAND binary_crow_search_test_mr2)
add_test(NAME BinaryCrowSearchTestMr3
        COMMAND binary_crow_search_test_mr3)
add_test(NAME BinaryCrowSearchTestMr4
        COMMAND binary_crow_search_test_mr4)
add_test(NAME BinaryCrowSearchTestMr5
        COMMAND binary_crow_search_test_mr5)
add_test(NAME BinaryCrowSearchTestMo1
        COMMAND binary_crow_search_test_mo1)
add_test(NAME BinaryCrowSearchTestMo2
        COMMAND binary_crow_search_test_mo2)
add_test(NAME BinaryCrowSearchTestMo3
        COMMAND binary_crow_search_test_mo3)
add_test(NAME BinaryCrowSearchTestMo4
        COMMAND binary_crow_search_test_mo4)
add_test(NAME BinaryCrowSearchTestMo5
        COMMAND binary_crow_search_test_mo5)
add_test(NAME BinaryCrowSearchTestMp1
        COMMAND binary_crow_search_test_mp1)
add_test(NAME BinaryCrowSearchTestMp2
        COMMAND binary_crow_search_test_mp2)
add_test(NAME BinaryCrowSearchTestMp3
        COMMAND binary_crow_search_test_mp3)
add_test(NAME BinaryCrowSearchTestMp4
        COMMAND binary_crow_search_test_mp4)
add_test(NAME BinaryCrowSearchTestMp5
        COMMAND binary_crow_search_test_mp5)
add_test(NAME BinaryCrowSearchTestMq1
        COMMAND binary_crow_search_test_mq1)
add_test(NAME BinaryCrowSearchTestMq2
        COMMAND binary_crow_search_test_mq2)
add_test(NAME BinaryCrowSearchTestMq3
        COMMAND binary_crow_search_test_mq3)
add_test(NAME BinaryCrowSearchTestMq4
        COMMAND binary_crow_search_test_mq4)
add_test(NAME BinaryCrowSearchTestMq5
        COMMAND binary_crow_search_test_mq5)

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
        set_property(TARGET GRASP_algorithm_test_cap71 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET GRASP_algorithm_test_cap72 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET GRASP_algorithm_test_cap73 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET GRASP_algorithm_test_cap74 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})        
        set_property(TARGET GRASP_algorithm_test_cap101 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET GRASP_algorithm_test_cap102 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET GRASP_algorithm_test_cap103 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET GRASP_algorithm_test_cap104 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET GRASP_algorithm_test_cap131 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET GRASP_algorithm_test_cap132 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET GRASP_algorithm_test_cap133 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET GRASP_algorithm_test_cap134 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET GRASP_algorithm_test_mr1 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET GRASP_algorithm_test_mr2 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET GRASP_algorithm_test_mr3 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET GRASP_algorithm_test_mr4 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET GRASP_algorithm_test_mr5 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET GRASP_algorithm_test_mo1 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET GRASP_algorithm_test_mo2 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET GRASP_algorithm_test_mo3 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET GRASP_algorithm_test_mo4 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET GRASP_algorithm_test_mo5 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET GRASP_algorithm_test_mp1 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET GRASP_algorithm_test_mp2 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET GRASP_algorithm_test_mp3 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET GRASP_algorithm_test_mp4 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET GRASP_algorithm_test_mp5 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET GRASP_algorithm_test_mq1 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET GRASP_algorithm_test_mq2 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET GRASP_algorithm_test_mq3 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET GRASP_algorithm_test_mq4 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET GRASP_algorithm_test_mq5 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        

        set_property(TARGET simulated_annealing_test_capa PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET simulated_annealing_test_capb PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET simulated_annealing_test_capc PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET simulated_annealing_test_cap71 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET simulated_annealing_test_cap72 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET simulated_annealing_test_cap73 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET simulated_annealing_test_cap74 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET simulated_annealing_test_cap101 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET simulated_annealing_test_cap102 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET simulated_annealing_test_cap103 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET simulated_annealing_test_cap104 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET simulated_annealing_test_cap131 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET simulated_annealing_test_cap132 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET simulated_annealing_test_cap133 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET simulated_annealing_test_cap134 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET simulated_annealing_test_mr1 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET simulated_annealing_test_mr2 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET simulated_annealing_test_mr3 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET simulated_annealing_test_mr4 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET simulated_annealing_test_mr5 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET simulated_annealing_test_mo1 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET simulated_annealing_test_mo2 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET simulated_annealing_test_mo3 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET simulated_annealing_test_mo4 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET simulated_annealing_test_mo5 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET simulated_annealing_test_mp1 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET simulated_annealing_test_mp2 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET simulated_annealing_test_mp3 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET simulated_annealing_test_mp4 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET simulated_annealing_test_mp5 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET simulated_annealing_test_mq1 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET simulated_annealing_test_mq2 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET simulated_annealing_test_mq3 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET simulated_annealing_test_mq4 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET simulated_annealing_test_mq5 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})

        set_property(TARGET hill_climbing_algorithm_test_capa PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET hill_climbing_algorithm_test_capb PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET hill_climbing_algorithm_test_capc PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET hill_climbing_algorithm_test_cap71 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET hill_climbing_algorithm_test_cap72 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET hill_climbing_algorithm_test_cap73 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET hill_climbing_algorithm_test_cap74 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET hill_climbing_algorithm_test_cap101 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET hill_climbing_algorithm_test_cap102 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET hill_climbing_algorithm_test_cap103 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET hill_climbing_algorithm_test_cap104 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET hill_climbing_algorithm_test_cap131 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET hill_climbing_algorithm_test_cap132 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET hill_climbing_algorithm_test_cap133 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET hill_climbing_algorithm_test_cap134 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET hill_climbing_algorithm_test_mr1 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET hill_climbing_algorithm_test_mr2 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET hill_climbing_algorithm_test_mr3 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET hill_climbing_algorithm_test_mr4 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET hill_climbing_algorithm_test_mr5 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET hill_climbing_algorithm_test_mo1 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET hill_climbing_algorithm_test_mo2 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET hill_climbing_algorithm_test_mo3 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET hill_climbing_algorithm_test_mo4 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET hill_climbing_algorithm_test_mo5 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET hill_climbing_algorithm_test_mp1 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET hill_climbing_algorithm_test_mp2 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET hill_climbing_algorithm_test_mp3 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET hill_climbing_algorithm_test_mp4 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET hill_climbing_algorithm_test_mp5 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET hill_climbing_algorithm_test_mq1 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET hill_climbing_algorithm_test_mq2 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET hill_climbing_algorithm_test_mq3 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET hill_climbing_algorithm_test_mq4 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET hill_climbing_algorithm_test_mq5 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})

        set_property(TARGET binary_crow_search_test_capa PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET binary_crow_search_test_capb PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET binary_crow_search_test_capc PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET binary_crow_search_test_cap71 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET binary_crow_search_test_cap72 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET binary_crow_search_test_cap73 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET binary_crow_search_test_cap74 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET binary_crow_search_test_cap101 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET binary_crow_search_test_cap102 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET binary_crow_search_test_cap104 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET binary_crow_search_test_cap131 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET binary_crow_search_test_cap132 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET binary_crow_search_test_cap133 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET binary_crow_search_test_cap134 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET binary_crow_search_test_mr1 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET binary_crow_search_test_mr2 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET binary_crow_search_test_mr3 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET binary_crow_search_test_mr4 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET binary_crow_search_test_mr5 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET binary_crow_search_test_mo1 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET binary_crow_search_test_mo2 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET binary_crow_search_test_mo3 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET binary_crow_search_test_mo4 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET binary_crow_search_test_mo5 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET binary_crow_search_test_mp1 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET binary_crow_search_test_mp2 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET binary_crow_search_test_mp3 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET binary_crow_search_test_mp4 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET binary_crow_search_test_mp5 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET binary_crow_search_test_mq1 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET binary_crow_search_test_mq2 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET binary_crow_search_test_mq3 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET binary_crow_search_test_mq4 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})
        set_property(TARGET binary_crow_search_test_mq5 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${BUILD_CONFIG_DIR})

    endforeach()
endif()
