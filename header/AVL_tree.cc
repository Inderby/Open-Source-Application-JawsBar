/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12191572KimYongBin on 2023/11/08.
 */

#include "AVL_tree.h"

AVL_Tree::AVL_Tree(int value_to_root) : root_{new Node(value_to_root)} {};

//return tree size
int Size() { return size_; }

//find maximun node in sub_tree that key value is root
void Maximun(int key_of_sub_root){
  //find node in AVL tree 
  Node* sub_root_node = Find(key_of_sub_root);
  Node* max_node = sub_root_node;

  //find maximun node in subtree and maximun node key
  while(max_node->left_child != NULL){
    max_node = max_node->left_child;
  }
  int max_key = max_node->key;

  //find maximun node depth
  int max_node_depth = 0;
  while(max_node->parent != NULL){
    max_node = max_node->parent;
    max_node_depth++;
  }
  
  //print subtree maximun  key, depth
  cout << max_key << " " << max_node_depth << endl;
  return;
}  
