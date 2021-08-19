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
/// 双边扫描法
/// 1．i =L; j = R; 将基准数挖出形成第一个坑a[i]。
/// 2．j--由后向前找比它小的数，找到后挖出此数填前一个坑a[i]中。
/// 3．i++由前向后找比它大的数，找到后也挖出此数填到前一个坑a[j]中。
/// 4．再重复执行2，3二步，直到i==j，将基准数填入a[i]中。
void recursiveQuickSort(int array[],int l,int r) {
    /** 解法2 **/
    if (l < r) {
        
        int i = l;
        int j = r;
        /// 这里也就开辟了一个坑位
        int x = array[l];
        
        /* 双边扫描法 (挖坑法)*/
        while ( i < j) {
            // 从右向左找第一个小于x的数，送坑位，填坑 （小于x的），往左边填充
            while (i < j && array[j] >= x) j--;
            array[i] = array[j];
            // 从左向右找第一个大于等于x的数，送坑位，填坑 （大于等于x的)，往右边填充
            while (i < j && array[i] < x) i++;
            array[j] = array[i];
        }
        
        /// 填坑x到i，这里就分界了
        array[i] = x;
        
        /* 单边扫描法 (简写逻辑，未验证)*/
//        int i_ = l;
//        int x_ = array[r];
//        int j_ = 0;
//        for (j_ = 0; j_ < r; j_++) {
//            if (array[i] < x_) {
//                swap(array[i], array[j]);
//                i+=1;
//            }
//        }
//        swap(array[i], array[r]);
        
        /// 以 l , i - 1 左分区
        recursiveQuickSort(array,l,i-1);
        /// 以 i + 1, r 右分区
        recursiveQuickSort(array, i+1, r);
    }
}

/// 第一种快速排序方式
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

/// 第二种快排方式 (单边扫描法)
void XYSort::quickSort2(vector<int> &array, int count, bool asc) {
    cout << "QUICK SORT2 - - - - - - - - - - " << endl;
    cout << "origin array is " << endl;
    for (int i = 0; i <  count; i++) {
        cout << array[i] << ',';
    }
    cout << endl;
    
    quickSort2_reverse(array, 0, count - 1,asc);
    cout << "sort array is " <<  (asc ? "asc":"not asc") << endl;
    for (int i = 0; i <  count; i++) {
        cout << array[i] << ',';
    }
    cout << endl;
}

void XYSort::quickSort2_reverse(vector<int> &array, int l, int r,bool asc) {
    if (l >= r) return;
    int partition = quickSort2_partition(array, l, r,asc);
    quickSort2_reverse(array, l, partition - 1,asc);
    quickSort2_reverse(array, partition + 1, r,asc);
}

int XYSort::quickSort2_partition(vector<int> &array, int l,int r,bool asc) {
    int i = l;
    /// j 为左区已排序
    for (int j = l; j < r; j++) {
        
        if (asc) {
            if (array[j] < array[r]) {
                      swap(array[i], array[j]);
                      i++;
                  }
        } else {
            if (array[j] > array[r]) {
                      swap(array[i], array[j]);
                      i++;
                  }
        }
        
      
    }
    swap(array[i], array[r]);
    return i;
}

/// 插入排序
/// 一个有序数组，一个无序数组， 默认取第一个元素放到有序数组, 假设最大
/// 然后依次取无序数组，与有序数组比较 (升序，降序)，并做插入操作
/// 比较完毕，则有序数组排序完毕
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
    for (int i = 0; i < count; i++) {
        /// 已排序区间最后值
        int min = i;
        /// 内循环 搜索最小
        for (int j = i + 1; j < count; j++) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        /// 存放最小值
        swap(array[i], array[min]);
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

/// 递归函数
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

int XYSort:: create_binarytree(ELEMENT1 *heap, int items[MAX_ELEMENTS], int n){
    if (n <= 0) return 0;
    for (int i = 0; i < n; i++,heap++) {
        ELEMENT1 value = {items[i]};
        *heap = value;
    }
    return 1;
}

void XYSort::heap_sort(ELEMENT1 *heap ,int n){
    
    cout << "HEAP SORT - - - - - - - - - - " << endl;
    cout << "origin array is " << endl;
    for (int i = 0; i <  n; i++) {
        cout << heap[i].key << ',';
    }
    cout << endl;
    
    ///创建一个最大堆
    create_maxheap(heap, n);
    ///进行排序过程
    int i = n - 1;
    while (i >= 0) {
        __swap(heap+0, heap + i);/// 将第一个和最后一个进行交换
        adapt_maxheap(heap, 0, i--);///将总的元素个数减一，适配成最大堆，这里只需要对首元素进行最大堆的操作
    }
    
    cout << "HEAP SORT - - - - - - - - - - " << endl;
    cout << "Sort array is " << endl;
    for (int i = 0; i <  n; i++) {
        cout << heap[i].key << ',';
    }
    cout << endl;
}

