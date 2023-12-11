/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12191572KimYongBin on 2023/12/11.
 */

#include "client_interface.h"

// 사용자의 입력에 따라 알맞은 기능을 수행되도록 조종하는 함수
void ClientInterface::SelectMenu() {
  DisplayBoard();
  int value_to_operate = -1;

  while (value_to_operate != 9) {
    std::cout << "(show Menu : 8) -->  select :   ";
    switch (value_to_operate) {
    case 1:
      std::cout << "Key to insert  :  ";
      std::cin >> value_to_operate;
      Insert(value_to_operate);
      break;
    case 2:
      std::cout << "Key to find  :  ";
      std::cin >> value_to_operate;
      Find(value_to_operate);
      break;
    case 3:
      Size();
      break;
    case 4:
      Empty();
      break;
    case 5:
      std::cout << "Key to find maximum  :  ";
      std::cin >> value_to_operate;
      Maximum(value_to_operate);
      break;
    case 6:
      std::cout << "Key to find minimum  :  ";
      std::cin >> value_to_operate;
      Minimum(value_to_operate);
      break;
    case 7:
      PrintHelper();
      break;
    case 8:
      DisplayBoard();
      break;
    case 9:
      return;
    default:
      std::cout << "Wrong entered\n" << std::endl;
    }
  }
}
