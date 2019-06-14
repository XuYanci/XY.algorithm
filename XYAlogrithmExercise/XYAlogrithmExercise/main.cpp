//
//  main.cpp
//  XYAlogrithmExercise
//
//  Created by Yanci on 2019/4/21.
//  Copyright © 2019 Yanci. All rights reserved.
//

#include <iostream>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include "XYSort.hpp"
#include "XYHeap.hpp"
#include "XYSearch.hpp"
#include "LeetCodeSolution.hpp"
/// XuYanci Alogrithm Exercise
void alogrithms();
void leetCodes();
 
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "XuYanci Alogrithm Exercise!\n";
    
    alogrithms();
    leetCodes();
//    structures();
    return 0;
}


void structures() {
    /// 最大堆
    Max_Heap *max_heap = new Max_Heap();
    max_heap->justRun();
}


void alogrithms() {
    XYSort *sort = new XYSort();
    XYSearch *search = new XYSearch();
    /// 冒泡排序
    int array[] = {3,2,1,5,4};
    sort->bubleSort(array,5,false);
    
    // 插入排序
    int array1[] = {3,2,1,5,4};
    sort->insertSort(array1, 5, false);
    
    // 选择排序
    int array2[] = {3,2,1,5,4};
    sort->selectSort(array2, 5, false);
    
    // 线性查找
    int array3[] = {3,2,1,5,4};
    search->linearSearch(array3,5, 5);
    
    // 二分查找
    int array4[] = {1,2,3,4,5};
    search->divideSearch(array4,5, 5);
    
    // 随机产生9个数
    srand((unsigned)time(NULL));
    int array5[] = {1,3,2,4,5,9,8,7,6};
    for(int i=0;i<9;i++){
        array5[i]=rand()%101;
    }
    int array6[] = {12,14,25,32,23,45,12,63,24,12};
    // 快速排序
    sort->quickSort(array6, 9, false);
    
    
    // @TODO 归并排序
    for(int i=0;i<9;i++){
        array5[i]=rand()%101;
    }
    sort->mergeSort(array5, 9, false);
    
    /// 堆排序
    int n = 7;
    int items[7] = {87,79,38,83,72,43,91};
    ELEMENT1 heap[7];
    sort->create_binarytree(heap, items, n);
    sort->heap_sort(heap, n);///38,43,72,79,83,87,91

}

void leetCodes() {
    // Leecode
    LeetCodeSolution *s = new LeetCodeSolution();
    std::vector<int>array6 = {1,2,3,4,5,6} ;
    
    // 移除重复项
    s->removeDuplicates(array6);
    // 旋转数组
    s->rotate(array6, 2);
    // 判断是否重复
    s->containsDuplicate(array6);
    // 只存在一个数字
    s->singleNumber(array6);
    // 移动0
    s->moveZeroes(array6);
    
    // 合并两个有序链表
    ListNode *l1 = new ListNode(5);
    ListNode *l2 = new ListNode(1);
    ListNode *l22 = new ListNode(2);
    ListNode *l222 = new ListNode(4);
    l2->next = l22;
    l22->next = l222;
    s->mergeTwoLists(l2, l1);
    
    // 链表反转
    s->reverseList(l2);
    
    // 整数反转
    s->reverse(-2147483648);
    
    // 计算素数
    s->countPrimes(10000);
    
    // 计算斐波那契数
    s->fib(30);
    
    
    int a[9] = {-1,0,0,3,3,3,0,0,0};
    int b[3] = {1,2,2};
    
    vector<int> nums1(a,a+9);
    vector<int> nums2(b,b+3);
    
    // 合并两个有序数组
    s->merge(nums1, 6, nums2, 3);
    
    vector<int>nums{2,7,11,15};
    s->twoSum(nums, 9);
    
    vector<char> array {'a','b','c','d','e','f'};
    s->reverseString(array);
    
    vector<int> array1 {10,9,2,5,3,7,101,18};
    s->lengthOfLIS(array1);
    
    
    LRUCache *cache = new LRUCache( 2 /* 缓存容量 */ );
    
    cache->put(1, 1);
    cache->put(2, 2);
    cache->get(1);       // 返回  1
    cache->put(3, 3);    // 该操作会使得密钥 2 作废
    cache->get(2);       // 返回 -1 (未找到)
    cache->put(4, 4);    // 该操作会使得密钥 1 作废
    cache->get(1);       // 返回 -1 (未找到)
    cache->get(3);       // 返回  3
    cache->get(4);       // 返回  4
    
    LFUCache *cache1 = new LFUCache( 2 /* capacity (缓存容量) */ );
    
    cache1->put(1, 1);
    cache1->put(2, 2);
    cache1->get(1);       // 返回 1
    cache1->put(3, 3);    // 去除 key 2
    cache1->get(2);       // 返回 -1 (未找到key 2)
    cache1->get(3);       // 返回 3
    cache1->put(4, 4);    // 去除 key 1
    cache1->get(1);       // 返回 -1 (未找到 key 1)
    cache1->get(3);       // 返回 3
    cache1->get(4);       // 返回 4
}
