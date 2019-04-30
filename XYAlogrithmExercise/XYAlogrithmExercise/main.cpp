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
    std::vector<int>array6 ;
//    array6.push_back(3);
//    array6.push_back(1);
//    array6.push_back(2);
//    array6.push_back(2);
//    array6.push_back(4);
//    array6.push_back(5);
//    array6.push_back(6);
//    array6.push_back(7);
        array6.push_back(-1200000005);
        array6.push_back(-1200000005);


//    // 移除重复项
//    s->removeDuplicates(array6);
//
//    // 旋转数组
//    s->rotate(array6, 2);
    // 判断是否重复
    s->containsDuplicate(array6);
    return 0;
}
