/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12161580ParkJiHun on 2023/11/09.
 */

#include "../header/AVL_tree.h"

// 엠프티 함수 선언문
int Empty(){
  // 사이즈가 0이면 1 반환, 0이 아니고 양수면 0 반환, 음수면 에러 반환
  if(Size() == 0){
    return 1;
  } else if(Size() > 0){
    return 0;
  } else {
    return -1;
  }
}  // 함수 선언 끝
