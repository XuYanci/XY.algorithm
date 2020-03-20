//
//  LeetCodeEveryDay.hpp
//  XYAlogrithmExercise
//
//  Created by Yanci on 2020/3/13.
//  Copyright © 2020 Yanci. All rights reserved.
//

#ifndef LeetCodeEveryDay_hpp
#define LeetCodeEveryDay_hpp
#include<iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <stack>
#include <string>
#include <map>
using namespace std;
class LeetCodeEveryDay {
public:
    //    给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
    //
    //    你可以假设数组是非空的，并且给定的数组总是存在多数元素。
    //
    //    来源：力扣（LeetCode）
    //    链接：https://leetcode-cn.com/problems/majority-element
    //    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
    int majorityElement(vector<int>& nums) {
        int count = nums.size() / 2;
        unordered_map<int,int>map;
        for (int i = 0; i < nums.size();i++) {
            map[nums[i]] = map[nums[i]] ? map[nums[i]] + 1 : 1;
            if (map[nums[i]] > count) {
                return nums[i];
            }
        }
        
        return 0;
    }
    
    //    给定一个无序的整数数组，找到其中最长上升子序列的长度。
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        /// 动态规划表
        vector<int>dp((int)nums.size(),0);
        for (int i = 0; i < nums.size(); i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                /// 状态转移方程
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i],dp[j] + 1);
                }
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
    
    //    给定一个包含了一些 0 和 1的非空二维数组 grid , 一个 岛屿 是由四个方向 (水平或垂直) 的 1 (代表土地) 构成的组合。你可以假设二维矩阵的四个边缘都被水包围着。
    //
    //    找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为0。)
    //
    //    来源：力扣（LeetCode）
    //    链接：https://leetcode-cn.com/problems/max-area-of-island
    //    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        if (grid.size() == 0) return 0;
        int maxArea = 0;
        
        int i = 0;
        int j = 0;
        
        for (i = 0; i < grid.size(); i++) {
            for (j = 0; j < grid[0].size();j++) {
                if (grid[i][j] == 1) {
                    int area = 0;
                    dfs_maxAreaOfIsland(grid, i, j, area);
                    maxArea = max(area,maxArea);
                } else {
                    continue;
                }
            }
        }
        
        
        return maxArea;
    }
    
    void dfs_maxAreaOfIsland(vector<vector<int>>& grid,int i,int j,int &area) {
        /// Reverse Exit
        if (i >= grid.size() || j >= grid[0].size()) return ;
        if (grid[i][j] == 0) return ;
        
        
        /// Reset grid zero
        grid[i][j] = 0;
        area += 1;
        
        /// UP
        dfs_maxAreaOfIsland(grid, i - 1, j,area);
        /// Down
        dfs_maxAreaOfIsland(grid, i + 1, j,area);
        /// Left
        dfs_maxAreaOfIsland(grid, i, j - 1,area);
        /// Right
        dfs_maxAreaOfIsland(grid, i, j + 1,area);
    }
    
    string compressString(string S) {
        char SS[50005];
        memset(SS, 0, 50005);
        char *ss = (char*)S.c_str();
        char *ss1 = ss + 1;
        int n = 1;
        int p = 0;
        while(*ss1 != '\0' && p < 50000) {
            if (*ss1 == *ss) {
                n++;
            }
            else {
                SS[p++] = *ss;
                string a =  to_string(n);
                memcpy(&SS[p],(char*)a.c_str(),a.size());
                p+=a.size();
                n = 1;
            }
            ss = ss + 1;
            ss1 = ss1 + 1;
        }
        
        SS[p++] = *ss;
        string a =  to_string(n);
        memcpy(&SS[p],(char*)a.c_str(),a.size());
        p+=a.size();
        
        return S.size() <= p ? S : SS;
        
    }
    //    给你一份『词汇表』（字符串数组） words 和一张『字母表』（字符串） chars。
    //
    //    假如你可以用 chars 中的『字母』（字符）拼写出 words 中的某个『单词』（字符串），那么我们就认为你掌握了这个单词。
    //
    //    注意：每次拼写时，chars 中的每个字母都只能用一次。
    //
    //    返回词汇表 words 中你掌握的所有单词的 长度之和。
    //
    //    来源：力扣（LeetCode）
    //    链接：https://leetcode-cn.com/problems/find-words-that-can-be-formed-by-characters
    //    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
    int countCharacters(vector<string>& words, string chars) {
        int count = 0;
        
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            string cc = chars;
            int idx;
            bool isExist = true;
            for (int j = 0; j < word.length();j++) {
                char a = word[j];
                idx= (int)cc.find(a);
                if(idx == string::npos ) {
                    isExist = false; break;
                } else {
                    cc.erase(idx,1);
                }
            }
            
            if (isExist) {
                count += word.length();
            }
            
        }
        
        return count;
    }
    //    矩形以列表 [x1, y1, x2, y2] 的形式表示，其中 (x1, y1) 为左下角的坐标，(x2, y2) 是右上角的坐标。
    //
    //    如果相交的面积为正，则称两矩形重叠。需要明确的是，只在角或边接触的两个矩形不构成重叠。
    //
    //    给出两个矩形，判断它们是否重叠并返回结果。
    //
    //    来源：力扣（LeetCode）
    //    链接：https://leetcode-cn.com/problems/rectangle-overlap
    //    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
    /// 这道题用了官方题解，一开始思考的是重叠部分，发现太多情况判断。
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return !(rec1[2] <= rec2[0] ||   // left
                 rec1[3] <= rec2[1] ||   // bottom
                 rec1[0] >= rec2[2] ||   // right
                 rec1[1] >= rec2[3]);    // top
        
        
    }
    
    //    给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。
    //
    //    在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。
    /// 思路1:
    /// 判断重复字符
    /// 最终结果是重复字符数+未重复字符数都算为(1)
    /// hashmap遍历
    /// 思路2:
    /// 大写字母26，小写字母26，可以字符转成int存放到数组对应位置
    /// 遍历数组即可
    int longestPalindrome(string s) {
        
        //
        //        unordered_map<char,int> _map;
        //        for (int i = 0; i < s.length();i++) {
        //            char c = s[i];
        //            if (_map[c]) {
        //                _map[c] = _map[c]+1;
        //            } else {
        //                _map[c] = 1;
        //            }
        //        }
        //
        //
        //        std::unordered_map<char,int>::iterator iter;
        //        int count = 0;
        //        bool flag = false; /// 标记未重复数目
        //        for (iter=_map.begin(); iter!=_map.end(); iter++)
        //        {
        //
        //            if(iter->second == 1 && flag == false) {
        //                count += 1; flag = true;
        //            } else if(iter->second > 1) {
        //
        //                if (iter->second % 2 == 0) {
        //                    count+= iter->second ;
        //                } else {
        //                    count+= (flag == false ? iter->second : iter->second -1) ;
        //                    flag = true;
        //                }
        //            }
        //        }
        //
        //
        //        return count;
        
        /// Solution 2
        int _map[125];
        memset(_map, 0, sizeof(int) * 125);
        int count = 0;
        bool flag = false; /// 标记未重复数目
        for (int i = 0; i < s.length();i++) {
            int c = s[i];
            if (_map[c]) {
                _map[c] = _map[c]+1;
            } else {
                _map[c] = 1;
            }
        }
        
        for (int i = 0; i < 125;i++)
        {
            int j = _map[i];
            if(j == 1 && flag == false) {
                count += 1; flag = true;
            } else if(j > 1) {
                
                if (j % 2 == 0) {
                    count+= j ;
                } else {
                    count+= (flag == false ? j : j -1) ;
                    flag = true;
                }
            }
        }
        
        return count;
        
    }
    
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        /// 1.排序
        sort(arr.begin(),arr.begin()+arr.size());
        /// 2.copy K个数到排序
        vector<int> copyArray;
        copyArray.assign(arr.begin(), arr.begin() + k);
        return copyArray;
    }
};

#endif /* LeetCodeEveryDay_hpp */
