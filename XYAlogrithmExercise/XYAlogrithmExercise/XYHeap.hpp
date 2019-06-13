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
#define MAX_ELEMENTS 20
#define HEAP_FULL(n) (MAX_ELEMENTS - 1 == n)
#define HEAP_EMPTY(n) (!n)
typedef struct {
    int key;
}ELEMENT;

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

    void justRun();
};



#endif /* XYHeap_hpp */
