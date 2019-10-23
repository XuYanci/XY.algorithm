//
//  XYStack.cpp
//  XYAlogrithmExercise
//
//  Created by Yanci on 2019/4/25.
//  Copyright © 2019 Yanci. All rights reserved.
//

#include "XYStack.hpp"

bool XYStack::dfs(Node cur, Node target, std::set<Node *> visited) {
    if (cur.val == target.val) return true;
    while(cur.list.empty() == false) {
        Node next = cur.list.front();
        visited.insert(&next);
        return dfs(next, target, visited);
    }
    return false;
}
