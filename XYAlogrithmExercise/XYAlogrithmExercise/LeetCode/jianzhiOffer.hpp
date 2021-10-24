//
//  jianzhiOffer.hpp
//  XYAlogrithmExercise
//
//  Created by Yanci on 2020/3/4.
//  Copyright © 2020 Yanci. All rights reserved.
//

#ifndef jianzhiOffer_hpp
#define jianzhiOffer_hpp
#include <vector>
#include <unordered_map>
#include <stdio.h>
#include <string>
#include <queue>
#include<iostream>
using namespace std;

class JianZhiOffer {
    
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    
    class Node {
    public:
        int val;
        Node* next;
        Node* random;
        
        Node(int _val) {
            val = _val;
            next = NULL;
            random = NULL;
        }
    };
    
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            if(map.find(nums[i]) == map.end()) {
                map[nums[i]] = nums[i];
            } else {
                return nums[i];
            }
            
        }
        return -1;
    }
    
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        
        int row = 0;
        int col = (int)matrix[0].size() - 1;
        
        bool isFind = false;
        while (row < matrix.size() && col >= 0) {
            if (matrix[row][col] == target) {
                isFind = true;break;
            }
            else if (matrix[row][col] > target) {
                col--;
            }else {
                row++;
            }
        }
        
        return isFind;
    }
    
    /// 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
    string replaceSpace(string s) {
        string::size_type position = 0;
        string flag = " ";
        
        while((position=s.find(flag,position))!=string::npos)
        {
            
            s.replace(position, 1 , "%20");
            
        }
        return s;
    }
    
    string replaceSpace1(string s) {
        string::iterator it = s.begin();
        string replaceSpace;
        while(it!=s.end()) {
            if (*it == ' ') {
                replaceSpace += "%20";
            } else {
                replaceSpace += *it;
            }
            *it++;
        }
        return replaceSpace;
    }
    
    string reverseLeftWords(string s, int n) {
        int size = (int)s.size();
        int moveLength = n % size;
        int i = 0;
        
        if (n >= size) return s;
        if (moveLength == 0) return s;
        
        char moveStr[moveLength];
        while(i < moveLength) {
            moveStr[i] = s[i];
            i++;
        }
        
        i = 0;
        while(i < size - moveLength) {
            s[i] =  s[i + moveLength];
            i++;
        }
        
        int j = 0;
        while(j < moveLength) {
            s[i + j] = moveStr[j];
            j++;
        }
        return s;
    }
    
    vector<int> reversePrint(ListNode* head) {
        vector<int> nums;
        vector<int>reverseNum;
        while(head != NULL) {
            nums.push_back(head->val);
            head = head->next;
        }
        for (int i = (int)nums.size() - 1; i >= 0; i--) {
            reverseNum.push_back(nums[i]);
        }
        return reverseNum;
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode *tail = NULL;
        while(head != NULL) {
            ListNode *q = head->next;
            head->next = tail;
            tail = head;
            head = q;
        }
        return tail;
    }
    
    Node* copyRandomList(Node* head) {
        unordered_map<Node *,Node*> nodeMap;
        
        if (head == NULL) {
            return NULL;
        }
        Node *copyHead = new Node(head->val);
        Node *copyHeadReserved = copyHead;
        copyHead->random = head->random;
        nodeMap[head] = copyHead;
        
        while(head != NULL) {
            head = head->next;
            if (head != NULL) {
                Node *node = new Node(head->val);
                node->random = head->random;
                nodeMap[head] = node;
                copyHead->next = node;
                copyHead = node;
            }
        }
        
        copyHead = copyHeadReserved;
        while(copyHead != NULL) {
            copyHead->random = nodeMap[copyHead->random];
            copyHead = copyHead->next;
            
        }
        
        return copyHeadReserved;
    }
    
    int findRepeatNumber1(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            if (map[nums[i]] == 1) {
                return nums[i];
            }
            map[nums[i]] = 1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                count++;
            }
        }
        return count;
    }
    
    int missingNumber(vector<int>& nums) {
        int j = 0;
        for (j = 0; j < nums.size();j++) {
            if (nums[j] != j) {
                return j;
            }
        }
        return j;
    }
    char firstUniqChar(string s) {
        s= "lll";
        unordered_map<char,int> _map;
        for(int i = 0; i < s.size();i++) {
            _map[s[i]] = _map.find(s[i]) != _map.end() ? _map[s[i]]+1 : 1;
        }
        
        for(int i = 0; i < s.size();i++) {
            if(_map[s[i]] == 1) {
                return s[i];
            }
        }
        return ' ';
    }
    
    bool findNumberIn2DArray1(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        if (matrix[0].size() == 0)  return false;
        int row = 0;
        
        /// 二分查找优化
        for(int i = 0; i < matrix.size();i++) {
            if(target > matrix[i][0]) {
                row++;;
                
            } else if(target == matrix[i][0]) {
                return true;
            }
        }
        /// 二分查找优化
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < matrix[0].size();j++) {
                if (target == matrix[i][j]) {
                    return true;
                }
            }
        }
        return false;
    }
    
    vector<int> levelOrder(TreeNode* root) {
        vector<int> orders;
        if (root == NULL) return vector<int>{};
        
        queue<TreeNode*> queue_;
        queue_.push(root);
        while (queue_.empty() != true) {
            TreeNode *root = queue_.front();
            orders.push_back(root->val);
            if (root->left) {
                queue_.push(root->left);
            }
            
            if (root->right) {
                queue_.push(root->right);
            }
            queue_.pop();
        }
        
        return orders;
    }
    
    vector<vector<int>> levelOrder1(TreeNode* root) {
        vector<vector<int>> orders;
        queue<int> levels;
        if (root == NULL) return vector<vector<int>>{};
        
        queue<TreeNode*> queue_;
        queue_.push(root);
        levels.push(0);
        
        
        while (queue_.empty() != true) {
            TreeNode *root = queue_.front();
            int level = levels.front();
            
            if(level < orders.size()) {
                //                orders[level].push_back(root->val);
                if (level % 2 == 0) {
                    orders[level].push_back(root->val);
                } else{
                    orders[level].insert(orders[level].begin(),root->val);
                }
                
            } else {
                orders.push_back(vector<int>{root->val});
            }
            
            if (root->left) {
                levels.push(level + 1);
                queue_.push(root->left);
            }
            
            if (root->right) {
                levels.push(level + 1);
                queue_.push(root->right);
            }
            queue_.pop();
            levels.pop();
        }
        return orders;
    }
    
    vector<TreeNode *> _A;
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if ( A == NULL || B == NULL) return false;
        
        
        /// TODO: Optimize: 1,2步可以合并成一步
        
        /// 1. 在A寻找B的根节点
        findBInA(A, B);
        
        if (_A.size() == 0) return false;
        
        /// 2. 比较
        for(int i = 0; i <_A.size();i++) {
            bool result = compareBInA(_A[i], B);
            if (result) {
                return result;
            }
        }
        
        return false;
        
    }
    
    bool compareBInA(TreeNode *A,TreeNode *B) {
        
        if (B == NULL) {
            return true;
        }
        
        if (A == NULL) {
            return false;
        }
        
        if ( A->val != B->val) {
            return false;
        }
        
        bool result = compareBInA(A->left, B->left);
        if (!result) {
            return result;
        }
        result = compareBInA(A->right, B->right);
        if (!result) {
            return result;
        }
        
        return true;
    }
    
    void findBInA(TreeNode *A,TreeNode *B) {
        if (A == NULL || B == NULL) {
            return;
        }
        if (A->val == B->val) {
            _A.push_back(A);
        }
        findBInA(A->left,B);
        findBInA(A->right,B);
    }
    
    TreeNode* mirrorTree(TreeNode* root) {
        mirrorTree1(root);
        return root;
    }
    
    
    void mirrorTree1(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        mirrorTree1(root->left);
        mirrorTree1(root->right);
       
        /// 后序替换
        TreeNode *left = root->left;
        root->left = root->right;
        root->right = left;
        return;
    }
    
    bool isSymmetric(TreeNode* root) {
        return false;
    }
    
    
};

#endif /* jianzhiOffer_hpp */
