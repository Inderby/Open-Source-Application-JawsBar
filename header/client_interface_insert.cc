/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12191572KimYongBin on 2023/12/11.
 */

#include "client_interface.h"

// 삽입 성공 여부를 출력해주는 함수
int ClientInterface::Insert(int value_to_insert) {
  if (tree_->Find(value_to_insert)) {
    std::cout << value_to_insert << " is already exists !\n";
    return;
  }
  std::cout << "Success to insert!" << std::endl;
  return tree_->Insert(value_to_insert);
}
