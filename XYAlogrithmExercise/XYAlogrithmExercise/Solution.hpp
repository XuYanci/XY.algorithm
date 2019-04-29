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
using namespace std;

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
        int move_nums[l];
        
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
};


#endif /* Solution_hpp */
