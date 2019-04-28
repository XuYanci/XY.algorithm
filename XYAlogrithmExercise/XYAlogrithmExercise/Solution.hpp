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
    // 删除重复元素
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
};


#endif /* Solution_hpp */
