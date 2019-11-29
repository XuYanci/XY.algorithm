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
#include <queue>
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
    /// 思路: 广度搜索
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vec_;
        
        if (root == NULL) return vec_;
        
        /// 队列存放结点
        std::queue<TreeNode *>_queue;
        if (root != NULL) {
            _queue.push(root);
        }
        
        vector<int> vec__;
        vec__.push_back(root->val);
        vec_.push_back(vec__);
        
        while (_queue.empty() == false) {
            unsigned long size = _queue.size();
            vec__.clear();
            for (int i = 0; i < size;i++) {
                TreeNode *cur = _queue.front();
                if (cur->left != NULL) {
                    vec__.push_back(cur->left->val);
                    _queue.push(cur->left);
                }
                if (cur->right != NULL) {
                    vec__.push_back(cur->right->val);
                    _queue.push(cur->right);
                }
                _queue.pop();
            }
            if (!vec__.empty())
              vec_.push_back(vec__);
        }
        return vec_;
    }
    
    /// 自顶向下
    int maximum_depth(TreeNode* root) {
        if (!root) {
            return 0;                                 // return 0 for null node
        }
        int left_depth = maximum_depth(root->left);
        int right_depth = maximum_depth(root->right);
        return max(left_depth, right_depth) + 1;      // return depth of the subtree rooted at root
    }
    
    /// 自底向上
    int answer;               // don't forget to initialize answer before call maximum_depth
    void maximum_depth(TreeNode* root, int depth) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right) {
            answer = max(answer, depth);
        }
        maximum_depth(root->left, depth + 1);
        maximum_depth(root->right, depth + 1);
    }
    
};

#endif /* XYTree_hpp */
