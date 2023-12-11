/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12191572KimYongBin on 2023/12/11.
 */

#include "client_interface.h"

// 사용자에게 사용할 기능을 출력해주는 함수
void ClientInterface::DisplayBoard() {
  std::cout << "         ** AVL Tree **     " << std::endl;
  std::cout << "                            " << std::endl;
  std::cout << "              Menu          " << std::endl;
  std::cout << "          1. Insert Key     " << std::endl;
  std::cout << "          2. Find Key       " << std::endl;
  std::cout << "          3. Show Size      " << std::endl;
  std::cout << "          4. Check Empty    " << std::endl;
  std::cout << "          5. Find Maximum   " << std::endl;
  std::cout << "          6. Find Minimum   " << std::endl;
  std::cout << "          7. Display Tree   " << std::endl;
  std::cout << "          8. Display Menu   " << std::endl;
  std::cout << "          9. Exit           " << std::endl;

  std::cout << std::endl;
}
