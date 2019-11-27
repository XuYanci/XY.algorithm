```

class LeetCodeSolution {
public:
    // 字符串反转
    void reverseString(vector<char>& s) ;
    // 两数之和
    vector<int> twoSum(vector<int>& nums, int target);
    // 移除重复数字
    int removeDuplicates(std::vector<int>& nums);
    // 旋转数组
    void rotate(vector<int>& nums, int k);
    // 包含重复数字
    bool containsDuplicate(vector<int>& array);
    // 只出现一次的数字
    int singleNumber(vector<int>& nums);
    // 移动零
    void moveZeroes(vector<int>& nums);
    // 合并两个有序链表
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
    // 链表反转
    ListNode* reverseList(ListNode* head);
    //  整数反转
    int reverse(int x);
    // 计算素数的个数
    int countPrimes(int n);
    // 二叉树深度
    int maxDepth(TreeNode* root);
    // 栈做法
    int fib(int N);
    // 合并两个数组
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
    // 二叉树反转
    TreeNode* invertTree(TreeNode* root);
    /// 加一
    vector<int> plusOne(vector<int>& digits);
    // 最长上升子序列
    int lengthOfLIS(vector<int>& nums);
    // 滑动窗口最大值
    vector<int> maxSlidingWindow(vector<int>& nums, int k);
    // 买卖股票的最佳时间II
    int maxProfit(vector<int>& prices);
    // 买卖股票的最佳时机
    int maxProfit1(vector<int>& prices);
    // 两个数组的交集 (考虑顺序)
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2);
    // 两个数组的交集 (不考虑顺序)
    vector<int> intersect1(vector<int>& nums1, vector<int>& nums2);
    /// 两两交换链表中的节点
    ListNode *swapPairs(ListNode *head);
    /// 杨辉三角形 (给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。在杨辉三角中，每个数是它左上方和右上方的数的和。)
    vector<vector<int>> generate(int numRows);
    /// 杨辉三角形2
    vector<int> getRow(int rowIndex);
    /// Pow  X的N次方
    double myPow(double x, int n);
    /// 岛屿问题
    int numIslands(vector<vector<char>>& grid);
    /// 打开转盘锁
    int openLock(vector<string>& deadends, string target);
    /// 完全平方数
    int numSquares(int n);
    /// 有效的括号
    bool isValid(string s);
    /// 每日温度
    vector<int> dailyTemperatures(vector<int>& T);
    /// 逆波兰表达式求值
    int evalRPN(vector<string>& tokens);
    /// 中序遍历
    vector<int> inorderTraversal(TreeNode* root);
 
    /// 目标和
    int findTargetSumWays(vector<int>& nums, int S);
    /// 对角线遍历
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) ;
    /// 螺旋矩阵
    vector<int> spiralOrder(vector<vector<int>>& matrix);
    /// 最长公共前缀
    string longestCommonPrefix(vector<string>& strs);
private:
    bool isPrime(int num);
    int getMaxValue(vector<int>& nums,int begin,int end) ;
    bool compareTwoArray(vector<int>&nums1,vector<int>&nums2);
    void reverseString_recursive(vector<char> &s,int start,int end);
    int generate_00(int i,int j);
    int generate_000(int i, int j);
    int islands_bfs(vector<vector<char>>& grid,int i,int j,size_t m,size_t n);
    int islands_dfs(vector<vector<char>>& grid,int i,int j,size_t m,size_t n);
    
};
```

Now Not Consider 空间复杂度+时间复杂度 
