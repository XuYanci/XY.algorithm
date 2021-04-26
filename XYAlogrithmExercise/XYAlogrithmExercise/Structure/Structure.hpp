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
    
};

#endif /* Structure_hpp */
