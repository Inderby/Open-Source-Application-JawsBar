/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12191572KimYongBin on 2023/11/25.
 */

#include "AVL_tree.h"

// 인자로 들어온 node를 root로 하는 sub tree의 크기를 반환하는 함수
int AVLTree::GetSizeOfSubTree(Node *root_of_sub_tree) {
  if (root_of_sub_tree == nullptr)
    return 0;
  return root_of_sub_tree->size_of_sub_tree;
}