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


