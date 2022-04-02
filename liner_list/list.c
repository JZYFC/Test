//
// Created by JZYFC on 2022/3/3.
//
#include "list.h"

// List
// no need for non-decrease
void del_x2y(SeqList *L, ElemType x, ElemType y) {
    size_t moveIndex = 0;
    size_t len = L->last + 1;
    for (size_t i = 0; i < len; ++i) {
        if (L->elem[i] >= x && L->elem[i] <= y) {
            L->last--;
            continue;
        }
        L->elem[moveIndex++] = L->elem[i];
    }
}

// need for non-decrease
void del_dupnum(SeqList *L) {
    size_t len = L->last;
    if (len == 0) return;
    ElemType prev = L->elem[0];
    size_t moveIndex = 1;
    for (size_t i = 1; i <= len; ++i) {
        ElemType curr = L->elem[i];
        if (prev == curr) {
            L->last--;
            continue;
        }
        L->elem[moveIndex++] = curr;
        prev = curr;
    }
}

void odd_even(SeqList *L) {
    size_t left = 0;
    size_t right = L->last;
    ElemType *ptr = L->elem;
    while (left < right) {
        if (ptr[left] % 2 == 1 && ptr[right] % 2 == 0) {
            left++;
            right--;
        } else if (ptr[left] % 2 != 1 && ptr[right] % 2 != 0) {
            ElemType tmp = ptr[left];
            ptr[left] = ptr[right];
            ptr[right] = tmp;
            left++;
            right--;
        } else if (ptr[left] % 2 == 1) {
            left++;
        } else {
            right--;
        }
    }
}

// Queue
bool init_queue(LinkQueue *LQ) {
    *LQ = (LinkQueue) malloc(sizeof(LinkQueueNode));
    if (*LQ == NULL) return false;
    (*LQ)->next = *LQ;
    (*LQ)->data = 0;
    return true;
}

bool enter_queue(LinkQueue *LQ, ElemType x) {
    LinkQueueNode *node = (LinkQueue) malloc(sizeof(LinkQueueNode));
    if (node == NULL) return false;
    node->data = x;
    node->next = (*LQ)->next;
    (*LQ)->next = node;
    *LQ = node;
    return true;
}

bool leave_queue(LinkQueue *LQ, ElemType *x) {
    if ((*LQ)->next == *LQ) {
        return false;
    }
    LinkQueue head = (*LQ)->next;
    *x = head->next->data;
    LinkQueue tmp = head->next;
    head->next = head->next->next;
    free(tmp);
    if (head->next == head) *LQ = head;
    return true;
}

// Stack
bool push(Stack *S, ElemType x) {
    if (S->top == Stack_Size - 1) return false;
    S->elem[++S->top] = x;
    return true;
}

bool pop(Stack *S, ElemType *x) {
    if (S->top == -1) return false;
    *x = S->elem[S->top--];
    return true;
}

void init_stack(Stack *S) {
    S->top = -1;
}
