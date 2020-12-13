//
//  XYCacheGoBack.hpp
//  XYAlogrithmExercise
//
//  Created by Yanci Xu on 2020/12/13.
//  Copyright © 2020 Yanci. All rights reserved.
//

#ifndef XYCacheGoBack_hpp
#define XYCacheGoBack_hpp
#include <vector>
#include <unordered_map>
#include <stdio.h>
using namespace std;

class XYCacheGoBack {
    
    /// LRU缓存
public:
    class XYLRUCache {
        
        /// 支持缓存大小
        int capacity;
        /// 当前键值大小
        int keyCount = 0;
        /// 键值数组（按访问排序）
        vector<int> keys;
        /// 存储键值对
        unordered_map<int, int> hashMap;
        
    public:
        XYLRUCache() {
            capacity = 2;
            keys = vector<int>(capacity,0);
        }
        
        /// 设置键值对
        /// @param key 键
        /// @param value 值
        void put(int key,int value) {
            /// 如果存在Key,则更新Key位置，并重新赋值
            /// 如果不存在Key，插入Key到首位，如果容量已满，则删除末尾
        if (get(key) == -1) {
                /// 如果已经满了，则删除最后一个键
                if (keyCount + 1> capacity) {
                    keyCount = capacity;
                    hashMap[keys[keyCount -1]] = -1;
                }
                /// 如果未满，则增加键数
                else {
                    keyCount++;
                }      
                /// 移动数组,空出位置
                int n = keyCount - 1;
                while (n > 0) {
                    keys[n] = keys[n-1];
                    n--;
                }
                /// 首位赋值
                keys[n] = key;
            }
            hashMap[key] = value;
        }
        
        
        /// 根据Key获取Value
        /// @param key 键值
        int get(int key) {
            
            /// 如果哈希表里面不存在该key
            if(!hashMap.count(key) || hashMap[key] == -1) {
                return -1;
            }
            
            /// 如果哈希表存在该key，更新key顺序,放到首位
            for (int i = 0; i < keyCount; i++) {
                if (keys[i] == key) {
                    /// 移动数组,空出位置
                    while (i > 0) {
                        keys[i] = keys[i-1];
                        i--;
                    }
                    keys[i] = key;
                    break;
                }
            }
            
            return hashMap[key] ;
        }
    };
    
    /// LFU缓存
    class XYLFUCache {
        
    };
    
};

#endif /* XYCacheGoBack_hpp */
