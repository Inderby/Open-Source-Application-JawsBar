/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12191572KimYongBin on 2023/12/11.
 */

#ifndef OPENSOURCEAPPLICATION_HEADER_CLIENT_INTERFACE_H_
#define OPENSOURCEAPPLICATION_HEADER_CLIENT_INTERFACE_H_

#include "AVL_tree.h"
#include "node.h"
#include "set.h"
#include <iostream>

class ClientInterface : public Set {
public:
  ClientInterface(AVLTree *tree);
  void SelectMenu();

private:
  void DisplayBoard();
  int Find(int value_to_find);
  int Insert(int value_to_insert);
  int Size();
  int Empty();
  std::pair<int, int> Maximum(int key_of_sub_root);
  std::pair<int, int> Minimum(int key_of_sub_root);
  std::pair<int, int> Rank(int key_of_rank);
  int Erase(int key_of_erase);
  void PrintHelper();
  void PreOrderHelper(Node *node_to_travel);
  void PostOrderHelper(Node *node_to_travel);
  void InOrderHelper(Node *node_to_travel);

  AVLTree *tree_;
};

#endif // OPENSOURCEAPPLICATION_HEADER_CLIENT_INTERFACE_H_
