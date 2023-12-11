/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12191572KimYongBin on 2023/12/11.
 */

#include "client_interface.h"

// Rank를 수행 후 사용자에게 출력해주는 함수
std::pair<int, int> ClientInterface::Rank(int value_to_operate) {
  std::pair<int, int> result_to_print = tree_->Rank(value_to_operate);
  if (result_to_print.second == -1) {
    std::cout << "Not exist value!" << std::endl;
    return;
  }
  std::cout << "Rank : " << result_to_print.second
            << ", depth : " << result_to_print.first << std::endl;
  return result_to_print;
}
