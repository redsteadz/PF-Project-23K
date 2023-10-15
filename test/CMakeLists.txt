cmake_minimum_required(VERSION 3.12)
project(Calc)

# Locate Google Test
find_package(GTest REQUIRED)



# Add an executable for your main code (matrices.cpp)
add_executable(test_matrices test_matrices.cpp)

# Add an executable for your tests (test_matrices.cpp)


# Link your tests with Google Test and the main code
target_link_libraries(test_matrices GTest::GTest GTest::Main)

enable_testing()
add_test(NAME Test_all COMMAND test_all)

