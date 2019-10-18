//
//  XYQueue.hpp
//  XYAlogrithmExercise
//
//  Created by Yanci on 2019/4/25.
//  Copyright © 2019 Yanci. All rights reserved.
//

#ifndef XYQueue_hpp
#define XYQueue_hpp

#include <stdio.h>
class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        return 0;
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        return 0;
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return true;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return true;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

//MyCircularQueue circularQueue = new MycircularQueue(3); // 设置长度为 3
//
//circularQueue.enQueue(1);  // 返回 true
//
//circularQueue.enQueue(2);  // 返回 true
//
//circularQueue.enQueue(3);  // 返回 true
//
//circularQueue.enQueue(4);  // 返回 false，队列已满
//
//circularQueue.Rear();  // 返回 3
//
//circularQueue.isFull();  // 返回 true
//
//circularQueue.deQueue();  // 返回 true
//
//circularQueue.enQueue(4);  // 返回 true
//
//circularQueue.Rear();  // 返回 4

#endif /* XYQueue_hpp */
