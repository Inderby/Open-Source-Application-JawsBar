/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12191572KimYongBin on 2023/12/11.
 */

#ifndef OPENSOURCEAPPLICATION_HEADER_CONVERTER_H_
#define OPENSOURCEAPPLICATION_HEADER_CONVERTER_H_

#include "AVL_tree.h"
#include <vector>

class Converter {
public:
  Converter(AVLTree tree);
  std::vector<int> ConvertToArray();
  AVLTree ConvertToTree(std::vector<int> array);
private:
  AVLTree tree_;
};

#endif // OPENSOURCEAPPLICATION_HEADER_CONVERTER_H_
