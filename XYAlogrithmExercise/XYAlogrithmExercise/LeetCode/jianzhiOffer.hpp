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
        if (head == NULL) {
            return NULL;
        }
        
        Node *headNode = new Node(head->val);
        Node *h = headNode;
        while(head != NULL) {
            head = head->next;
            if (head) {
                Node *nextNode = new Node(head->val);
                headNode->next = nextNode;
                headNode = nextNode;
            }
        }
        return h;
    }
    
};

#endif /* jianzhiOffer_hpp */
