/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12191572KimYongBin on 2023/12/11.
 */

#include "client_interface.h"

// 비어 있다는 것을 출력해주는 함수
int ClientInterface::Empty() {

  if (tree_->Size()) {
    std::cout << "No empty! " << std::endl;
    return 0;
  } else {
    std::cout << "Empty!" << std::endl;
    return 1;
  }
}
