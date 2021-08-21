//
//  Tree.hpp
//  XYAlogrithmExercise
//
//  Created by Yanci Xu on 2021/5/9.
//  Copyright © 2021 Yanci. All rights reserved.
//

#ifndef Tree_hpp
#define Tree_hpp


#include <stdio.h>

class Tree {
    
    typedef struct  btnode {
        int data;
        struct btnode *lchild,*rchild;
    } * BinTree;
    
    
    /// 计算高度
    int Height(BinTree bt) {
        return reverseHeight(bt);
    }
    
    int reverseHeight(BinTree bt) {
        if (bt == NULL) {
            return 0;
        }
        int l = reverseHeight(bt->lchild);
        int h = reverseHeight(bt->rchild);
        return ( l > h ? l : h) + 1;
    }
    
    /// 先序遍历
    void PreOrderTree(BinTree root) {
        if (root == NULL) {
            return;
        }
        printf("%d",root->data);
        PreOrderTree(root->lchild);
        PreOrderTree(root->rchild);
    }
    
    /// 树拷贝
    void CopyTree(BinTree root,BinTree newRoot) {
        reverseCopyTree(root, newRoot);
    }
    
    void reverseCopyTree(BinTree root,BinTree newRoot) {
        root->data = newRoot->data;
        if (root->lchild != NULL) {
            newRoot->lchild = new btnode();
            reverseCopyTree(root->lchild,newRoot->lchild);
        }

        if (root->rchild != NULL) {
            newRoot->rchild = new btnode();
            reverseCopyTree(root->rchild, newRoot->rchild);
        }
    }
    
    /// 计算相同val的数目
    int Count(BinTree root,int val) {
        int count = 0;
        preOrderCount(root, val, &count);
        return count;
    }
    
    void preOrderCount(BinTree root,int val, int *count) {
        if (root == NULL) {
            return;
        }
        if (root->data == val) {
            *count += *count + 1;
        }
        PreOrderTree(root->lchild);
        PreOrderTree(root->rchild);
    }
    
    /// 计算叶子数目
    int leftnode_num(BinTree root) {
        return reverseLeftNodeNum(root);
    }
    
    int reverseLeftNodeNum(BinTree root) {
        if (root->lchild == NULL && root->rchild == NULL) {
            return 0;
        }
        int l = reverseLeftNodeNum(root->lchild);
        int r = reverseLeftNodeNum(root->rchild);
        return l + 1 + r + 1;
    }
    
    /// 计算树数目
    int node_num(BinTree root) {
        return  reverseNodeNum(root);
    }
    
    int reverseNodeNum(BinTree root) {
        if (root == NULL) {
            return 0;
        }
        int l = reverseNodeNum(root->lchild);
        int r = reverseNodeNum(root->rchild);
        return l + 1 + r + 1;
    }
    
};
#endif /* Tree_hpp */
