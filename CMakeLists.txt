# Add your algorithms library
# add_library(algorithms cool_algorithm.cpp super_fun_algorithm.cpp)

# Add executable targets for your tests
# add_executable(test_algorithm1 src/tests/test_algorithm1.cpp)
add_executable(does_it_run src/tests/does_it_run.cpp)
# Add more test executables as needed

# Link your algorithms library to the test executables
# target_link_libraries(test_algorithm1 PRIVATE algorithms)
# Link more test executables as needed

# Register tests with CTest
add_test(NAME DoesItRun COMMAND does_it_run)
#add_test(NAME TestAlgorithm2 COMMAND test_algorithm2)
# Add more tests as needed
