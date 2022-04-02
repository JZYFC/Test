//
// Created by JZYFC on 2022/3/7.
//

#ifndef TEST_SIMPLE_VECTOR_H
#define TEST_SIMPLE_VECTOR_H

#include <stdlib.h>

typedef int ElemType;

typedef struct {
    ElemType* elem;
    size_t last;
    size_t maxSize;
} Vector, *VectorPtr;

#endif //TEST_SIMPLE_VECTOR_H
