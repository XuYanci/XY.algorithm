//
//  XYQueue.hpp
//  XYAlogrithmExercise
//
//  Created by Yanci on 2019/4/25.
//  Copyright © 2019 Yanci. All rights reserved.
//

#ifndef XYQueue_hpp
#define XYQueue_hpp
#include <list>
#include <stdio.h>
class MyCircularQueue {
public:
    
    /// 当前队列长度
    int currentLength;
    /// 当前队列指针
    int currentIndex = 0;
    /// 队列容量 1000
    int queue[1000];
    
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        currentLength =  k;
        for (int i = 0; i < k - 1;i++) {
            queue[i] = -1;
        }
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (currentIndex + 1 >= currentLength)
            return false;
        queue[++currentIndex] = value;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (currentIndex > 0) {
            queue[--currentIndex] = -1;
            return true;
        }
        return false;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        // if (currentIndex <= 0) return - 1;
        return queue[0];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (currentIndex < 0) return - 1;
        return queue[currentIndex];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return currentIndex >= 0 ? true : false;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (currentIndex + 1 == currentLength ) ? true : false;
    }
};


struct Node {
    int val;
    std::list<Node>list;
};


class XYQueue {
    /// 广度优先搜索
    int BFS(Node root, Node target);
};
#endif /* XYQueue_hpp */
