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
    
 
//    在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字
//    输入：nums = [3,4,3,3]
//    输出：4
    int onlyOne(vector<int> &nums) {
        return 0;
    }
 
    /// 矩阵相乘 O(n^3)
    int caculateMatrixAB(int A[2][2],int B[2][2]) {
        int C[2][2];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                C[i][j] = 0;
                for (int k = 0; k < 2; k++) {
                    C[i][j] += A[i][k] + B[k][j];
                }
            }
        }
        return 0;
    }
    
 
};
#endif /* XYArrayChars_hpp */
