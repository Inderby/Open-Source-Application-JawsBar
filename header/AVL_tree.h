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

class AVL_Tree
{
public:
    AVL_Tree(int value_to_root);
    int find(int value_to_find);
    int insert(int value_to_insert);
    int size();
    int empty();
    void maximum(int key_of_sub_root);
    void minimum(int key_of_sub_root);
    void rank(int key_of_rank);
    void erase(int key_of_erase);

private:
    int getHeight(int key_of_node);
    void balancing(Node *node_to_balancing);
    void reParenting(Node *node_to_reParenting);
    int getBalanceFactor(Node *node_to_check);
    Node *rotateLeft(Node *node_to_rotate);
    Node *rotateRight(Node *node_to_rotate);
    Node *root_;
};

#endif // OPENSOURCEAPPLICATION_HEADER_AVLTREE_H_
