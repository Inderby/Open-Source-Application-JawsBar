/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12191572KimYongBin on 2023/11/09.
 */

#include "AVL_tree.h"

// 노드의 height를 반환하는 함수임.
int AVLTree::GetHeight(Node *node_of_check) {
  if (node_of_check == nullptr)
    return 0;
  else
    return node_of_check->height;
}