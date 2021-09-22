cmake_minimum_required(VERSION 3.10)
project(NaTddExercises CXX)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -pedantic -Werror)

include(cmake/GTest.cmake)

enable_testing()
add_test(tests_for_legacy tests_for_legacy)

add_custom_target(tests1
                  COMMAND "./tests_for_legacy"
                  DEPENDS tests_for_legacy)

