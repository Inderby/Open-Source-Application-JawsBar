/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12191572KimYongBin on 2023/12/11.
 */

#include "converter.h"

// tree를 오름차순으로 정렬된 배열로 변환해주는 함수
std::vector<int> Converter::ConvertToArray() {

  std::vector<int> array_to_return;

  // tree가 비어 있지 않다면 1개씩 반복하여 추출해줌
  while (!tree_.Empty()) {
    std::pair<int, int> result_pair_to_extract =
        tree_.Minimum(this->tree_.Root()->key);

    array_to_return.push_back(result_pair_to_extract.first);
    this->tree_.Erase(result_pair_to_extract.first);
  }
  return array_to_return;
}
