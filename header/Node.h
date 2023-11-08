/**
 * Copyright OpenSourceApplication-JawsBar.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * Created by 12191572KimYongBin on 2023/11/08.
 */

#ifndef OPENSOURCEAPPLICATION_HEADER_NODE_H_
#define OPENSOURCEAPPLICATION_HEADER_NODE_H_

struct Node
{
public:
    int key;
    Node *left_child = nullptr;
    Node *right_child = nullptr;
    int height = 1;
    Node(int value) : key{value} {};
};

#endif // OPENSOURCEAPPLICATION_HEADER_NODE_H_
