//
//  XYQueue.cpp
//  XYAlogrithmExercise
//
//  Created by Yanci on 2019/4/25.
//  Copyright © 2019 Yanci. All rights reserved.
//

#include "XYQueue.hpp"
#include <queue>
#include <set>
int XYQueue::BFS(Node root, Node target) {
    std::queue<Node>_queue;
    int step = 0;
    _queue.push(root);
    while (_queue.empty() == false) {
        step = step  + 1;
        unsigned long size = _queue.size();
        for (int i = 0; i < size;i++) {
            Node cur = _queue.front();
            if (cur.val == target.val) {
                return step;
            }
           
            while(cur.list.empty() == false) {
                Node next = cur.list.front();
                _queue.push(next);
                cur.list.pop_front();
            }
            _queue.pop();
        }
    }
    return 0;
}

