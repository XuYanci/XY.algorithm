//
//  main.cpp
//  XYAlogrithmExercise
//
//  Created by Yanci on 2019/4/21.
//  Copyright © 2019 Yanci. All rights reserved.
//

#include <iostream>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include "XYSort.hpp"
#include "XYSort_goback.hpp"
#include "XYHeap.hpp"
#include "XYSearch.hpp"
#include "LeetCodeSolution.hpp"
#include "LeetCodeSolution_goback.hpp"
#include "XYStack.hpp"
#include "XYLinkList.hpp"
#include "XYCache.hpp"
#include "jianzhiOffer.hpp"
#include "LeetCodeEveryDay.hpp"

/// XuYanci Alogrithm Exercise

/// 算法
void alogrithms();
/// LeetCodes
void leetCodes();
/// LeetCodes复习
void leetCodesGoBack();
/// 数据结构
void structures();
/// 数据结构复习
void structuresGoBack();
/// 剑指Offer
void JianZhiOfferRun();//
/// LeetCode每日一题
void LeetCodeEveryDayss();
void cache();
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "XuYanci Alogrithm Exercise!\n";
    
//    alogrithms();
     leetCodes();
//    structures();
    //leetCodesGoBack();
//    structuresGoBack();
//    cache();
//    JianZhiOfferRun();
//    LeetCodeEveryDayss();
    return 0;
}

void cache() {
    XYLRUCache *cache = new XYLRUCache( 2 /* 缓存容量 */ );
    
    cache->put(1, 1);
    cache->put(2, 2);
    cache->get(1);       // 返回  1
    cache->put(3, 3);    // 该操作会使得密钥 2 作废
    cache->get(2);       // 返回 -1 (未找到)
    cache->put(4, 4);    // 该操作会使得密钥 1 作废
    cache->get(1);       // 返回 -1 (未找到)
    cache->get(3);       // 返回  3
    cache->get(4);       // 返回  4
}


void leetCodesGoBack() {
    LeetCodeSolutionGoBack *s = new LeetCodeSolutionGoBack();
    vector<int>nums{3,3};
    s->twoSum(nums, 6);
    s->reverse2(-2147483648);
    vector<string> prefixs {"ca","c"};
    s->longestCommonPrefix(prefixs);
    vector<int> temperatures {73, 74, 75, 71, 69, 72, 76, 73};
    s->dailyTemperatures(temperatures);
    s->dailyTemperatures1(temperatures);
    
    vector<int> nums1 {43,9,26,24,39,40,20,11,18,13,14,30,48,47,37,24,32,32,2,26};
    s->findTargetSumWays1(nums1, 47);
    
    
    vector<vector<int>> matrix;
    int a11[4] = {1,2,3,4};
    int a22[4] = {5,6,7,8};
    int a33[4] = {9,10,11,12};
    int a44[4] = {13,14,15,16};
    vector<int> nums111(a11,a11+4);
    vector<int> nums222(a22,a22+4);
    vector<int> nums333(a33,a33+4);
    vector<int> nums444(a44,a44+4);
    
    matrix.push_back(nums111);
    matrix.push_back(nums222);
    matrix.push_back(nums333);
    matrix.push_back(nums444);
    s->rotate(matrix);
    
    vector<int> heights {2,1,5,6,2,3};
    s->largestRectangleArea(heights);
}

void structures() {
    /// 最大堆
    Max_Heap *max_heap = new Max_Heap();
    max_heap->justRun();
    
    vector<int> temperatures {73, 74, 75, 71, 69, 72, 76, 73};
   
    XYStack *stack = new XYStack();
    /// 到下一个比我大的需要多少步
    stack->nextExceed(temperatures);
    /// 到下一个比我小的需要多少步
    stack->prevExceed(temperatures);
}

void structuresGoBack() {
    XYSortGoBack *sort = new XYSortGoBack();
    int array6[] = {12,14,25,32,23,45,13,63,24};
    // 快速排序
    sort->quickSort(array6, 9);
    
    /// 堆排序
    Min_Heap *heap = new Min_Heap();
    heap->JustRun();
}

void alogrithms() {
    XYSort *sort = new XYSort();
    XYSearch *search = new XYSearch();
    /// 冒泡排序
    int array[] = {3,2,1,5,4};
    sort->bubleSort(array,5,false);
    
    // 插入排序
    int array1[] = {3,2,1,5,4};
    sort->insertSort(array1, 5, false);
    
    // 选择排序
    int array2[] = {3,2,1,5,4};
    sort->selectSort(array2, 5, false);
    
    // 线性查找
    int array3[] = {3,2,1,5,4};
    search->linearSearch(array3,5, 5);
    
    // 二分查找
    int array4[] = {1,2,3,4,5};
    search->divideSearch(array4,5, 5);
    
    // 随机产生9个数
    srand((unsigned)time(NULL));
    int array5[] = {1,3,2,4,5,9,8,7,6};
    for(int i=0;i<9;i++){
        array5[i]=rand()%101;
    }
    int array6[] = {12,14,25,32,23,45,12,63,24,12};
    // 快速排序
    sort->quickSort(array6, 9, false);
    
    
    // @TODO 归并排序
    for(int i=0;i<9;i++){
        array5[i]=rand()%101;
    }
    sort->mergeSort(array5, 9, false);
    
    /// 堆排序
    int n = 7;
    int items[7] = {87,79,38,83,72,43,91};
    ELEMENT1 heap[7];
    sort->create_binarytree(heap, items, n);
    sort->heap_sort(heap, n);///38,43,72,79,83,87,91
    
    MyLinkedList linkedList ;
    linkedList.addAtHead(1);
    linkedList.addAtHead(3);
    linkedList.addAtTail(5);
    ;
    linkedList.addAtIndex(1,2);   //链表变为1-> 2-> 3
    linkedList.get(1);            //返回2
    linkedList.deleteAtIndex(1);  //现在链表是1-> 3
    linkedList.deleteAtIndex(1);
    linkedList.deleteAtIndex(1);
    linkedList.deleteAtIndex(0);
    linkedList.get(1);            //返回3
}

void leetCodes() {
    // Leecode
    LeetCodeSolution *s = new LeetCodeSolution();
    std::vector<int>array6 = {1,2,3,4,5,6} ;
    
    // 移除重复项
    s->removeDuplicates(array6);
    // 旋转数组
    s->rotate(array6, 2);
    // 判断是否重复
    s->containsDuplicate(array6);
    // 只存在一个数字
    s->singleNumber(array6);
    // 移动0
    s->moveZeroes(array6);
    
    // 合并两个有序链表
    ListNode *l1 = new ListNode(5);
    ListNode *l2 = new ListNode(1);
    ListNode *l22 = new ListNode(2);
    ListNode *l222 = new ListNode(4);
    l2->next = l22;
    l22->next = l222;
    s->mergeTwoLists(l2, l1);
    
    // 链表反转
    s->reverseList(l2);
    
    // 整数反转
    s->reverse(-2147483648);
    
    // 计算素数
    s->countPrimes(10000);
    
    // 计算斐波那契数
    s->fib(30);
    
    int a[9] = {-1,0,0,3,3,3,0,0,0};
    int b[3] = {1,2,2};
    
    vector<int> nums1(a,a+9);
    vector<int> nums2(b,b+3);
    
    // 合并两个有序数组
    s->merge(nums1, 6, nums2, 3);
    
    vector<int>nums{2,7,11,15};
    s->twoSum(nums, 9);
    
    vector<char> array {'a','b','c','d','e','f'};
    s->reverseString(array);
    
    vector<int> array1 {10,9,2,5,3,7,101,18};
    s->lengthOfLIS(array1);
    
    
    LRUCache *cache = new LRUCache( 2 /* 缓存容量 */ );
    
    cache->put(1, 1);
    cache->put(2, 2);
    cache->get(1);       // 返回  1
    cache->put(3, 3);    // 该操作会使得密钥 2 作废
    cache->get(2);       // 返回 -1 (未找到)
    cache->put(4, 4);    // 该操作会使得密钥 1 作废
    cache->get(1);       // 返回 -1 (未找到)
    cache->get(3);       // 返回  3
    cache->get(4);       // 返回  4
    
    LFUCache *cache1 = new LFUCache( 2 /* capacity (缓存容量) */ );
    
    cache1->put(1, 1);
    cache1->put(2, 2);
    cache1->get(1);       // 返回 1
    cache1->put(3, 3);    // 去除 key 2
    cache1->get(2);       // 返回 -1 (未找到key 2)
    cache1->get(3);       // 返回 3
    cache1->put(4, 4);    // 去除 key 1
    cache1->get(1);       // 返回 -1 (未找到 key 1)
    cache1->get(3);       // 返回 3
    cache1->get(4);       // 返回 4
    
    int a1[5] = {9,4,9,8,4};
    int b1[3] = {4,9,5};
    vector<int> nums11(a1,a1+5);
    vector<int> nums22(b1,b1+3);
    //    s->intersect(nums11, nums22);
    s->intersect1(nums11, nums22);
    
    
    vector<vector<int>> matrix;
    int a11[4] = {5,1,9,11};
    int a22[4] = {2,4,8,10};
    int a33[4] = {13,3,6,7};
    int a44[4] = {15,14,12,16};
    vector<int> nums111(a11,a11+4);
    vector<int> nums222(a22,a22+4);
    vector<int> nums333(a33,a33+4);
    vector<int> nums444(a44,a44+4);
    
    matrix.push_back(nums111);
    matrix.push_back(nums222);
    matrix.push_back(nums333);
    matrix.push_back(nums444);
    s->rotate(matrix);
    
    ListNode *l01 = new ListNode(1);
    ListNode *l02 = new ListNode(2);
    ListNode *l03 = new ListNode(3);
    //    ListNode *l04 = new ListNode(4);
    l01->next = l02;
    l02->next = l03;
    //    l03->next = l04;
    ListNode *head =  s->swapPairs(l01);
    
    /// YangHui Triangle 1
    s->generate(5);
    
    /// YangHui Triangle 2
    s->getRow(3);
    
    /// 岛屿数量
    vector<vector<char> > grid = {{'1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','0','1','0','1','1'},{'0','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','0'},{'1','0','1','1','1','0','0','1','1','0','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','0','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','0','1','1','1','1','1','1','0','1','1','1','0','1','1','1','0','1','1','1'},{'0','1','1','1','1','1','1','1','1','1','1','1','0','1','1','0','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','0','1','1'},{'1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'0','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','0','1','1','1','1','1','1','1','0','1','1','1','1','1','1'},{'1','0','1','1','1','1','1','0','1','1','1','0','1','1','1','1','0','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','0'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','0','0'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'}};
    s->numIslands(grid);
    
    
    vector<string> deadends = {"0201","0101","0102","1212","2002"};
    s->openLock(deadends, "0202");
    
    s->numSquares(13);
    
    MinStack* obj = new MinStack();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->pop();
    int param_3 = obj->top();
    int param_4 = obj->getMin();
    
    s->isValid("()");
    
    vector<int> temperatures {73, 74, 75, 71, 69, 72, 76, 73};
    s->dailyTemperatures(temperatures);
    
    vector<string> tokens {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    s->evalRPN(tokens);
    
    TreeNode *root =  new TreeNode(1);
    TreeNode *right1 =  new TreeNode(2);
    root->left = NULL;
    root->right = right1;
    TreeNode *left1 =  new TreeNode(3);
    right1->left = left1;
    right1->right = NULL;
    
    s->inorderTraversal(root);
    
    vector<int> ways {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    s->findTargetSumWays(ways, 0);
    
    vector<vector<int> > orders = {{1,2,3},{4,5,6}};
    s->findDiagonalOrder(orders);
    
    vector<string> prefixs {"ca","c"};
    s->longestCommonPrefix(prefixs);
    
    vector<vector<int> > intervals =
    {{74,78},{61,63},{46,50},{51,54},{50,50},{60,64},{39,42},{25,27},{91,95},{14,16},{85,85},{5,7},{45,46},{45,49},{66,66},{73,73},{25,26},{25,26},{45,48},
        {67,67}};
    s->merge(intervals);
}

void JianZhiOfferRun() {
    JianZhiOffer *offer = new JianZhiOffer();
//    vector<int> numbers {73, 74, 75, 71, 69, 72, 76, 73};
//    offer->findRepeatNumber(numbers);
//
    offer->replaceSpace("We are happy.");
}


void LeetCodeEveryDayss() {
    LeetCodeEveryDay *everyDay = new LeetCodeEveryDay();
//    vector<int> nums{3,2,3};
//    everyDay->majorityElement(nums);
//    everyDay->lengthOfLIS(nums);
    
    vector<vector<int>>grid {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    

    everyDay->maxAreaOfIsland(grid);
    everyDay->compressString("ccc");
    
    vector<string> words{"boygirdlggnh"};
 
    string chars = "usdruypficfbpfbivlrhutcgvyjenlxzeovdyjtgvvfdjzcmikjraspdfp";
    everyDay->countCharacters(words,chars );
    
    vector<int> rec1{7,8,13,15};
    vector<int> rec2{10,8,12,20};
    int ret =  everyDay->isRectangleOverlap(rec1,rec2);
    
    everyDay->longestPalindrome("aasdfdsfbbcde");
    
    
    vector<int> A{1,2,2};
    everyDay->minIncrementForUnique(A);
    vector<int> nums{1,2,3,1};
    everyDay->massage(nums);
}
