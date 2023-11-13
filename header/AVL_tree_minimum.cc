/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12161580ParkJiHun on 2023/11/09.
 */

#include "AVL_tree.h"

// key value를 가지는 서브트리의 최솟값을 구하는 함수임.
void AVLTree::Minimum(int key_of_sub_root){
  Node* cur_node = Root();

  // 반복문을 통해 루트부터 시작해 서브 루트를 찾아가는 이진 탐색 알고리즘임.
  while (cur_node->key != key_of_sub_root)
  {
    // 현재 노드 키 값보다 서브 루트 키 값이 작은 경우 현재노드를 왼쪽 자식으로 변경함.
    if (cur_node->key > key_of_sub_root)
    {
      cur_node = cur_node->left_child;
    }
    // 현재 노드 키 값보다 서브 루트 키 값이 큰 경우 현재노드를 오른쪽 자식으로 변경함. 
    else {
      cur_node = cur_node->right_child;
    }
  }  
  
  bool null_check = true;
  int node_depth = 0;
  // 미니멈 노드를 저장할 변수에 일단 현재 노드 저장함.
  Node* minimum_node = cur_node;
  // 반복문을 통해 왼쪽 자식이 널포인트가 아닐때까지 반복하여 최솟값을 찾음.
  while (null_check)
  {
    if (minimum_node->left_child == nullptr)
    {
      null_check = false;
    } 
    else {
      minimum_node = minimum_node->left_child;
      node_depth++;
    }
  }  

  // minimum Node의 key값과 depth값 출력함. 
  std::cout << minimum_node->key << " " << node_depth << "\n";
}  
