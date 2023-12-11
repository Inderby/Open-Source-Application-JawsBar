/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12191572KimYongBin on 2023/12/11.
 */

#include "converter.h"

// 배열을 인자로 받아 AVL Tree로 변환해주는 함수
AVLTree Converter::ConvertToTree(std::vector<int> array_to_convert) {
  AVLTree tree_to_return = AVLTree();

  for (int i = 0; i < array_to_convert.size(); i++)
    tree_to_return.Insert(array_to_convert[i]);
  return tree_to_return;
}
