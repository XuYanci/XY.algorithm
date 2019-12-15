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
class XYLFUCache {
public:
    XYLFUCache(int capacity) {
        
    }
    
    int get(int key) {
        return 0;
    }
    
    void put(int key, int value) {
        
    }
};
#endif /* XYCache_hpp */
