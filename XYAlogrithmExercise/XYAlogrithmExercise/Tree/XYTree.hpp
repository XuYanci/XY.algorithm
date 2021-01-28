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
#include <unordered_map>
using namespace std;
//1.前序遍历：先访问根节点——左子树——右子树。
//2.中序遍历：先访问左子树——根节点——右子树，按照这个顺序。
//3.后序遍历：和前面差不多，先访问树的左子树——右子树——根节点。
//4.按层遍历：把一棵树从上到下，从左到右依次写出来。

class XYTree {
public:
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
    
    /// 自底向上
    int maximum_depth(TreeNode* root) {
        if (!root) {
            return 0;                                 // return 0 for null node
        }
        
        int left_depth = maximum_depth(root->left);
        int right_depth = maximum_depth(root->right);
        
        /// 左子树深度，右子树深度（选择较大） + 1
        return max(left_depth, right_depth) + 1;      // return depth of the subtree rooted at root
    }
    
    /// 自顶到下
    int answer;               // don't forget to initialize answer before call maximum_depth
    void maximum_depth(TreeNode* root, int depth) {
        if (!root) {
            return;
        }
        
        /// 如果左节点以及右节点都不存在的话
        if (!root->left && !root->right) {
            answer = max(answer, depth);
        }
        
        /// 继续遍历左
        maximum_depth(root->left, depth + 1);
        
        /// 继续遍历右
        maximum_depth(root->right, depth + 1);
    }
    
    /// 恢复二叉搜索树
    /// 题目:给你二叉搜索树的根节点 root ，该树中的两个节点被错误地交换。请在不改变其结构的情况下，恢复这棵树。
    /// 思路:
    //    a1,a2,a3, b1,b2,b3
    //    a2与b2交换时候 a1,b2,a3,b1,a2,b3
    //    找出不满足（ 第一个节点 < 第二个节点)
    //    b2 > a3 选择第一个节点
    //    b1 > a2 选择后一个节点
    
    vector<TreeNode *> recoverTreeList;
    
    TreeNode *prev = NULL;
    TreeNode *x = NULL;
    TreeNode *y = NULL;
    void recoverTree(TreeNode* root) {
        
        /** 方式1 */
        //        if (root == NULL) {
        //            return;
        //        }
        //
        //        recoverTreeList = vector<TreeNode*>();
        //        recoverTreeMiddle(root);
        //
        //        TreeNode *x = NULL;
        //        TreeNode *y = NULL;
        //
        //        for (int i = 0; i < recoverTreeList.size() - 1; i++) {
        //            if (recoverTreeList[i]->val > recoverTreeList[i + 1]->val) {
        //                y = recoverTreeList[i+1];
        //                if (x == NULL) {
        //                    x = recoverTreeList[i];
        //                }
        //            }
        //        }
        //
        //        int tmp = x->val;
        //        x->val = y->val;
        //        y->val = tmp;
        
        /** 方式2
         不扫描一遍，浪费O(N)存储空间
         */
        recoverTreeMiddle2(root);
        
        int tmp = x->val;
        x->val = y->val;
        y->val = tmp;
        
    }
    
    void recoverTreeMiddle(TreeNode *root) {
        if (root == NULL) {
            return;;
        }
        recoverTreeMiddle(root->left);
        recoverTreeList.push_back(root);
        recoverTreeMiddle(root->right);
    }
    
    void recoverTreeMiddle2(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        recoverTreeMiddle2(root->left);
        
        if (prev != NULL && prev->val > root->val) {
            if (x == NULL) {
                x = prev;
            }
            y = root;
        }
        
        prev = root;
        recoverTreeMiddle2(root->right);
    }
    
    
    /// 从前序与中序遍历序列构造二叉树
    /// 思路:先序遍历（根，左，右），中序遍历（左，根，右），属于递归问题，从上到下
    ///  1,2,3,[4],5,6,7
    /// [4],1,2,3,5,6,7
    unordered_map<int, int> buildTreeMap;
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        /// 根据中序遍历建立映射
        buildTreeMap1(inorder);
        /// 递归构造二叉树
        TreeNode *root = buildTreeRecursive(preorder,
                                            0,
                                            (int)preorder.size() - 1,
                                            inorder,
                                            0,
                                            (int)inorder.size() - 1);
        return root;
    }
    
    void buildTreeMap1(vector<int>&inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            buildTreeMap[inorder[i]] = i;
        }
    }
    //    [3,9];
    //    [9,3];
    TreeNode * buildTreeRecursive(vector<int>& preorder,
                                  int preBegin,
                                  int preEnd,
                                  vector<int>& inorder,
                                  int inBegin,
                                  int inEnd) {
        if (preBegin > preEnd) {
            return NULL;
        }
        
        TreeNode *node = new TreeNode(preorder[preBegin]);
        
        /// 根据哈希查找对应中序遍历的根节点(全局的)
        int inorderRootIndex = buildTreeMap[preorder[preBegin]];
        /// 根据中序遍历的根节点 【left, root, right】，计算出左节点数目
        /// LeftNum = PreEnd - findRootIndex (global map)
        int leftNum = inorderRootIndex - inBegin;
        
        node->left = buildTreeRecursive(preorder,
                                        preBegin + 1,
                                        preBegin + leftNum,
                                        inorder,
                                        inBegin,
                                        inBegin + leftNum - 1);
        
        node->right = buildTreeRecursive(preorder,
                                         preBegin + leftNum + 1,
                                         preEnd,
                                         inorder,
                                         inBegin + leftNum + 1,
                                         inEnd);
        return node;
    }
    
    /// 二叉树中的最大路径和
    int maxValue = INT_MIN;
    int maxPathSum(TreeNode* root) {
        reverseMaxPathSum(root);
        return maxValue;
    }
    
private:
    int reverseMaxPathSum(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        /// 后序遍历
        int left = max(0,reverseMaxPathSum(root->left));
        int right = max(0,reverseMaxPathSum(root->right));
        int lmr = left + right + root->val;
        int ret = max(left,right) + root->val;
        maxValue = max(maxValue,lmr);
        maxValue = max(maxValue,ret);
        return ret;
    }
    
    
};

#endif /* XYTree_hpp */
