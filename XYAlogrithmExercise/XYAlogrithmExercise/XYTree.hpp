//
//  XYTree.hpp
//  XYAlogrithmExercise
//
//  Created by Yanci on 2019/4/25.
//  Copyright © 2019 Yanci. All rights reserved.
//

#ifndef XYTree_hpp
#define XYTree_hpp

#include <stdio.h>
#include <vector>
using namespace std;
//1.前序遍历：先访问根节点——左子树——右子树。
//2.中序遍历：先访问左子树——根节点——右子树，按照这个顺序。
//3.后序遍历：和前面差不多，先访问树的左子树——右子树——根节点。按层遍历：把一棵树从上到下，从左到右依次写出来。
class XYTree {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x):val(x),left(NULL),right(NULL){}
    };
    
    /// 先序 (递归)
    void preorder(TreeNode *root,vector<int> &vec) {
        if (root == NULL) return;
        vec.push_back(root->val);
        preorder(root->left,vec);
        preorder(root->right,vec);
    }
    
    /// 先序
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> vec;
        preorder(root, vec);
        return vec;
    }
    
    /// 中序 (递归)
    void midorder(TreeNode *root,vector<int> &vec) {
        if (root == NULL) return;
        midorder(root->left,vec);
        vec.push_back(root->val);
        midorder(root->right,vec);
    }
    /// 中序
    vector<int> midorderTraversal(TreeNode *root) {
        vector<int> vec;
        midorder(root, vec);
        return vec;
    }
    
    /// 后序 (递归)
    void postorder(TreeNode *root,vector<int> &vec) {
        if (root == NULL) return;
        postorder(root->left,vec);
        postorder(root->right,vec);
        vec.push_back(root->val);
    }
    /// 后序
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> vec;
        postorder(root, vec);
        return vec;
    }
    /// 层次遍历
    vector<int> levelorderTraversal(TreeNode *root) {
        vector<int> vec;
        return vec;
    }
    
};

#endif /* XYTree_hpp */
