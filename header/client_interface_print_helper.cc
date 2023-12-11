/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12191572KimYongBin on 2023/12/11.
 */

#include "client_interface.h"

// 순회 방식을 사용자에게 알려주고 선택하게 하는 함수
void ClientInterface::PrintHelper() {
  std::cout << "         ** Print Menu **   " << std::endl;
  std::cout << "                            " << std::endl;
  std::cout << "              Menu          " << std::endl;
  std::cout << "          1. PreOrder       " << std::endl;
  std::cout << "          2. InOrder        " << std::endl;
  std::cout << "          3. PostOrder      " << std::endl;
  int option_to_travel = -1;
  std::cin >> option_to_travel;
  switch (option_to_travel) {
  case 1:
    PreOrderHelper(tree_->Root());
    std::cout << std::endl;
    break;
  case 2:
    InOrderHelper(tree_->Root());
    std::cout << std::endl;
    break;
  case 3:
    PostOrderHelper(tree_->Root());
    std::cout << std::endl;
    break;
  case 4:
    return;
  default:
    std::cout << " !!! Wrong enter !!!\n" << std::endl;
    break;
  }
}
