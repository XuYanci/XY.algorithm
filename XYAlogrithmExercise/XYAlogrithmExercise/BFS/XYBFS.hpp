//
//  XYQueue.hpp
//  XYAlogrithmExercise
//
//  Created by Yanci on 2019/4/25.
//  Copyright © 2019 Yanci. All rights reserved.
//

#ifndef XYQueue_hpp
#define XYQueue_hpp
#include <list>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class XYBFS {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x):val(x),left(NULL),right(NULL){}
    };
    
    struct Node {
        int val;
        std::list<Node>list;
    };
    
    /// 广度优先搜索
    int BFS(Node root, Node target);
    /// 最小深度
    int minDepth(TreeNode* root);
    /// 打开转盘锁
    int openLock(vector<string>& deadends, string target);
};
 

#endif /* XYQueue_hpp */
