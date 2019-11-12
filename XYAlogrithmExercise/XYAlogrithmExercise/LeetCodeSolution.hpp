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
#include <cstring>
#include <string>

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

class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {}
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
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
    // 两个数组的交集 (考虑顺序)
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2);
    // 两个数组的交集 (不考虑顺序)
    vector<int> intersect1(vector<int>& nums1, vector<int>& nums2);
    
    
    /// 选择矩阵
    void rotate(vector<vector<int>>& matrix) ;
    
    /// 有效的数独
    bool isValidSudoku(vector<vector<char>>& board);
    
    // 寻找右区间
    vector<int> findRightInterval(vector<vector<int>>& intervals);
    /// 两两交换链表中的节点
    ListNode *swapPairs(ListNode *head);
    /// 杨辉三角形 (给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。在杨辉三角中，每个数是它左上方和右上方的数的和。)
    vector<vector<int>> generate(int numRows);
    /// 杨辉三角形2
    vector<int> getRow(int rowIndex);
    /// Pow  X的N次方
    double myPow(double x, int n);
    /// 岛屿问题
    int numIslands(vector<vector<char>>& grid);
    
    /// 打开转盘锁
    int openLock(vector<string>& deadends, string target);
    
    /// 完全平方数
    int numSquares(int n);
    
    /// 有效的括号
    bool isValid(string s);
    
    /// 每日温度
    vector<int> dailyTemperatures(vector<int>& T);
 
    /// 克隆图
    Node* cloneGraph(Node* node);
 
    /// 逆波兰表达式求值
    int evalRPN(vector<string>& tokens);
 
    /// 中序遍历
    vector<int> inorderTraversal(TreeNode* root);
 
private:
    bool isPrime(int num);
    int getMaxValue(vector<int>& nums,int begin,int end) ;
    bool compareTwoArray(vector<int>&nums1,vector<int>&nums2);
    void reverseString_recursive(vector<char> &s,int start,int end);
    int generate_00(int i,int j);
    int generate_000(int i, int j);
    int islands_bfs(vector<vector<char>>& grid,int i,int j,size_t m,size_t n);
    int islands_dfs(vector<vector<char>>& grid,int i,int j,size_t m,size_t n);
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
    int cap;
    Node *head;
    Node *tail;
};

/// LFUCache
/// Refer To : https://mp.weixin.qq.com/s/XBP-38JlpYHTTXIKTTdAXg
class LFUCache {
public:
    int cap;
    //当前容量
    int size;
    // 最小的 freq，删除元素时需要知道该删除哪个链表
    int minFreq;
    // 保存 value和freq
    unordered_map<int, pair<int, int>> valueFreqMap;
    // 保存 key 在链表中的位置
    unordered_map<int, list<int>::iterator> iterMap;
    // freq 对应的链表
    unordered_map<int, list<int>> freqListMap;
    
    // 初始化
    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
    }
    
    int get(int key) {
        if(valueFreqMap.count(key)==0) return -1;
        // 删除链表中的节点
        freqListMap[valueFreqMap[key].second].erase(iterMap[key]);
        // 增加使用频次
        valueFreqMap[key].second++;
        // 把 key 放到链表的末尾
        freqListMap[valueFreqMap[key].second].push_back(key);
        // 记录 key 值链表中的位置
        iterMap[key] = --freqListMap[valueFreqMap[key].second].end();
        // 修改最小 freq
        if(freqListMap[minFreq].size() == 0)
            minFreq++;
        
        return valueFreqMap[key].first;
    }
    
    void put(int key, int value) {
        if(cap <= 0) return;
        // get 方法会修改使用频次
        int storedValue=get(key);
        if(storedValue != -1) {
            valueFreqMap[key].first = value;
            return;
        }
        
        // 超出容量限制，该删除了
        if(size >= cap ){
            valueFreqMap.erase( freqListMap[minFreq].front() );
            iterMap.erase( freqListMap[minFreq].front() );
            freqListMap[minFreq].pop_front();
            size--;
        }
        
        // 保存到各个 map 中
        valueFreqMap[key] = {value, 1};
        freqListMap[1].push_back(key);
        // 最后一个位置
        iterMap[key] = --freqListMap[1].end();
        minFreq = 1;
        size++;
    }
};



#endif /* Solution_hpp */
