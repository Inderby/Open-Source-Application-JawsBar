/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12191572KimYongBin on 2023/12/11.
 */

#include "client_interface.h"

// 중위 순회를 하며 key를 출력해주는 함수
void ClientInterface::InOrderHelper(Node *node_to_travel) {
  if (node_to_travel == nullptr)
    return;
  InOrderHelper(node_to_travel->left_child);
  std::cout << node_to_travel->key << " ";
  InOrderHelper(node_to_travel->right_child);
}
