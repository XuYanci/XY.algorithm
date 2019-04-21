//
//  XYSort.cpp
//  XYAlogrithmExercise
//
//  Created by Yanci on 2019/4/21.
//  Copyright © 2019 Yanci. All rights reserved.
//

#include "XYSort.hpp"
#include <iostream>
#include <vector>
using namespace std;

XYSort::XYSort(){
    
}

XYSort::~XYSort(){
    
}

void XYSort::bubleSort(int *array, int count,bool asc) {
    cout << "BUBBLE SORT" << endl;
    cout << "origin array is " << endl;
    for (int i = 0; i <  count; i++) {
        cout << array[i] << ',';
    }
    cout << endl;
    // 单次遍历，交换大小，最大的在最后  （升序）
    if (asc) {
        for (int i = 0 ; i < count ; i++) {
            for (int j = 0; j < count -  i - 1 ; j++) {
                // 升序
                if (array[j] > array[j+1]) {
                    int temp = array[j+1];
                    array[j+1] = array[j];
                    array[j] = temp;
                }
            }
        }
    }
    // 单次遍历，交换大小，最小的在最后  （降序）
    else {
        for (int i = 0 ; i < count ; i++) {
            for (int j = 0; j < count -  i - 1 ; j++) {
                /// 降序
                if (array[j] < array[j+1]) {
                    int temp = array[j+1];
                    array[j+1] = array[j];
                    array[j] = temp;
                }
            }
        }
    }
    
    cout << "sort array is " <<  (asc ? "asc":"not asc") << endl;
    for (int i = 0; i <  count; i++) {
        cout << array[i] << ',';
    }
    cout << endl;
}

void XYSort::quickSort(int *array,int count,bool asc) {
    cout << "QUICK SORT" << endl;
    cout << "origin array is " << endl;
    for (int i = 0; i <  count; i++) {
        cout << array[i] << ',';
    }
    cout << endl;
    // 一个有序数组，一个无序数组， 然后无序数组逐个取与有序数组比较并插入到有序数组
    cout << "sort array is " <<  (asc ? "asc":"not asc") << endl;
    for (int i = 0; i <  count; i++) {
        cout << array[i] << ',';
    }
    cout << endl;
}

void XYSort::insertSort(int *array,int count,bool asc) {
    cout << "INSERT SORT" << endl;
    cout << "origin array is " << endl;
    for (int i = 0; i <  count; i++) {
        cout << array[i] << ',';
    }
    cout << endl;
    
    // 一个有序数组，一个无序数组， 默认取第一个元素放到有序数组, 假设最大
    // 然后依次取无序数组，与有序数组比较 (升序，降序)，并做插入操作
    // 比较完毕，则有序数组排序完毕
    vector<int>sortArray(1,array[0]);
    
    /// 外循环，无序列表
    for (int i = 1; i < count; i++) {
        long j;
        int temp = array[i];
        // 与有序数组比较，从最大开始比较
        for (j = sortArray.size() - 1;j >= 0; j--) {
            if (temp > sortArray[j]) {
                sortArray.insert(sortArray.begin() + j + 1, temp);
                break;
            } else {
                continue;
            }
        }
        // 如果是最小的，则插入第一个位置
        if (j < 0) {
            sortArray.insert(sortArray.begin(), temp);
        }
    }
    
    cout << "sort array is " <<  (asc ? "asc":"not asc") << endl;
    for (int i = 0; i <  count; i++) {
        cout << sortArray[i] << ',';
    }
    cout << endl;
}


