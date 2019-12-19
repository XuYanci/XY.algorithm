//
//  XYSort_goback.cpp
//  XYAlogrithmExercise
//
//  Created by Yanci on 2019/12/13.
//  Copyright © 2019 Yanci. All rights reserved.
//

#include "XYSort_goback.hpp"

void XYSortGoBack::quickSort(int *array,int count) {
    
    printf("Quick Sort Source:\n");
    for (int i = 0; i < count; i++) {
        printf("%d,",array[i]);
    }
    
    recursiveQuickSort(array, 0, count - 1);
    
    printf("\n");
    
    
    printf("Quick Sort Result ASC:\n");
    for (int i = 0; i < count; i++) {
        printf("%d,",array[i]);
    }
}

void XYSortGoBack::recursiveQuickSort(int *array,int left,int right) {
    
    if (left > right) return;
    /// Guard i,j,Key temp
    int i,j,temp;
    i = left;
    j = right;
    temp = array[left];
    
    while (i != j) {
        while (array[j] >= temp && i < j ) {
            j--;
        }
        while (array[i] <= temp && i < j) {
            i++;
        }
        
        /// Swap and Continue
        if ( i < j) {
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
    
    
    /// Swap the Key and Change The Key
    array[left] = array[i];
    array[i] = temp;
    
    recursiveQuickSort(array, left, i - 1);
    recursiveQuickSort(array, i + 1, right);
}


void XYSortGoBack::mergeSort(int *array, int count) {
    int temp[count];
    recrusiveMergeSort(array, 0, count,temp);
}

/// 递归体
void XYSortGoBack::recrusiveMergeSort(int *array, int left, int right, int *temp) {
    /// 递归出口
    if(left<right){
        
        /// 递归体
        int mid = (left + right) / 2;
        
        /// 分
        recrusiveMergeSort(array, left, mid,temp);
        recrusiveMergeSort(array, mid + 1, right,temp);
        
        /// 递归函数
        merge(array, left, mid, right, temp);
    }
}

void XYSortGoBack::merge(int *array, int left, int mid, int right, int *temp) {
    int i = left;
    int j = mid + 1;
    int t = 0;
    while (i <= mid && j <= right) {
        if (array[i] < array[j]) {
            temp[t++] = array[i++];
        }
        else {
            temp[t++] = array[j++];
        }
    }
    
    while (i <= mid) {
        temp[t++] = array[i++];
    }
    while (j <= mid) {
        temp[t++] = array[j++];
    }
    
    t = 0;
    
    while (left <= right) {
        array[left++] = temp[t++];
    }
    
}




