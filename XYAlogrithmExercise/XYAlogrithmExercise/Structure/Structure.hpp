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
    
    MobileLinkNode *head;
    
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
    
};

#endif /* Structure_hpp */
