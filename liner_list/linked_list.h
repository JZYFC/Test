//
// Created by JZYFC on 2022/3/5.
//

#ifndef TEST_LINKED_LIST_H
#define TEST_LINKED_LIST_H

#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;

struct lnklist {
    ElemType data;
    struct lnklist *next;
};
typedef struct lnklist Node;
typedef struct lnklist *LinkList;

void lnk_del_x2y(LinkList L, ElemType mink, ElemType maxk);

int lnk_search(LinkList L, int k, ElemType *p_ele);

void lnk_merge(LinkList A, LinkList B, LinkList C);
#endif //TEST_LINKED_LIST_H
