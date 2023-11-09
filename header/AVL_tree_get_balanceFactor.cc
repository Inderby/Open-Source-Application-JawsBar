/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12191572KimYongBin on 2023/11/09.
 */

#include "AVL_tree.h"
/*인자로 들어온 노드에 양쪽 자식의 높이 차이를 반환해주는 기능*/
int AVL_Tree::GetBalanceFactor(Node *node_to_check)
{
  return GetHeight(node_to_check->left_child) - GetHeight(node_to_check->right_child);
}
