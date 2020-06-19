//
//  XYHuiSu.hpp
//  XYAlogrithmExercise
//
//  Created by SUGAR Dev on 2020/6/15.
//  Copyright © 2020 Yanci. All rights reserved.
//

#ifndef XYHuiSu_hpp
#define XYHuiSu_hpp

#include <stdio.h>
#include <vector>
using namespace std;
/// 回溯算法
class XYHuiSu {
    
private:
    int maxW = 0;
    int maxV = 0;
    void recursiveKnapSack(vector<int> weight,int n,int w,int i,int cw) {
        /// 如果装满了，或者已经是最大重量，则直接返回
        if (cw == w || i == n ) {
            if (cw > maxW) {
                maxW = cw;
            }
            return;
        }
        /// 不放入i物品
        recursiveKnapSack(weight, n, w, i + 1, cw);
        /// 放入i物品
        if (cw + weight[i] <= w) {
            recursiveKnapSack(weight, n, w, i + 1, cw + weight[i]);
        }
        
    }
    
    void recursiveKnapSack2(vector<int> weight,vector<int> value,int n,int w,int i,int cw,int cv) {
        /// 如果装满了，或者已经是最大重量，则直接返回
        if (cw == w || i == n ) {
            if (cv > maxV) {
                maxV = cv;
            }
            
            if (cw > maxW) {
                maxW = cw;
            }
            return;
        }
        /// 不放入i物品
        recursiveKnapSack2(weight,value, n, w, i + 1, cw, cv);
        /// 放入i物品
        if (cw + weight[i] <= w) {
            recursiveKnapSack2(weight,value, n, w, i + 1, cw + weight[i],cv + value[i]);
        }
        
    }
    
    
public:
    
    /// 简单背包问题
    /// 对于一组不同重量、不可分割的物品，我们需要选择一些装入背包，在满足背包最大重量限制的前提下，背包中物品总重量的最大值是多少呢？
    void knapsack(vector<int> weight,int n,int w) {
        recursiveKnapSack(weight, n, w, 0, 0);
        printf("XYHuiSu knapsack MaxW = %d",maxW);
    }
    
    
    /// 背包问题升级版本:
    /// 我们刚刚讲的背包问题，只涉及背包重量和物品重量。我们现在引入物品价值这一变量。
    /// 对于一组不同重量、不同价值、不可分割的物品，我们选择将某些物品装入背包，在满足背包最大重量限制的前提下，背包中可装入物品的总价值最大是多少呢？
    int knapsack2(vector<int>weight,vector<int>value,int n ,int w) {
        return 0;
    }
    
    
};
#endif /* XYHuiSu_hpp */
