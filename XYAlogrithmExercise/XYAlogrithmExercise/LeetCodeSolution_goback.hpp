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
using namespace std;

class ListNode_ {
    int val;
    ListNode_(int x) { val = x; }
    public :
    ListNode_ *next;
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
    
    
};


#endif /* LeetCodeSolution_goback_hpp */
