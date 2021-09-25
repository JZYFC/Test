//
// Created by JZYFC on 2021/9/20.
//

#include <stdio.h>
#include "testData.h"

static int dataSet[25];
static _Bool isReadData;
static int indexOfSet = 0;


void readData();

extern int getNextData() {
    if (isReadData == 0) {
        readData();
    }
    return dataSet[indexOfSet++];
}

void readData() {
    puts("Input data sequence:");
    for (int i = 0; i < 25; ++i) {
        scanf("%1d", &(dataSet[indexOfSet++]));
    }
    isReadData = 1;
    indexOfSet = 0;
}