//
//  StackQueueArray.hpp
//  XYAlogrithmExercise
//
//  Created by Yanci Xu on 2021/5/2.
//  Copyright © 2021 Yanci. All rights reserved.
//

#ifndef StackQueueArray_hpp
#define StackQueueArray_hpp

#include <stdio.h>

/// 栈，队列，数组
class StackQueueArray {
    /// 1. 实现循环队列
    /// 队列为空: front == rear
    /// 队列满: (rear + 1) % maxsize = front
    /// 队列长度: (r-f+n)%n
    
/// 最大长度
#define MAX 255
    
private:
    int rear;
    int front;
    int maxSize;
    int queue[MAX];
    int stack1[MAX];
    int stack2[MAX];
    int stack1Top;
    int stack2Top;
    int doubleStackSize;
public:
    void initCircleQueue(int queueLength) {
        maxSize = queueLength;
        front = rear = 0;
    }
    
    void enQueue(int value) {
        if (isQueueFull()) {
            return;
        }
        queue[rear] = value;
        rear++;
    }
    
    int deQueue() {
        if (isQueueEmpty()) {
            return -1;
        }
        int value = queue[front];
        front++;
        return value;
    }
    
    int lengthOfQueue() {
        return (rear - front + maxSize) % maxSize;
    }
    
    bool isQueueFull() {
        return (rear + 1) % maxSize == front;
    }
    
    bool isQueueEmpty() {
        return rear == front;
    }
    
    /// 2. 实现双栈
    void initDoubleStack(int length) {
        doubleStackSize = length;
        stack1Top = 0;
        stack2Top = length - 1;
    }
    
    void pushStack1(int value) {
        if (isDoubleStackFull()) {
            return;
        }
        stack1[stack1Top++] = value;
    }
    
    void pushStack2(int value) {
        if (isDoubleStackFull()) {
            return;
        }
        stack2[stack2Top--] = value;
    }
    
    int popStack1() {
        if (stack1Top == 0) {
            return -1;
        }
        return stack1[stack1Top--];
    }
    
    int popStack2() {
        if (stack2Top == doubleStackSize - 1) {
            return -1;
        }
        return stack1[stack2Top++];
    }
    
    bool isDoubleStackFull() {
       return stack1Top + 1 == stack2Top;
    }
};

#endif /* StackQueueArray_hpp */
