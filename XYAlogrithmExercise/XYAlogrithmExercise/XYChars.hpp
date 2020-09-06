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
        for (int i = 0; i < SIZE; i++) {
            bc[i] = -1;
        }
        /// 如果有相同的ascii，取最后一个，因为坏字符在后面哦
        for (int i = 0; i < m; ++i) {
            int ascii = (int)b[i];
            bc[ascii] = i;
        }
    }
    
    /// 公共后缀子串
    /// suffix 后缀记录
    /// prefix 前缀记录
    void bm_generateGS(vector<char>b,int m,vector<int>suffix,vector<bool>prefix) {
        for (int i = 0; i < m; ++i) {
            suffix[i] = -1;
            prefix[i] = false;
        }
        
        for (int i = 0; i < m - 1; ++i) { /// b[0,i]
            int j = i;
            int k = 0;
            while (j >= 0 && b[j] == b[m-1-k]) { /// 与b[0,m-1]求公共后缀子串
                --j;
                ++k;
                suffix[k] = j + 1;
            }
            /// 如果公共后缀子串也是模式串的前缀子串
            if ( j==-1) {
                prefix[k] = true;
            }
        }
    }
    
    // j表示坏字符对应的模式串中的字符下标; m表示模式串长度
    int bm_moveByGS(int j,int m,vector<int>suffix,vector<bool>prefix) {
        int k = m - 1 - j; /// 好后缀长度
        /// 存在好后缀模式子串,移动位数: move = j - suffix[k] + 1
        if (suffix[k] != -1) return j - suffix[k] + 1;
        /// 否则看看是否存在公共后缀子串也是前缀子串，有就移动呗
        for (int r = j+2; r<= m-1; ++r) {
            if (prefix[m-r] == true) {
                return r;
            }
        }
        return m;
    }
    
    /// BM
    /// 题目:主串M，模式串N ( 10)， 查找模式串 (1)
    // a,b表示主串和模式串；n，m表示主串和模式串的长度。
    /// 返回的是匹配的下标
    int bm(vector<char>a,int n,vector<char>b,int m) {
        vector<int>bc(0,SIZE);
        bm_generateBC(b, m, bc); /// 构建坏字符哈希表
        vector<int>suffix(0,m);
        vector<bool>prefix(0,m);
        bm_generateGS(b, m, suffix, prefix); /// 构建好后缀
        int i = 0;
        /// 最多匹配 n - m , i代表主串匹配开始地址
        while (i <= n - m) {
            int j;
            /// 倒序匹配字符串
            for (j = m -1; j >= 0; --j) {
                if(a[i+j]!=b[j])break;
            }
            // 匹配成功，返回下标
            if (j<0){
                return i;
            }
            /// 存在坏字符，则计算移动位置
            int x = j-bc[(int)a[i+j]];
            int y = 0;
            /// 如果存在好后缀
            if (j < m-1) {
                /// 计算好后缀
                y = bm_moveByGS(j,m, suffix, prefix);
            }
            /// 取坏字符，好后缀比较大一个（⚠️坏字符偏移计算可能是负数)
            i = i + max(x, y);
        }
        return -1;
    }
    
    /// KMP
    void kmp() {
        
    }
    
private:
    int SIZE = 256;
    
};
#endif /* XYChars_hpp */
