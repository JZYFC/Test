//
// Created by 蒋镇宇 on 2022/4/2.
//

#ifndef TEST_TSMATRIX_H
#define TEST_TSMATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;

#define MAXSIZE 100          //假设非零元个数的最大值为100
typedef struct {
    int i,j;									//非零元的行下标和列下标，i 和 j 从 1 开始计数，与数学中矩阵元素的编号一致
    ElemType e;						//非零元的值
}Triple;

typedef struct {
    Triple data[MAXSIZE];			// 非零元三元组表
    int    m, n, len;							// 矩阵的行数、列数和非零元个数
}TSMatrix;

bool add_matrix(const TSMatrix *pM, const TSMatrix *pN, TSMatrix *pQ);

void printMatrix(const TSMatrix* tsMatrix);

void addElem(TSMatrix *tsMatrix, int i, int j, ElemType e);

#endif //TEST_TSMATRIX_H
