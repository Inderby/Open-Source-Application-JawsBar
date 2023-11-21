/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12161580ParkJiHun on 2023/11/20.
 */

#include "AVL_tree.h"

std::pair<int, int> AVLTree::Rank(int key_of_rank){
  Node *cur_node = Exist(key_of_rank);
  // rank 저장 변수 선언, 자기 자신을 포함하니 1로 초기화.
  int rank = 1;
  // 우선 자기 왼쪽 서브트리 노드수 전부 더함
  rank += cur_node->left_child->children_n_me;
  cur_node = cur_node->parent;

  // 루트까지 올라가면서 만난 부모 노드의 키가 자기보다 크면 1만 증가, 자기보다 작으면 왼쪽 자식노드들 총 개수를 더함.
  while (cur_node != nullptr){
    if (cur_node->key < key_of_rank) {
      rank += cur_node->left_child->children_n_me + 1;
    } else { rank++; }
    cur_node = cur_node->parent;
  }

  // Node의 depth와 rank를 출력함.
  SetIsPrint(false);
  int depth_of_key = Find(key_of_rank);
  SetIsPrint(true);
  if (GetIsPrint()) {
    std::cout << depth_of_key << " " << rank << "\n";
  }
  
  return {depth_of_key, rank};
}
