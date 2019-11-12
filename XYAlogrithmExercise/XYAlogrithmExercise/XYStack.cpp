//
//  XYStack.cpp
//  XYAlogrithmExercise
//
//  Created by Yanci on 2019/4/25.
//  Copyright © 2019 Yanci. All rights reserved.
//

#include "XYStack.hpp"

bool XYStack::dfs(Node1 cur, Node1 target, std::set<Node1 *> visited) {
    if (cur.val == target.val) return true;
    while(cur.list.empty() == false) {
        Node1 next = cur.list.front();
        visited.insert(&next);
        return dfs(next, target, visited);
    }
    return false;
}
