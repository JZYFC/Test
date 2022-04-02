//
// Created by JZYFC on 2022/3/5.
//
#include "linked_list.h"

size_t getListSize(Node *curr);

void lnk_del_x2y(LinkList L, ElemType mink, ElemType maxk) {
    Node *prev = L;
    Node *pStart = NULL;
    Node *curr = L->next;
    bool isFree = false;
    while (curr != NULL) {
        if (pStart == NULL && curr->data > mink && curr->data < maxk) {
            pStart = prev;
        }
        if (pStart != NULL ) {
            if (curr->data < maxk)
                isFree = true;
            else {
                pStart->next = curr;
                break;
            }
        }
        prev = curr;
        curr = curr->next;
        if (isFree) free(prev);
    }
}

int lnk_search(LinkList L, int k, ElemType* p_ele) {
    Node* curr = L->next;
    size_t cnt = getListSize(curr);
    curr = L->next;
    if (cnt < k) return 0;
    for (int i = 0; i < cnt - k; ++i) {
        curr = curr->next;
    }
    *p_ele = curr->data;
    return 1;
}

size_t getListSize(Node* curr) {
    size_t cnt = 0;
    curr = curr->next;
    while (curr != NULL) {
        curr = curr->next;
        cnt++;
    }
    return cnt;
}

void lnk_merge(LinkList A, LinkList B, LinkList C) {
    Node* currA = A->next;
    Node* currB = B->next;
    Node* currC = C;
    while(currA != NULL && currB != NULL) {
        currC->next = currA;
        currC = currC->next;
        currA = currA->next;

        currC->next = currB;
        currC = currC->next;
        currB = currB->next;
    }
    if (currA != NULL) {
        currC->next = currA;
    } else {
        currC->next = currB;
    }
}