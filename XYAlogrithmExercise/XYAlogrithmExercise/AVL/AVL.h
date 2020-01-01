#ifndef AVL_H
#define AVL_H

typedef int Status;
typedef int DataType;
#define TRUE 1
#define FALSE 0
//平衡二叉树排序树结点定义
struct AVLTreeNode
{
	DataType data;
	int bf;
	struct AVLTreeNode *leftchild; //左孩子指针
	struct AVLTreeNode *rightchild; //右孩子指针
};
//平衡二叉树排序树类型定义
typedef struct AVLTreeNode *AVLNode;
typedef struct AVLTreeNode *AVLTree;
typedef AVLTree *PAVLTree;

//函数功能： 计算AVL树的深度
//输入参数： AVL树
//返回值：  AVL树的深度
Status AVLDepth(AVLNode bt);

//函数功能： 中序遍历AVL树
//输入参数： AVL树
//返回值：  无
void Inorder(AVLNode bt);

//函数功能： 检索AVL树
//输入参数bt： AVL树
//输入参数key： 要检索的元素
//返回值：  成功返回1，否则返回0
Status searchAVL(AVLNode bt, DataType key);

//函数功能： 销毁AVL树
//输入参数： AVL树
//返回值：  无
void destroyAVL(PAVLTree bt);

//函数功能： 左旋AVL树
//输入参数： AVL树
//返回值：  无
void leftRotate(AVLNode *bt);

//函数功能： 右旋AVL树
//输入参数： AVL树
//返回值：  无
void rightRotate(AVLNode *bt);

//函数功能： 左平衡处理AVL树
//输入参数： AVL树
//返回值：  无
void leftBalance(AVLNode *bt);

//函数功能： 左平衡处理AVL树
//输入参数： AVL树
//返回值：  无
void rightBalance(AVLNode *bt);

//函数功能： 在AVL树中插入元素
//输入参数bt： AVL树
//输入参数key： 要插入的元素
//输入参数more： 层数是否增加
//返回值：  无
Status insertAVL(AVLNode *bt, DataType key, Status *more);

//函数功能： 在AVL树中删除元素
//输入参数bt： AVL树
//输入参数key： 要删除的元素
//输入参数less： 层数是否减少
//返回值：  无
Status deleteAVL(AVLNode *bt, DataType key, Status *less);


#endif
