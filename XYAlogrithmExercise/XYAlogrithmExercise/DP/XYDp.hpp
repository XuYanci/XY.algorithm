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
        if (dpMap[amount]) {
            return dpMap[amount];
        }
        /// 如果金额等于0，则返回0，结束递归
        if (amount == 0) {
            return 0;
        }
        
        /// 如果金额小于0,则返回-1,结束递归(说明没有解决)
        if (amount < 0) {
            return -1;
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
         return  dpMap[amount];
    }
    
    /// 动态规划，使用DP_Table实现 (自下到上)
    /// dp[i] = x, 当目标金额为i的时候，至少需要x枚硬币
    /// 三要素: 重叠子问题，最优子结构，状态转移方程 (子问题间必须独立)
    int coinChange1(vector<int>& coins, int amount) {
        /// 这里为什么要amount + 1
        vector<int> dpTable(amount + 1, amount + 1);
        dpTable[0] = 0;
        
      
        for (int i = 0; i < dpTable.size(); i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] < 0) {
                    continue;;
                }
                
                /// dp[i] = min (dp[i],  dp[i - coins[j]] + 1)
                dpTable[i] = min(dpTable[i],1 + dpTable[i - coins[j]]);
            }
        }

        return (dpTable[amount] == amount + 1) ? -1 : dpTable[amount];;
    }
    
    int main()
    {
        return 0;
    }
    
};
#endif /* XYDp_hpp */
