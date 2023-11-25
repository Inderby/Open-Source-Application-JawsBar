/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12191572KimYongBin on 2023/11/25.
 */

#include "AVL_tree.h"

// 노드의 depth와 rank를 공백으로 구분하여 출력하는 함수임. 
std::pair<int, int> AVLTree::Rank(int key_of_rank) {
  Node *node_to_search = root_;
  int depth_of_node = 0;

  // 찾을 노드의 rank를 저장하는 변수임.
  int rank_of_node = 0;

  // root노드부터 rank를 매길 node를 찾아 내려감.
  while (node_to_search != nullptr && node_to_search->key != key_of_rank) {

    // 찾는 과정에서 오른쪽 방향으로 path가 이동하면, 이동하기 이전에
    // 왼쪽 노드를 root로 하는 sub tree의 크기만큼 rank가 올라감.
    if (key_of_rank > node_to_search->key)
      rank_of_node += GetSizeOfSubTree(node_to_search->left_child) + 1;

    node_to_search = (key_of_rank < node_to_search->key)
                         ? node_to_search->left_child
                         : node_to_search->right_child;
    depth_of_node++;
  }
  if (node_to_search == nullptr) {
    if (GetIsPrint()) {
      std::cout << 0 << "\n";
    }
    return {0, 0};
  }

  rank_of_node += GetSizeOfSubTree(node_to_search->left_child);
  if (GetIsPrint()) {
    std::cout << depth_of_node << " " << rank_of_node + 1 << "\n";
  }
  return {depth_of_node, rank_of_node};
}
