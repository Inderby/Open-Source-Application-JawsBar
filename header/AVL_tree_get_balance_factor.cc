/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12191572KimYongBin on 2023/11/09.
 */

#include "AVL_tree.h"

// 노드의 왼쪽자식과 오른쪽 자식의 차를 반환하는 함수임.
int AVLTree::GetBalanceFactor(Node *node_to_check) {
  return GetHeight(node_to_check->left_child) -
         GetHeight(node_to_check->right_child);
}
