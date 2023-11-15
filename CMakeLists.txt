#
# Copyright OpenSourceApplication-JawsBar.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.
#
# Created by 12191572KimYongBin on 2023/11/14.
#
cmake_minimum_required(VERSION 3.13)

project(OpenSourceApplicationJawsBar)

set(CMAKE_CXX_STANDARD 11)

find_package(GTest REQUIRED)
message("GTest_INCLUDE_DIRS = ${GTest_INCLUDE_DIRS}")


add_subdirectory(header)

add_executable(mainApp main.cc)
target_link_libraries(mainApp AVL_library)

add_executable(testRunner integrate_test_code.cc)
target_link_libraries(testRunner AVL_library ${GTEST_LIBRARIES})
