/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12191572KimYongBin on 2023/12/11.
 */

#include "client_interface.h"

// Minimum 노드를 찾은 후 출력해주는 함수
std::pair<int, int> ClientInterface::Minimum(int value_to_operate) {
  if (tree_->Find(value_to_operate) == 0) {
    std::cout << "Not exist value!" << std::endl;
    return;
  }
  std::pair<int, int> result_to_print = tree_->Minimum(value_to_operate);
  std::cout << "Min key value is : " << result_to_print.first
            << ", depth is : " << result_to_print.second << std::endl;
  return result_to_print;
}
