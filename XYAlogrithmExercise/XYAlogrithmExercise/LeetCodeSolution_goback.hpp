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
using namespace std;
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
    
};
#endif /* LeetCodeSolution_goback_hpp */
