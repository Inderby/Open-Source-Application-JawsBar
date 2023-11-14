cmake_minimum_required(VERSION 3.13)

project(OpenSourceApplicationJawsBar)

set(CMAKE_CXX_STANDARD 11)

find_package(GTest REQUIRED)
message("GTest_INCLUDE_DIRS = ${GTest_INCLUDE_DIRS}")


add_subdirectory(header)

add_executable(mainApp main.cc)
target_link_libraries(mainApp AVL_library)

#add_executable(unitTestRunner test_runner.cc)
#target_link_libraries(unitTestRunner AVL_library ${GTEST_LIBRARIES})
