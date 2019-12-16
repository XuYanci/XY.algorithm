//
//  XYCache.hpp
//  XYAlogrithmExercise
//
//  Created by Yanci on 2019/12/15.
//  Copyright © 2019 Yanci. All rights reserved.
//

#ifndef XYCache_hpp
#define XYCache_hpp

#include <stdio.h>
#include <vector>
#include <map>
#include <list>
#include <unordered_map>
using namespace std;

class XYLRUCache {
    
    /// 容量
    int _capacity;
    /// 存放项 (按时间排序)
    map<int,int> items;
    /// 存放Keys
    vector<int> keys;
    map<int,int>::iterator iter;
    
public:
    XYLRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        int val = items[key] ? items[key] : -1;
        if (val!=-1){
            put(key,val);
        }
        return  val;
    }
    
    void put(int key, int value) {
        int findIndex = -1;
        for (int i = 0; i < keys.size(); i++) {
            if (key == keys[i]) {
                findIndex = i;
                break;
            }
        }
        
        if (findIndex != -1) {
            keys.erase(keys.begin() + findIndex);
            keys.insert(keys.begin(), key);
            items[key] = value;
            return;
        }
        keys.insert(keys.begin(), key);
        items[key] = value;
        
        if (keys.size() > _capacity) {
            items[keys.back()] = NULL;
            keys.erase(keys.end() - 1);
            
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/// LFU Cache
/// Refer to https://mp.weixin.qq.com/s/XBP-38JlpYHTTXIKTTdAXg
class XYLFUCache {
    
    /// 总容量
    int cap;
    /// 当前容量
    int size;
    /// 存储最小次数
    int minFreq;
    /// Map<Key,<Value,Freq>>
    unordered_map<int, pair<int, int>> valueFreqMap;
    /// Map<Freq,List>
    unordered_map<int, list<int>> freqListMap;
    /// Map<Key,Iter>
    unordered_map<int, list<int>::iterator> iterMap;
    
    
public:
    XYLFUCache(int capacity) {
        size = 0;
        cap = capacity;
    }
    
    int get(int key) {
        
        /// 查找ValueFreq里面是否存在Key，不存在则代表没有存此Key的Value
        if (valueFreqMap.count(key) == 0) return -1;
        
        /// 根据Freq Key找到Freq列表删除Key节点
        freqListMap[valueFreqMap[key].second].erase(iterMap[key]);
        /// Freq增加1
        valueFreqMap[key].second++;
        /// 根据Freq Key找到Freq列表插入到尾巴节点
        freqListMap[valueFreqMap[key].second].push_back(key);
        /// 记录IterMap Key对应的Item
        iterMap[key] = --freqListMap[valueFreqMap[key].second].end();
        /// 如果最小Freq列表为空，则minFreq++ (每次get,put都会调用这个方法，主要是刷新minFreq)
        if(freqListMap[minFreq].size() == 0) {
            minFreq++;
        }
        /// 返回Key对应的值
        return valueFreqMap[key].first;
    }
    
    void put(int key, int value) {
        /// 如果容量小于等于0，直接返回
        if (cap <= 0) return;
        ///获取Key存储的值 （这里主要是为了刷新Key次数排序以及Key时间排序)
        int storedValue = get(key);
        /// 如果存在值，则重新赋值
        if (storedValue != -1) {
            valueFreqMap[key].first = value;
            return;
        }
        
        /// 如果超过容量了
        if (size >= cap) {
            /// 删除最小次数以及以及最少访问节点 Key (最近最少访问啊嘛)
            valueFreqMap.erase(freqListMap[minFreq].front());
            /// 删除IterMap对应的Key
            iterMap.erase(freqListMap[minFreq].front());
            /// 删除Key
            freqListMap[minFreq].pop_front();
            /// 减少容量
            size--;
        }
        
        /// 如果没有超过容量,则赋予默认值
        valueFreqMap[key] = {value,1};
        /// Freq[1]插入该Key
        freqListMap[1].push_back(key);
        
        /// IterMap记录该Key
        iterMap[key] = --freqListMap[1].end();
        /// 记录最小Freq
        minFreq = 1;
        /// 增加容量
        size++;
        
    }
};
#endif /* XYCache_hpp */
