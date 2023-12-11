/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12191572KimYongBin on 2023/12/11.
 */

#ifndef OPENSOURCEAPPLICATION_HEADER_SET_H_
#define OPENSOURCEAPPLICATION_HEADER_SET_H_

#include "node.h"
#include <iostream>

class Set {
public:
  virtual int Find(int value_to_find);
  virtual int Insert(int value_to_insert);
  virtual int Size();
  virtual int Empty();
  virtual std::pair<int, int> Maximum(int key_of_sub_root);
  virtual std::pair<int, int> Minimum(int key_of_sub_root);
  virtual std::pair<int, int> Rank(int key_of_rank);
  virtual int Erase(int key_of_erase);
  virtual Node *Root();
};

#endif // OPENSOURCEAPPLICATION_HEADER_Set_H_
