/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12191572KimYongBin on 2023/11/08.
 */

#ifndef OPENSOURCEAPPLICATION_HEADER_AVLTREE_H_
#define OPENSOURCEAPPLICATION_HEADER_AVLTREE_H_

#include "node.h"
#include <algorithm>
#include <iostream>

class AVLTree {
public:
  AVLTree();
  ~AVLTree(){};
  int Find(int value_to_find);
  int Insert(int value_to_insert);
  int Size() { return size_; }
  int Empty();
  std::pair<int, int> Maximum(int key_of_sub_root);
  std::pair<int, int> Minimum(int key_of_sub_root);
  void Rank(int key_of_rank);
  void Erase(int key_of_erase);
  void SetIsPrint(bool flag_of_print) { is_print_ = flag_of_print; };
  bool GetIsPrint() { return is_print_; };

private:
  int GetHeight(Node *node_to_check);
  void Balancing(Node *&node_to_balancing, int value_of_balancing);
  void ReParenting(Node *node_to_reParenting);
  void Children(Node *node_to_update);
  int GetBalanceFactor(Node *node_to_check);
  Node *Exist(int value_to_search);
  Node *InternalInsert(Node *root_of_sub_tree, int value_to_insert);
  Node *RotateLeft(Node *node_to_rotate);
  Node *RotateRight(Node *node_to_rotate);
  Node *Root() { return root_; };
  Node *root_;
  int size_;
  bool is_print_;
};

#endif // OPENSOURCEAPPLICATION_HEADER_AVLTREE_H_
