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

using namespace std;
#include <stdio.h>


class JianZhiOffer {
public:
//    找出数组中重复的数字。
//
//
//    在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
//
//    来源：力扣（LeetCode）
//    链接：https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof
//    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
    
    
//    在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
//    
//    来源：力扣（LeetCode）
//    链接：https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof
//    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
};
#endif /* jianzhiOffer_hpp */
