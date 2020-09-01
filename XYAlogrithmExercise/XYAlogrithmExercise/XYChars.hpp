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
            /// 逐个遍历比较
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
        for (int i = 0; i < m ; i++) {
            hash_a += a[i];
        }
        
        vector<int>hash_b(n-m+1,0); /// 计算b哈希值,a子串长度计算
        
        /// 计算出第一个b值
        for (int j = 0; j < m; j++) {
            hash_b[0] += b[j];
        }
        
        /// 递推计算b值
        for (int j = 1; j < n-m; j++) {
            hash_b[j] = hash_b[j - 1] - b[j - 1] + b[j - 1 + m];
        }
        
        int offset = 0;
        for (int i = 0; i < n - m + 1; i++) {
            /// 如何哈希值相同，在做一次比较避免哈希冲突
            if (hash_a == hash_b[offset]) {
                for(int j = 0;j < m;j++){
                    if (a[j] != b[j + offset]) {
                        break;
                    }
                }
                break;
            }
            offset+=1;
        }
    }
    
    /// 坏字符散列表
    void bm_generateBC(vector<char>b,int m,vector<int>bc) {
        
    }
    
    /// 公共后缀子串
    void bm_generateGS(vector<char>b,int m,vector<int>suffix,vector<bool>prefix) {
        
    }
    
    
    // j表示坏字符对应的模式串中的字符下标; m表示模式串长度
    int bm_moveByGS(int j,int m,vector<int>suffix,vector<bool>prefix) {
        return 0;
    }
    
    /// BM
    /// 题目:主串M，模式串N ( 10)， 查找模式串 (1)
    // a,b表示主串和模式串；n，m表示主串和模式串的长度。
    int bm(vector<char>a,int n,vector<char>b,int m) {
        return 0;
    }
    
    /// KMP
    void kmp() {
        
    }
    
private:
    int SIZE = 256;
    
};
#endif /* XYChars_hpp */
