# XY.alogrithm

Exercise alogrithm

```
class XYSort {
public:
    XYSort();
    ~XYSort();
    
    // 冒泡排序
    void bubleSort(int *array,int count,bool asc);
    
    // 快速排序
    void quickSort(int *array,int count,bool asc);
    
    // 插入排序
    void insertSort(int *array,int count,bool asc);
    
    // 选择排序
    void selectSort(int *array,int count,bool asc);
    
    // 归并排序
    void mergeSort(int *array,int count,bool asc);
    
    
protected:
    
private:
    // 合并两个有序数组
    void merge(int array0[],int left,int mid,int right,int temp[]);
    void merge_Sort(int arr[],int left,int right,int temp[]);
    
};

class XYSearch {
    public:
    
    XYSearch();
    ~XYSearch();
    

    void linearSearch(int *array,int count,int val);
    void divideSearch(int *array,int count,int val);
    int recursiveDivideSearch(int *array,int low,int high,int key);
    
};

```


Exercise LeetCodes
```

class LeetCodeSolution {
public:
 
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
    // 字符串反转
    void reverseString(vector<char>& s) ;
    // 两数之和
    vector<int> twoSum(vector<int>& nums, int target);
    
private:
    bool isPrime(int num);
    
};
```
Exercise Thinking 

学习和应用递归思想;

学习和应用哈希表思想;
