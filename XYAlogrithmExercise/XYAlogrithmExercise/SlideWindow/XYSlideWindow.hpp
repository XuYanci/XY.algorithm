//
//  XYSlideWindow.hpp
//  XYAlogrithmExercise
//
//  Created by XuYanci on 2021/2/5.
//  Copyright © 2021 Yanci. All rights reserved.
//

#ifndef XYSlideWindow_hpp
#define XYSlideWindow_hpp
#include <vector>
#include <stdio.h>
#include <string>
#include <unordered_map>
using namespace std;

class XYSlideWindow {
public:
    /// 滑动窗口思想:
    /// 窗口大小
    /// 窗口增长（右移动）
    /// 窗口缩小（左移动）
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> maxNums;
        
    

        return maxNums;
    }
    
    string minWindow(string s, string t) {
        string minWindowStr;
        
        /** 思路1: 暴力 */
        
        /// 哈希表记录t
//        unordered_map<char, int> tMap;
//        unordered_map<char, int> tMap1;
//        for (char c:t) {
//            tMap[c]++;
//        }
//
//        /// 包含数目
//        int validCount = 0;
//        for (int i = 0; i < s.size(); i++) {
//            /// 重置包含数目
//            validCount = 0;
//            /// 复制哈希表，作为比较依据
//            tMap1 = tMap;
//            for (int j = i; j < s.size(); j++) {
//                /// 如果哈希包含，且值大于0 (代表可比较)
//                if (tMap1.count(s[j]) && tMap1[s[j]] > 0) {
//                    /// 哈希包含减去1
//                    tMap1[s[j]]--;
//                    /// 合法数目+1
//                    validCount++;
//                }
//                /// 如果已经包含足够的数目
//                if (validCount == t.size()) {
//                    string containStr = s.substr(i,j - i + 1);
//                    if (minWindowStr.size() == 0) {
//                        minWindowStr = containStr;
//                        break;
//                    }
//                    else if (minWindowStr.size() > containStr.size()) {
//                        minWindowStr = containStr;
//                        break;
//                    }
//                }
//
//            }
//        }
        
        /** 思路2: 滑动窗口算法*/
        
        /// 滑动窗口
        unordered_map<char, int>window;
        
        /// 需要的参数
        unordered_map<char, int>need;
        
        /// 登记匹配的字符
        for (char c : t) { need[c]++; }
        
        /// 左标
        int left = 0;
        /// 右标
        int right = 0;
        /// 有效数目
        int valid = 0;
        
        /// 当窗口小于原字符串大小
        while (right < s.size()) {
            
            
            /// 判断移入字符是否有效
            if (need.count(s[right]) && window[s[right]] < need[s[right]]) {
                valid++;
            }
            
            /// 滑动窗口标记当前移入字符
            window[s[right]]++;
            
            /// 窗口增大
            right++;
            
            /// 如果已经凑够有效数目，则开始缩小窗口了
            while (valid == t.size()) {
                /// 有效字符串 (ING HERE)
                minWindowStr = s.substr(left,right - left);
                
                /// 判断移出字符是否有效
                if (need.count(s[left]) && window[s[left]] >= need[s[left]]) {
                    valid--;
                }

                
                window[s[left]]--;
                /// 窗口缩小
                left++;
                
            }
            
        }
        
        return minWindowStr;
    }
    
    vector<string> permutation(string s) {
        vector<string> permutation;
        return permutation;
    }
    
    vector<int> findAnagrams(string s, string p) {
        vector<int> anagrams;
        return anagrams;
    }
    
    int lengthOfLongestSubstring(string s) {
        return 0;
    }
};
#endif /* XYSlideWindow_hpp */
