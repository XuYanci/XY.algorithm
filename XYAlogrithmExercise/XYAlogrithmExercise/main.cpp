//
//  main.cpp
//  XYAlogrithmExercise
//
//  Created by Yanci on 2019/4/21.
//  Copyright © 2019 Yanci. All rights reserved.
//

#include <iostream>
#include "XYSort.hpp"
#include "XYSearch.hpp"

/// XuYanci Alogrithm Exercise
// 排序:
// 冒泡排序
// 插入排序
// 快速排序
// 归并排序
// 堆排序
// 查找:
// 二分查找
// 二叉树:
// 图:
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    

    int array[] = {3,2,1,5,4};
    XYSort *sort = new XYSort();
    sort->bubleSort(array,5,false);
    int array1[] = {3,2,1,5,4};
    sort->insertSort(array1, 5, false);
 
    
    return 0;
}
