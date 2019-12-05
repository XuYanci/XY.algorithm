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
#include <vector>
#include <stack>
using namespace std;
struct Node1 {
    int val;
    std::list<Node1>list;
};

class XYStack {
    bool dfs(Node1 cur,Node1 target, std::set<Node1 *> visited);
public:
    vector<int> prevExceed(vector<int> &input) {
        vector<int> result (input.size(), -1);
        stack<int> monoStack;
        for(int i = 0; i < input.size(); i++) {
            while(!monoStack.empty() && input[monoStack.top()] > input[i]) {
                result[monoStack.top()] = i - monoStack.top();
                monoStack.pop();
            }
            monoStack.push(i);
        }
        return result;
    }
    vector<int> nextExceed(vector<int> &input) {
        vector<int> result (input.size(), -1);
        stack<int> monoStack;
        for(int i = 0; i < input.size(); i++) {
            while(!monoStack.empty() && input[monoStack.top()] < input[i]) {
                result[monoStack.top()] = i - monoStack.top();
                monoStack.pop();
            }
            monoStack.push(i);
        }
        return result;
    }
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
 

#endif /* XYStack_hpp */
