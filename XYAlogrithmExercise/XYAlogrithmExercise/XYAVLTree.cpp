//
//  XYAVLTree.cpp
//  XYAlogrithmExercise
//
//  Created by Yanci on 2019/12/27.
//  Copyright © 2019 Yanci. All rights reserved.
//

#include "XYAVLTree.hpp"
#include <stdio.h>
#include <stdlib.h>

/// 计算树的深度
Status XYAVLTree::AVLDepth(AVLNode bt) {
    //// 递归出口，bt为NULL时候，返回0
    if (bt == NULL) return 0;
    /// 默认左子树深度1
    int left = 1;
    /// 默认右子树深度1
    int right = 1;
    /// 递归左子树
    left += AVLDepth(bt->leftchild);
    /// 递归右子树
    right+= AVLDepth(bt->rightchild);
    /// 返回深度较大的
    return left > right  ? left : right;
}

/// 中序遍历 (递归还是用栈理解才人性化^_^)
void XYAVLTree::Inorder(AVLNode bt) {
    if (bt == NULL) return;
    Inorder(bt->leftchild);
    printf("%d",bt->data);
    Inorder(bt->rightchild);
}

/// 搜索AVL树
Status XYAVLTree::searchAVL(AVLNode bt, DataType data) {
    if (!bt) return false;
    if (bt->data == data) {
        return true;
    }
    /// 如果小于值，则继续往左边找
    else if ( data  < bt->data ) {
        
        return searchAVL(bt->leftchild, data);
    }
    /// 如果大于值，则继续往右边找
    else {
        return searchAVL(bt->rightchild, data);
    }
    return 1;
}

/// 释放AVL树
void XYAVLTree::destroyAVL(PAVLTree bt) {
    AVLNode p = *bt;
    if (p == NULL) {
        return;
    }
    
    destroyAVL(&(p->leftchild));
    destroyAVL(&(p->rightchild));
    *bt = NULL;
}

/// AVL左旋
void XYAVLTree::leftRotate(AVLNode *bt) {
    /// 右节点
    AVLNode rc = (*bt)->rightchild;
    /// 根的右节点等于右节点的左节点
    (*bt)->rightchild = rc->leftchild;
    //// 右节点的左节点等于根节点
    rc->leftchild = (*bt);
    (*bt) = rc;
}

/// AVL右旋
void XYAVLTree::rightRotate(AVLNode *bt) {
    /// 左节点
    AVLNode lc = (*bt)->leftchild;
    /// 根的左节点等于左节点的右节点
    (*bt)->leftchild = lc->rightchild;
    /// 左节点的右节点等于根节点
    lc->rightchild = (*bt);
    (*bt) = lc;
}

/// 左平衡
/// LL OR LR
void XYAVLTree::leftBalance(AVLNode *bt) {
    /// 找到左树
    AVLNode lc = (*bt)->leftchild;
    AVLNode lc_rc;
    /// 查看平衡因子bf
    switch (lc->bf) {
            //特殊情况, 删除时候要考虑0, 否则会出现删除节点不平衡情况
        case 0:
            (*bt)->bf = 1;
            lc->bf = 0;
            rightRotate(bt);
            break;
            /// L,L
        case 1:
            (*bt)->bf = 0;
            lc->bf = 0;
            rightRotate(bt);
            break;
            
            /// LR, 先左旋再右旋
        case -1:
            lc_rc = lc->rightchild;
            switch (lc_rc->bf) {
                case 1:
                    (*bt)->bf = -1;lc->bf = 0;break;
                    break;
                case 0:
                    (*bt)->bf = 0;
                    lc->bf = 0;
                    
                    break;
                case -1:
                    (*bt)->bf = 0;
                    lc->bf = 1;
                    break;
                    
                default:
                    break;
            }
            lc_rc->bf = 0;
            leftRotate(&((*bt)->rightchild));
            rightRotate(bt);
            break;
        default:
            break;
    }
}

/// 右平衡
/// RR OR RL
void XYAVLTree::rightBalance(AVLNode *bt) {
    AVLNode rc = (*bt)->rightchild;
    AVLNode rc_lc;
    switch (rc->bf) {
            //特殊情况, 删除时候要考虑0, 否则会出现删除节点不平衡情况
        case 0:
            (*bt)->bf = -1;rc->bf = 0;
            leftRotate(bt);
            break;
            /// RL, 先右旋再左旋
        case 1:
            rc_lc = rc->leftchild;
            switch (rc_lc->bf) {
                case 1:
                    (*bt)->bf = 0;
                    rc->bf = -1;
                    break;
                case 0:
                    (*bt)->bf = 0;
                    rc->bf = 0;
                    break;
                case -1:
                    (*bt)->bf = 1;
                    rc->bf = 0;
                    break;
                default:
                    break;
            }
            rc_lc->bf = 0;
            rightRotate(&((*bt)->rightchild));
            leftRotate(bt);
            break;
            /// RR
        case -1:
            (*bt)->bf = 0;
            rc->bf = 0;
            leftRotate(bt);
            break;
        default:
            break;
    }
}

Status XYAVLTree::insertAVL(AVLNode *bt, DataType data, Status *more) {
    /// bt 为空，树长高
    if (*bt == NULL) {
        *bt = (AVLNode)malloc(sizeof(struct AVLTreeNode));
        (*bt)->rightchild = (*bt)->leftchild = NULL;
        (*bt)->data = data;
        (*bt)->bf =0;
        *more = true;
    }else{
        /// 树中已存在和data相等的节点
        if (data == (*bt)->data) {
            *more = false;return 0;
        }
        /// 插入左子树
        else if(data <  (*bt)->data) {
            if (insertAVL(&((*bt)->leftchild), data, more) == 0) {
                return 0;
            }
            if (true == *more) {
                switch ((*bt)->bf) {
                        /// LL,左平衡操作，more = false,不需要继续向上回溯
                    case 1:
                        /// 左平衡
                        leftBalance(bt);
                        *more = false;
                        break;
                        /// 深度+1,more = true, 需要继续向上回溯
                    case 0:
                        (*bt)->bf = 1;
                        *more = true;
                        break;
                        /// 深度+1,more = false,不需要继续向上回溯
                    case -1:
                        (*bt)->bf = 0;
                        *more = false;
                        break;
                    default:
                        break;
                }
            }
        }
        /// 插入右子树
        else {
            if (insertAVL(&((*bt)->rightchild), data, more) == 0) return 0;
            if (true == *more) {
                switch ((*bt)->bf) {
                        
                        /// more = false,不需要回溯
                    case 1:
                        (*bt)->bf = 0;
                        *more = false;
                        break;
                        
                        /// more = true, 需要回溯
                    case 0:
                        (*bt)->bf = -1;
                        *more = true;
                        break;
                        
                        /// RR OR RL, 右平衡操作, more = false,不需要回溯
                    case -1:
                        
                        rightBalance(bt);
                        *more = false;
                        break;
                    default:
                        break;
                }
            }
        }
    }
    return 1;
}

Status XYAVLTree::deleteAVL(AVLNode *bt, DataType data, Status *less) {
    AVLNode q = NULL;
    if ((*bt) == NULL) {
        *less = false;
        return 0;
    }
    else if(data == (*bt)->data) {
        if ((*bt)->leftchild == NULL) {
            (*bt) = (*bt)->rightchild; *less = true;
        } else if((*bt)->rightchild == NULL) {
            (*bt) = (*bt)->leftchild; *less = true;
        } else {
            q = (*bt)->leftchild;
            while (q->rightchild != NULL) {
                q = q->rightchild;
            }
            (*bt)->data = q->data;
            if (deleteAVL(&((*bt)->leftchild), q->data, less ) == 0) return 0;
            if (true == *less) {
                switch ((*bt)->bf) {
                    case 1:
                        (*bt)->bf =  0;
                        *less = true;
                        break;
                    case 0:
                        (*bt)->bf = AVLDepth((*bt)->leftchild) - AVLDepth((*bt)->rightchild);
                        *less = false;
                        break;
                    case -1:
                        rightBalance(bt);
                        if ((*bt)->rightchild->bf == 0)
                            *less = false;
                        else
                            *less = true;
                        
                        break;
                    default:
                        break;
                }
            }
        }
    } else if (data < (*bt)->data) {
        if (deleteAVL(&((*bt)->leftchild), data, less) == 0) return 0;
        if (true == *less) {
            switch ((*bt)->bf) {
                case 1:
                    (*bt)->bf = 0; *less = true;
                    break;
                case 0:
                    (*bt)->bf = -1; *less = false;
                    break;
                case -1:
                    rightBalance(bt);
                    if ((*bt)->rightchild->bf == 0)
                        *less = false;
                    else
                        *less = true;
                    break;
                default:
                    break;
            }
        }
    } else {
        if (deleteAVL(&((*bt)->rightchild), data, less) == 0) return 0;
        if (true == *less) {
            switch ((*bt)->bf) {
                case 1:
                    leftBalance(bt);
                    if ((*bt)->leftchild->bf == 0) *less = false;
                    else *less = true;
                    break;
                case 0:
                    (*bt)->bf = 1; *less = false;
                    break;
                case -1:
                    (*bt)->bf = 0; *less = true;
                default:
                    break;
            }
        }
    }
    return 1;
}
