//
//  XYSort.hpp
//  XYAlogrithmExercise
//
//  Created by Yanci on 2019/4/21.
//  Copyright © 2019 Yanci. All rights reserved.
//

#ifndef XYSort_hpp
#define XYSort_hpp

#define MAX_ELEMENTS 20
typedef struct {
    int key;
}ELEMENT1;

#include <stdio.h>
#include <vector>
using namespace std;
class XYSort {
public:
    XYSort();
    ~XYSort();
    
    // 冒泡排序
    void bubleSort(int *array,int count,bool asc);
    
    // 快速排序
    void quickSort(int *array,int count,bool asc);
    
    /// 快速排序2
    void quickSort2(vector<int> &array,int count,bool asc);
    
    // 插入排序
    void insertSort(int *array,int count,bool asc);
    
    // 选择排序
    void selectSort(int *array,int count,bool asc);
    
    // 归并排序
    void mergeSort(int *array,int count,bool asc);
    
    // 堆排序
    void heap_sort(ELEMENT1 *heap ,int n);
    int create_binarytree(ELEMENT1 *heap, int items[MAX_ELEMENTS], int n);
    
protected:
    
private:
    // 私有方法:合并两个有序数组
    void merge(int array0[],int left,int mid,int right,int temp[]);
    void merge_Sort(int arr[],int left,int right,int temp[]);
    void quickSort2_reverse(vector<int> &array,int l,int r,bool asc);
    int quickSort2_partition(vector<int> &array,int l,int r,bool asc);
    /// 私有方法:堆排序
    void __swap(ELEMENT1 *lhs,ELEMENT1 *rhs){
        ELEMENT1 temp = *lhs;
        *lhs = *rhs;
        *rhs = temp;
    }
    
    void adapt_maxheap(ELEMENT1 *heap ,int node ,int n){
        int parent = node - 1 < 0 ? 0 : node - 1;
        int child = 2 * parent + 1;/// 因为没有哨兵，所以在数组中的关系由原来的：parent = 2 * child => parent = 2 * child + 1
        int max_node = max_node = 2*parent+2 < n - 1 ? 2*parent+2 : n - 1;
        ELEMENT1 temp = *(heap + parent);
        for (;child <= max_node; parent = child,child = child * 2 + 1,max_node = 2*parent+2 < n - 1 ? 2*parent+2 : n - 1) {
            if ((heap + child)->key <= (heap + child + 1)->key && child + 1 < n) {
                child++;
            }
            if ((heap + child)->key < temp.key) {
                break;
            }
            *(heap + parent) = *(heap + child);
        }
        *(heap + parent) = temp;
    }
    
    int create_maxheap(ELEMENT1 *heap ,int n){
        
        for (int node = n/2; node > 0; node--) {
            adapt_maxheap(heap, node, n);
        }
        return 1;
    }
};
#endif /* XYSort_hpp */
