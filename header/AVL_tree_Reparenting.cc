/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12202973ChoSoYoung on 2023/11/20.
 */

#include "AVL_tree.h"

Node* AVLTree::ReParenting(Node* cur_node, int key_of_erase) {
    // 노드가 존재하지 않으면 0을 출력함.
    if (cur_node == nullptr) {
        return nullptr;
    }

    // 현재 노드의 값이 찾는 값이 아닐 경우 재귀함수를 호출함. 
    if (cur_node->key < key_of_erase) {
        cur_node->right_child = ReParenting(cur_node->right_child, key_of_erase);
    }
    else if (cur_node->key > key_of_erase) {
        cur_node->left_child = ReParenting(cur_node->left_child, key_of_erase);
    }


    // 현재 노드의 값이 찾고자 하는 값일 경우 delete를 실행함.  
    else if (cur_node->key == key_of_erase) {
        // case 1: 자식이 없거나 한 명 있는 경우  
        if (cur_node->left_child == nullptr && cur_node->right_child == nullptr) {
            delete cur_node;
            return nullptr;
        }
        else if (cur_node->left_child == nullptr) {
            Node* new_child = cur_node->right_child;
            delete cur_node;
            return new_child;
        }
        else if (cur_node->right_child == nullptr) {
            Node* new_child = cur_node->left_child;
            delete cur_node;
            return new_child;
        }

        // case 2: 자식이 둘 다 있는 경우에는 오른쪽 서브트리의 최솟값을 찾아
        // 노드의 값을 교환한다음, 재귀함수를 호출함. 
        else {
            Node* min_right_subtree = cur_node->right_child;
            while (min_right_subtree->left_child != NULL) {
                min_right_subtree = min_right_subtree->left_child;
            }

            // 현재 지워야 하는 키값을 서브트리의 최솟값에 위치시킴.
            cur_node->key = min_right_subtree->key;
            min_right_subtree->key = key_of_erase;
            cur_node->right_child = ReParenting(cur_node->right_child, key_of_erase);
        }
    }

    // height 조정함. 
    cur_node->height = std::max(GetHeight(cur_node->left_child),
        GetHeight(cur_node->right_child)) +
        1;
    cur_node->size_of_sub_tree =
      GetSizeOfSubTree(cur_node->left_child) +
      GetSizeOfSubTree(cur_node->right_child) + 1;
    // Balancing 시행함.
    Balancing(cur_node, key_of_erase);

    return cur_node;

}
