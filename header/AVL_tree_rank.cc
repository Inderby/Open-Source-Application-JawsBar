/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12191572KimYongBin on 2023/11/25.
 */

#include "AVL_tree.h"

std::pair<int, int> AVLTree::Rank(int key_of_rank) {
  Node *node_to_search = root_;
  // key값을 찾거나 없다면 break함.
  Node *parent_node_of_node_to_search = nullptr;
  int depth_of_node = 0;
  int rank_of_node = 0;
  while (node_to_search != nullptr && node_to_search->key != key_of_rank) {
    parent_node_of_node_to_search = node_to_search;
    if (key_of_rank > node_to_search->key) {
      rank_of_node += GetSizeOfSubTree(node_to_search->left_child) + 1;
    }
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

  if (GetIsPrint()) {
    std::cout << depth_of_node << " " << rank_of_node + 1 << "\n";
  }
  return {depth_of_node, rank_of_node};
}
