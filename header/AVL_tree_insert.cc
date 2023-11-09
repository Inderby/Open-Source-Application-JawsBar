/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12191572KimYongBin on 2023/11/09.
 */

#include "AVL_tree.h"

int AVL_Tree::Insert(int value_to_insert)
{
  if(this->size_ == 0){
    this->root_ = InternalInsert(this->root_, value_to_insert);
      return 0;
  }
  else{
    if(value_to_insert == this->root_->key)
      return 0;

    int depth_of_new_node = 0;
    if((depth_of_new_node =Find(value_to_insert)) == 0){
      this->root_ = InternalInsert(this->root_, value_to_insert);
      depth_of_new_node = Find(value_to_insert);
    }
    return depth_of_new_node;
  }

}
