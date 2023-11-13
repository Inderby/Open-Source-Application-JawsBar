/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12191572KimYongBin on 2023/11/09.
 */

#include "AVL_tree.h"

Node *AVLTree::Exist(int value_to_find)
{
  Node *node_to_search = root_;
  /*key값을 찾거나 없다면 break*/
  while (node_to_search != nullptr && node_to_search->key != value_to_find)
  {
    node_to_search = (value_to_find < node_to_search->key) ? 
      node_to_search->left_child : node_to_search->right_child;
  }

  return node_to_search;
}