/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12202973ChoSoYoung  on 2023/11/09.
 */

#include "AVL_tree.h"

#include <iostream>

//find maximum node in sub_tree that key value is root
void AVL_Tree::Maximum(int key_of_sub_root){
  //find node in AVL tree 
  Node* sub_root_node = Exist(key_of_sub_root);
  Node* max_node = sub_root_node;

  //find maximum node in subtree and maximum node key
  while(max_node->right_child != NULL){
    max_node = max_node->right_child;
  }
  int max_key = max_node->key;

  //find maximum node depth
  int max_node_depth = 0;
  while(max_node->parent != NULL){
    max_node = max_node->parent;
    max_node_depth++;
  }

  //print subtree maximum  key, depth
  std::cout << max_key << " " << max_node_depth << "\n";
  return;
}
