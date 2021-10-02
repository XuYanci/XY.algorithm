//
//  XYGreed.hpp
//  XYAlogrithmExercise
//
//  Created by Yanci on 2020/3/14.
//  Copyright © 2020 Yanci. All rights reserved.
//

#ifndef XYGreed_hpp
#define XYGreed_hpp
#include <vector>
#include <stdio.h>
using namespace std;
/// 贪心算法
class XYGreed {
    
    /// 跳跃游戏
    bool canJump(vector<int>& nums) {
        int n = (int)nums.size();
        
        /// 能达到的最大部署
        int greatest = 0;
        for (int i = 0; i < n; i++) {
            /// 判断是否在最大步数之内
            if(i <= greatest) {
                greatest = max(greatest, i + nums[i]);
                /// 如果到达n，返回成功
                if (greatest >= n) {
                    return  true;
                }
            }
        }
        
        return false;
    }
    
};
#endif /* XYGreed_hpp */
