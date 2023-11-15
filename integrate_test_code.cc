/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12191572KimYongBin on 2023/11/15.
 */
#include "header/AVL_tree.h"
#include <gtest/gtest.h>
#include <iostream>

class AVLTreeFixture
    : public testing::TestWithParam<std::vector<std::pair<std::string, int>>> {
public:
  std::pair<int, int> Perform(std::pair<std::string, int>);

protected:
  AVLTree avl_tree_;
};

std::pair<int, int>
AVLTreeFixture::Perform(std::pair<std::string, int> command_value) {
  std::string command = command_value.first;
  int value = command_value.second;
  std::pair<int, int> return_value = {0, 0};
  if (command == "insert") {
    return_value = {avl_tree_.Insert(value), -1};
  } else if (command == "find") {
    return_value = {avl_tree_.Find(value), -1};
  } else if (command == "minimum") {
    return_value = avl_tree_.Minimum(value);
  } else if (command == "maximum") {
    return_value = avl_tree_.Maximum(value);
  } else if (command == "empty") {
    return_value = {avl_tree_.Empty(), -1};
  } else { // command == "size"
    return_value = {avl_tree_.Size(), -1};
  }
  return return_value;
}

TEST_P(AVLTreeFixture, TestAllFunction) {
  std::vector<std::pair<std::string, int>> command_value_series = GetParam();
  std::vector<std::pair<int, int>> generate_result;
  for (int i = 0; i < command_value_series.size(); i++) {
    generate_result.push_back(Perform(command_value_series[i]));
  }
  std::vector<std::pair<int, int>> expect_result{
      {0, -1}, {1, -1}, {1, -1}, {0, -1}, {2, -1}, {2, -1},
      {17, 2}, {2, -1}, {3, -1}, {14, 3}, {11, 2}, {0, -1},
      {3, -1}, {8, -1}, {18, 2}, {11, 3}, {3, -1}, {11, 2}};
  ASSERT_EQ(generate_result, expect_result);
}

INSTANTIATE_TEST_SUITE_P(
    AVLTreeTest, AVLTreeFixture,
    testing::Values(std::vector<std::pair<std::string, int>>{{"insert", 18},
                                                             {"insert", 9},
                                                             {"insert", 4},
                                                             {"find", 5},
                                                             {"insert", 7},
                                                             {"insert", 17},
                                                             {"minimum", 18},
                                                             {"insert", 11},
                                                             {"insert", 14},
                                                             {"maximum", 11},
                                                             {"minimum", 17},
                                                             {"empty", -1},
                                                             {"insert", 15},
                                                             {"size", -1},
                                                             {"maximum", 9},
                                                             {"minimum", 17},
                                                             {"insert", 13},
                                                             {"minimum", 14}}));

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
