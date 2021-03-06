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
#include <string>
using namespace std;
/// 回溯算法
class XYHuiSu {
    
private:
    int maxW = 0;
    int maxV = 0;
    int minDist = 0;
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
        recursiveKnapSack2(weight,value, n, w, 0, 0,0);
        printf("XYHuiSu knapsack MaxV = %d",maxV);
        return 0;
    }
    
    /**
     假设我们有一个 n 乘以 n 的矩阵 w[n][n]。矩阵存储的都是正整数。棋子起始位置在左上角，终止位置在右下角。我们将棋子从左上角移动到右下角。每次只能向右或者向下移动一位。从左上角到右下角，会有很多不同的路径可以走。我们把每条路径经过的数字加起来看作路径的长度。那从左上角移动到右下角的最短路径长度是多少呢？
     */
    void minDistBT(int i,int j,int dist,vector<vector<int>> w,int n) {
        /// 如果已经到达最右边直接返回
        if (i == n && j == n) {
            if (dist < minDist) {
                minDist = dist;
            }
            return;
        }
        
        /// 下移
        if (i < n) {
            minDistBT(i + 1, j, dist + w[i][j], w, n);
        }
        
        /// 右移
        if (j < n) {
            minDistBT(i, j + 1, dist+w[i][j], w, n);
        }
    }
    
    
    /// 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
    vector<vector<int>> permute1;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>arrange;
        premuteReverse(nums, arrange);
        return permute1;
    }
    
    void premuteReverse(vector<int>& nums, vector<int>&arrange) {
        /// 达到全排列标准 （大小等于nums's count）
        if (arrange.size() == nums.size()) {
            permute1.push_back(arrange);
            return;
        }
        
        /// 遍历数组所有数字
        for (int i = 0; i < nums.size(); i++) {
            /// 取出数字
            int num = nums[i];
            // 判断是否包含取出数字，不包含则继续找
            if (!count(arrange.begin(), arrange.end(), num)) {
                /// 记录该数字
                arrange.push_back(num);
                premuteReverse(nums, arrange);
                /// 删除该数字
                arrange.erase(arrange.end() - 1);
            }
        }
        
    }
    
    //n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
    vector<vector<string>> solveNQueensArray;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        solveNQueensReverse(0,board);
        return solveNQueensArray;
    }
    
    void solveNQueensReverse(int row, vector<string> &board) {
        /// 如果已经走完了，则记录有效棋盘字符串
        if (row == board.size()) {
            solveNQueensArray.push_back(board);
            return;;
        }
        
        /// 获取当前列数
        int col = (int)board[row].size();
        
        /// 穷举
        for (int i = 0; i < col; i++) {
            if (!isValidQueen(board,row,i)) {
                continue;
            }
            board[row][i] = 'Q';
            solveNQueensReverse(row + 1, board);
            board[row][i] = '.';
        }
    }
    
    /// 判断皇后是否放置正确
    /// 任何两个皇后都不能处于同一条横行、纵行或斜线上。
    bool isValidQueen(vector<string> &board,int row,int i) {
      
        /// 判断同一列是否存在皇后
        for (int j = 0; j < row + 1; j++) {
            if (board[j][i] == 'Q') {
                return false;
            }
        }
        
        /// 判断是否在同一行皇后
        for (int j = 0; j < i; j++) {
            if (board[row][j] == 'Q') {
                return false;
            }
        }
        
        /// 判断左上斜 / 右上斜
        for (int j = row - 1; j >= 0 ; j--) {
            if (i - (row - j) >= 0 &&  board[j][i -  (row - j)] == 'Q') {
                return false;
            }
            if (i +  (row - j) < board[j].size() && board[j][i + (row - j)] == 'Q') {
                return false;
            }
        }

     
        return true;
    }
    
};
#endif /* XYHuiSu_hpp */
