//
//  XYArrayChars.hpp
//  XYAlogrithmExercise
//
//  Created by Yanci on 2019/11/24.
//  Copyright © 2019 Yanci. All rights reserved.
//

#ifndef XYArrayChars_hpp
#define XYArrayChars_hpp
#include <vector>
#include <stdio.h>
using namespace std;
class XYArrayChars {
    
    // 反转数组中的元素。
    void reverse(int *v, int N) {
        int i = 0;
        int j = N - 1;
        while (i < j) {
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }
    
    // 给定一个数组和一个值，原地删除该值的所有实例并返回新的长度。
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                ++k;
            }
        }
        return k;
    }
};
#endif /* XYArrayChars_hpp */
