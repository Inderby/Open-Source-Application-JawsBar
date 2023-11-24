/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12191572KimYongBin on 2023/11/15.
 */
#include "header/AVL_tree.h"
#include <fstream>
#include <gtest/gtest.h>
#include <iostream>

// 전역번수를 최대한 사용하지 않으려 했지만 찾아본 결과 googletest에서는
// 전역변수를 사용하지 않고서는 main함수의 파라미터를 테스트에 사용할 인자로써
// 넣어줄 수 없는 것으로 보임
std::string input_file;
std::string output_file;

// 테스트를 위해 생성한 wrapper 클래스
class AVLTreeFixture : public testing::TestWithParam<
                           std::pair<std::vector<std::pair<std::string, int>>,
                                     std::vector<std::pair<int, int>>>> {
public:
  void SetUp() override;
  std::pair<int, int> Perform(std::pair<std::string, int>);

protected:
  AVLTree avl_tree_;
  std::vector<std::pair<std::string, int>> input_;
  std::vector<std::pair<int, int>> expected_;
};

// input과 예상되는 output을 각 테스트마다 세팅해주는 함수
void AVLTreeFixture::SetUp() {
  input_ = GetParam().first;
  expected_ = GetParam().second;
}

// test.in 파일과 test.out파일의 값을 각각 vector로 변환하여
// pair<input,output>으로 변환 시키는 함수
static std::pair<std::vector<std::pair<std::string, int>>,
                 std::vector<std::pair<int, int>>>
ReadTestCases(const std::string &filename_input,
              const std::string &filename_output) {

  std::ifstream file_input(filename_input);
  std::ifstream file_output(filename_output);
  std::vector<std::pair<std::string, int>> input;
  std::vector<std::pair<int, int>> expected;

  // 파일의 두 read 권한이 있을 경우 input, output 벡터 생성
  if (file_input.is_open() && file_output.is_open()) {
    int number_of_commmand, value, result_1, result_2;
    std::string command;
    file_input >> number_of_commmand;

    for (int i = 0; i < number_of_commmand; i++) {
      file_input >> command >> value;
      input.emplace_back(command, value);
    }

    for (int i = 0; i < number_of_commmand; i++) {
      file_output >> result_1 >> result_2;
      expected.emplace_back(result_1, result_2);
    }

    file_input.close();
    file_output.close();
  }
  return {input, expected};
}

// test로 들어올 값을 파라미터로 입력 받게 하는 googletest 라이브러리 매크로
INSTANTIATE_TEST_SUITE_P(FileTestCases, AVLTreeFixture,
                         ::testing::Values(ReadTestCases(input_file,
                                                         output_file)));

// AVLTree가 목적에 맞는 기능을 하기 위해 command와 value를 입력 받는 함수
// 이때 반환 값이 1개일 경우 나머지 빈칸은 -1로 표기하였음
std::pair<int, int>
AVLTreeFixture::Perform(std::pair<std::string, int> command_and_value) {
  std::string command = command_and_value.first;
  int value = command_and_value.second;
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

// 모든 함수를 사용하는 통합 테스트를 시행
TEST_P(AVLTreeFixture, TestAllFunction) {
  std::vector<std::pair<int, int>> generate_result;
  std::cout << input_.size() << "\n";
  for (int i = 0; i < input_.size(); i++) {
    generate_result.push_back(Perform(input_[i]));
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
