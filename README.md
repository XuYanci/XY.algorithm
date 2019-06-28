```
//
//  Solution.hpp
//  XYAlogrithmExercise
//
//  Created by Yanci on 2019/4/28.
//  Copyright © 2019 Yanci. All rights reserved.
//

#ifndef Solution_hpp
#define Solution_hpp
#include <vector>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <list>
 #include <queue>
using namespace std;
struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class LeetCodeSolution {
public:
    // 字符串反转
    void reverseString(vector<char>& s) ;
    // 两数之和
    vector<int> twoSum(vector<int>& nums, int target);
    // 移除重复数字
    int removeDuplicates(std::vector<int>& nums);
    // 旋转数组
    void rotate(vector<int>& nums, int k);
    // 包含重复数字
    bool containsDuplicate(vector<int>& array);
    // 只出现一次的数字
    int singleNumber(vector<int>& nums);
    // 移动零
    void moveZeroes(vector<int>& nums);
    // 合并两个有序链表
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
    // 链表反转
    ListNode* reverseList(ListNode* head);
    //  整数反转
    int reverse(int x);
    // 计算素数的个数
    int countPrimes(int n);
    // 二叉树深度
    int maxDepth(TreeNode* root);
    // 栈做法
    int fib(int N);
    // 合并两个数组
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
    // 二叉树反转
    
    TreeNode* invertTree(TreeNode* root);
    /// 加一
    vector<int> plusOne(vector<int>& digits);
    // 最长上升子序列
    int lengthOfLIS(vector<int>& nums);
    
    // 滑动窗口最大值
    vector<int> maxSlidingWindow(vector<int>& nums, int k);
    
    // 买卖股票的最佳时间II
    int maxProfit(vector<int>& prices);
    // 买卖股票的最佳时机
    int maxProfit1(vector<int>& prices);
   
private:
    bool isPrime(int num);
    int getMaxValue(vector<int>& nums,int begin,int end) ;
    
};

/// LRU Cache
class LRUCache {
    // Double Link List
    class   Node {
    public:
        int key;
        int val;
        Node *prev;
        Node *next;
    };
public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    // 根据key获取value
    int get(int key) {
        /// 查找hashMap，有则返回
        map<int, Node*>::iterator it;
        if ((it = hashMap.find(key)) != hashMap.end()) {
            removeNode(it->second);
            addNode(it->second);
            return it->second->val;
        }
 
        return -1;
    }
    
    // 放入指定value到key中
    void put(int key, int value) {
        /// 查找hashMap
        map<int, Node*>::iterator it;
        /// 如果存在，则删除节点，并将节点放到最后
        if ((it = hashMap.find(key)) != hashMap.end()) {
            it->second->val = value;
            removeNode(it->second);
            Node *newNode = new Node();
            newNode->key = key;
            newNode->val = value;
            addNode(newNode);
//            hashMap.insert(make_pair(key, newNode));
            hashMap[key] = newNode;
            return;
        }
   
        /// 如果已满
        /// 删除最近一个节点
        if (hashMap.size() == cap) {
            removeFirst();
        }
        
        /// 如果不存在，则新建节点并将节点放到最后
        Node *newNode = new Node();
        newNode->key = key;
        newNode->val = value;
        addNode(newNode);
//        hashMap.insert(make_pair(key, newNode));
        hashMap[key] = newNode;
    }
private:
    // 删除最近一个节点
    void removeFirst() {
        Node *tmp = head->next;
        removeNode(tmp);
        hashMap.erase(tmp->key);
    }
    // 删除节点
    void removeNode(Node *n) {
        n->prev->next = n->next;
        n->next->prev = n->prev;
  
    }
    
    // 添加节点
    void addNode(Node *n) {
        n->next = tail;
        n->prev = tail->prev;
        tail->prev->next = n;
        tail->prev = n;
    }
    
    /// HashMap
    map<int,Node *> hashMap;

class LeetCodeSolution {
public:
    // 字符串反转
    void reverseString(vector<char>& s) ;
    // 两数之和
    vector<int> twoSum(vector<int>& nums, int target);
    // 移除重复数字
    int removeDuplicates(std::vector<int>& nums);
    // 旋转数组
    void rotate(vector<int>& nums, int k);
    // 包含重复数字
    bool containsDuplicate(vector<int>& array);
    // 只出现一次的数字
    int singleNumber(vector<int>& nums);
    // 移动零
    void moveZeroes(vector<int>& nums);
    // 合并两个有序链表
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
    // 链表反转
    ListNode* reverseList(ListNode* head);
    //  整数反转
    int reverse(int x);
    // 计算素数的个数
    int countPrimes(int n);
    // 二叉树深度
    int maxDepth(TreeNode* root);
    // 栈做法
    int fib(int N);
    // 合并两个数组
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
    // 二叉树反转
    
    TreeNode* invertTree(TreeNode* root);
    /// 加一
    vector<int> plusOne(vector<int>& digits);
    // 最长上升子序列
    int lengthOfLIS(vector<int>& nums);
    // 滑动窗口最大值
    vector<int> maxSlidingWindow(vector<int>& nums, int k);
    // 买卖股票的最佳时间II
    int maxProfit(vector<int>& prices);
    // 买卖股票的最佳时机
    int maxProfit1(vector<int>& prices);
    // 两个数组的交集 (考虑顺序)
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2);
    // 两个数组的交集 (不考虑顺序)
    vector<int> intersect1(vector<int>& nums1, vector<int>& nums2);
private:
    bool isPrime(int num);
    int getMaxValue(vector<int>& nums,int begin,int end) ;
    bool compareTwoArray(vector<int>&nums1,vector<int>&nums2);
    
};

```
