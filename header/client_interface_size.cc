/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12191572KimYongBin on 2023/12/11.
 */

#include "client_interface.h"

// 사용자에게 tree의 크기를 출력해주는 함수
int ClientInterface::Size() {
  std::cout << "Current tree is " << tree_->Size() << "\n";
  return tree_->Size();
}
