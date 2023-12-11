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
#include "set.h"
#include <algorithm>
#include <iostream>

class AVLTree : public Set {
public:
  AVLTree();
  ~AVLTree(){};
  int Find(int value_to_find);
  int Insert(int value_to_insert);
  int Size() { return size_; }
  int Empty();
  std::pair<int, int> Maximum(int key_of_sub_root);
  std::pair<int, int> Minimum(int key_of_sub_root);
  std::pair<int, int> Rank(int key_of_rank);
  int Erase(int key_of_erase);
  void SetIsPrint(bool flag_of_print) { is_print_ = flag_of_print; };
  bool GetIsPrint() { return is_print_; };
  Node *Root() { return root_; };

private:
  int GetHeight(Node *node_to_check);
  void Balancing(Node *&node_to_balancing, int value_of_balancing);
  int GetBalanceFactor(Node *node_to_check);
  int GetSizeOfSubTree(Node *root_of_sub_tree);
  Node *Exist(int value_to_search);
  Node *InternalInsert(Node *root_of_sub_tree, int value_to_insert);
  Node *ReParenting(Node *node_to_reParenting, int key_of_erase);
  Node *RotateLeft(Node *node_to_rotate);
  Node *RotateRight(Node *node_to_rotate);
  Node *root_;
  int size_;
  bool is_print_;
};

#endif // OPENSOURCEAPPLICATION_HEADER_AVLTREE_H_
