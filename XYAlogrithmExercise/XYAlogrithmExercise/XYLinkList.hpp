//
//  XYLinkList.hpp
//  XYAlogrithmExercise
//
//  Created by Yanci on 2019/11/26.
//  Copyright © 2019 Yanci. All rights reserved.
//

#ifndef XYLinkList_hpp
#define XYLinkList_hpp

#include <stdio.h>
#include <map>
#include <unordered_map>
using namespace std;
/// Singly List Node
struct SinglyListNode {
    int val;
    SinglyListNode *next;
    SinglyListNode(int x): val(x), next(NULL) {}
};


struct ListNode_ {
    int val;
    ListNode_ *next;
    ListNode_(int x) : val(x), next(NULL) {}
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
class MyLinkedList {
    
    SinglyListNode *head;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        int count = 0;
        SinglyListNode *cur = head;
        while (cur != NULL && count++ != index) {
            cur = cur->next;
        }
        int val = cur != NULL ? cur->val : -1;
        return val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        SinglyListNode *add = new SinglyListNode(val);
        add->next = head;
        head = add;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        SinglyListNode *add = new SinglyListNode(val);
        SinglyListNode *cur = head;
        while(cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = add;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        
        if (index == 0) addAtHead(val);
        
        SinglyListNode *prev = head;
        SinglyListNode *next = prev->next;
        SinglyListNode *add = new SinglyListNode(val);
        
        int count = 0;
        while (next != NULL && ++count != index) {
            prev = prev->next;
            next = next->next;
        }
        
        add->next = next;
        prev->next = add;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        
        if (index == 0) { head = head->next; return; }
        
        SinglyListNode *prev = head;
        SinglyListNode *next = prev->next;
        
        int count = 0;
        while (++count != index) {
            prev = prev->next;
            next = next->next;
        }
        prev->next = next ?  next->next : NULL;
    }
    
    bool hasCycle(ListNode_ *head) {
        if (head == NULL) return false;
 
        unordered_map<ListNode_ *, int> linkListMap;
        linkListMap[head] = 1;
        
        while (head->next != NULL) {
            head = head->next;
            if (linkListMap[head] == 1) {
                return true;
            }
            linkListMap[head] = 1;
        }
        
        return false;
    }
};

#endif /* XYLinkList_hpp */
