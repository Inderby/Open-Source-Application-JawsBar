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

add_executable(IntegrateTestRunner testing/integrate_test_code.cc)
target_link_libraries(IntegrateTestRunner AVL_library ${GTEST_LIBRARIES})

add_executable(InsertTestRunner testing/insert_test_code.cc)
target_link_libraries(InsertTestRunner AVL_library ${GTEST_LIBRARIES})

add_executable(FindTestRunner testing/find_test_code.cc)
target_link_libraries(FindTestRunner AVL_library ${GTEST_LIBRARIES})

add_executable(SizeTestRunner testing/size_test_code.cc)
target_link_libraries(SizeTestRunner AVL_library ${GTEST_LIBRARIES})

add_executable(EmptyTestRunner testing/empty_test_code.cc)
target_link_libraries(EmptyTestRunner AVL_library ${GTEST_LIBRARIES})

add_executable(MaximumTestRunner testing/maximum_test_code.cc)
target_link_libraries(MaximumTestRunner AVL_library ${GTEST_LIBRARIES})

add_executable(MinimumTestRunner testing/minimum_test_code.cc)
target_link_libraries(MinimumTestRunner AVL_library ${GTEST_LIBRARIES})

add_executable(RankTestRunner testing/rank_test_code.cc)
target_link_libraries(RankTestRunner AVL_library ${GTEST_LIBRARIES})

add_executable(EraseTestRunner testing/erase_test_code.cc)
target_link_libraries(EraseTestRunner AVL_library ${GTEST_LIBRARIES})
