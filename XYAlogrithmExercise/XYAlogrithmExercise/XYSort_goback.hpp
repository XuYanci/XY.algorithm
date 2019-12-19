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
#endif /* XYSort_goback_hpp */
