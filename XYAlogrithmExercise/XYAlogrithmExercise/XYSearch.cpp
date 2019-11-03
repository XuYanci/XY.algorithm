//
//  XYSearch.cpp
//  XYAlogrithmExercise
//
//  Created by Yanci on 2019/4/21.
//  Copyright © 2019 Yanci. All rights reserved.
//

#include "XYSearch.hpp"
#include <iostream>
#include <vector>
using namespace std;

XYSearch::XYSearch() {
    
}

XYSearch::~XYSearch() {
    
}

// 线性查找，遍历查找
void XYSearch::linearSearch(int *array,int count,int val) {
    cout << "Linear Search  - - - - - - - - - - " << endl;
    cout << "origin array is " << endl;
    for (int i = 0; i <  count; i++) {
        cout << array[i] << ',';
    }
    cout << endl;
    
    int pos = -1;
    for (int i = 0; i< count; i++) {
        if (array[i] == val) {
            pos = i;break;
        }
    }
    printf("find val = %d,find pos = %d",val,pos);
    cout << endl;
}

// 二分查找，在有序的数组查找
void XYSearch::divideSearch(int *array,int count,int val) {
    cout << "Divide Search  - - - - - - - - - - " << endl;
    cout << "origin array is " << endl;
    for (int i = 0; i <  count; i++) {
        cout << array[i] << ',';
    }
    cout << endl;
    
    int beginPos = 0;
    int endPos  = count ;
    int pos = -1;
    int   dividePos = (beginPos + endPos ) / 2;
    while (beginPos <= endPos) {
        if (array[dividePos] == val) {
            pos = dividePos;
            break;
        }
        else if(array[dividePos] > val) {
            endPos = dividePos - 1;
        }
        else if(array[dividePos] < val) {
            beginPos = dividePos + 1;
        }
        dividePos = (beginPos + endPos ) / 2;
    }
    
    printf("find val = %d,find pos =%d ",val,pos);
    cout <<endl;
    
}

int XYSearch::recursiveDivideSearch(int *array,int low,int high,int key) {
    if(low > high)//查找不到
        return -1;
    int mid = (low+high)/2;
    if(key == array[mid])//查找到
        return mid;
    else if(key < array[mid])
        return recursiveDivideSearch(array,low,mid-1,key);
    else
        return recursiveDivideSearch(array,mid+1,high,key);
    
}
