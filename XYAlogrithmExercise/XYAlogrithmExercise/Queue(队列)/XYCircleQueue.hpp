//
//  XYCircleQueue.hpp
//  XYAlogrithmExercise
//
//  Created by Yanci Xu on 2021/2/21.
//  Copyright © 2021 Yanci. All rights reserved.
//

#ifndef XYCircleQueue_hpp
#define XYCircleQueue_hpp

#include <stdio.h>

/// 循环队列A
class MyCircularQueueA {
    int front;
    int rear;
    int capacity;
    int *array;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueueA(int k) {
        /// 这里+1是因为
        /// 为了避免“队列为空”和“队列为满”的判别条件冲突，我们有意浪费了一个位置
        /// 例如: | 0 | 1 | 如果rear = 1,capacity = 2, front = 1,   (enQueue) rear = (rear+1)%capacity , 那么 rear = 0 = front 这样就不对了。
        capacity = k + 1;
        array = new int[capacity];
        front = 0;
        rear = 0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        array[rear] = value;
        rear = (rear + 1) % capacity;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % capacity;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        
        return array[front];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return array[(rear -1 + capacity) % capacity];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return front == rear;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (rear + 1) % capacity == front;
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

class MyCircularQueueB {
public:
    
    /// 当前队列长度
    int currentLength;
    /// 当前队列指针
    int currentIndex = 0;
    /// 队列容量 1000
    int queue[1000];
    
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueueB(int k) {
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


#endif /* XYCircleQueue_hpp */
