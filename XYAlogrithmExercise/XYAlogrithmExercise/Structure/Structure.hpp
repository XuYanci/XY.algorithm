//
//  Structure.hpp
//  XYAlogrithmExercise
//
//  Created by Yanci Xu on 2021/4/26.
//  Copyright © 2021 Yanci. All rights reserved.
//

#ifndef Structure_hpp
#define Structure_hpp

#include <stdio.h>
#include <vector>
using namespace std;
/// 数据结构主观题
class Structure {
    
    struct MobileLinkNode{
        char *nameType;
        double price;
        MobileLinkNode *next;
    };
    
    typedef struct node {
        int data;
        node *next;
    }LinkL,*LinkList;
    
    
    
    
    MobileLinkNode *head;
    LinkList linkListHead;
    
    int findK(int a[],int n,int k) {
        for (int i = 0; i < n; i++) {
            if (a[i] == k) {
                return i;
            }
        }
        return -1;
    }
    
    /// 初始化链表
    void initLink() {
        head = new MobileLinkNode();
        head->next = NULL;
        
        linkListHead = new LinkL();
        linkListHead->next = NULL;
    }
    
    /// 价格从低到高存储在一个带有头节点的单循环链表中
    void insertLink(MobileLinkNode *newNode) {
        MobileLinkNode *_head = head;
        MobileLinkNode *prev = _head;
        MobileLinkNode *next = _head->next;
        
        /// 如果节点不为空
        while (next) {
            /// 如果节点大于插入节点，则插入节点
            if (next->price > newNode->price) {
                /// 先链接
                newNode->next = next;
                /// 后断开
                prev->next = newNode;
            }
            
            prev = head->next;
            next = _head->next;
        }
        
        /// 如果是空链表，则插入到第一个
        if (next == NULL) {
            prev->next = newNode;
            return;
        }
    }
    
    void deleteMaxLinkValue(LinkList head) {
        LinkList _head = head;
        LinkList _next = _head->next;
        LinkList _max = _next;
        LinkList _max_prev = _head;
        
        /// Find Max Value
        while (_next != NULL) {
            if (_next->data > _max->data) {
                _max_prev = _head;
                _max = _next;
            }
            _head = _next;
            _next = _next->next;
        }
        
        /// Not the last node
        if (_max_prev->next) {
            _max_prev->next = _max_prev->next->next;
        }
        /// Is the last node
        else {
            _max_prev->next = NULL;
        }
        
    }
    
    /// 带头结点的单链表head中计算值为x的结点数
    int CountLinkList(LinkList head,int x) {
        LinkList _head = head->next;
        int count = 0;
        while (_head != NULL) {
            if (_head->data == x) {
                count++;
            }
            _head = _head->next;
        }
        return count;
    }
    
    /// 不带头结点的单链表head中计算值为x的结点数
    int CountLink1(LinkList head) {
        int count = 0;
        while (head != NULL) {
            head = head->next;
            count++;
        }
        return count;
    }
    
    /// 插入value到线性表
    void insertLinearTable(int index,int value) {
        int arrsize = 10;
        int A[arrsize];
        
        if (index > arrsize - 1) {
            return;
        }
        
        /// 向右移动，空出位置
        for (int i = arrsize - 1; i > index; i--) {
            A[i] = A[i - 1];
        }
        
        A[index] = value;
    }
    
    /// LinkA (递增有序), LinkB(递增有序), A,B合并递增有序
    LinkList mergeLinkList(LinkList A,LinkList B) {
        /// 1. 合并两个有序链表
        LinkList p = A->next;
        LinkList q = B->next;
        /// 1.新建头结点
        LinkList tail = new LinkL();
        LinkList head = tail;
        while (p != NULL  && q != NULL) {
            if (p->data <= q->data) {
                tail->next = p;
                p = p->next;
            } else {
                tail->next = q;
                q = q->next;
            }
            tail = tail->next;
        }
        
        if (p != NULL) {
            tail->next = p;
        }
        
        if (q != NULL) {
            tail->next = q;
        }
        
        return head;
    }
    
    /// LinkA (递增有序), LinkB(递增有序), A,B合并递减有序 (前插)
    LinkList mergeLinkListA(LinkList A,LinkList B) {
        /// 1. 合并两个有序链表
        LinkList p = A->next;
        LinkList q = B->next;
        /// 1.新建头结点
        LinkList head = new LinkL();
        LinkList next = head->next;
        
        while (p != NULL  && q != NULL) {
            if (p->data <= q->data) {
                p->next = next;
                head->next = p;
                next = p;
                p = p->next;
            } else {
                q->next = next;
                head->next = q;
                next = q;
                q = q->next;
            }
        }
        
        /// 这里不能直接插入，需要逐个前插入
        while (p != NULL) {
            p->next = next;
            head->next = p;
            next = p;
            p = p->next;
        }
        
        /// 这里不能直接插入，需要逐个前插入
        while (q != NULL) {
            p->next = next;
            head->next = q;
            next = q;
            q = q->next;
        }
        
        return head;
    }
    
    /// 判断带头结点的单链表L的元素值是否递增
    bool analysisIsLinkListIncrease(LinkList A) {
        LinkList head = A;
        LinkList next = head;
        if (!next) {
            return false;
        }
        int val = next->data;
        while (next != NULL && val >= next->data) {
            next = next->next;
        }
        return  next == NULL ?  true : false;
    }
    
    void deletaABC(vector<int> A,vector<int> B,vector<int> C) {
        int max = A[0];
        
        int i = 0;
        int j = 0;
        int k = 0;
        
        int countA = (int)A.size();
        int countB = (int)B.size();
        int countC = (int)C.size();
        
        while (i < countA && j < countB && k < countC) {
            
            if (A[i] == B[j] == C[k]) {
                
                /// 左移删除结点
                int l = (int)A.size() - i - 1;
                while (l-- > 0) {
                    A[i] = A[i+1];
                }
                
                /// 左移删除结点
                l = (int)B.size() - j - 1;
                while (l-- > 0) {
                    B[j] = B[j+1];
                    
                    }
                
                /// 左移删除结点
                l = (int)C.size() - k - 1;
                while (l-- > 0) {
                    C[k] = C[k+1];
                }
                
                countA--;
                countB--;
                countC--;
                
                if(i < countA || j < countB || k < countC) {
                    max = A[i];
                }
                
            }
            
            if(i >= countA || j >= countB || k >= countC) {
                break;;
            }
            
            if (A[i] < max) {
                i++;
                max = A[i] > max ? A[i] : max;
            }
            
            if (B[j] < max) {
                j++;
                max = B[j] > max ? B[j] : max;
            }
            
            if (C[k] < max) {
                k++;
                max = C[k] > max ? C[k] : max;
            }
        }
        
    }
    
    /// A,B,C三个线性表，删除即在B又在C出现的元素
    /// O(A+B+C)
    void deleteABC(LinkList A,LinkList B, LinkList C) {
        LinkList maxLinkList;
        /// 默认最大值，作为瞄点
        maxLinkList = A;
        
        /// 假设是带头节点
        LinkList APrev = A;
        LinkList BPrev = B;
        LinkList CPrev = C;
        
        A = A->next;
        B = B->next;
        C = C->next;
        
        /// 边界：A，B，C都不为空的时候
        while (A != NULL && B!= NULL && C!=NULL) {
            /// 如果结点都相等的情况下，则删除当前结点
            if (A->data == B->data == C->data) {
                APrev->next = A->next;
                A=A->next;
                BPrev->next = B->next;
                B=B->next;
                CPrev->next = C->next;
                C=C->next;
                
                if (A == NULL || B== NULL || C==NULL) {
                    break;;
                } else {
                    maxLinkList = A;
                }
                
            }
            
            if (A == NULL || B == NULL || C==NULL) {
                break;;
            }
            
            /// 往瞄点靠近
            if (A->data < maxLinkList->data) {
                A = A->next;
                maxLinkList = A->data > maxLinkList->data ? A : maxLinkList;
            }
            /// 往瞄点靠近
            if (B->data < maxLinkList->data) {
                B = B->next;
                maxLinkList = B->data > maxLinkList->data ? B : maxLinkList;
            }
            /// 往瞄点靠近
            if (C->data < maxLinkList->data) {
                C = C->next;
                maxLinkList = C->data > maxLinkList->data ? C : maxLinkList;
            }
            
        }
        
    }
};

#endif /* Structure_hpp */
