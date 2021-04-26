//
//  XYHeap.cpp
//  XYAlogrithmExercise
//
//  Created by Yanci on 2019/4/25.
//  Copyright © 2019 Yanci. All rights reserved.
//

#include "XYHeap.hpp"

void Max_Heap::insert_max_heap(ELEMENT item,int *n) {
    if(HEAP_FULL(*n)) {
        return;
    }
    int i = ++(*n);
    for(;(i!=1)&&(item.key > heap[i/2].key);i=i/2) {
        heap[i] = heap[i/2];
    }
    heap[i] = item;
}

ELEMENT Max_Heap::delete_max_heap(int *n) {
    int parent,child;
    ELEMENT temp,item;
    temp = heap[--*n];
    item = heap[1];
    parent = 1;
    child = 2;
    for (;child <= *n; child = child * 2) {
        if ((child < *n) && (heap[child].key < heap[child + 1].key)) {
            child++;
        }
        if(temp.key >= heap[child].key) {
            break;
        }
        heap[parent] = heap[child];
        parent = child;
    }
    heap[parent] = temp;
    return item;
}

void Max_Heap::create_max_heap(void) {
    int total = (*heap).key;
    int child = 2,parent = 1;
    for (int node = total / 2; node > 0; node--) {
        parent = node;
        child = 2 * node;
        int max_node = 2 * node + 1;
        ELEMENT temp = *(heap + parent);
        for(; child <= total; child *= 2,max_node=2*parent + 1) {
            if (child + 1 <= total && (*(heap + child)).key < (*(heap + child + 1)).key) {
                child++;
            }
            if (temp.key > (*(heap+child)).key) {
                break;
            }
            
            *(heap+parent) = *(heap + child);
            parent = child;
        }
        *(heap+parent)=temp;
    }
}

int Max_Heap::create_binary_tree(ELEMENT *heap,int items[MAX_ELEMENTS]) {
    int total;
    if (!items) {
        return 0;
    }
    ELEMENT *temp = heap;
    heap++;
    for(total=1;*items;total++,(heap)++,items=items+1){
        ELEMENT ele = {*items};
        ELEMENT temp_key = {total};
        *temp = temp_key;
        *heap = ele;
    }
    return 1;
}

void Max_Heap::justRun() {
    int items[MAX_ELEMENTS] = {79,66,43,83,30,87,38,55,91,72,49,9};
    ELEMENT *position = heap;
    create_binary_tree(position, items);
    for (int i = 0; (*(heap+i)).key > 0; i++) {
        printf("binary tree element is %d\n",(*(heap + i)).key);
    }
    create_max_heap();
    for (int i = 0; (*(heap+i)).key > 0; i++) {
        printf("heap element is %d\n",(*(heap + i)).key);
    }
}

