//
//  XYSort_goback.hpp
//  XYAlogrithmExercise
//
//  Created by Yanci on 2019/12/13.
//  Copyright © 2019 Yanci. All rights reserved.
//

#ifndef XYSort_goback_hpp
#define XYSort_goback_hpp

#include <stdio.h>
class XYSortGoBack {
public:
    // 快速排序 (ASC升序）
    void quickSort(int *array,int count);
    // 归并排序
    void mergeSort(int *array,int count);
private:
    void recursiveQuickSort(int *array,int left,int right);
    void recrusiveMergeSort(int *array,int left,int right,int *temp);
    void merge(int *array,int left,int mid,int right,int *temp);
    
};

class XYSortGoBack2 {
public:
    /// 冒泡排序
    void bubbleSort(int *array,int count) {
        for (int i = 0; i < count; i++) {
            for(int j = 0; j < count - i - 1; j++) {
                if (array[j] < array[j+1]) {
                    int tmp = array[j+1];
                    array[j+1] = array[j];
                    array[j] = tmp;
                }
            }
        }
    }
    
    /// 快速排序
    void quickSort(int *array,int count) {
        reverseQuickSort(0, count, array);
    }
    
    /// 快速排序递归入口
    void reverseQuickSort(int l,int r,int *array) {
        /// 递归退出条件
        if (l >= r) {
            return;
        }
        /// 获取中间位置，左边<中间<右边
        int middle = partitionQuickSort(l, r, array);
        /// 左分区排序
        reverseQuickSort(l, middle - 1, array);
        /// 右分区排序
        reverseQuickSort(middle + 1, r, array);
    }
    
    /** 双边扫描法 **/
    int partitionQuickSort2(int l,int r,int *array) {
        
        /// 挖个坑
        int x = array[l];
        int i = l;
        int j = r - 1;
        
        while (i < j) {
            /// 从右边扫描，寻找小于x
            while (array[j] > x && i < j) j--;
            /// 填坑
            array[i] = array[j];
            /// 从左边扫描，寻找大于x
            while (array[i] <  x  && i < j) i++;
            /// 填坑
            array[j] = array[i];
        }
        /// 填坑
        array[i] = x;
        return i;
    }
    
    /** 单边扫描法 **/
    int partitionQuickSort(int l,int r,int *array) {
        /// 最右边作为哨兵
        int pivot = array[r - 1];
        /// i 就是中间位置
        int i = l;
        for (int j = l; j < r - l - 1; j++) {
            /// 判断下标j是否小于哨兵，如果小于则交换i,j,中间位置+1 (小<中<大)
            if (array[j] < pivot) {
                int tmp = array[j];
                array[j] = array[i];
                array[i] = tmp;
                i++;
            }
        }
        
        int tmp = array[i];
        array[i] = pivot;
        array[r - 1] = tmp;
        
        return  i;
    }
    
    /// 插入排序
    void insertSort(int *array,int count) {
        for (int j = 1; j < count; j++) {
            /// 已排序数组尾部 (比较值)
            int x = array[j - 1];
            /// 未排序数组首部
            int i = j;
            /// 判断为未排序数，如果小于已排序，则移动，空出位置
            while ( i > 0 && array[i] < x  ) {
                array[i] = array[i-1];
                i--;
            }
            /// 填入空位置
            array[i] = x;
        }
    }
    
    /// 选择排序
    void selectSort(int *array,int count) {
        
        /// 最小值
        int min = array[0];
        
        for (int i = 0; i < count; i++) {
            /// 已排序区间
            int minJ = i;
            /// 寻找未排序区间最小值下标
            for (int j = i + 1; j < count; j++) {
                if (array[j] < min) {
                    minJ = j;
                }
            }
            
            /// 交换值，将未排序区间最小值交换放到已排序区间尾部
            int tmp = array[i];
            array[i] = array[minJ];
            array[minJ] = tmp;
        }
        
    }
    
    /// 归并排序
    void mergeSort(int *array,int count) {
        reverseMergeSort(array, 0, count);
    }
    
    
    /// 递归归并排序
    void reverseMergeSort(int *array,int left,int right) {
        
        /// 递归退出条件
        if (left < right) return;
        int mid = (left + right) / 2;
        
        // 分
        reverseMergeSort(array, left, mid);
        reverseMergeSort(array, mid+1, right);
        // 治
        partitionMergeSort(array, left, right);
    }
    
    /// 合并两个有序数组
    void partitionMergeSort(int *array,int left,int right) {
        int mid = (left + right) / 2;
        
        /// 有序数组1下标开始位置
        int i = left;
        /// 有序数组2下标开始位置
        int j = mid + 1;
        
        /// 临时数组，存放排序结果
        int temp[right - left];
        int n = 0;
        
        while (i < mid + 1 && j < right) {
            /// 如果有序数组1小于有序数组2，则存储进来
            if (array[i] < array[j]) {
                temp[n++] = array[i];
                i++;
            }
            /// 如果有序数组2小于有序数组1，则存储进来
            else {
                temp[n++] = array[j];
                j++;
            }
        }
        
        /// i收尾，拷贝剩余数组
        while (i < mid + 1) {
            temp[n++] = array[i];
        }
        
        /// j收尾，拷贝剩余数组
        while (j < right) {
            temp[n++] = array[j];
        }
        
        /// 拷贝已排序的到数组中
        int t = 0;
        while (t < right - left) {
            array[left++] = temp[t++];
        }
    }
    
    /// 堆排序
    void heapSort(int *array,int count) {
        
        /// 建堆，从后到前开始堆化，堆化方式从上到下
        for (int i = count / 2; i >= 1; i--) {
            heaplify(array, i, count);
        }
        
        /// 堆排序，逐渐取根节点，然后堆化
        int k = count;
        while (k > 1) {
            
            int tmp = array[k];
            array[k] = array[1];
            array[1] = tmp;
            
            k--;
            heaplify(array, 1, k);
        }
    }
    
    /// i坐标从1开始计数
    void heaplify(int *array, int i, int count) {
        while (true) {
            int maxpos = i / 2;
            if (maxpos < count && array[i * 2] > array[maxpos]) {
                maxpos = i * 2;
            }
            if (i * 2 + 1 < count && array[i * 2 + 1] > array[maxpos]) {
                maxpos = i * 2 + 1;
            }
            
            /// 交换位置
            int tmp = array[maxpos];
            array[maxpos] = array[i];
            array[i] = tmp;
            
            if (i == maxpos) break;;
            i = maxpos;
        }
    }
    
};
#endif /* XYSort_goback_hpp */
