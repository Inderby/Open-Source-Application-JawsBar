/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12191572KimYongBin on 2023/11/09.
 */

#include "AVL_tree.h"

/*트리의 균형이 깨졌을 때 우회전을 시행하는 함수*/
Node *AVL_Tree::RotateRight(Node *node_to_rotate)
{
  Node *node = node_to_rotate->left_child;
  node_to_rotate->left_child = node->right_child;
  node->right_child = node_to_rotate;

  // 위치가 바뀌었으므로 높이 재조정
  node_to_rotate->height = std::max(
    GetHeight(node_to_rotate->left_child), 
    GetHeight(node_to_rotate->right_child)) + 1;
    
  node->height = std::max(
    GetHeight(node->left_child),
    GetHeight(node->right_child)) + 1;

  return node;
}