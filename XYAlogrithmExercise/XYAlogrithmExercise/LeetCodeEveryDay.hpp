//
//  LeetCodeEveryDay.hpp
//  XYAlogrithmExercise
//
//  Created by Yanci on 2020/3/13.
//  Copyright © 2020 Yanci. All rights reserved.
//

#ifndef LeetCodeEveryDay_hpp
#define LeetCodeEveryDay_hpp

#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <stack>

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
    
    
};

#endif /* LeetCodeEveryDay_hpp */
