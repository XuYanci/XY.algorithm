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
using namespace std;
struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
//    执行用时 : 32 ms, 在Remove Duplicates from Sorted Array的C++提交中击败了96.66% 的用户
//    内存消耗 : 10 MB, 在Remove Duplicates from Sorted Array的C++提交中击败了75.10% 的用户
    int removeDuplicates(std::vector<int>& nums) {
        
        if (nums.size() == 0) return 0;
        
        int count = 0;
        for (int i = 0 ; i < nums.size();i++) {
            if(nums[count] != nums[i]) {
                nums[++count] = nums[i];
            }
        }
        return count + 1;
    }

//    执行用时 : 28 ms, 在Rotate Array的C++提交中击败了97.36% 的用户
//    内存消耗 : 9.7 MB, 在Rotate Array的C++提交中击败了12.68% 的用户
    void rotate(vector<int>& nums, int k) {
        if (k == nums.size())return;
        int l = k % nums.size();
        int move_nums[l+1];
        
        int j = 0;
        for (unsigned long i = nums.size() - l; i < nums.size(); i++) {
            move_nums[j++] = nums[i];
        }
        
        for (unsigned long i = 0; i < nums.size() - l; i++) {
            nums[nums.size() - 1 - i ] = nums[nums.size() - 1 - l - i];
        }
        
        for (unsigned long i = 0;i < l; i++) {
            nums[i] = move_nums[i];
        }
        
    }
    
    bool containsDuplicate(vector<int>& array) {
        return true;
        
    }
    
//    func containsDuplicate(_ nums: [Int]) -> Bool {
//        if nums.count <= 1 {
//            return false;
//        }
//            var dict = [Int: Int]()
//            for i in 0...nums.count - 1 {
//                if (dict[nums[i]] == nil) {
//                    dict[nums[i]] = nums[i];
//                }
//                else {
//                    return true
//                }
//            }
//            return false
//            }
    
    // 只出现一次的数字
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] == nums[i + 1]) {
                i += 2;
            } else {
                return nums[i];
            }
        }
        return 0;
    }
  
    // 移动零
    // 124 ms    9.5 MB
    // 效率有点低??? 冒泡思维在思考一下
    void moveZeroes(vector<int>& nums) {
        int beginpos = 0;
        int counter =0 ;
        while (beginpos < nums.size() - counter) {
            if(nums[beginpos] == 0) {
                for (int i = beginpos; i <  nums.size() - 1;i++) {
                    int temp = nums[i];
                    nums[i] = nums[i+1];
                    nums[i+1] = temp;
                }
               
                counter++;
                beginpos = 0;
                continue;
            }
            beginpos++;
        }
    }
    
    // 合并两个有序链表
    // 16 ms 9 MB
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if (l1 == NULL) {
            return l2;
        }
        
        if (l2 == NULL) {
            return l1;
        }
        
        ListNode *p1;
        ListNode *p11;
        ListNode *firstHead = l1;
        p1 = NULL;
        p11 = l1;
        bool insertBefore =false;
        
        while(p11!=NULL) {
            if(p11->val > l2->val) {
                if (p1 != NULL) {
                    p1->next = l2;
                }
                ListNode *temp = l2->next;
                l2->next = p11;
                
                if (p1 == NULL) {
                    firstHead = l2;
                    insertBefore = true;
                }
                l2 = temp;
            }
            
            if (insertBefore) {
                p1 = firstHead;
                p11 = p1->next;
                insertBefore = false;
            }
            else {
                if (p1 == NULL) {
                    p1 = p11;
                    p11 = p1->next;
                } else {
                    p1 = p1->next;
                    p11 = p1->next;
                }
            }
            
            if (l2 == NULL) {
                break;
            }
        }
        
        if (l2 != NULL) {
            p1->next = l2;
        }
        
        return firstHead;
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode *p = head;
        ListNode *q = p->next;
        
        p->next = NULL;
        
        while(q!=NULL) {
            ListNode *qq = q->next;
            q->next = p;
            p = q;
            q = qq;
        }
        
        return p;
    }
};


#endif /* Solution_hpp */
