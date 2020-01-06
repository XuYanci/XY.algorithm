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
Status XYAVLTree::AVLDepth(AVLNode bt) {
    if (bt == NULL) return 0;
    int left = 1;
    int right = 1;
    left += AVLDepth(bt->leftchild);
    right+= AVLDepth(bt->rightchild);
    return left > right  ? left : right;
}

void XYAVLTree::Inorder(AVLNode bt) {
    if (bt == NULL) return;
    Inorder(bt->leftchild);
    printf("%d",bt->data);
    Inorder(bt->rightchild);
}

Status XYAVLTree::searchAVL(AVLNode bt, DataType data) {
    if (!bt) return false;
    if (bt->data == data) {
        return true;
    }
    else if ( data  < bt->data ) {
        return searchAVL(bt->leftchild, data);
    }
    else {
        return searchAVL(bt->rightchild, data);
    }
    return 1;
}

void XYAVLTree::destroyAVL(PAVLTree bt) {
    AVLNode p = *bt;
    if (p == NULL) {
        return;
    }
    destroyAVL(&(p->leftchild));
    destroyAVL(&(p->rightchild));
    *bt = NULL;
}

void XYAVLTree::leftRotate(AVLNode *bt) {
    AVLNode rc = (*bt)->rightchild;
    (*bt)->rightchild = rc->leftchild;
    rc->leftchild = (*bt);
    (*bt) = rc;
}

void XYAVLTree::rightRotate(AVLNode *bt) {
    AVLNode lc = (*bt)->leftchild;
    (*bt)->leftchild = lc->rightchild;
    lc->rightchild = (*bt);
    (*bt) = lc;
}

void XYAVLTree::leftBalance(AVLNode *bt) {
    AVLNode lc = (*bt)->leftchild;
    AVLNode lc_rc;
    switch (lc->bf) {
        case 0:
            (*bt)->bf = 1;
            lc->bf = 0;
            rightRotate(bt);
            break;
        case 1:
            (*bt)->bf = 0;
            lc->bf = 0;
            rightRotate(bt);
            break;
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

void XYAVLTree::rightBalance(AVLNode *bt) {
    AVLNode rc = (*bt)->rightchild;
    AVLNode rc_lc;
    switch (rc->bf) {
        case 0:
            (*bt)->bf = -1;rc->bf = 0;
            leftRotate(bt);
            break;
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
                    case 1:
                        leftBalance(bt);
                        *more = false;
                        
                        break;
                    case 0:
                        (*bt)->bf = 1;
                        *more = true;
                        break;
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
                    case 1:
                        (*bt)->bf = 0;
                        *more = false;
                        break;
                    case 0:
                        (*bt)->bf = -1;
                        *more = true;
                        break;
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
