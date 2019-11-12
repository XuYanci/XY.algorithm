//
//  XYStack.hpp
//  XYAlogrithmExercise
//
//  Created by Yanci on 2019/4/25.
//  Copyright © 2019 Yanci. All rights reserved.
//

#ifndef XYStack_hpp
#define XYStack_hpp
#include <list>
#include <stdio.h>
#include <set>
struct Node {
    int val;
    std::list<Node>list;
};

class XYStack {
    bool dfs(Node cur,Node target, std::set<Node *> visited);
};


class MinStack {
public:
    int stack[1024 * 10];
    int stackIndex = 0;
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        stack[stackIndex++] = x;
    }
    
    void pop() {
        stack[--stackIndex] = 0;
    }
    
    int top() {
        
        return stack[stackIndex - 1];
    }
    
    int getMin() {
        int min = stack[0];
        for (int i= 1; i < stackIndex; i++) {
            if (stack[i] < min) {
                min = stack[i];
            }
        }
        return min;
    }
};

/// 递增栈
class IncrementalStack {};
/// 递减栈
class DecreaseStack {};

#endif /* XYStack_hpp */
