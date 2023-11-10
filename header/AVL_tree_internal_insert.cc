/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12191572KimYongBin on 2023/11/09.
 */

#include "AVL_tree.h"

/*내부적으로 재귀함수를 사용하여 노드 삽입을 하기위한 함수*/
Node* AVL_Tree::InternalInsert(Node* root_of_sub_tree, int value_to_insert)
{
  /*트리가 비어있을 땐 바로 새로운 노드 삽입*/
  if (root_of_sub_tree == nullptr)
  {
    Node* new_node = new Node(value_to_insert);

    root_of_sub_tree = new_node;
    return root_of_sub_tree;
  }
  else if (root_of_sub_tree->key < value_to_insert)
  { /*item이 key값보다 크다면 오른쪽으로 이동*/
    root_of_sub_tree->right_child = InternalInsert(root_of_sub_tree->right_child, value_to_insert);
  }
  else
  { /* item이 key값보다 작다면 왼쪽으로 이동*/
    root_of_sub_tree->left_child = InternalInsert(root_of_sub_tree->left_child, value_to_insert);
  }
  root_of_sub_tree->height = std::max(
    GetHeight(root_of_sub_tree->left_child),
    GetHeight(root_of_sub_tree->right_child)
  ) + 1;
  Balancing(root_of_sub_tree); /* 새로운 노드가 추가되었으므로 재귀적으로 부모노드들 높이 1증가 시켜주고
                                  Balace Factor 측정하여 2이상이라면 재조정함수 */
  return root_of_sub_tree;
}