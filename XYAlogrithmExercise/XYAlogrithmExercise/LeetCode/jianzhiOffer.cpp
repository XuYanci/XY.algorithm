//
//  jianzhiOffer.cpp
//  XYAlogrithmExercise
//
//  Created by Yanci on 2020/3/4.
//  Copyright © 2020 Yanci. All rights reserved.
//

#include "jianzhiOffer.hpp"
#include <stack>
using namespace std;

class MinStack {
    int stack[1024 * 10];
    int stackIndex = 0;
 
public:
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
    
    int min() {
        int min = stack[0];
        for (int i= 1; i < stackIndex; i++) {
            if (stack[i] < min) {
                min = stack[i];
            }
        }
        return min;
    }
};

class CQueue {
    stack<int> stackOne;
    stack<int> stackTwo;
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        stackOne.push(value);
        
        // stack<int> copyStackOne;
        // stack<int> copyStackTwo;
        // copyStackOne = stackOne;
        // while (copyStackOne.empty() == false) {
        //     int value = copyStackOne.top();
        //     copyStackTwo.push(value);
        //     copyStackOne.pop();
        // }
        // stackTwo = copyStackTwo;
    }
    
    int deleteHead() {
        int head = -1;
        
         if (stackOne.empty() && stackTwo.empty()) return -1;
        
        /// 如果为空，则重新倒入一遍
        if (stackTwo.empty()) {
            while (stackOne.empty() == false) {
                int v = stackOne.top();
                stackTwo.push(v);
                stackOne.pop();
            }
        }

            
        head = stackTwo.top();
        stackTwo.pop();
        
        return head;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
