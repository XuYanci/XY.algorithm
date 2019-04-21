//
//  XYSort.cpp
//  XYAlogrithmExercise
//
//  Created by Yanci on 2019/4/21.
//  Copyright © 2019 Yanci. All rights reserved.
//

#include "XYSort.hpp"
#include <iostream>
using namespace std;

XYSort::XYSort(){
    
}

XYSort::~XYSort(){
    
}

void XYSort::bubleSort(int *array, int count,bool asc) {
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

void XYSort::quickSort(int *array) {
    
}

void XYSort::insertSort(int *array) {
    
}


