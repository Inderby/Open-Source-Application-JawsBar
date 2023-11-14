#include "header/AVL_tree.h"
#include <string>
#include <stdio.h>
int main(int argc, char **argv) {
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
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
        avl_tree.Size();
      }
    }
  }
}