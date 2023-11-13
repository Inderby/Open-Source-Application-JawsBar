/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12202973ChoSoYoung  on 2023/11/09.
 */

#include "AVL_tree.h"

//key value가 root인 서브트리의 최댓값을 찾는 함수임. 
void AVLTree::Maximum(int key_of_sub_root){
  //key value를 가진 Node를 찾음. 
  Node* sub_root_node = Exist(key_of_sub_root);
  Node* max_node = sub_root_node;

  //Node의 오른쪽으로 이동하며 최댓값을 찾음.
  while(max_node->right_child != NULL){
    max_node = max_node->right_child;
  }

  int max_key = max_node->key;
  int max_node_depth = Find(max_key);

  //maximum Node의 key와 depth 출력함.
  std::cout << max_key << " " << max_node_depth << "\n";
  return;
}
