//
//  XYAVLTree.hpp
//  XYAlogrithmExercise
//
//  Created by Yanci on 2019/12/27.
//  Copyright © 2019 Yanci. All rights reserved.
//

#ifndef XYAVLTree_hpp
#define XYAVLTree_hpp

#include <stdio.h>

typedef int Status;
typedef int  DataType;

struct AVLTreeNode {
    DataType data;
    int bf;
    struct AVLTreeNode *leftchild;
    struct AVLTreeNode *rightchild;
};
typedef struct AVLTreeNode *AVLNode;
typedef struct AVLTreeNode *AVLTree;

typedef AVLTree *PAVLTree;




class XYAVLTree {
    /// AVL树深度
    Status AVLDepth(AVLNode bt);
    /// AVL中序遍历
    void Inorder(AVLNode bt);
    /// 搜索AVL
    Status searchAVL(AVLNode bt,DataType key);
    /// 摧毁AVL
    void destroyAVL(PAVLTree bt);
    /// 左旋
    void leftRotate(AVLNode *bt);
    /// 右旋
    void rightRotate(AVLNode *bt);
    /// 左平衡
    void leftBalance(AVLNode *bt);
    /// 右平衡
    void rightBalance(AVLNode *bt);
    /// 插入AVL
    Status insertAVL(AVLNode *bt, DataType key, Status *more);
    /// 删除AVL
    Status deleteAVL(AVLNode *bt, DataType key, Status *less);
};
#endif /* XYAVLTree_hpp */
