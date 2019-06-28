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
private:
    bool isPrime(int num);
    int getMaxValue(vector<int>& nums,int begin,int end) ;
    bool compareTwoArray(vector<int>&nums1,vector<int>&nums2);
    
};
```
