//
//  XYStack.cpp
//  XYAlogrithmExercise
//
//  Created by Yanci on 2019/4/25.
//  Copyright © 2019 Yanci. All rights reserved.
//

#include "XYStack.hpp"

bool XYStack::

dfs(Node1 cur, Node1 target, std::set<Node1 *> visited) {
    if (cur.val == target.val) return true;
    while(cur.list.empty() == false) {
        Node1 next = cur.list.front();
        visited.insert(&next);
        return dfs(next, target, visited);
    }
    return false;
}

/// 单调栈
//增、减栈区别：根据堆栈的生成方向不同。
//递增堆栈(ascending stack)：堆栈由低地址向高地址生长。
//递减堆栈(secending stack)：堆栈由高地址向低地址生长。


