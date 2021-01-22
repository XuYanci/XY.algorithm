//
//  XYDp.hpp
//  XYAlogrithmExercise
//
//  Created by Yanci on 2020/1/2.
//  Copyright © 2020 Yanci. All rights reserved.
//

#ifndef XYDp_hpp
#define XYDp_hpp

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/// 动态规划
class XYdp {
public:
    /// 备忘录 (减少不必要的计算)
    unordered_map<int, int> dpMap;
    /// 零钱兑换
    /// 思路: N叉树遍历，取最小树深度即可，自定向下
    int coinChange(vector<int>& coins, int amount) {
        int ret = coinChangeReverse(coins, amount);
        return ret;
    }
    
    int coinChangeReverse(vector<int>& coins, int amount) {
        /// 如果金额等于0，则返回0，结束递归
        if (amount == 0) {
            return 0;
        }
        
        /// 如果金额小于0,则返回-1,结束递归(说明没有解决)
        if (amount < 0) {
            return -1;
        }
        
        if (dpMap[amount]) {
            return dpMap[amount];
        }
        
        int minCost = INT8_MAX;
        
        /// 递归N叉树
        for (int i = 0; i < coins.size(); i++) {
            int result = coinChangeReverse(coins,amount - coins[i]);
            if (result == -1) {
                continue;
            }
            minCost = min(minCost,result + 1);
        }
         dpMap[amount] = (minCost != INT8_MAX) ? minCost : -1;
         return (minCost != INT8_MAX) ? minCost : -1;
    }
    
    
    
    int main()
    {
        return 0;
    }
    
};
#endif /* XYDp_hpp */
