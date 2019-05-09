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
#include "XYSearch.hpp"
#include "Solution.hpp"

/// XuYanci Alogrithm Exercise
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "XuYanci Alogrithm Exercise!\n";
    
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
    search->divideSearch(array4,5, 100);
 
    // 随机产生9个数
    srand((unsigned)time(NULL));
    int array5[] = {1,3,2,4,5,9,8,7,6};
    for(int i=0;i<9;i++){
        array5[i]=rand()%101;
    }
    // 快速排序
    sort->quickSort(array5, 9, false);
    
    // Leecode
    Solution *s = new Solution();
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
    
    
    int a[6] = {1,2,3,0,0,0};
    int b[3] = {2,5,6};
    
    vector<int> nums1(a,a+6);
    vector<int> nums2(b,b+3);
    
    s->merge(nums1, 3, nums2, 3);
    return 0;
}
