//
//  Solution.cpp
//  XYAlogrithmExercise
//
//  Created by Yanci on 2019/4/28.
//  Copyright © 2019 Yanci. All rights reserved.
//

#include "Solution.hpp"


//    执行用时 : 32 ms, 在Remove Duplicates from Sorted Array的C++提交中击败了96.66% 的用户
//    内存消耗 : 10 MB, 在Remove Duplicates from Sorted Array的C++提交中击败了75.10% 的用户
int Solution::removeDuplicates(std::vector<int>& nums) {
    
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
void Solution::rotate(vector<int>& nums, int k) {
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

bool Solution::containsDuplicate(vector<int>& array) {
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
int Solution::singleNumber(vector<int>& nums) {
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
void Solution::moveZeroes(vector<int>& nums) {
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
ListNode* Solution::mergeTwoLists(ListNode* l1, ListNode* l2) {
    
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

ListNode* Solution::reverseList(ListNode* head) {
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

//  整数反转
int Solution::reverse(int x) {
    if (x == 0) {
        return 0;
    }
    
    int n = 0;
    vector<int>array;
    int val = x / (long)pow(10, n) ;
    while (val != 0) {
        val = x / (long)pow(10, n);
        array.push_back(val % 10);
        n++;
    }
    
    long y = 0;
    for (int i = 0; i < array.size(); i++) {
        y +=  array[i] * pow(10, n - 2 - i);
        if (y < (int)pow(-2, 31)|| y > (int)pow(2, 31) ) {
            y = 0;break;
        }
    }
    return (int)y;
}
int Solution::countPrimes(int n) {
    int count = 0;
    
    for (int i = 2;i<n;i++)
    {
        if(isPrime(i)) {
            count++;
        }
    }
    return count;
}

bool Solution::isPrime(int num) {
    if (num <= 3) {
        return num > 1;
    }
    // 不在6的倍数两侧的一定不是质数
    if (num % 6 != 1 && num % 6 != 5) {
        return false;
    }
    
    for (int i = 5; i <= sqrt(num); i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}
int Solution::maxDepth(TreeNode* root) {
    if( root == NULL )
        return 0;
    if( root->left == NULL && root->right == NULL )
        return 1;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

// 递归做法
// int fib(int N) {
//     // 递归出口
//     if (N == 0)
//         return 0;
//     else if (N == 1)
//         return 1;
//     return fib(N - 1) + fib(N - 2);
// }
// 栈做法
int Solution::fib(int N) {
    if (N == 0)
        return 0;
    else if (N == 1 || N == 2)
        return 1;
    
    stack<int>s1;
    s1.push(N);
    int val = 0;
    
    while(!s1.empty()) {
        int n = s1.top();
        s1.pop();
        if (n == 1) {
            val += 1; continue;
        }
        if (n == 2) {
            val += 1; continue;
        } else if (n > 2){
            s1.push(n - 1);
            s1.push(n - 2);
        }
    }
    
    return val;
}

// 合并两个数组
void Solution::merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    
    // 归并排序
    int i = 0;
    int j = 0;
    int t = 0;
    vector<int>temp(m+n,0);
    
    while ( i < m && j < n) {
        if (nums1[i] < nums2[j]) {
            temp[t++] = nums1[i++];
        } else {
            temp[t++] = nums2[j++];
        }
    }
    
    while(i<m){
        temp[t++] = nums1[i++];
    }
    while(j<n){
        temp[t++] = nums2[j++];
    }
    
    t = 0;
    i = 0;
    while(i < m + n){
        nums1[t++] = temp[i++];
    }
}
// 二叉树反转
TreeNode* Solution::invertTree(TreeNode* root) {
    // 递归实现
    // 递归体
    // left  = right
    // 递归出口
    ///root == NULL
    
    if (root != NULL) {
        TreeNode *right = invertTree(root->right);
        TreeNode *left =  invertTree(root->left);
        root->left = right;
        root->right = left;
    }
    return root;
}
/// 加一
vector<int> Solution::plusOne(vector<int>& digits) {
    return vector<int>(0,0);
}
