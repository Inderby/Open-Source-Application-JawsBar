/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12191572KimYongBin on 2023/11/09.
 */

#include "AVL_tree.h"

/*해당 노드를 기점으로 균형을 재조정을 시행하는 함수이다*/
void AVLTree::Balancing(Node *node_to_balancing)
{
  {
    int value_of_node = node_to_balancing->key;
    int balance_factor = GetBalanceFactor(node_to_balancing);

    // case 1 (left left) : balance_factor가 -1~1을 벗어난 노드를 기준으로 왼쪽, 왼쪽 노드가 존재하는 경우
    if (balance_factor > 1 && value_of_node < node_to_balancing->left_child->key)
    {
      node_to_balancing = RotateRight(node_to_balancing);
    }
    // case 2 (left right) : balance_factor가 -1~1을 벗어난 노드를 기준으로 왼쪽, 오른쪽 노드가 존재하는 경우
    else if (balance_factor > 1 && value_of_node > node_to_balancing->left_child->key)
    {
      node_to_balancing->left_child = RotateLeft(node_to_balancing->left_child);
      node_to_balancing = RotateRight(node_to_balancing);
    }
    // case 3 (right right) : balance_factor가 -1~1을 벗어난 노드를 기준으로 오른쪽, 오른쪽 노드가 존재하는 경우
    else if (balance_factor < -1 && value_of_node > node_to_balancing->right_child->key)
    {
      node_to_balancing = RotateLeft(node_to_balancing);
    }
    // case 4 ( right left) : balance_factor가 -1~1을 벗어난 노드를 기준으로 오른쪽, 왼쪽 노드가 존재하는 경우
    else if (balance_factor < -1 && value_of_node < node_to_balancing->right_child->key)
    {
      node_to_balancing->right_child = RotateRight(node_to_balancing->right_child);
      node_to_balancing = RotateLeft(node_to_balancing);
    }
  }
}
