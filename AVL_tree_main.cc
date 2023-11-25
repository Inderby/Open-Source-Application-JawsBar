/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12202973ChoSoYoung on 2023/11/26.
 */

#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>

struct Node {
public:
  int key = 0;
  Node *left_child = nullptr;
  Node *right_child = nullptr;
  int height = 1;
  int size_of_sub_tree = 1;
  Node(int value) : key{value} {};
};

class AVLTree {
public:
  AVLTree();
  ~AVLTree(){};
  int Find(int value_to_find);
  int Insert(int value_to_insert);
  int Size() { return size_; }
  int Empty();
  std::pair<int, int> Maximum(int key_of_sub_root);
  std::pair<int, int> Minimum(int key_of_sub_root);
  std::pair<int, int> Rank(int key_of_rank);
  int Erase(int key_of_erase);
  void SetIsPrint(bool flag_of_print) { is_print_ = flag_of_print; };
  bool GetIsPrint() { return is_print_; };

private:
  int GetHeight(Node *node_to_check);
  void Balancing(Node *&node_to_balancing, int value_of_balancing);
  int GetBalanceFactor(Node *node_to_check);
  int GetSizeOfSubTree(Node *root_of_sub_tree);
  Node *Exist(int value_to_search);
  Node *InternalInsert(Node *root_of_sub_tree, int value_to_insert);
  Node *ReParenting(Node *node_to_reParenting, int key_of_erase);
  Node *RotateLeft(Node *node_to_rotate);
  Node *RotateRight(Node *node_to_rotate);
  Node *Root() { return root_; };
  Node *root_;
  int size_;
  bool is_print_ = true;
};

// 생성자 정의
AVLTree::AVLTree() : root_{nullptr}, size_{0}, is_print_{false} {};

// 트리의 균형이 깨졌을 때 우회전을 시행하는 함수임.
Node *AVLTree::RotateRight(Node *node_to_rotate) {
  Node *node = node_to_rotate->left_child;
  node_to_rotate->left_child = node->right_child;
  node->right_child = node_to_rotate;

  // 위치가 바뀌었으므로 높이를 재조정함.
  node_to_rotate->height = std::max(GetHeight(node_to_rotate->left_child),
                                    GetHeight(node_to_rotate->right_child)) +
                           1;
  node_to_rotate->size_of_sub_tree =
      GetSizeOfSubTree(node_to_rotate->left_child) +
      GetSizeOfSubTree(node_to_rotate->right_child) + 1;
  node->height =
      std::max(GetHeight(node->left_child), GetHeight(node->right_child)) + 1;
  node->size_of_sub_tree = GetSizeOfSubTree(node->left_child) +
                           GetSizeOfSubTree(node->right_child) + 1;
  return node;
}

// 트리의 균형이 깨졌을 때 좌회전을 시행하는 함수임.
Node *AVLTree::RotateLeft(Node *node_to_rotate) {
  Node *node = node_to_rotate->right_child;
  node_to_rotate->right_child = node->left_child;
  node->left_child = node_to_rotate;

  // 위치가 바뀌었으므로 높이를 재조정함.
  node_to_rotate->height = std::max(GetHeight(node_to_rotate->left_child),
                                    GetHeight(node_to_rotate->right_child)) +
                           1;
  node_to_rotate->size_of_sub_tree =
      GetSizeOfSubTree(node_to_rotate->left_child) +
      GetSizeOfSubTree(node_to_rotate->right_child) + 1;
  node->height =
      std::max(GetHeight(node->left_child), GetHeight(node->right_child)) + 1;
  node->size_of_sub_tree = GetSizeOfSubTree(node->left_child) +
                           GetSizeOfSubTree(node->right_child) + 1;
  return node;
}

// 노드 삭제 시 부모와 자식관계를 수정하고, balancing을 시행하는 함수임.
Node *AVLTree::ReParenting(Node *cur_node, int key_of_erase) {
  // 노드가 존재하지 않으면 0을 출력함.
  if (cur_node == nullptr) {
    return nullptr;
  }

  // 현재 노드의 값이 찾는 값이 아닐 경우 재귀함수를 호출함.
  if (cur_node->key < key_of_erase) {
    cur_node->right_child = ReParenting(cur_node->right_child, key_of_erase);
  } else if (cur_node->key > key_of_erase) {
    cur_node->left_child = ReParenting(cur_node->left_child, key_of_erase);
  }

  // 현재 노드의 값이 찾고자 하는 값일 경우 delete를 실행함.
  else if (cur_node->key == key_of_erase) {
    // case 1: 자식이 없거나 한 명 있는 경우에는 해당 노드를 삭제하고,
    // 새로운 child를 반환함.
    if (cur_node->left_child == nullptr && cur_node->right_child == nullptr) {
      delete cur_node;
      return nullptr;
    } else if (cur_node->left_child == nullptr) {
      Node *new_child = cur_node->right_child;
      delete cur_node;
      return new_child;
    } else if (cur_node->right_child == nullptr) {
      Node *new_child = cur_node->left_child;
      delete cur_node;
      return new_child;
    }

    // case 2: 자식이 둘 다 있는 경우에는 오른쪽 서브트리의 최솟값을 찾아
    // 노드의 값을 교환한다음, 재귀함수를 호출함.
    else {
      Node *min_right_subtree = cur_node->right_child;
      while (min_right_subtree->left_child != NULL) {
        min_right_subtree = min_right_subtree->left_child;
      }

      // 현재 지워야 하는 키값을 서브트리의 최솟값에 위치시킴.
      cur_node->key = min_right_subtree->key;
      min_right_subtree->key = key_of_erase;
      cur_node->right_child = ReParenting(cur_node->right_child, key_of_erase);
    }
  }

  // height 조정함.
  cur_node->height = std::max(GetHeight(cur_node->left_child),
                              GetHeight(cur_node->right_child)) +
                     1;

  cur_node->size_of_sub_tree = GetSizeOfSubTree(cur_node->left_child) +
                               GetSizeOfSubTree(cur_node->right_child) + 1;

  // Balancing 시행함.
  int balance_factor = GetBalanceFactor(cur_node);

  // case 1(left left) : balance_factor가 -1~1을 벗어난 노드를 기준으로 왼쪽,
  // 왼쪽 노드가 존재하는 경우
  if (balance_factor > 1 && GetBalanceFactor(cur_node->left_child) >= 0) {
    return RotateRight(cur_node);
  }
  // case 2(left right) : balance_factor가 -1~1을 벗어난 노드를 기준으로 왼쪽,
  // 오른쪽 노드가 존재하는 경우
  else if (balance_factor > 1 && GetBalanceFactor(cur_node->left_child) < 0) {
    cur_node->left_child = RotateLeft(cur_node->left_child);
    return RotateRight(cur_node);
  }
  // case 3(right right) : balance_factor가 -1~1을 벗어난 노드를 기준으로
  // 오른쪽, 오른쪽 노드가 존재하는 경우
  else if (balance_factor < -1 &&
           GetBalanceFactor(cur_node->right_child) <= 0) {
    return RotateLeft(cur_node);
  }
  // case 4(right left) : balance_factor가 -1~1을 벗어난 노드를 기준으로
  // 오른쪽, 왼쪽 노드가 존재하는 경우
  else if (balance_factor < -1 && GetBalanceFactor(cur_node->right_child) > 0) {
    cur_node->right_child = RotateRight(cur_node->right_child);
    return RotateLeft(cur_node);
  }

  return cur_node;
}

// 노드의 depth와 rank를 공백으로 구분하여 출력하는 함수임.
std::pair<int, int> AVLTree::Rank(int key_of_rank) {
  Node *node_to_search = root_;
  int depth_of_node = 0;

  // 찾을 노드의 rank를 저장하는 변수임.
  int rank_of_node = 0;

  // root노드부터 rank를 매길 node를 찾아 내려감.
  while (node_to_search != nullptr && node_to_search->key != key_of_rank) {

    // 찾는 과정에서 오른쪽 방향으로 path가 이동하면, 이동하기 이전에
    // 왼쪽 노드를 root로 하는 sub tree의 크기만큼 rank가 올라감.
    if (key_of_rank > node_to_search->key)
      rank_of_node += GetSizeOfSubTree(node_to_search->left_child) + 1;

    node_to_search = (key_of_rank < node_to_search->key)
                         ? node_to_search->left_child
                         : node_to_search->right_child;
    depth_of_node++;
  }
  if (node_to_search == nullptr) {
    if (GetIsPrint()) {
      std::cout << 0 << "\n";
    }
    return {0, 0};
  }

  rank_of_node += GetSizeOfSubTree(node_to_search->left_child);
  if (GetIsPrint()) {
    std::cout << depth_of_node << " " << rank_of_node + 1 << "\n";
  }
  return {depth_of_node, rank_of_node};
}

// key value를 가지는 서브트리의 최솟값을 구하는 함수임.
std::pair<int, int> AVLTree::Minimum(int key_of_sub_root) {
  Node *sub_root_node = Exist(key_of_sub_root);
  bool null_check = true;

  // 미니멈 노드를 저장할 변수에 일단 현재 노드 저장함.
  Node *minimum_node = sub_root_node;

  // 반복문을 통해 왼쪽 자식이 널포인트가 아닐때까지 반복하여 최솟값을 찾음.
  while (null_check) {
    if (minimum_node->left_child == nullptr) {
      null_check = false;
    } else {
      minimum_node = minimum_node->left_child;
    }
  }

  // minimum Node의 key값과 depth값 출력함.
  if (GetIsPrint()) {
    std::cout << minimum_node->key << " ";
  }
  int depth_of_key = Find(minimum_node->key);
  return {minimum_node->key, depth_of_key};
}

// key value가 root인 서브트리의 최댓값을 찾는 함수임.
std::pair<int, int> AVLTree::Maximum(int key_of_sub_root) {
  // key value를 가진 Node를 찾음.
  Node *sub_root_node = Exist(key_of_sub_root);
  Node *max_node = sub_root_node;

  // Node의 오른쪽으로 이동하며 최댓값을 찾음.
  while (max_node->right_child != NULL) {
    max_node = max_node->right_child;
  }

  int max_key = max_node->key;

  // maximum Node의 key와 depth 출력함.
  if (GetIsPrint()) {
    std::cout << max_key << " ";
  }
  int depth_of_key = Find(max_key);
  return {max_key, depth_of_key};
}

// 내부적으로 재귀함수를 사용하여 노드 삽입을 하기위한 함수임.
Node *AVLTree::InternalInsert(Node *root_of_sub_tree, int value_to_insert) {
  // 트리가 비어있을 땐 바로 새로운 노드를 삽입함.
  if (root_of_sub_tree == nullptr) {
    Node *new_node = new Node(value_to_insert);
    root_of_sub_tree = new_node;
    return root_of_sub_tree;
  }

  if (root_of_sub_tree->key <
      value_to_insert) { // item이 key값보다 크다면 오른쪽으로 이동함.
    root_of_sub_tree->right_child =
        InternalInsert(root_of_sub_tree->right_child, value_to_insert);
  } else { // item이 key값보다 작다면 왼쪽으로 이동함.
    root_of_sub_tree->left_child =
        InternalInsert(root_of_sub_tree->left_child, value_to_insert);
  }

  // 새로운 노드가 추가되었으므로, 재귀적으로 부모노드들 높이를 1증가시킴.
  root_of_sub_tree->height =
      std::max(GetHeight(root_of_sub_tree->left_child),
               GetHeight(root_of_sub_tree->right_child)) +
      1;
  root_of_sub_tree->size_of_sub_tree =
      GetSizeOfSubTree(root_of_sub_tree->left_child) +
      GetSizeOfSubTree(root_of_sub_tree->right_child) + 1;
  // Balancing Factor 측정하여 2 이상이면 재조정함.
  Balancing(root_of_sub_tree, value_to_insert);

  return root_of_sub_tree;
}

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

// 인자로 들어온 node를 root로 하는 sub tree의 크기를 반환하는 함수임.
int AVLTree::GetSizeOfSubTree(Node *root_of_sub_tree) {
  if (root_of_sub_tree == nullptr)
    return 0;
  return root_of_sub_tree->size_of_sub_tree;
}

// 노드의 height를 반환하는 함수임.
int AVLTree::GetHeight(Node *node_of_check) {
  if (node_of_check == nullptr)
    return 0;
  else
    return node_of_check->height;
}

// 노드의 왼쪽자식과 오른쪽 자식의 차를 반환하는 함수임.
int AVLTree::GetBalanceFactor(Node *node_to_check) {
  return GetHeight(node_to_check->left_child) -
         GetHeight(node_to_check->right_child);
}

// key값을 가진 Node의 depth를 출력하는 함수임.
int AVLTree::Find(int value_to_find) {
  Node *node_to_search = root_;
  int depth_of_find = 0;

  // key값을 찾거나 없다면 break함.
  while (node_to_search != nullptr && node_to_search->key != value_to_find) {
    node_to_search = (value_to_find < node_to_search->key)
                         ? node_to_search->left_child
                         : node_to_search->right_child;
    depth_of_find++;
  }

  // 찾고자 하는 노드를 찾지 못하면 0을 반환함.
  if (node_to_search == nullptr) {
    if (GetIsPrint()) {
      std::cout << 0 << "\n";
    }
    return 0;
  }

  if (GetIsPrint()) {
    std::cout << depth_of_find << "\n";
  }
  return depth_of_find;
}

// AVL Tree에 key value을 가진 노드를 가리키는 포인터를 반환하는 함수임.
Node *AVLTree::Exist(int value_to_find) {
  Node *node_to_search = root_;
  // key값을 찾거나 없다면 break함.
  while (node_to_search != nullptr && node_to_search->key != value_to_find) {
    node_to_search = (value_to_find < node_to_search->key)
                         ? node_to_search->left_child
                         : node_to_search->right_child;
  }

  return node_to_search;
}

// 해당 key를 가진 노드의 depth를 출력한 후 삭제하고,
// 해당 key를 가진 노드가 없을 경우 0을 출력하는 함수임.
int AVLTree::Erase(int key_of_erase) {
  Node *del_node = Exist(key_of_erase);

  // node가 없을 경우 0을 출력함.
  if (del_node == nullptr) {
    if (GetIsPrint()) {
      std::cout << 0 << "\n";
    }
    return 0;
  } else {
    // node가 존재할 경우에는 depth를 출력하고 삭제를 진행함.
    this->size_--;
    int value_to_return = Find(key_of_erase);
    this->root_ = ReParenting(this->root_, key_of_erase);
    return value_to_return;
  }
}

// AVL Tree가 empty하면 1, 아니면 0을 반환하는 함수임.
int AVLTree::Empty() {
  // 사이즈가 0이면 1 반환, 0이 아니고 양수면 0 반환, 음수면 에러를 반환함.
  if (Size() == 0) {
    if (GetIsPrint()) {
      std::cout << 1 << "\n";
    }
    return 1;
  } else {
    if (GetIsPrint()) {
      std::cout << 0 << "\n";
    }
    return 0;
  }
}

// 해당 노드를 기점으로 균형을 재조정을 시행하는 함수임.
void AVLTree::Balancing(Node *&node_to_balancing, int value_of_balancing) {
  {

    int balance_factor = GetBalanceFactor(node_to_balancing);

    // case 1(left left) : balance_factor가 -1~1을 벗어난 노드를 기준으로 왼쪽,
    // 왼쪽 노드가 존재하는 경우
    if (balance_factor > 1 &&
        value_of_balancing < node_to_balancing->left_child->key) {
      node_to_balancing = RotateRight(node_to_balancing);
    }
    // case 2(left right) : balance_factor가 -1~1을 벗어난 노드를 기준으로 왼쪽,
    // 오른쪽 노드가 존재하는 경우
    else if (balance_factor > 1 &&
             value_of_balancing > node_to_balancing->left_child->key) {
      node_to_balancing->left_child = RotateLeft(node_to_balancing->left_child);
      node_to_balancing = RotateRight(node_to_balancing);
    }
    // case 3(right right) : balance_factor가 -1~1을 벗어난 노드를 기준으로
    // 오른쪽, 오른쪽 노드가 존재하는 경우
    else if (balance_factor < -1 &&
             value_of_balancing > node_to_balancing->right_child->key) {
      node_to_balancing = RotateLeft(node_to_balancing);
    }
    // case 4(right left) : balance_factor가 -1~1을 벗어난 노드를 기준으로
    // 오른쪽, 왼쪽 노드가 존재하는 경우
    else if (balance_factor < -1 &&
             value_of_balancing < node_to_balancing->right_child->key) {
      node_to_balancing->right_child =
          RotateRight(node_to_balancing->right_child);
      node_to_balancing = RotateLeft(node_to_balancing);
    }
  }
}

int main(int argc, char **argv) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int test_case_count = 0;
  std::cin >> test_case_count;

  while (test_case_count--) {
    AVLTree avl_tree = AVLTree();
    avl_tree.SetIsPrint(true);
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
      } else if (command == "rank") {
        std::cin >> value;
        avl_tree.Rank(value);
      } else if (command == "erase") {
        std::cin >> value;
        avl_tree.Erase(value);
      } else { // command == "size"
        std::cout << avl_tree.Size() << "\n";
      }
    }
  }
}