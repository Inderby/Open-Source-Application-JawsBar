/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12191572KimYongBin on 2023/11/09.
 */

#include "AVL_tree.h"

// key값을 가진 Node의 depth를 출력하는 함수임.
int AVLTree::Find(int value_to_find) {
  Node *node_to_search = root_;
  int depth_of_find = 0;

  // key값을 찾거나 없다면 break함.
  while (node_to_search != nullptr && node_to_search->key != value_to_find) {
    node_to_search = (value_to_find < node_to_search->key)
                         ? node_to_search->left_child
                         : node_to_search->right_child;
    depth_of_find++;
  }

  // 찾고자 하는 노드를 찾지 못하면 0을 반환함.
  if (node_to_search == nullptr) {
    std::cout << 0 << "\n";
    return 0;
  }

  std::cout << depth_of_find << "\n";
  return depth_of_find;
}
