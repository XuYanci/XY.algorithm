//
//  XYChars.hpp
//  XYAlogrithmExercise
//
//  Created by SUGAR Dev on 2020/7/7.
//  Copyright © 2020 Yanci. All rights reserved.
//

#ifndef XYChars_hpp
#define XYChars_hpp

#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

class XYChars {
    /// BF: 暴力查找法
    /// 题目:主串M，模式串N (10)， 查找模式串 (1)
    /// 算法复杂度: (N - M + 1) * M = O(n * m)
    void bf() {
        vector<char>a = {'a','b','c'};
        vector<char>b = {'a','c','b','a','b','b','a','b','c','d'};
        int n = (int)b.size();
        int m = (int)a.size();
        
        int offset = 0;
        bool isMatch = true;
        
        for (int i = 0; i < n - m + 1; i++) {
            isMatch = true;
            /// Recursive Math char
            for(int j = 0;j < m;j++){
                if (a[j] != b[j + offset]) {
                    isMatch = false;
                    break;
                }
            }
            /// Match
            if (isMatch) {
                break;
            }
            /// Not Match, offset one
            else {
                offset +=1;
            }
        }
    }
    /// RK (BF算法升级版，主要是求哈希以及哈希碰撞处理一下)
    /// 题目:主串M，模式串N ( 10)， 查找模式串 (1)
    /// 算法复杂度: O(n)
    void rk() {
        vector<char>a = {'a','b','c'};
        vector<char>b = {'a','c','b','a','b','b','a','b','c','d'};
        
        int n = (int)b.size();
        int m = (int)a.size();
        
        int hash_a = 0; /// 计算a子串哈希值
        vector<int>hash_b(n-m+1,0); /// 计算b哈希值,a子串长度计算
        int offset = 0;
        
        for (int i = 0; i < n - m + 1; i++) {
            if (hash_a == hash_b[offset]) {
                break;
            }
            offset+=1;
        }
    }
    
    /// BM
    /// 题目:主串M，模式串N ( 10)， 查找模式串 (1)
    void bm() {
        
    }
    /// KMP
    void kmp() {
        
    }
};
#endif /* XYChars_hpp */
