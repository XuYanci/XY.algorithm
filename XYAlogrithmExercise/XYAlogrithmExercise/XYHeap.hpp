//
//  XYHeap.hpp
//  XYAlogrithmExercise
//
//  Created by Yanci on 2019/4/25.
//  Copyright © 2019 Yanci. All rights reserved.
//

#ifndef XYHeap_hpp
#define XYHeap_hpp

#include <stdio.h>
#include <list>
#include <vector>
#include <iostream>
using namespace std;
#define MAX_ELEMENTS 20
#define HEAP_FULL(n) (MAX_ELEMENTS - 1 == n)
#define HEAP_EMPTY(n) (!n)
typedef struct {
    int key;
}ELEMENT;


/// 最大堆
class Max_Heap {
    
    ELEMENT heap[MAX_ELEMENTS];
    
public:
    /// 最大堆插入操作
    void insert_max_heap(ELEMENT item,int *n);
    /// 最大堆删除操作
    ELEMENT delete_max_heap(int *n);
    /// 创建最大队
    void create_max_heap(void);
    /// 创建二进制树
    int create_binary_tree(ELEMENT *heap,int items[MAX_ELEMENTS]);
    
    void __swap(ELEMENT *lhs,ELEMENT *rhs);
    
    void justRun();
};


class Min_Heap {
    void Sift(vector<int> &R,int k,int m) {
        int i,j,x;
        int t;
        i = k;
        j = 2 * i + 1;
        t = R[k];
        x = R[k];
        while (j < m) {
            /// 优先筛选右子树
            if ((j + 1 < m) && (R[j] > R[j+1])) {
                j++;
            }
            if (x < R[j]) break;
            else {
                R[i] = R[j];
                i = j;
                j = 2 * i + 1;
            }
            
        }
        
         R[i] = t;
    }
    
    void HeapSort(vector<int>R){
        int i;
        int n = (int)R.size();
        for (i = n/2 - 1 ;i>=0;i--) {
            Sift(R, i, n);
            cout << "A";
        }
        cout << "Create Min Heap";
        for (int i =0; i < n;i++) {
            std::cout << R[i];
        }
        
        for (i = n - 1; i >= 1; i--) {
            swap(R[0], R[i]);
            Sift(R, 0, i);
        }
        cout << "Min Heap Sort ";
        for (int i =0; i < n;i++) {
            std::cout << R[i];
        }
    }
    
public: /// C++ 不加public,默认私有private
    void JustRun() {
        vector<int> R {65,88,55,34,92,27,13,40};
        HeapSort(R);
        
    }
    
};


class XYHeap2 {
    vector<int> a;
    int n;
    int count;

public:

    XYHeap2(int capacity) {
        n = capacity;
        count = 0;
    }

    /// 建堆方式1
    void buildHeap(vector<int>&a,int n,bool asc) {
        /// 建立堆（从下到上）
        for (int i = 1; i < n; i++) {
            up(a, n, i,asc);
        }

        if (asc) {
            printf("Build Min Heap is: \n");
        } else {
            printf("Build Max Heap is: \n");
        }

        for (int i = 1; i < n; i++) {
            printf("%d,",a[i]);
        }
        printf("\n");
    }

    /// 上浮操作
    void up(vector<int>&a,int n,int i,bool asc) {
        /// 根节点停止
        while (i / 2 > 0) {
            /// 如果父亲节点比我小，则交换节点（这里是大根堆）
            int pos = asc == true ? (a[i/2] > a[i] ? i / 2 : i) : (a[i/2] < a[i] ? i / 2 : i);
            swap(a[i], a[pos]);
            i = i / 2;
        }
    }

    void down(vector<int>&a,int n,bool asc) {
        /// 下沉动作
        int i = 1;
        while (i * 2 <= n) {
            /// 取较小的一个
            int pos = a[i * 2] < a[i] ? i * 2 : i;
            if (i * 2 + 1 <= n) {
                pos = a[i * 2 + 1] < a[pos] ? i * 2 + 1 : pos;
            }
            swap(a[i], a[pos]);
            i = pos;
        }
    }


    /// 堆排序
    /// @param a 排序数组
    /// @param n 数组个数
    /// @param asc 升序，降序
    void sort(vector<int>&a,int n,bool asc) {
        /// 根据排序条件建立堆
        buildHeap(a, n,asc);

        /// 最后一个元素
        int j = n - 1;
        while (j > 1) {

            /// 放到最后一个元素 (有序数组)
            swap(a[1], a[j]);

            /// 下沉动作
            down(a, j - 1, asc);

            j--;
        }

        if (asc) {
            printf("Min Heap Sort is: \n");
        } else {
            printf("Max Heap Sort is: \n");
        }


        for (int i = n - 1; i >= 1; i--) {
            printf("%d,",a[i]);
        }
        printf("\n");
    }

};



#endif /* XYHeap_hpp */
