//
// Created by 蒋镇宇 on 2022/4/2.
//

#include "tsmatrix.h"

bool add_matrix(const TSMatrix *pM, const TSMatrix *pN, TSMatrix *pQ) {
    if (pM->m != pN->m || pM->n != pN->n) return false;
    int p1 = 0, p2 = 0, p3 = 0;
    pQ->m = pM->m;
    pQ->n = pM->n;
    while (p1 != pM->len && p2 != pN->len) {
        if (pM->data[p1].i == pN->data[p2].i && pM->data[p1].j == pN->data[p2].j) {
            Triple t = {pM->data[p1].i, pM->data[p1].j, pM->data[p1].e + pN->data[p2].e};
            if (t.e != 0) {
                pQ->data[p3++] = t;
                pQ->len++;
            }
            p1++;
            p2++;
        } else if (pM->data[p1].i == pN->data[p2].i) {
            if (pM->data[p1].j > pN->data[p2].j) {
                pQ->data[p3] = pN->data[p2];
                p2++;
                p3++;
                pQ->len++;
            } else {
                pQ->data[p3] = pM->data[p1];
                p1++;
                p3++;
                pQ->len++;
            }
        } else {
            if (pM->data[p1].i > pN->data[p2].i) {
                pQ->data[p3] = pN->data[p2];
                p2++;
                p3++;
                pQ->len++;
            } else {
                pQ->data[p3] = pM->data[p1];
                p1++;
                p3++;
                pQ->len++;
            }
        }
    }
    if (pM->len == p1) {
        while (pN->len != p2) {
            pQ->data[p3++] = pN->data[p2++];
            pQ->len++;
        }
    } else {
        while (pM->len != p1) {
            pQ->data[p3++] = pM->data[p1++];
            pQ->len++;
        }
    }
    return true;
}

void printMatrix(const TSMatrix *tsMatrix) {
    int p = 0;
    for (int i = 0; i < tsMatrix->m; ++i) {
        for (int j = 0; j < tsMatrix->n; ++j) {
            Triple curr = tsMatrix->data[p];
            if (i + 1 == curr.i && j + 1 == curr.j) printf("%.2d ", curr.e);
            else printf("** ");
        }
        printf("\n");
    }
}

void addElem(TSMatrix *tsMatrix, int i, int j, ElemType e) {

}