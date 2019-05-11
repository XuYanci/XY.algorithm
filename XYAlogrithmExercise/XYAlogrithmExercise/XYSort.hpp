//
//  XYSort.hpp
//  XYAlogrithmExercise
//
//  Created by Yanci on 2019/4/21.
//  Copyright © 2019 Yanci. All rights reserved.
//

#ifndef XYSort_hpp
#define XYSort_hpp

#include <stdio.h>
class XYSort {
public:
    XYSort();
    ~XYSort();
    
    // 冒泡排序
    void bubleSort(int *array,int count,bool asc);
    
    // 快速排序
    void quickSort(int *array,int count,bool asc);
    
    // 插入排序
    void insertSort(int *array,int count,bool asc);
    
    // 选择排序
    void selectSort(int *array,int count,bool asc);
    
    // 归并排序
    void mergeSort(int *array,int count,bool asc);
    
    
protected:
    
private:
    // 合并两个有序数组
    void merge(int array0[],int left,int mid,int right,int temp[]);
    void merge_Sort(int arr[],int left,int right,int temp[]);
    
};
#endif /* XYSort_hpp */
