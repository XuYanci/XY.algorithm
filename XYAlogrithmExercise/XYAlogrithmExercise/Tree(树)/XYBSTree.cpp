//
//  XYBSTree.cpp
//  XYAlogrithmExercise
//
//  Created by Yanci on 2019/12/23.
//  Copyright © 2019 Yanci. All rights reserved.
//

#include "XYBSTree.hpp"

/// 二叉搜索
BSTreeNode* XYBSTree::BSTSearch(BinSearTreeNode *bt, DataType key) {
    BSTreeNode *p,*parent;
    p = bt;
    parent = p;
    while (p) {
        parent = p;
        if (p->data == key) {
            printf("exit this key \n");
            return NULL;
        }
        /// 如果寻找的值大于结点值，则往左边继续寻找
        if (p->data > key) {
            p = p->leftchild;
        }
        /// 如果寻找的值小于结点值，则往右边继续寻找
        else {
            p = p->rightchild;
        }
    }
    return parent;
}

int XYBSTree::BSTInsert(BinSearTreeNode *bt, DataType key) {
    BSTreeNode *p,*temp;
    /// 找到对应的节点
    temp = BSTSearch(bt, key);
    if (temp == NULL) {
        printf("exist this key \n"); return 0;
    }
    /// 如果节点为空，则新建节点
    p =  new BinSearTreeNode();
    if (p == NULL) {
        printf("Alloc Failure! \n"); return 0;
    }
    p->data = key;
    /// 如果值小于搜索到父节点，则插入左边
    if (key < temp->data) {
        temp->leftchild = p;
    }
    /// 如果值大于搜索到父节点，则插入右边
    else {
        temp->rightchild = p;
    }
    
    return 1;
}

BSTreeNode* XYBSTree::create(vector<int> vals) {
    return NULL;
}

int XYBSTree::BSTDelete1(BinSearTreeNode *bt, DataType key) {
    BSTreeNode *parent,*p,*maxpl;
    p = bt;
    parent = NULL;
    while (p != NULL) {
        if (p->data == key) break;
        parent = p;
        if (p->data > key)
            p = p->leftchild;
        else
            p = p->rightchild;
    }
    /// 如果被删除的节点不存在
    if (p == NULL) {
        printf(" not exist \n");return 0;
    }
    /// 左子树为空
    if (p->leftchild == NULL) {
        /// 如果是根节点
        if (parent == NULL) {
            bt = p->rightchild;
        }
        /// 如果左子树是删除的节点，父亲节点的左子树=删除节点的右子树
        else if (parent->leftchild == p) {
            parent->leftchild = p->rightchild;
        }
        /// 否则父亲的右子树就是删除节点的右子树
        else {
            parent->rightchild = p->rightchild;
        }
    }
    /// 左子树不为空
    if (p->leftchild != NULL) {
        BSTreeNode *parentp;
        parentp = p;
        /// 默认先从左子树开始查找
        maxpl = p->leftchild;
        while(maxpl->rightchild != NULL) {
            parentp = maxpl;
            maxpl = maxpl->rightchild;
        }
        p->data = maxpl->data; /// 修改p的数据域为maxp1的数据域
        if (parentp == p) { // 如果Maxp1的父节点是p自身
            p->leftchild = maxpl->leftchild; // 修改p节点的左指针
        }
        else { // 修改父节点的右指针
            parentp->rightchild = maxpl->leftchild;
        }
        p = maxpl;
    }
    /// 释放节点
    free(p);
    return 1;
}

int XYBSTree::BSTDelete2(BinSearTreeNode *bt, DataType key) {
    
    BSTreeNode *parent,*p,*maxpl;
    p = bt;
    parent = NULL;
    while (p != NULL) {
        if (p->data == key) break;
        parent = p;
        if (p->data > key)
            p = p->leftchild;
        else
            p = p->rightchild;
    }
    if (p == NULL) {
        printf(" not exist \n");return 0;
    }
    
    if (p->leftchild == NULL) {
        if (parent == NULL) {
            bt = p->rightchild;
        }
        else if (parent->leftchild == p) {
            parent->leftchild = p->rightchild;
        }
        else {
            parent->rightchild = p->rightchild;
        }
    }
    if (p->leftchild != NULL) {
     
        maxpl = p->leftchild;
        while(maxpl->rightchild != NULL) {
            maxpl = maxpl->rightchild;
        }
        maxpl->rightchild = p->rightchild;
        if (parent == NULL) {
            bt = p->leftchild;
        }
        else if (parent->leftchild == p){
            parent->leftchild = p->leftchild;
        } else {
            parent->rightchild = p->leftchild;
        }
       
    }
    free(p);
    return 1;
}
