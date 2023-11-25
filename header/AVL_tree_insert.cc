/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12191572KimYongBin on 2023/11/09.
 */

#include "AVL_tree.h"

// 인자로 들어온 값을 내부적으로 InternalInsert를 호출해 삽입하고 depth를
// 반환하는 함수임.
int AVLTree::Insert(int value_to_insert) {
  // Tree가 비어 있는 경우 바로 삽입 수행함.
  if (this->size_ == 0) {
    this->root_ = InternalInsert(this->root_, value_to_insert);
    this->root_->size_of_sub_tree++;
    this->size_++;
    if (GetIsPrint()) {
      std::cout << 0 << "\n";
    }
    return 0;
  } else {
    // root의 key값과 동일할 경우 해당 depth인 0을 반환함.
    if (value_to_insert == this->root_->key)
      return 0;

    int depth_of_new_node = 0;
    // 해당 value가 Tree내에 존재하지 않을 경우 수행함.
    if (Exist(value_to_insert) == nullptr) {
      this->root_ = InternalInsert(this->root_, value_to_insert);
      depth_of_new_node = Find(value_to_insert);
      this->size_++;
    }
    return depth_of_new_node;
  }
}
