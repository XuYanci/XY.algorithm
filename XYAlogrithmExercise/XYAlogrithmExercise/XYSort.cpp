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

// 单次遍历，交换大小，最大的在最后  （升序）
// 单次遍历，交换大小，最小的在最后  （降序）
void XYSort::bubleSort(int *array, int count,bool asc) {
    cout << "BUBBLE SORT - - - - - - - - - - " << endl;
    cout << "origin array is " << endl;
    for (int i = 0; i <  count; i++) {
        cout << array[i] << ',';
    }
    cout << endl;
    for (int i = 0 ; i < count ; i++) {
        for (int j = 0; j < count -  i - 1 ; j++) {
            // 升序
            if (asc && array[j] > array[j+1]) {
                int temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }
            else  if ( !asc && array[j] < array[j+1]) {
                int temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }
        }
    }
    
    cout << "sort array is " <<  (asc ? "asc":"not asc")  << endl;
    for (int i = 0; i <  count; i++) {
        cout << array[i] << ',';
    }
    cout << endl;
}

/// 解法1:
/// L,R,P
/// L -> R, L直到找到比自己大的,Stop,如果碰撞到R，并不会停止
/// R -> L, R直到找到比自己小的,Stop,停止并交换, 如果碰撞到L,停止并交换,如果已经被L标记，停止并交换

/// 解法2:
/// 个人觉得更加方便
//1．i =L; j = R; 将基准数挖出形成第一个坑a[i]。
//2．j--由后向前找比它小的数，找到后挖出此数填前一个坑a[i]中。
//3．i++由前向后找比它大的数，找到后也挖出此数填到前一个坑a[j]中。
//4．再重复执行2，3二步，直到i==j，将基准数填入a[i]中。

void recursiveQuickSort(int array[],int l,int r) {

/** 解法1 **/
//    int beforel = l;
//    int beforep = p ;
//
//    if (r < l) {
//        return;
//    }
//
//    if (r == l && array[l] > array[p]) {
//        int temp = array[l];
//        array[l] = array[p];
//        array[p] = temp;
//        return;
//    }
//
//
//    while (l < r) {
//        while (array[l] < array[p]) {
//            l = l + 1;
//        }
//
//
//        while (array[r] >= array[p] && r > l) {
//            r = r - 1;
//        }
//
//        if (l < r) {
//            /// 交换
//            int temp = array[r];
//            array[r] = array[l];
//            array[l] = temp;
//
//        }
//
//        else if (r < l) {
//            break;
//        }
//        else if (r == l && array[l] > array[p]) {
//            int temp = array[l];
//            array[l] = array[p];
//            array[p] = temp;
//            break;
//        }
//
//    }
//
//    // Left
//    recursiveQuickSort(array, l - 1, beforel, l - 2);
//    // Right
//    recursiveQuickSort(array, beforep,r + 1 , beforep - 1);
    
/** 解法2 **/
    if (l < r) {
        int i = l;
        int j = r;
        int x = array[l];
        while ( i < j) {
            // 从右向左找第一个小于等于x的数
            while (i < j && array[j] >= x) {
                j--;
            }
           
            if(i<j) {
                array[i++] = array[j];
            }
            // 从左向右找第一个小于x的数
            while (i < j && array[i] < x) {
                i++;
            }
            if(i < j)
                array[j--] = array[i];
        }
        array[i] = x;
        recursiveQuickSort(array,l,i-1);
        recursiveQuickSort(array, i+1, r);
    }
}

void XYSort::quickSort(int *array,int count,bool asc) {
    cout << "QUICK SORT - - - - - - - - - - " << endl;
    cout << "origin array is " << endl;
    for (int i = 0; i <  count; i++) {
        cout << array[i] << ',';
    }
    cout << endl;
    
    // 递归做法
    int l = 0;
    int r = count - 1;
    recursiveQuickSort(array, l, r);
    
    cout << "sort array is " <<  (asc ? "asc":"not asc") << endl;
    for (int i = 0; i <  count; i++) {
        cout << array[i] << ',';
    }
    cout << endl;
}



// 一个有序数组，一个无序数组， 默认取第一个元素放到有序数组, 假设最大
// 然后依次取无序数组，与有序数组比较 (升序，降序)，并做插入操作
// 比较完毕，则有序数组排序完毕
void XYSort::insertSort(int *array,int count,bool asc) {
    cout << "INSERT SORT - - - - - - - - - - " << endl;
    cout << "origin array is " << endl;
    for (int i = 0; i <  count; i++) {
        cout << array[i] << ',';
    }
    cout << endl;
    // 这里用数组也是可以，记住一个下标位置就可以了
    vector<int>sortArray(1,array[0]);
    /// 外循环，有序列表
    for (int i = 1; i < count; i++) {
        long j;
        int temp = array[i];
        // 与有序数组比较，从最大开始比较
        for (j = sortArray.size() - 1;j >= 0; j--) {
            if (asc && temp > sortArray[j]) {
                sortArray.insert(sortArray.begin() + j + 1, temp);
                break;
            }
            else if (!asc && temp < sortArray[j]) {
                sortArray.insert(sortArray.begin() + j + 1, temp);
                break;
            }
            else {
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

/// 选择排序，线性搜索最小，然后交换放到数组位置，逐个交换；
void XYSort:: selectSort(int *array,int count,bool asc) {
    cout << "SELECT SORT - - - - - - - - - - " << endl;
    cout << "origin array is " << endl;
    for (int i = 0; i <  count; i++) {
        cout << array[i] << ',';
    }
    cout << endl;
    
    /// 选择排序，线性搜索最小，然后交换放到数组位置，逐个交换；
    /// 外循环 存放最小值数组
    /// 内循环 搜索最小
    for (int i = 0; i < count; i++) {
        int temp = array[i];
        int downSign = -1;
        for (int j = i+1; j < count; j++) {
            if (asc && array[j] < temp) {
                temp = array[j];
                downSign = j;
            }
            if (!asc && array[j] > temp) {
                temp = array[j];
                downSign = j;
            }
        }
        if (downSign> 0) {
            array[downSign] = array[i];
            array[i] = temp;
        }
    }
    
    
    cout << "sort array is " <<  (asc ? "asc":"not asc") << endl;
    for (int i = 0; i <  count; i++) {
        cout << array[i] << ',';
    }
    
    cout << endl;
}

// 归并排序
// 思路是这样的:
// 分而治之
// 先分，后治
// 思考了半个小时，暂时没有根据动画解出来;先看看答案先
// Refer to : https://www.cnblogs.com/chengxiao/p/6194356.html
// 🤔: 之前一直没想到用mid这个来分，回头想其实很简单
void XYSort:: mergeSort(int *array,int count,bool asc) {
    
    cout << "MERGE SORT - - - - - - - - - - " << endl;
    cout << "origin array is " << endl;
    for (int i = 0; i <  count; i++) {
        cout << array[i] << ',';
    }
    cout << endl;
 
    int temp[count];
    merge_Sort(array,0,count-1,temp);
    
    cout << "sort array is " <<  (asc ? "asc":"not asc") << endl;
    for (int i = 0; i <  count; i++) {
        cout << array[i] << ',';
    }
    
    cout << endl;
}


void XYSort::merge_Sort(int arr[] ,int left,int right,int temp[]){
    if(left<right){  // 递归出口
        // 递归体
        int mid = (left+right)/2;
        merge_Sort(arr,left,mid,temp);//左边归并排序，使得左子序列有序
        merge_Sort(arr,mid+1,right,temp);//右边归并排序，使得右子序列有序
        merge(arr,left,mid,right,temp);//将两个有序子数组合并操作
    }
}

void XYSort::merge(int arr[],int left,int mid,int right,int temp[]) {
    int i = left;//左序列指针
    int j = mid+1;//右序列指针
    int t = 0;//临时数组指针
    while (i<=mid && j<=right){
        if(arr[i]<=arr[j]){
            temp[t++] = arr[i++];
        }else {
            temp[t++] = arr[j++];
        }
    }
    while(i<=mid){//将左边剩余元素填充进temp中
        temp[t++] = arr[i++];
    }
    while(j<=right){//将右序列剩余元素填充进temp中
        temp[t++] = arr[j++];
    }
    t = 0;
    //将temp中的元素全部拷贝到原数组中
    while(left <= right){
        arr[left++] = temp[t++];
    }
    
}


