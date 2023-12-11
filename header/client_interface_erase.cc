/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12191572KimYongBin on 2023/12/11.
 */

#include "client_interface.h"

// 삭제 수행을 출력해주는 함수
int ClientInterface::Erase(int value_to_operate) {
  int result_to_print = tree_->Erase(value_to_operate);
  if (result_to_print == 0 && tree_->Root()->key == value_to_operate) {
    std::cout << "Erase! depth : " << result_to_print << std::endl;
    return;
  } else if (result_to_print == 0) {
    std::cout << "Fail to erase!" << std::endl;
    return;
  }
  std::cout << "Erase! depth : " << result_to_print << std::endl;

  return result_to_print;
}
