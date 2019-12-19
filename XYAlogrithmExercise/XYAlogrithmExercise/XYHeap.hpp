//
//  XYHeap.hpp
//  XYAlogrithmExercise
//
//  Created by Yanci on 2019/4/25.
//  Copyright © 2019 Yanci. All rights reserved.
//

#ifndef XYHeap_hpp
#define XYHeap_hpp

#include <stdio.h>
#include <list>
#include <vector>
using namespace std;
#define MAX_ELEMENTS 20
#define HEAP_FULL(n) (MAX_ELEMENTS - 1 == n)
#define HEAP_EMPTY(n) (!n)
typedef struct {
    int key;
}ELEMENT;


/// 最大堆
class Max_Heap {
   
    ELEMENT heap[MAX_ELEMENTS];

    public:
    /// 最大堆插入操作
    void insert_max_heap(ELEMENT item,int *n);
    /// 最大堆删除操作
    ELEMENT delete_max_heap(int *n);
    /// 创建最大队
    void create_max_heap(void);
    /// 创建二进制树
    int create_binary_tree(ELEMENT *heap,int items[MAX_ELEMENTS]);

    void __swap(ELEMENT *lhs,ELEMENT *rhs);
    
    void justRun();
};


class Min_Heap {
    void Sift(vector<int> R,int k,int m) {
        int i,j,x;
        int t;
        i = k;
        j = 2 * i;
        t = R[k];
        x = R[k];
        while (j <= m) {
            if ((j < m) && (R[j] > R[j+1])) {
                j++;
            }
            if (x < R[j]) break;
            else {
                R[i] = R[j];
                i = j;
                j = 2 * i;
            }
            
        }
        
        R[i] = t;
    }
    
    void HeapSort(vector<int>R){
        int i;
        int n = (int)R.size();
        for (i = n /2 ;i>=1;i--) {
            Sift(R, i, n);
        }
        for (i = n; i >= 2; i--) {
            swap(R[1], R[i]);
            Sift(R, 1, i-1);
        }
    }
    
};


#endif /* XYHeap_hpp */
