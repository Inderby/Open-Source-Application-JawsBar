/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12202973ChoSoYoung on 2023/11/17.
 */

#include "AVL_tree.h"

void AVLTree::Erase(int key_of_erase) {
    Node* del_node = Exist(key_of_erase);

    //node가 없을 경우 0을 출력함.
    if (del_node == nullptr) {
        std::cout << 0 << "\n";
        return;
    }
    else {
        //node가 존재할 경우에는 depth를 출력하고 삭제를 진행함. 
        Find(key_of_erase);
        this->root_ = ReParenting(this->root_, key_of_erase);
        return;
    }
    
}
