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
using namespace std;
/// 动态规划
class XYdp {
    
    int w[5] = { 0 , 2 , 3 , 4 , 5 };            //商品的体积2、3、4、5
    int v[5] = { 0 , 3 , 4 , 5 , 6 };            //商品的价值3、4、5、6
    int bagV = 8;                            //背包大小
    int dp[5][9] = { { 0 } };                    //动态规划表
    int item[5];                            //最优解情况
    
    void findMax() {                    //动态规划
        for (int i = 1; i <= 4; i++) {
            for (int j = 1; j <= bagV; j++) {
                if (j < w[i])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }
    
    void findWhat(int i, int j) {                //最优解情况
        if (i >= 0) {
            if (dp[i][j] == dp[i - 1][j]) {
                item[i] = 0;
                findWhat(i - 1, j);
            }
            else if (j - w[i] >= 0 && dp[i][j] == dp[i - 1][j - w[i]] + v[i]) {
                item[i] = 1;
                findWhat(i - 1, j - w[i]);
            }
        }
    }
    
    void print() {
        for (int i = 0; i < 5; i++) {            //动态规划表输出
            for (int j = 0; j < 9; j++) {
                cout << dp[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;
        
        for (int i = 0; i < 5; i++)            //最优解输出
            cout << item[i] << ' ';
        cout << endl;
    }
    
    int main()
    {
        findMax();
        findWhat(4, 8);
        print();
        
        return 0;
    }
    

    int knapsack(vector<int> weight,int n,int w) {
        /// states[i][j] 第i个物品，j决策值
        /// 默认都为0
        vector<vector<bool>> states;
        states[0][0] = true;
        if (weight[0] <= w) {
            states[0][weight[0]] = true;
        }
        
        /// 顺序放第i个物品
        for (int i = 1; i < n; ++i) {
            /// 不把第i个物品放入
            for (int j = 0; j <= w; ++j) {
                /// 如果前一个物品决策了，则当前状态等于前一个物品决策 （不放入）
                if (states[i-1][j] == true) states[i][j] = states[i-1][j];
            }
            /// 把第i个物品放入
            for (int j = 0; j <= w-weight[i]; ++j) {
                /// 如果前一个物品决策了，则当前状态加上决策值得 （放入）
                if(states[i-1][j] == true) states[i][j+weight[i]] = true;
            }
        }
        
        /// 打印值
        for (int i = w; i >= 0; --i) {
            if (states[n-1][i] == true) return i;
        }
        
        return 0;
    }
    
    int knapsack2(vector<int>items,int n ,int w) {
        vector<bool>states;
        states[0] = true;
        if (items[0] <= w) {
            states[items[0]] = true;
        }
        
        for (int i =1; i < n; ++i) {
            /// 把第i个物品放入背包 (重复状态)
            for (int j = w - items[i]; j >= 0; --j) {
                if(states[j] == true) states[j+items[i]] = true;
            }
        }
        
        for (int i = w; i >= 0; --i) {
            if (states[i] == true) return i;
        }
        return 0;
    }

 


};
#endif /* XYDp_hpp */
