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
#include <vector>
#include <string>
using namespace std;

class MyCircularQueue1 {
    int front;
    int rear;
    int capacity;
    int *array;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue1(int k) {
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
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x):val(x),left(NULL),right(NULL){}
    };
    
    /// 广度优先搜索
    int BFS(Node root, Node target);
//     最小深度
//     给定一个二叉树，找出其最小深度。
//     最小深度是从根节点到最近叶子节点的最短路径上的节点数量
    int minDepth(TreeNode* root);
    
    /// 打开转盘锁
//    你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' 。每个拨轮可以自由旋转：例如把 '9' 变为  '0'，'0' 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。
//
//    锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。
//
//    列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。
//
//    字符串 target 代表可以解锁的数字，你需要给出最小的旋转次数，如果无论如何不能解锁，返回 -1。
//
//    来源：力扣（LeetCode）
//    链接：https://leetcode-cn.com/problems/open-the-lock
//    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
    int openLock(vector<string>& deadends, string target);
};


/// 双向队列
class DoubleEndQueue {
    
};

#endif /* XYQueue_hpp */
