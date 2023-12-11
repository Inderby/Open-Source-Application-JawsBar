/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12191572KimYongBin on 2023/12/11.
 */

#include "client_interface.h"

// 사용자가 찾는 key의 깊이를 알려주는 함수
int ClientInterface::Find(int value_to_find) {
  int return_value = tree_->Find(value_to_find);
  if (return_value) {
    std::cout << "find! depth is : " << return_value;
  } else {
    std::cout << "no exist!";
  }
  std::cout << "\n";
  return return_value;
}
