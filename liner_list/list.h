//
// Created by JZYFC on 2022/3/3.
//

#ifndef TEST_LIST_H
#define TEST_LIST_H

#include "stdlib.h"
#include "stdbool.h"

typedef int ElemType;

#define MAXSIZE 100

// List
typedef struct {
    ElemType elem[MAXSIZE];
    size_t last;
} SeqList;


void del_x2y(SeqList *L, ElemType x, ElemType y);

void del_dupnum(SeqList *L);

void odd_even(SeqList *L);

// Queue
struct QueueNode {
    ElemType data;          // 数据域
    struct QueueNode *next;      // 指针域
};
typedef struct QueueNode LinkQueueNode;
typedef struct QueueNode *LinkQueue;

bool init_queue(LinkQueue *LQ);

bool enter_queue(LinkQueue *LQ, ElemType x);

bool leave_queue(LinkQueue *LQ, ElemType *x);

//Stack
#define Stack_Size 50
typedef struct{
    ElemType elem[Stack_Size];
    int top;
}Stack;

bool push(Stack* S, ElemType x);
bool pop(Stack* S, ElemType *x);
void init_stack(Stack *S);

#endif //TEST_LIST_H
