/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12161580ParkJiHun on 2023/11/09.
 */

#include "AVL_tree.h"

// 노드의 children_n_me를 업데이트하는 함수임.
void AVLTree::Children(Node *node_to_update) {
  // 부모 노드가 널포인터일 경우 그대로 종료함.
  if (node_to_update == nullptr)
    return;
  // 부모 노드가 존재한다면 부모 노드를 계속 호출하면서 칠드런 1 증가함.
  if (node_to_update->parent != nullptr) {
    Children(node_to_update->parent);
  } else {
    node_to_update->children_n_me++;
  }
}
