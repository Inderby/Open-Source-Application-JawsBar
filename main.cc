/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12191572KimYongBin on 2023/11/14.
 */
#include "header/AVL_tree.h"
#include <stdio.h>
#include <string>
int main(int argc, char **argv) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int test_case_count = 0;
  std::cin >> test_case_count;

  while (test_case_count--) {
    AVLTree avl_tree = AVLTree();
    int question_cnt = 0;

    std::cin >> question_cnt;
    for (int i = 0; i < question_cnt; i++) {
      std::string command = "";
      int value = 0;

      std::cin >> command;

      if (command == "insert") {
        std::cin >> value;
        avl_tree.Insert(value);
      } else if (command == "find") {
        std::cin >> value;
        avl_tree.Find(value);
      } else if (command == "minimum") {
        std::cin >> value;
        avl_tree.Minimum(value);
      } else if (command == "maximum") {
        std::cin >> value;
        avl_tree.Maximum(value);
      } else if (command == "empty") {
        avl_tree.Empty();
      } else { // command == "size"
        std::cout << avl_tree.Size() << "\n";
      }
    }
  }
}
