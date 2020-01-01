#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"
Status AVLDepth(AVLNode bt)// 计算二叉树深度
{
	if (bt == NULL)
		return 0;
	int left = 1;
	int right = 1;
	left += AVLDepth(bt->leftchild);
	right += AVLDepth(bt->rightchild);
	return left > right ? left : right;
}
void Inorder(AVLNode bt)//中序遍历
{
	if (bt == NULL) return;
	Inorder(bt->leftchild);
	printf("%d ", bt->data);
	Inorder(bt->rightchild);
}
Status searchAVL(AVLNode bt, DataType data)//查找Data
{
	if (!bt)
		return FALSE;
	if (bt->data == data)
		return TRUE;
	else if (data < bt->data)
		return searchAVL(bt->leftchild, data);
	else
		return searchAVL(bt->rightchild, data);
}
void destroyAVL(PAVLTree bt)// 销毁AVL
{
	AVLNode p = *bt;
	if (p == NULL)
		return;
	destroyAVL(&(p->leftchild));
	destroyAVL(&(p->rightchild));
	*bt = NULL;
}
void leftRotate(AVLNode *bt)//左旋
{
	AVLNode p = *bt;
	AVLNode rc = (*bt)->rightchild;
	(*bt)->rightchild = rc->leftchild;
	rc->leftchild = (*bt);
	(*bt) = rc;
}
void rightRotate(AVLNode *bt)//	右旋
{
	AVLNode lc = (*bt)->leftchild;
	(*bt)->leftchild = lc->rightchild;
	lc->rightchild = (*bt);
	(*bt) = lc;
}
void leftBalance(AVLNode *bt)//对树bt的左平衡处理
{
	AVLNode lc = (*bt)->leftchild; //lc指向bt的左孩子
	AVLNode lc_rc;
	switch (lc->bf)
	{
	case 0:
		(*bt)->bf = 1;  lc->bf = 0;   rightRotate(bt);
		break;
		//LL型, 进行右旋操作
	case 1:
		(*bt)->bf = 0;  lc->bf = 0;  rightRotate(bt);
		break;
		//LR型, 进行左旋操作, 再右旋操作
	case -1:
		lc_rc = lc->rightchild;
		switch (lc_rc->bf) //修改bt及其左孩子的平衡因子
		{
		case 1:    (*bt)->bf = -1; lc->bf = 0;  break;
		case 0:    (*bt)->bf = 0;  lc->bf = 0;  break;
		case -1:   (*bt)->bf = 0;  lc->bf = 1;  break;
		}
		lc_rc->bf = 0;
		leftRotate(&((*bt)->leftchild));
		rightRotate(bt);
		break;
	}//end 60
}
void rightBalance(AVLNode *bt)//对树bt的右平衡处理
{
	AVLNode rc = (*bt)->rightchild;
	AVLNode rc_lc;
	switch (rc->bf)
	{
		//特殊情况, 删除时候要考虑0, 否则会出现删除节点不平衡情况
	case 0:
		(*bt)->bf = -1;  rc->bf = 0;  leftRotate(bt);
		break;
		//RR型, 进行左旋操作
	case -1:
		(*bt)->bf = 0;  rc->bf = 0;  leftRotate(bt);
		break;
		//RL型, 进行右旋操作，再左旋操作
	case 1:
		rc_lc = rc->leftchild;
		switch (rc_lc->bf)
		{
		case 1:    (*bt)->bf = 0;  rc->bf = -1;  break;
		case 0:    (*bt)->bf = 0;  rc->bf = 0;   break;
		case -1:   (*bt)->bf = 1;  rc->bf = 0;   break;
		}
		rc_lc->bf = 0;
		rightRotate(&((*bt)->rightchild));
		leftRotate(bt);
		break;
	}//end 88
}
Status insertAVL(AVLNode *bt, DataType data, Status *more)//插入
{
	if (*bt == NULL) //bt为空, 树长高
	{
		*bt = (AVLNode)malloc(sizeof(struct AVLTreeNode));
		(*bt)->rightchild = (*bt)->leftchild = NULL;
		(*bt)->data = data;
		(*bt)->bf = 0;
		*more = TRUE;
	}
	else
	{
		//树中已存在和data相等的结点
		if (data == (*bt)->data)
		{
			*more = FALSE; return 0;//未插入
		}
		//插入左子树
		else if (data < (*bt)->data)
		{
			//下面两种方法都可以
			//insertAVL(&((*bt)->leftchild), data, more); //递归循环
			//if (FALSE == *more) return 0;//未插入
			if (insertAVL(&((*bt)->leftchild), data, more) == 0)
				return 0; //递归循环,递归出口
			if (TRUE == *more)
			{
				switch ((*bt)->bf)// 检查bt的平衡因子
				{
				case 1://原左高, 左平衡
					leftBalance(bt); *more = FALSE; break;
				case 0://原等高, 左变高
					(*bt)->bf = 1; *more = TRUE; break;
				case -1://原右高, 变等高
					(*bt)->bf = 0; *more = FALSE; break;
				}
			}//end 138
		}// end 131
		//插入右子树
		else
		{
			//下面两种方法都可以
			//insertAVL(&((*bt)->rightchild), data, more);
			//if (FALSE == *more ) return 0;//未插入
			if (insertAVL(&((*bt)->rightchild), data, more) == 0)
				return 0; //递归循环
			if (TRUE == *more)
			{
				switch ((*bt)->bf)
				{
				case 1: //原左高, 变等高
					(*bt)->bf = 0; *more = FALSE; break;
				case 0: //原等高, 变右高
					(*bt)->bf = -1;    *more = TRUE; break;
				case -1: //原右高, 右平衡
					rightBalance(bt); *more = FALSE; break;
				}
			}//end 159
		}// end 152
	}//end 123
	return 1;
}
Status deleteAVL(AVLNode *bt, DataType data, Status *less)//删除
{
	AVLNode q = NULL;
	if ((*bt) == NULL) //空树
	{
		*less = FALSE; return 0;
	}
	else if (data == (*bt)->data) //相等
	{
		if ((*bt)->leftchild == NULL)  //左子树为空, 接右子树
		{
			(*bt) = (*bt)->rightchild; *less = TRUE;
		}
		else if ((*bt)->rightchild == NULL) //右子树为空, 接左子树
		{
			(*bt) = (*bt)->leftchild; *less = TRUE;
		}
		else    //左右子树均不空, 则用其左子树的最大值取代
		{
			q = (*bt)->leftchild;
			while (q->rightchild != NULL) q = q->rightchild;
			(*bt)->data = q->data;
			//递归删除左孩子
			if (deleteAVL(&((*bt)->leftchild),q->data,less)==0)
				return 0;
			if (TRUE == *less)
			{
				switch ((*bt)->bf)
				{
				case 1:
					(*bt)->bf = 0;*less = TRUE;break;
				case 0:
					(*bt)->bf = AVLDepth((*bt)->leftchild) - 
					AVLDepth((*bt)->rightchild);
					*less = FALSE;break;
				case -1:
					rightBalance(bt);
					if ((*bt)->rightchild->bf == 0)
						*less = FALSE;
					else
						*less = TRUE;
					break;
				}
			}// end 200
		}// end 192
	}// end 182
	else if (data < (*bt)->data)  //左子树中继续查找
	{
		//递归删除左孩子
		if (deleteAVL(&((*bt)->leftchild), data, less) == 0) return 0;
		/*if (FALSE == *less)
		DO NOTHING;*/
		if (TRUE == *less)
		{
			switch ((*bt)->bf)
			{
			case 1:
				(*bt)->bf = 0;*less = TRUE;break;
			case 0:
				(*bt)->bf = -1;*less = FALSE;break;
			case -1:
				rightBalance(bt);
				if ((*bt)->rightchild->bf == 0)
					*less = FALSE;
				else
					*less = TRUE;
				break;
			}
		}// end 227
	}// end 221
	else    //右子树中继续查找
	{
		//递归删除右孩子
		if(deleteAVL(&((*bt)->rightchild),data,less)==0) return 0;
		/*if (FALSE == *less)
		DO NOTHING;*/
		if (TRUE == *less)
		{
			switch ((*bt)->bf)
			{
			case 1:
				leftBalance(bt);
				if ((*bt)->leftchild->bf == 0)
					*less = FALSE;
				else
					*less = TRUE;
				break;
			case 0:
				(*bt)->bf = 1;*less = FALSE; break;
			case -1:
				(*bt)->bf = 0;*less = TRUE; break;
			}
		}//end 251
	}// end 245
	return 1;
}