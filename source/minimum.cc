/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12161580ParkJiHun on 2023/11/09.
 */

#include <iostream>
#include "../header/AVL_tree.h"

// 최솟값을 구하는 함수 구현
void Minimum(int key_of_sub_root){
  // 노드 포인터 타입 변수인 현재_노드에 엑시스트 함수 리턴 값으로 키에 맞는 노드 대입
  Node* cur_node = Exist(int key_of_sub_root);
  // 널 포인트인지 확인하는 불 타입 변수
  bool null_check = true;
  // 깊이 측정 변수
  int count = 0;
  // 미니멈 노드를 저장할 변수에 일단 현재 노드 저장
  Node* minimum_node = cur_node;
  // 반복문을 통해 왼쪽 자식이 널포인트가 아닐때까지 반복
  while (null_check)
  {
    // 최소_노드 왼쪽 자식이 널포인터라면
    if (minimum_node->left_child == nullptr)
    {
      // 널체크 거짓으로 바꿔서 반복문 종료
      null_check = false;
    // 왼쪽 자식이 널포인터가 아니라면
    } else {
      // 미니멈_노드를 현재 노드 왼쪽 자식으로 변경
      minimum_node = minimum_node->left_child;
      // 카운트 증가
      count++;
    }
  }  // 와일문 끝
  // 미니멈_노드 키 값이랑 뎁스 출력
  std::cout << minimum_node->key << " " << count;
}  // Minimum 함수 끝