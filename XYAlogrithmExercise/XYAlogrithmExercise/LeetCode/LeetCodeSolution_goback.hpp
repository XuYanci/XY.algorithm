//
//  LeetCodeSolution_goback.hpp
//  XYAlogrithmExercise
//
//  Created by Yanci on 2019/12/2.
//  Copyright © 2019 Yanci. All rights reserved.
//

#ifndef LeetCodeSolution_goback_hpp
#define LeetCodeSolution_goback_hpp

#include <stdio.h>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
using namespace std;

class ListNode_ {
public:
    int val;
    ListNode_ *next;
    ListNode_(int x) { val = x; }
};
class LeetCodeSolutionGoBack {
    
public:
    
    //    给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
    //
    //    你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
    //
    //    示例:
    //
    //    给定 nums = [2, 7, 11, 15], target = 9
    //
    //    因为 nums[0] + nums[1] = 2 + 7 = 9
    //    所以返回 [0, 1]
    //
    //    来源：力扣（LeetCode）
    //    链接：https://leetcode-cn.com/problems/two-sum
    //    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
    //
    /// 思路1
    /// 暴力解法: 组合，取2个数字， C(2/m)
    /// 假设 N = 4 , N = 2 ,  ( 4 x 3 x 2 x 1 ) / ( 2 x ( 2 x 1)) = 6
    /// 思路2
    /// 双哈希表
    /// 思路3
    /// 单哈希表
    /// 遇到一个问题：就是Key相同情况下需要区别
    /// [3,3] 如果判断是  if (_map[nums[i]] && _map[target-nums[i]]) 则得出结果是 : 1 ,1
    /// 如果判断是   if (_map[nums[i]] && _map[target-nums[i]] != i)  则得出结果是: 0 , 1
    
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> sumTwo;
        
        
        /// Solution 2
        map<int,int> _map;
        for (int i = 0; i < nums.size();i++) {
            _map[nums[i]] = i;
        }
        
        
        for (int i = 0; i < nums.size(); i++) {
            if (_map[nums[i]] && _map[target-nums[i]] != i) {
                sumTwo.push_back(i);
                sumTwo.push_back(_map[target-nums[i]]);
                return sumTwo;
            }
        }
        
        /// Solution 1
        //        for (int i = 0; i < nums.size(); i++) {
        //            for (int j = i + 1; j < nums.size();j++) {
        //                if (nums[i] + nums[j] == target) {
        //                    sumTwo.push_back(i);
        //                    sumTwo.push_back(j);
        //                    return sumTwo;
        //                }
        //            }
        //        }
        
        /// Solution 3
        //        map<int,int> _map;
        //        map<int,int>::iterator it1;
        //        for(int i = 0; i < nums.size();i++) {
        //            it1 = _map.find(target - nums[i]);
        //            if (it1 != _map.end() ) {
        //                sumTwo.push_back(_map[target-nums[i]] );
        //                sumTwo.push_back(i);
        //                return sumTwo;
        //            }
        //            _map[nums[i]] = i;
        //
        //        }
        
        
        return sumTwo;
    }
    
    
    //    给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
    //
    //    示例 1:
    //
    //    输入: 123
    //    输出: 321
    //     示例 2:
    //
    //    输入: -123
    //    输出: -321
    //    示例 3:
    //
    //    输入: 120
    //    输出: 21
    //
    //    来源：力扣（LeetCode）
    //    链接：https://leetcode-cn.com/problems/reverse-integer
    //    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
    //    思路一
    //    字符串反转，利用系统库进行字符串反转，字符串转int,int转字符串的方式，有点hack
    //    思路二
    //    LIFO, 从个位，逐个入栈 (个位，百位，千位) ，然后逐个出栈计算得出结果。(因为知道长度)可以进行Pow(10,i)
    //    思路三
    //    直接计算 (需要提前知道数字长度)，这样的话就可以进行提前运算
    ///   溢出类型用Long表示
    
    int reverse(int x) {
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
    
    int reverse0(long x) {
        string s = to_string(abs(x));
        ::reverse(s.begin(),s.end());
        long val = x < 0 ?  -stol(s) : stol(s);
        if (val < (int)pow(-2, 31)|| val > (int)pow(2, 31) ) {
            val = 0;
        }
        return (int)val;
    }
    
    int reverse1(int x) {
        int n = 0;
        int nDigits = to_string(abs(x)).length() - 1;
        long y = 0;
        
        int val = x / (long)pow(10, n) ;
        while (val != 0) {
            val = x / (long)pow(10, n);
            y +=  (val % 10) * pow(10, nDigits - n);
            if (y < (int)pow(-2, 31)|| y > (int)pow(2, 31) ) {
                y = 0;break;
            }
            n++;
        }
        
        return (int)y;
    }
    
    int reverse2(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
    //    编写一个函数来查找字符串数组中的最长公共前缀。
    //
    //    如果不存在公共前缀，返回空字符串 ""。
    //
    //    示例 1:
    //
    //    输入: ["flower","flow","flight"]
    //    输出: "fl"
    //    示例 2:
    //
    //    输入: ["dog","racecar","car"]
    //    输出: ""
    //    解释: 输入不存在公共前缀。
    //
    //    来源：力扣（LeetCode）
    //    链接：https://leetcode-cn.com/problems/longest-common-prefix
    //    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
    //    思路一
    //    以第一个字符串作为base,其实最长公共也就是第一个字符串的size了。
    //    然后逐个字符串比较，遇到不同则退出，并返回最长公共前缀即可。
    string longestCommonPrefix(vector<string>& strs) {
        int prefix_length = 0;
        if (strs.size() == 0) return "";
        if (strs.size() == 1) return strs[0];
        
        for (int j = 0; j < strs[0].size();j++) {
            char p = strs[0][prefix_length];
            for (int i = 1; i < strs.size(); i++) {
                if(strs[i][prefix_length] != p) {
                    string prefix = strs[0].substr(0,prefix_length);
                    return prefix;
                }
            }
            prefix_length++;
        }
        
        /// 正好第一个比较完毕，并没有找到不同的字符串例如: ["ab","abc"]
        return strs[0];
    }
    
    string longestCommonPrefix1(vector<string>& strs) {
        if(strs.size()==0) return "";
        auto s1 = max_element(strs.begin(),strs.end());
        auto s2 = min_element(strs.begin(),strs.end());
        auto pair = mismatch(s1->begin(),s1->end(),s2->begin());
        return string(s1->begin(),pair.first);
    }
    
    //    给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
    //
    //    有效字符串需满足：
    //
    //    左括号必须用相同类型的右括号闭合。
    //    左括号必须以正确的顺序闭合。
    //    注意空字符串可被认为是有效字符串。
    //
    //    示例 1:
    //
    //    输入: "()"
    //    输出: true
    //    示例 2:
    //
    //    输入: "()[]{}"
    //    输出: true
    //    示例 3:
    //
    //    输入: "(]"
    //    输出: false
    //    示例 4:
    //
    //    输入: "([)]"
    //    输出: false
    //    示例 5:
    //
    //    输入: "{[]}"
    //    输出: true
    //
    //    来源：力扣（LeetCode）
    //    链接：https://leetcode-cn.com/problems/valid-parentheses
    //    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
    
    /// 解法一、
    /// 如果是 (,{,[入栈
    /// 如果是 ),},]判断栈顶是否对应的左部分，是则出栈，否则代表无效
    /// 最终如果是空则代表合法的
    bool isValid(string s) {
        stack<char> _stack;
        unsigned int length = s.length();
        char c[length+1];
        strcpy(c,s.c_str());
        for (int i = 0; i < length; i++) {
            if (_stack.empty()) {
                _stack.push(c[i]);
            }
            else if (c[i] == ')' ) {
                if (_stack.top() == '(')
                    _stack.pop();
                else return false;
            }
            else if (c[i] == '}' ) {
                if (_stack.top() == '{')
                    _stack.pop();
                else
                    return false;
            }
            else if (c[i] == ']') {
                if ( _stack.top() == '[')
                    _stack.pop();
                else return false;
            } else {
                _stack.push(c[i]);
            }
        }
        
        return _stack.empty() ? true : false;
    }
    
    //    根据每日 气温 列表，请重新生成一个列表，对应位置的输入是你需要再等待多久温度才会升高超过该日的天数。如果之后都不会升高，请在该位置用 0 来代替。
    //
    //    例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。
    //
    //    提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。
    //
    //    来源：力扣（LeetCode）
    //    链接：https://leetcode-cn.com/problems/daily-temperatures
    //    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
    
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> s;
        int size = (int)T.size();
        vector<int> _vector(size , 0);
        for(int i = 0; i < size; i++){
            while(!s.empty()&&T[s.top()]<T[i]){
                _vector[s.top()]= i-s.top();
                s.pop();
            }
            s.push(i);
        }
        
        return _vector;
    }
    
    /// 官方题解
    vector<int> dailyTemperatures1(vector<int> &T) {
        vector<int> ans (T.size());
        
        /// next数组记录温度的索引位置
        /// warmer_index记录比当前温度高的索引位置，取最小值
        /// warmer_index - i 则是当前温度到比当前温度高的步伐
        vector<int> next(101,INT_MAX);
        /// 逆序
        for (int i = T.size() - 1; i >= 0; --i) {
            int warmer_index = INT_MAX;
            
            /// warmer_index记录比当前温度高的索引位置，取最小值
            for (int t = T[i] + 1; t<=100;++t) {
                if (next[t] < warmer_index) {
                    warmer_index = next[t];
                }
            }
            if (warmer_index < INT_MAX) {
                ans[i] = warmer_index - i;
            }
            next[T[i]] = i;
        }
        
        return ans;
    }
    
    /*
     给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
     
     示例：
     
     给定一个链表: 1->2->3->4->5, 和 n = 2.
     
     当删除了倒数第二个节点后，链表变为 1->2->3->5.
     
     来源：力扣（LeetCode）
     链接：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list
     著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
     思路：
     
     1. 用数组保存所有节点信息，缺点需要遍历两次
     然后取删除节点的前一个节点也就是 int index = (int)listVector.size() - n - 1;
     如果index < 0, 则代表是第一个节点，head = head -> next
     如果index >= 0 则代表非并非第一个节点, node->next = node->next->next;
     
     2. 双指针技巧，P1,P2，间隔N , 然后P2到达底部也就代表P1就是倒数第N个需要删除。(代码晚点实现)
     */
    
    ListNode_ *removeNthFromEnd(ListNode_ *head, int n) {
        ListNode_ *tail = head;
        vector<ListNode_ *>listVector;
        listVector.push_back(head);
        while (tail->next != NULL) {
            tail = tail->next;
            listVector.push_back(tail);
        }
        
        int index = (int)listVector.size() - n - 1;
        
        if (index < 0) {
            head = head->next;
            return head;
        }
        ListNode_ *node = listVector[index];
        node->next = node->next->next;
        
        return head;
    }
    
    //将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
    //
    //示例：
    //
    //输入：1->2->4, 1->3->4
    //输出：1->1->2->3->4->4
    //
    //来源：力扣（LeetCode）
    //链接：https://leetcode-cn.com/problems/merge-two-sorted-lists
    //著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
    /// 解法一、
    /// 参考归并排序 (分而治之中的治)
    ListNode_* mergeTwoLists(ListNode_* l1, ListNode_* l2) {
        ListNode_ *head = new ListNode_(0);
        ListNode_ *pHead = head;
        while(l1!=NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                pHead->next = l1;
                pHead = l1;
                l1 = l1->next;
            }
            else {
                pHead->next = l2;
                pHead = l2;
                l2 = l2->next;
            }
        }
        
        while (l1 != NULL) {
            pHead->next = l1;
            pHead = l1;
            l1 = l1->next;
        }
        
        while (l2 != NULL) {
            pHead->next = l2;
            pHead = l2;
            l2 = l2->next;
        }
        
        return head->next;
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        /// BFS
        queue<int>_queue;
        int size = (int)nums.size();
        int i = 0;
        _queue.push(0);
        int counter = 0;
        while (i < size) {
            int sizeCounter = 0;
            int size1 = (int)_queue.size();
            while (sizeCounter < size1) {
                int front = _queue.front();
                int val = front + nums[i];
                int val1 = front - nums[i];
                
                _queue.push(val);
                _queue.push(val1);
                _queue.pop();
                sizeCounter++;
                if (val == S && i == size - 1) {
                    counter++;
                }
                if (val1 == S && i == size - 1) {
                    counter++;
                }
            }
            i++;
        }
        
        
        //        while (_queue.empty() == false) {
        //            int front = _queue.front();
        //            _queue.pop();
        //            if (front == S) {
        //                counter++;
        //            }
        //        }
        return counter;
    }
    
    int findTargetSumWays1(vector<int>& nums, int S) {
        /// DFS
        int counter = 0;
        dfs_findTargetSumWays(0, 0, nums, S,counter);
        return counter;
    }
    void dfs_findTargetSumWays(int curVal,int i,vector<int>& nums,int S,int &counter) {
        
        if (i == nums.size()) {
            if ( S == curVal ){
                counter++;
            }
            return;
        }
        dfs_findTargetSumWays(curVal + nums[i], i+1, nums, S,counter);
        dfs_findTargetSumWays(curVal - nums[i], i+1, nums, S,counter);
    }
    
    ListNode_* swapPairs(ListNode_* head) {
        /// 解法一、双指针
        //        ListNode_ *p1 = head;
        //        ListNode_ *p2 = p1 ? p1->next : NULL;
        //        head = p2 ? p2 : head;
        //        ListNode_ *prep2 = NULL;
        //        while (p1 != NULL && p2 != NULL) {
        //            ListNode *p3 = p2->next;
        //            p2->next = p1;
        //            p1->next = p3;
        //            if (prep2) {
        //                prep2->next = p2;
        //            }
        //            prep2 = p1;
        //            p1 = p3;
        //            p2 = p1 ? p1->next : NULL;
        //        }
        //        return head;
        
        
        /// 解法二、 四指针 (??? 我的天)
        ListNode_ *p1 = head;
        ListNode_ *p2 = p1 ? p1->next : NULL;
        head = p2 ? p2 : head;
        
        while(p1 != NULL && p2 != NULL) {
            ListNode_ *p3 = p2->next;
            ListNode_ *p4 = p3 ? (p3->next!=NULL ? p3->next: p3) : NULL;
            p1->next = p4;
            p2->next = p1;
            p1 = p3;
            p2 = p1 ? p1->next : NULL;
        }
        return head;
    }
    
    
    //给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
    //
    //不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
    //
    //示例 1:
    //
    //给定数组 nums = [1,1,2],
    //
    //函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。
    //
    //你不需要考虑数组中超出新长度后面的元素。
    //示例 2:
    //
    //给定 nums = [0,0,1,1,1,2,2,3,3,4],
    //
    //函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。
    //
    //你不需要考虑数组中超出新长度后面的元素。
    //
    //来源：力扣（LeetCode）
    //链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array
    
    int removeDuplicates(vector<int>& nums) {
        /// 解法一、由于数组是已经排好序，比较的值与当前值不同，则插入，并且设置不同值为当前值
        //    if (nums.size() == 0) return 0;
        //
        //    int count = 0;
        //    for (int i = 0 ; i < nums.size();i++) {
        //        if(nums[count] != nums[i]) {
        //            nums[++count] = nums[i];
        //        }
        //    }
        //    return count + 1;
        
        /// 解法二、原地删除元素,p_counter - 1 记录前一个，p_counter 记录后一个元素
        int p_counter = 1;
        while(p_counter < nums.size()) {
            /// 如果前后对比一样，则删除前一个数值，同时p_counter保持不变，这样自然后移一位
            if (nums[p_counter - 1] == nums[p_counter] ) {
                nums.erase(nums.begin() + p_counter - 1);
            } else {
                p_counter++;
            }
        }
        return (int)nums.size();
    }
    
    //给定一个 n × n 的二维矩阵表示一个图像。
    //
    //将图像顺时针旋转 90 度。
    //
    //说明：
    //
    //你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。
    //
    //示例 1:
    //
    //给定 matrix =
    //[
    // [1,2,3],
    // [4,5,6],
    // [7,8,9]
    // ],
    //
    //原地旋转输入矩阵，使其变为:
    //[
    // [7,4,1],
    // [8,5,2],
    // [9,6,3]
    // ]ee
    //
    //来源：力扣（LeetCode）
    //链接：https://leetcode-cn.com/problems/rotate-image
    //著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
    /// 解法一、
    /// 推导出公式
    /// N 为 长度
    /// X0,Y0 => Y0,N - X0
    void rotate(vector<vector<int>>& matrix) {
        int n = (int)matrix.size();
        int x0;int y0;
        x0 = 0;
        y0 = 0;
        for (int i = 0; i < n / 2 ;i++) {
            for (int j = 0; j < n - 2 * i - 1;j++) {
                /// 左上角
                int x00 = x0;
                int y00 = y0 + j;
               
                /// 右上角
                int x11 = y00;
                int y11 = n - x00 - 1;
                
                /// 右下角
                int x22 = y11;
                int y22 = n - x11 - 1;
                
                /// 左下角
                int x33 = y22;
                int y33 = n - x22 - 1;
                
                /// temp = 左上角
                int temp = matrix[x00][y00];
                /// temp0 = 右上角
                int temp0 = matrix[x11][y11];
                /// temp1 = 右下角
                int temp1 = matrix[x22][y22];
                /// temp2 = 左下角
                int temp2 = matrix[x33][y33];
                
                /// 左上角 = 左下角
                matrix[x00][y00] = temp2;
                /// 右上角 = 左上角
                matrix[x11][y11] = temp;
                /// 右下角 = 右上角
                matrix[x22][y22] = temp0;
                /// 左下角 = 右下角
                matrix[x33][y33] = temp1;
            }
            x0++;
            y0++;
        }
       
    }
    
    
//    给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
//    求在该柱状图中，能够勾勒出来的矩形的最大面积。
//    解法一、递增栈
//    利用递增栈确保柱形是递增的关系，这样就能计算出值，然后取最大值即可
//    例如柱形是 1,2,3,4,0, 到达0之前是递增关系，遇到0时候，便可以计算出前面的面积，1,1*4,2,2*3,3,3*2,4 取最大值就是最大面积
////  栈比较时候,递增栈( i - stack[top - 1] - 1 ) * a[stack[top]]
////  栈停止 (length - stack[top-1] - 1) * a[stack[top]]
    int largestRectangleArea(vector<int>& heights) {
        int value = 0;
        stack<int> increaseStack;
        increaseStack.push(-1);
        
        /// 递增栈
        for (int i = 0; i < (int)heights.size();i++) {
            
            while(increaseStack.top() != -1
                  && !increaseStack.empty()
                  && heights[increaseStack.top()] > heights[i]) {
                
                int top = increaseStack.top();
                increaseStack.pop();
                int top1 = increaseStack.top();
                /// 公式:  ( i - stack[top - 1] - 1 ) * a[stack[top]]
                value = max(value, ( i - top1 - 1) * heights[top]);
            }
            
            increaseStack.push(i);
        }
        
        int height = (int)heights.size();
        /// 栈停止
        while (increaseStack.size() > 1) {
            int top = increaseStack.top();
            increaseStack.pop();
            int top1 = increaseStack.top();
            /// 公式: (length - stack[top-1] - 1) * a[stack[top]]
            value = max(value,(height - top1 - 1) * heights[top]);
        }
        
        return value;
    }
};
#endif /* LeetCodeSolution_goback_hpp */
