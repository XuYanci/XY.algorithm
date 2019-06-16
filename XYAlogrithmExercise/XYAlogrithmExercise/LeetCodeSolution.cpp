//
//  Solution.cpp
//  XYAlogrithmExercise
//
//  Created by Yanci on 2019/4/28.
//  Copyright © 2019 Yanci. All rights reserved.
//

#include "LeetCodeSolution.hpp"
void LeetCodeSolution::reverseString(vector<char>& s)
{
    // {1,2,3,4,5,6}
    
    for (int i = 0; i < s.size() / 2;i++) {
        char j = s[i];
        s[i] =  s[s.size() - i - 1];
        s[s.size() - i - 1] = j;
    }
}

vector<int> LeetCodeSolution:: twoSum(vector<int>& nums, int target) {
    
    /** // 1.  暴力算法
     // 如果只有两个数字，则直接返回
     if (nums.size() == 2) {
     int arr[] = {0,1};
     vector<int> v (arr, arr + sizeof(arr) / sizeof(int) );
     return v;
     }
     
     for (int i = 0; i < nums.size(); i++) {
     int val1 = nums[i];
     for (int j = i + 1; j < nums.size(); j++) {
     if (val1 + nums[j] == target) {
     int arr[] = {i,j};
     vector<int> v (arr, arr + sizeof(arr) / sizeof(int) );
     return v;
     }
     }
     }
     
     vector<int> v;
     return v;
     **/
    
    // 2. 哈希表算法
    map<int,int>hash;
    vector<int> sum {};
    
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        auto search = hash.find(complement);
        // 检查之前是否存在该键值
        if (search != hash.end()) {
            // 存在则返回
            sum = vector<int>{hash[complement],i};
            return sum;
        }
        // 存储键值
        hash[nums[i]] = i;
    }
    return sum;
}

/*
 从排序数组中删除重复项
 自己解题思路分析：
 1. 计数器count存放多少个不同
 2. 同时nums[count]为P,标记当前比较值，向右比较
 如果不同则复制到count位置，同时P右移一次
 如果相同，则继续向右比较
 算法复杂度:
 O(n)
 */

int LeetCodeSolution::removeDuplicates(std::vector<int>& nums) {
    
    if (nums.size() == 0) return 0;
    
    int count = 0;
    for (int i = 0 ; i < nums.size();i++) {
        if(nums[count] != nums[i]) {
            nums[++count] = nums[i];
        }
    }
    return count + 1;
}

/*
 旋转数组
 自己解题思路分析:
 1. 开辟一个存放旋转的数组空间，主要存放偏移的部分
 2. 复制旋转部分到旋转数组空间
 3. 原数组右边移动，头部空出空间
 4. 复制旋转数组到头部空间
 算法复杂度:
 O(n)
 */
void LeetCodeSolution::rotate(vector<int>& nums, int k) {
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

/*
 存在重复
 自己解题思路分析:
 这道题本身还想设计一个简单的哈希表，设计失败 :(
 但是主要思想就是使用哈希表解决；
 1. 哈希表查询
 2. 如果没有则登记到哈希表
 3. 如果有则返回存在重复
 算法复杂度:
 O(n)
 */
bool LeetCodeSolution::containsDuplicate(vector<int>& array) {
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

/*
 只出现一次的数字
 自己解题思路分析:
 1. 先排序
 2. 两两比较
 算法复杂度:
 排序算法O(未知) + O(n)
 */
int LeetCodeSolution::singleNumber(vector<int>& nums) {
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

/*
 移动零
 自己解题思路分析:
 1. 类似于冒泡排序的思路
 2. 如果为0，则冒泡交换到最后, counter++,这样右边都是0
 3. 继续从头开始比较 ( beginpos < counter),直到比较结束
 算法复杂度:
 O(n2)
 */
void LeetCodeSolution::moveZeroes(vector<int>& nums) {
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

/*
 合并两个有序链表
 解题思路:
 这里自己是思考写的，根据大概思路，所以代码写的有点不怎么规范 :(
 此类问题很常见，可以用递归，或者归并（分而治之)来解决，有固定的算法模型可以参考；
 1. 参考归并排序中的合并两个有序数组，属于同一类问题
 算法复杂度:
 O(n)
 */
ListNode* LeetCodeSolution::mergeTwoLists(ListNode* l1, ListNode* l2) {
    
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

/*
 反转链表
 解题思路:
 1. 主要需要两个指针, P , P->next, P->next->next (保存下一个q指针)
 2. 然后指针指向反转，继续右移动指针即可
 算法复杂度:
 O(n)
 */
ListNode* LeetCodeSolution::reverseList(ListNode* head) {
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

/*
 整数反转
 解题思路分析:
 1. val = val / pow(10,n) % 10 取得个位，百位，千位依次类推入栈
 2. 依次出栈,乘以pow(10,n),这样就能够获得反转值
 算法复杂度:
 O(n*2)
 */
int LeetCodeSolution::reverse(int x) {
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

/* 计算素数
 解题思路:
 1.不在6的倍数两侧的一定不是质数
 2.在6的倍数两侧也可能不是质数,再判断一次, 6(i) - 1 , 6(i) + 1
 算法复杂度:
 O(sqrt(n)/3),
 */
int LeetCodeSolution::countPrimes(int n) {
    int count = 0;
    
    for (int i = 2;i<n;i++)
    {
        if(isPrime(i)) {
            count++;
        }
    }
    return count;
}

bool LeetCodeSolution::isPrime(int num) {
    if (num <= 3) {
        return num > 1;
    }
    // 不在6的倍数两侧的一定不是质数
    if (num % 6 != 1 && num % 6 != 5) {
        return false;
    }
    //在6的倍数两侧也可能不是质数,再判断一次
    for (int i = 5; i <= sqrt(num); i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

/*
 二叉树的最大深度
 解题思路:
 递归体: 左右边取最大值+1
 递归出口: root == NULL , 结束, root->left == NULL 而且 root->right == NULL , 返回1
 算法复杂度:
 */
int LeetCodeSolution::maxDepth(TreeNode* root) {
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


int LeetCodeSolution::fib(int n) {
    if(n <= 1)
        return n;
    int meno_i_1 = 1;
    int meno_i_2 = 0;
    int meno_i = 1;
    for(int i = 2; i <= n; i++)
    {
        meno_i = meno_i_1 + meno_i_2;
        meno_i_2 = meno_i_1;
        meno_i_1 = meno_i;
    }
    return meno_i;
}

// 栈做法
//int LeetCodeSolution::fib(int N) {
//    if (N == 0)
//        return 0;
//    else if (N == 1 || N == 2)
//        return 1;
//
//    stack<int>s1;
//    s1.push(N);
//    int val = 0;
//
//    while(!s1.empty()) {
//        int n = s1.top();
//        s1.pop();
//        if (n == 1) {
//            val += 1; continue;
//        }
//        if (n == 2) {
//            val += 1; continue;
//        } else if (n > 2){
//            s1.push(n - 1);
//            s1.push(n - 2);
//        }
//    }
//
//    return val;
//}

// 合并两个数组
// 解题思路：
// 参考归并排序
void LeetCodeSolution::merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    
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

/*
 二叉树反转
 解题思路:
 递归实现
 递归体
 left  = right
 递归出口
 root == NULL
 */
TreeNode* LeetCodeSolution::invertTree(TreeNode* root) {    
    if (root != NULL) {
        TreeNode *right = invertTree(root->right);
        TreeNode *left =  invertTree(root->left);
        root->left = right;
        root->right = left;
    }
    return root;
}

/// 加一
vector<int> LeetCodeSolution::plusOne(vector<int>& digits) {
    return vector<int>(0,0);
}

int LeetCodeSolution::lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    int dp[n];
    memset(dp, 0, sizeof(dp));
    int maxLen = 1;
    for (int i = 0; i < n; ++i)
    {
        dp[i] = 1;
        for (int j = 0; j < i; ++j)
        {
            if (nums[i] > nums[j] && dp[i] < (dp[j] + 1))
            {
                dp[i] = dp[j] + 1;
                maxLen = ((maxLen > dp[i]) ? maxLen : dp[i]);
            }
        }
    }
    return maxLen;
}
 

/*
 滑动窗口最大值
 1.暴力遍历法
 2.双向队列解法
*/
typedef pair<int, int> Pair;
vector<int> LeetCodeSolution::maxSlidingWindow(vector<int>& nums, int k) {
    vector<int>maxes;

    // 暴力遍历法
//    for (int i = 0; i < nums.size(); i+= 1) {
//        int value = getMaxValue(nums,i,i+k);
//        maxes.push_back(value);
//    }
//    return maxes;
    
    // 双向队列解法
//    if (nums.size() == 0)
//        return vector<int>(0);
//
//    deque<int> Q;
//    vector<int>B(nums.size() - k + 1);
//    int w = k;
//    int n = nums.size();
//    for (int i = 0; i < w; i++) {
//        while (!Q.empty() && nums[i] >= nums[Q.back()])
//            Q.pop_back();
//        Q.push_back(i);
//    }
//    for (int i = w; i < n; i++) {
//        B[i-w] = nums[Q.front()];
//        while (!Q.empty() && nums[i] >= nums[Q.back()])
//            Q.pop_back();
//        while (!Q.empty() && Q.front() <= i-w)
//            Q.pop_front();
//        Q.push_back(i);
//    }
//    B[n-w] = nums[Q.front()];
//    return B;
    
    /// 最大堆解法
    int w = k;
    int n = nums.size();
    vector<int>B(nums.size() - k + 1);
    priority_queue<Pair> Q; //优先级队列保存窗口里面的值
    for (int i = 0; i < w; i++)
    Q.push(Pair(nums[i], i));  //构建w个元素的最大堆
    for (int i = w; i < n; i++) {
        Pair p = Q.top();
        B[i-w] = p.first;
        while (p.second <= i-w) {
            Q.pop();
            p = Q.top();
        }
        Q.push(Pair(nums[i], i));
    }
    B[n-w] = Q.top().first;
    return B;
}

int LeetCodeSolution::getMaxValue(vector<int>& nums,int begin,int end) {
    int maxValue = nums[begin];
    
    for (int i = begin + 1; i < end; i++) {
        if (nums[i] > maxValue) {
            maxValue = nums[i];
        }
    }
    
    return maxValue;
}

int LeetCodeSolution::maxProfit(vector<int>& prices) {
    /// 贪心算法
    if (prices.size() == 0) {
        return 0;
    }
    
    unsigned long length = prices.size();
    int res = 0;
    int cur = prices[0];
    for (int i = 0; i < length; i++) {
        if (prices[i] > cur) {
            res += (prices[i] - cur);
            cur = prices[i];
        } else {
            cur = prices[i];
        }
    }
    
    return res;
}
