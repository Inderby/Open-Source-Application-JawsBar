#
# Copyright OpenSourceApplication-JawsBar.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.
#
# Created by 12191572KimYongBin on 2023/11/14.
#
add_library(AVL_library 
    AVL_tree_reparenting.cc
    AVL_tree_get_size_of_sub_tree.cc
    AVL_tree_rank.cc
    AVL_tree_erase.cc
    AVL_tree_balancing.cc
    AVL_tree_empty.cc
    AVL_tree_exist.cc
    AVL_tree_find.cc
    AVL_tree_get_balance_factor.cc
    AVL_tree_get_height.cc
    AVL_tree_insert.cc
    AVL_tree_internal_insert.cc
    AVL_tree_maximum.cc
    AVL_tree_minimum.cc
    AVL_tree_rotate_left.cc
    AVL_tree_rotate_right.cc
    AVL_tree.cc
)
