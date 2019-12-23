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
        if (p->data > key) {
            p = p->leftchild;
        } else {
            p = p->rightchild;
        }
    }
    return parent;
}

int XYBSTree::BSTInsert(BinSearTreeNode *bt, DataType key) {
    BSTreeNode *p,*temp;
    temp = BSTSearch(bt, key);
    if (temp == NULL) {
        printf("exist this key \n"); return 0;
    }
    p =  new BinSearTreeNode();
    if (p == NULL) {
        printf("Alloc Failure! \n"); return 0;
    }
    p->data = key;
    if (key < temp->data) {
        temp->leftchild = p;
    } else {
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
        BSTreeNode *parentp;
        parentp = p;
        maxpl = p->leftchild;
        while(maxpl->rightchild != NULL) {
            parentp = maxpl;
            maxpl = maxpl->rightchild;
        }
        p->data = maxpl->data;
        if (parentp == p) {
            p->leftchild = maxpl->leftchild;
        }
        else {
            parentp->rightchild = maxpl->leftchild;
        }
        p = maxpl;
    }
    free(p);
    return 1;
}

int XYBSTree::BSTDelete2(BinSearTreeNode *bt, DataType key) {
    return 1;
}
