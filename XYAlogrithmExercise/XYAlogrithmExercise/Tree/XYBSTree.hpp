//
//  XYBSTree.hpp
//  XYAlogrithmExercise
//
//  Created by Yanci on 2019/12/23.
//  Copyright © 2019 Yanci. All rights reserved.
//

#ifndef XYBSTree_hpp
#define XYBSTree_hpp

#include <stdio.h>
#include <vector>
using namespace std;
/// 二叉排序树的类型定义
typedef int DataType;
typedef struct BinSearTreeNode {
    DataType data;
    struct BinSearTreeNode *leftchild;
    struct BinSearTreeNode *rightchild;
}BSTreeNode;

typedef BSTreeNode *BinSearTree;

/// 二叉排序树
class XYBSTree {
public:
    /// 二叉排序树插入
    BSTreeNode* BSTSearch(BinSearTreeNode *bt,DataType key);
    /// 二叉排序树的插入
    int BSTInsert(BinSearTreeNode *bt,DataType key);
    /// 二叉排序树的建立
    BSTreeNode *create(vector<int>vals);
    /// 二叉排序树的删除
    int BSTDelete1(BinSearTreeNode *bt,DataType key);
    /// 二叉排序树的删除
    int BSTDelete2(BinSearTreeNode *bt,DataType key);
};
#endif /* XYBSTree_hpp */
