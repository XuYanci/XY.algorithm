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
    
    
    int Height(BinTree bt) {
        return 0;
    }
    
    void PreOrderTree(BinTree root) {
        
    }
    
    void CopyTree(BinTree root,BinTree newRoot) {
        
    }
    
    int Count(BinTree root,int val) {
        return 0;
    }
    
    int leftnode_num(BinTree root) {
        return 0;
    }
    
    int node_num(BinTree root) {
        return  0;
    }
    
    
};
#endif /* Tree_hpp */
