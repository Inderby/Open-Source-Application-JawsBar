/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12161580ParkJiHun on 2023/11/09.
 */

#include "AVL_tree.h"

// key value를 가지는 서브트리의 최솟값을 구하는 함수임.
std::pair<int, int> AVLTree::Minimum(int key_of_sub_root) {
  Node *sub_root_node = Exist(key_of_sub_root);
  bool null_check = true;
  int node_depth = 0;

  // 미니멈 노드를 저장할 변수에 일단 현재 노드 저장함.
  Node *minimum_node = sub_root_node;

  // 반복문을 통해 왼쪽 자식이 널포인트가 아닐때까지 반복하여 최솟값을 찾음.
  while (null_check) {
    if (minimum_node->left_child == nullptr) {
      null_check = false;
    } else {
      minimum_node = minimum_node->left_child;
      node_depth++;
    }
  }

  // minimum Node의 key값과 depth값 출력함.
  std::cout << minimum_node->key << " ";
  int depth_of_key = Find(minimum_node->key);
  return {minimum_node->key, depth_of_key};
}
