//
//  jianzhiOffer.hpp
//  XYAlogrithmExercise
//
//  Created by Yanci on 2020/3/4.
//  Copyright © 2020 Yanci. All rights reserved.
//

#ifndef jianzhiOffer_hpp
#define jianzhiOffer_hpp
#include <vector>
#include <unordered_map>
#include <stdio.h>
#include <string>
#include <queue>
#include <stack>
#include<iostream>

using namespace std;

class JianZhiOffer {
    
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    
    class Node {
    public:
        int val;
        Node* next;
        Node* random;
        
        Node(int _val) {
            val = _val;
            next = NULL;
            random = NULL;
        }
    };
    
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            if(map.find(nums[i]) == map.end()) {
                map[nums[i]] = nums[i];
            } else {
                return nums[i];
            }
            
        }
        return -1;
    }
    
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        
        int row = 0;
        int col = (int)matrix[0].size() - 1;
        
        bool isFind = false;
        while (row < matrix.size() && col >= 0) {
            if (matrix[row][col] == target) {
                isFind = true;break;
            }
            else if (matrix[row][col] > target) {
                col--;
            }else {
                row++;
            }
        }
        
        return isFind;
    }
    
    /// 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
    string replaceSpace(string s) {
        string::size_type position = 0;
        string flag = " ";
        
        while((position=s.find(flag,position))!=string::npos)
        {
            
            s.replace(position, 1 , "%20");
            
        }
        return s;
    }
    
    string replaceSpace1(string s) {
        string::iterator it = s.begin();
        string replaceSpace;
        while(it!=s.end()) {
            if (*it == ' ') {
                replaceSpace += "%20";
            } else {
                replaceSpace += *it;
            }
            *it++;
        }
        return replaceSpace;
    }
    
    string reverseLeftWords(string s, int n) {
        int size = (int)s.size();
        int moveLength = n % size;
        int i = 0;
        
        if (n >= size) return s;
        if (moveLength == 0) return s;
        
        char moveStr[moveLength];
        while(i < moveLength) {
            moveStr[i] = s[i];
            i++;
        }
        
        i = 0;
        while(i < size - moveLength) {
            s[i] =  s[i + moveLength];
            i++;
        }
        
        int j = 0;
        while(j < moveLength) {
            s[i + j] = moveStr[j];
            j++;
        }
        return s;
    }
    
    vector<int> reversePrint(ListNode* head) {
        vector<int> nums;
        vector<int>reverseNum;
        while(head != NULL) {
            nums.push_back(head->val);
            head = head->next;
        }
        for (int i = (int)nums.size() - 1; i >= 0; i--) {
            reverseNum.push_back(nums[i]);
        }
        return reverseNum;
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode *tail = NULL;
        while(head != NULL) {
            ListNode *q = head->next;
            head->next = tail;
            tail = head;
            head = q;
        }
        return tail;
    }
    
    Node* copyRandomList(Node* head) {
        unordered_map<Node *,Node*> nodeMap;
        
        if (head == NULL) {
            return NULL;
        }
        Node *copyHead = new Node(head->val);
        Node *copyHeadReserved = copyHead;
        copyHead->random = head->random;
        nodeMap[head] = copyHead;
        
        while(head != NULL) {
            head = head->next;
            if (head != NULL) {
                Node *node = new Node(head->val);
                node->random = head->random;
                nodeMap[head] = node;
                copyHead->next = node;
                copyHead = node;
            }
        }
        
        copyHead = copyHeadReserved;
        while(copyHead != NULL) {
            copyHead->random = nodeMap[copyHead->random];
            copyHead = copyHead->next;
            
        }
        
        return copyHeadReserved;
    }
    
    int findRepeatNumber1(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            if (map[nums[i]] == 1) {
                return nums[i];
            }
            map[nums[i]] = 1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                count++;
            }
        }
        return count;
    }
    
    int missingNumber(vector<int>& nums) {
        int j = 0;
        for (j = 0; j < nums.size();j++) {
            if (nums[j] != j) {
                return j;
            }
        }
        return j;
    }
    char firstUniqChar(string s) {
        s= "lll";
        unordered_map<char,int> _map;
        for(int i = 0; i < s.size();i++) {
            _map[s[i]] = _map.find(s[i]) != _map.end() ? _map[s[i]]+1 : 1;
        }
        
        for(int i = 0; i < s.size();i++) {
            if(_map[s[i]] == 1) {
                return s[i];
            }
        }
        return ' ';
    }
    
    bool findNumberIn2DArray1(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        if (matrix[0].size() == 0)  return false;
        int row = 0;
        
        /// 二分查找优化
        for(int i = 0; i < matrix.size();i++) {
            if(target > matrix[i][0]) {
                row++;;
                
            } else if(target == matrix[i][0]) {
                return true;
            }
        }
        /// 二分查找优化
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < matrix[0].size();j++) {
                if (target == matrix[i][j]) {
                    return true;
                }
            }
        }
        return false;
    }
    
    vector<int> levelOrder(TreeNode* root) {
        vector<int> orders;
        if (root == NULL) return vector<int>{};
        
        queue<TreeNode*> queue_;
        queue_.push(root);
        while (queue_.empty() != true) {
            TreeNode *root = queue_.front();
            orders.push_back(root->val);
            if (root->left) {
                queue_.push(root->left);
            }
            
            if (root->right) {
                queue_.push(root->right);
            }
            queue_.pop();
        }
        
        return orders;
    }
    
    vector<vector<int>> levelOrder1(TreeNode* root) {
        vector<vector<int>> orders;
        queue<int> levels;
        if (root == NULL) return vector<vector<int>>{};
        
        queue<TreeNode*> queue_;
        queue_.push(root);
        levels.push(0);
        
        
        while (queue_.empty() != true) {
            TreeNode *root = queue_.front();
            int level = levels.front();
            
            if(level < orders.size()) {
                //                orders[level].push_back(root->val);
                if (level % 2 == 0) {
                    orders[level].push_back(root->val);
                } else{
                    orders[level].insert(orders[level].begin(),root->val);
                }
                
            } else {
                orders.push_back(vector<int>{root->val});
            }
            
            if (root->left) {
                levels.push(level + 1);
                queue_.push(root->left);
            }
            
            if (root->right) {
                levels.push(level + 1);
                queue_.push(root->right);
            }
            queue_.pop();
            levels.pop();
        }
        return orders;
    }
    
    vector<TreeNode *> _A;
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if ( A == NULL || B == NULL) return false;
        
        
        /// TODO: Optimize: 1,2步可以合并成一步
        
        /// 1. 在A寻找B的根节点
        findBInA(A, B);
        
        if (_A.size() == 0) return false;
        
        /// 2. 比较
        for(int i = 0; i <_A.size();i++) {
            bool result = compareBInA(_A[i], B);
            if (result) {
                return result;
            }
        }
        
        return false;
        
    }
    
    bool compareBInA(TreeNode *A,TreeNode *B) {
        
        if (B == NULL) {
            return true;
        }
        
        if (A == NULL) {
            return false;
        }
        
        if ( A->val != B->val) {
            return false;
        }
        
        bool result = compareBInA(A->left, B->left);
        if (!result) {
            return result;
        }
        result = compareBInA(A->right, B->right);
        if (!result) {
            return result;
        }
        
        return true;
    }
    
    void findBInA(TreeNode *A,TreeNode *B) {
        if (A == NULL || B == NULL) {
            return;
        }
        if (A->val == B->val) {
            _A.push_back(A);
        }
        findBInA(A->left,B);
        findBInA(A->right,B);
    }
    
    TreeNode* mirrorTree(TreeNode* root) {
        mirrorTree1(root);
        return root;
    }
    
    
    void mirrorTree1(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        mirrorTree1(root->left);
        mirrorTree1(root->right);
        
        /// 后序替换
        TreeNode *left = root->left;
        root->left = root->right;
        root->right = left;
        return;
    }
    
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        if (root->left == NULL && root->right == NULL) return true;
        if (root->left == NULL || root->right == NULL) return false;
        return isSymmetric_(root->left, root->right);
    }
    
    bool isSymmetric_(TreeNode *root,TreeNode *root1) {
        
        if (root == NULL && root1 == NULL) {
            return true;
        }
        else if (root == NULL || root1 == NULL) {
            return false;
        }
        else if(root->val != root1->val) {
            return false;
        }
        
        bool result = isSymmetric_(root->left, root1->right);
        if (!result) {
            return false;
        }
        
        result = isSymmetric_(root->right, root1->left);
        if (!result) {
            return false;
        }
        
        return true;
    }
    
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        return fib(n - 1) + fib(n - 2);
    }
    
    int fib1(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        /// TODO: dp状态表可以省略掉
        vector<long>s(n,0);
        
        for (int i = 0; i < n;i++) {
            if (i == 0)
            {
                s[i] = 0;
                
            }
            else if (i == 1)
            {
                s[i] = 1;
            }
            else {
                s[i] = (s[i - 1]  +  s[i - 2] )% 1000000007;
            }
        }
        
        return (s[n - 1] + s[n - 2]) % 1000000007;
    }
    
    int numWays(int n) {
        if (n == 0) return 1;
        if (n == 1) return 1;
        if (n == 2) return 2;
        
        
        /// TODO: dp状态表可以省略掉
        vector<long>s(n,0);
        
        for (int i = 0; i < n;i++) {
            if (i == 0)
            {
                s[i] = 0;
                
            }
            else if (i == 1)
            {
                s[i] = 1;
            }
            else if (i == 2) {
                s[i] = 2;
            }
            else {
                s[i] = (s[i - 1]  +  s[i - 2] )% 1000000007;
            }
        }
        
        return (s[n - 1] + s[n - 2]) % 1000000007;
    }
    
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int max = 0;
        for (int i = 1; i < prices.size(); i++) {
            for (int j = 0; j < i; j++) {
                int value = prices[i] - prices[j];
                max = max  > value ?  max :  value;
            }
        }
        return max;
    }
    
    int maxValue(vector<vector<int>>& grid) {
        
        /// 边界判断，如果行数等于0
        if (grid.size() == 0) return 0;
        /// 边界判断，如果烈数等于0
        if (grid[0].size() == 0) return 0;
        
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size();j++) {
                int left = 0;
                if (j - 1 >= 0) {
                    left = grid[i][j-1];
                }
                int top = 0;
                if (i - 1 >= 0) {
                    top = grid[i - 1][j];
                }
                /// 状态转移公式
                grid[i][j] += left > top ?  left : top;
            }
        }
        
        return grid[grid.size() - 1][grid[0].size() - 1];
    }
    
    int translateNum(int num) {
        
        /// 将数字转换成数组
        vector<int>nums;
        while (num / 10 > 0) {
            int value = num % 10;
            nums.insert(nums.begin(), value);
            num /= 10;
        }
        nums.insert(nums.begin(), num % 10);
        
        /// 状态转移公式:
        /// dp[i] =  dp[i -1] + dp[i -2] ( 10<=nums[i-1] * 10 + nums[i] <= 25)
        /// dp[i] = dp[i-1]
        vector<int>dp(nums.size(),0);
        dp[0] = 1;
        
        for (int i = 1; i < nums.size(); i++) {
            if(nums[i -1] * 10 + nums[i]  >= 10 && nums[i-1] * 10 + nums[i] <= 25) {
                dp[i] = dp[i-1] + (i - 2 < 0 ? 1 : dp[i -2]);
            } else {
                dp[i] = dp[i-1];
            }
        }
        
        
        return dp[nums.size() - 1];
        
    }
    
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> _map;
        
        int maxValue = 0;
        int value = 0;
        int begin = 0;
        for(int i = 0;i < s.size();i++) {
            if (_map.find(s[i]) == _map.end() || _map[s[i]] < begin) {
                _map[s[i]] = i;
                value++;
                maxValue = maxValue > value ? maxValue : value;
            }
            else {
                begin = _map[s[i]] ;
                value = i - _map[s[i]];
                _map[s[i]] = i;
            }
        }
        
        return maxValue;
    }
    
    ListNode* deleteNode(ListNode* head, int val) {
        
        if (head == NULL) return NULL;
        if (head->val == val) {
            head = head->next;
            return head;
        }
        
        ListNode *h = head;
        ListNode *prev = head;
        head = head->next;
        while (head != NULL) {
            if (head->val == val) {
                prev->next = head->next;
                break;;
            }
            prev = head;
            head = head->next;
        }
        
        return h;
    }
    
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if (head == NULL) return NULL;
        if (k == 0) return NULL;
        
        ListNode *tail = head;
        
        int count = 0;
        while (tail != NULL && count < k) {
            tail = tail->next;
            count++;
        }
        
        if (tail == NULL) return head;
        
        while (tail != NULL) {
            tail = tail->next;
            head = head->next;
        }
        
        return head;
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode * h = head;
        
        while (l1 != NULL && l2 != NULL) {
            if(l1->val <= l2->val) {
                head->next = l1;
                l1 = l1->next;
            } else {
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }
        
        while (l1 != NULL) {
            head->next = l1;
            l1 = l1->next;
            head = head->next;
        }
        
        while (l2 != NULL) {
            head->next = l2;
            l2 = l2->next;
            head = head->next;
        }
        
        return h->next;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode *, int> _map;
        
        while (headA != NULL) {
            _map[headA] = 1;
            headA = headA->next;
        }
        
        while (headB != NULL && _map.find(headB) == _map.end()) {
            headB = headB->next;
        }
        
        return headB;;
        
    }
    
    vector<int> exchange(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size();i++) {
            if(nums[i] % 2 == 1) {
                int temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
                j++;
            }
        }
        return nums;
    }
    
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> _map;
        vector<int> twoSum;
        for (int i = 0; i < nums.size(); i++) {
            if (_map.find(nums[i]) != _map.end()) {
                twoSum.push_back(nums[i]);
                twoSum.push_back(target - nums[i]);
                break;
            }
            _map[target - nums[i]] = 1;
        }
        return twoSum;
    }
    
    string reverseWords(string s) {
        stack<string> _stack;
        
        string ss = "";
        for(int i = 0; i < s.size(); i++) {
            if (s[i] == ' ' ) {
                if (ss.size() > 0) {
                    _stack.push(ss);
                }
                ss = "";
            } else {
                ss += s[i];
            }
        }
        
        if (ss.size() > 0) {
            _stack.push(ss);
        }
        
        string result = "";
        while(_stack.empty() == false) {
            result += _stack.top();
            _stack.pop();
            if (_stack.empty()) break;
            result += ' ';
        }
        
        return result;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        bool result = false;
        
        vector<vector <int> > visited(board.size() ,vector<int>(board[0].size(),0));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    visited[i][j] = true;
                    result = dfs_exist(board, word, 0 + 1, i, j,visited);
                    visited[i][j] = false;
                    if (result) {return true;}
                }
            }
        }
        return result;
    }
    
    bool dfs_exist(vector<vector<char>>& board,string word, int index,int i ,int j,vector<vector<int>>&visited) {
        if (index == word.size()) {
            return true;
        }
        
        // 上
        int upI = i - 1;
        int UpJ = j;
        
        // 下
        int downI = i + 1;
        int downJ = j;
        
        // 左
        int leftI = i;
        int leftJ = j - 1;
        
        // 右
        int rightI = i;
        int rightJ = j + 1;
        
        int row = (int)board.size();
        int col = (int)board[0].size();
        
        bool result = false;
        if (upI >= 0 && upI < row && UpJ >=0 && UpJ < col && board[upI][UpJ] == word[index] && !visited[upI][UpJ]) {
            visited[upI][UpJ] = true;
            result = dfs_exist(board, word, index + 1, upI, UpJ,visited);
            visited[upI][UpJ] = false;
            if (result) return true;
        }
        if (downI >= 0 && downI < row && downJ >=0 && downJ < col && board[downI][downJ] == word[index]&& !visited[downI][downJ]) {
            visited[downI][downJ] = true;
            result = dfs_exist(board, word, index + 1, downI, downJ,visited);
            visited[downI][downJ] = false;
            if (result) return true;
        }
        if (leftI >= 0 && leftI < row && leftJ >=0 && leftJ < col && board[leftI][leftJ] == word[index]&& !visited[leftI][leftJ]) {
            visited[leftI][leftJ] = true;
            result = dfs_exist(board, word, index + 1, leftI, leftJ,visited);
            visited[leftI][leftJ] = false;
            if(result) return true;
        }
        if (rightI >= 0 && rightI < row && rightJ >=0 && rightJ < col && board[rightI][rightJ] == word[index]&& !visited[rightI][rightJ]) {
            visited[rightI][rightJ] = true;
            result = dfs_exist(board, word, index + 1, rightI, rightJ,visited);
            visited[rightI][rightJ] = false;
            if (result) return true;
        }
        
        return false;
    }
    
    
    int movingCount(int m, int n, int k) {
        
        vector<vector<int>>visited(m ,vector<int>(n,0));
        visited[0][0] = true;
        dfs_movingCount(0, 0, visited,k);
        
        
        int movingCount = 0;
        for (int i = 0; i < m; i++) {
            for(int j = 0;j < n;j++) {
                if (visited[i][j] == true) {
                    movingCount++;
                }
            }
        }
        
        return movingCount;
    }
    
    void dfs_movingCount(int i,int j,vector<vector<int>>&visited,int k) {
        
        if (( (i / 10) + (i % 10) + (j / 10) + (j % 10)) > k ) {
            return;;
        }
        
        visited[i][j] = true;
        // 上
        int upI = i - 1;
        int UpJ = j;
        
        // 下
        int downI = i + 1;
        int downJ = j;
        
        // 左
        int leftI = i;
        int leftJ = j - 1;
        
        // 右
        int rightI = i;
        int rightJ = j + 1;
        
        int row = (int)visited.size();
        int col = (int)visited[0].size();
        
        
        if (upI >= 0 && upI < row && UpJ >=0 && UpJ < col && !visited[upI][UpJ]) {
            
            dfs_movingCount(upI, UpJ,visited,k);
        }
        if (downI >= 0 && downI < row && downJ >=0 && downJ < col && !visited[downI][downJ]) {
            
            dfs_movingCount(downI, downJ,visited,k);
        }
        if (leftI >= 0 && leftI < row && leftJ >=0 && leftJ < col && !visited[leftI][leftJ]) {
            
            dfs_movingCount( leftI, leftJ,visited,k);
        }
        if (rightI >= 0 && rightI < row && rightJ >=0 && rightJ < col && !visited[rightI][rightJ]) {
            
            dfs_movingCount( rightI, rightJ,visited,k);
        }
        
    }
};

#endif /* jianzhiOffer_hpp */
