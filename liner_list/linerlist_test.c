#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "list.h"

void printSeqList(SeqList *L) {
    printf("SeqList: { elem: {");
    for (size_t i = 0; i <= L->last - 1; i++) {
        printf("%d, ", L->elem[i]);
    }
    printf("%d}, last: %llu }\n", L->elem[L->last], L->last);
}

int main() {

    return 0;
}