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
        /// A的头结点作为第一个结点
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
};

#endif /* Structure_hpp */
