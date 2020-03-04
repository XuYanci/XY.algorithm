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
};
#endif /* jianzhiOffer_hpp */
