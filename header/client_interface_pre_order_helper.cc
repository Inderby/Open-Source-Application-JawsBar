/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12191572KimYongBin on 2023/12/11.
 */

#include "client_interface.h"

// 전위 순회 방식으로 key 값을 출력해주는 함수
void ClientInterface::PreOrderHelper(Node *node_to_travel) {
  if (node_to_travel == nullptr)
    return;
  std::cout << node_to_travel->key << " ";
  PreOrderHelper(node_to_travel->left_child);
  PreOrderHelper(node_to_travel->right_child);
}
