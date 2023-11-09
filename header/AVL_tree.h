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

#include "Node.h"
#include <algorithm>

class AVL_Tree
{
public:
    AVL_Tree(int value_to_root);
    int Find(int value_to_find);
    int Insert(int value_to_insert);
    int Size();
    int Empty();
    void Maximum(int key_of_sub_root);
    void Minimum(int key_of_sub_root);
    void Rank(int key_of_rank);
    void Erase(int key_of_erase);

private:
    int GetHeight(Node *node_to_check);
    void Balancing(Node *node_to_balancing);
    void ReParenting(Node *node_to_reParenting);
    int GetBalanceFactor(Node *node_to_check);
    Node *InternalInsert(Node *root_of_sub_tree, int value_to_insert);
    Node *RotateLeft(Node *node_to_rotate);
    Node *RotateRight(Node *node_to_rotate);
    Node *root_;
    int size_;
};

#endif // OPENSOURCEAPPLICATION_HEADER_AVLTREE_H_
