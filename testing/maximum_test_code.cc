/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12191572KimYongBin on 2023/12/10.
 */

#include "../header/AVL_tree.h"
#include <fstream>
#include <gtest/gtest.h>
#include <iostream>

std::string input_file;
std::string output_file;

class AVLTreeFixture : public testing::TestWithParam<
                           std::tuple<std::vector<int>, std::vector<int>,
                                      std::vector<std::pair<int, int>>>> {
public:
  void SetUp() override;
  int Perform(int);

protected:
  AVLTree avl_tree_;
  std::vector<int> input_;
  std::vector<std::pair<int, int>> expected_;
  std::vector<int> init_values_;
};

// input과 예상되는 output을 각 테스트마다 세팅해주는 함수
void AVLTreeFixture::SetUp() {
  std::tuple<std::vector<int>, std::vector<int>,
             std::vector<std::pair<int, int>>>
      test_collect = GetParam();
  init_values_ = std::get<0>(test_collect);
  for (int i = 0; i < init_values_.size(); i++)
    Perform(init_values_[i]);

  input_ = std::get<1>(test_collect);
  expected_ = std::get<2>(test_collect);
}

// test.in 파일과 test.out파일의 값을 각각 vector로 변환하여
// pair<input,output>으로 변환 시키는 함수
static std::tuple<std::vector<int>, std::vector<int>,
                  std::vector<std::pair<int, int>>>
ReadTestCases(const std::string &filename_input,
              const std::string &filename_output) {

  std::ifstream file_input(filename_input);
  std::ifstream file_output(filename_output);
  std::vector<int> input;
  std::vector<std::pair<int, int>> expected;
  std::vector<int> init_values;
  // 파일의 두 read 권한이 있을 경우 input, output 벡터 생성
  if (file_input.is_open() && file_output.is_open()) {
    int number_of_init_command = 0, number_of_commmand = 0, value = 0,
        result1 = 0, result2 = 0;

    file_input >> number_of_init_command;

    // 특정 시점의 avl tree를 나타내주기 위해 초기값을 세팅해줌
    for (int i = 0; i < number_of_init_command; i++) {
      file_input >> value;
      init_values.push_back(value);
    }

    file_input >> number_of_commmand;

    for (int i = 0; i < number_of_commmand; i++) {
      file_input >> value;
      input.push_back(value);
    }

    for (int i = 0; i < number_of_commmand; i++) {
      file_output >> result1 >> result2;
      expected.emplace_back(result1, result2);
    }

    file_input.close();
    file_output.close();
  }
  return {init_values, input, expected};
}

// test로 들어올 값을 파라미터로 입력 받게 하는 googletest 라이브러리 매크로
INSTANTIATE_TEST_SUITE_P(FileTestCases, AVLTreeFixture,
                         ::testing::Values(ReadTestCases(input_file,
                                                         output_file)));

// AVLTree의 특정 시점을 나타내기 위해 value를 입력 받아 insert하는 함수
int AVLTreeFixture::Perform(int value_to_insert) {
  int return_value = -1;
  return_value = avl_tree_.Insert(value_to_insert);
  return return_value;
}

// Maximum 함수를 사용하는 unit 테스트를 시행
TEST_P(AVLTreeFixture, TestAllFunction) {
  std::vector<std::pair<int, int>> generate_result;
  for (int i = 0; i < input_.size(); i++) {
    generate_result.push_back(avl_tree_.Maximum(input_[i]));
  }

  ASSERT_EQ(generate_result, expected_);
}

int main(int argc, char **argv) {
  // 실행 프로그램에 인자로 들어온 input파일명과 output 파일명을 받아오는 부분
  input_file = std::string(argv[1]);
  output_file = std::string(argv[2]);

  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}