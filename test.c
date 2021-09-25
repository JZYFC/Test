#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//#define DEBUG
#define START_AT_RIGHT

#if defined(START_AT_UP)
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3
#elif defined(START_AT_RIGHT)
#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3
#endif

#ifdef DEBUG
#include "testData.h"
#endif

#define X_LIMIT 10
#define Y_LIMIT 10

// Wrong output         input:1210122110110111222333323
// A  B  E  F  .  .  .  N  O  P
// Q  C  D  G  .  K  L  M  .  .
// R  .  .  H  I  J  .  .  .  .
// S  .  .  .  .  .  X  W  V  U
// T  .  .  .  .  Z  Y  .  .  .
// .  .  .  .  .  .  .  .  .  .
// .  .  .  .  .  .  .  .  .  .
// .  .  .  .  .  .  .  .  .  .
// .  .  .  .  .  .  .  .  .  .
// .  .  .  .  .  .  .  .  .  .




int checkIsAllBlocked(const char area[X_LIMIT][Y_LIMIT], int x, int y);

int checkNumUsable(const char area[X_LIMIT][Y_LIMIT], int num, int x, int y);

void printMatrix(const char area[X_LIMIT][Y_LIMIT]);

void changeIndex(int num, int *x, int *y);

int main(void) {
    int direction;
    srand((unsigned int) time(NULL));
    char area[X_LIMIT][Y_LIMIT];
    memset(area, '.', sizeof(char) * X_LIMIT * Y_LIMIT);
    char c = 'A';
    int x = 0, y = 0;
    area[x][y] = c;
    while (c < 'Z' && checkIsAllBlocked(area, x, y)) {
#ifdef DEBUG
        direction = getNextData();
#else
        direction = rand() % 4;
#endif
        while (checkNumUsable(area, direction, x, y) == 0)
            direction = rand() % 4;
        changeIndex(direction, &x, &y);
        area[x][y] = ++c;
        // printMatrix(area);
        // printf("*****%d*****\direction", c - 'A');
        // getchar();
    }

    // Print matrix
    printMatrix(area);

    return 0;
}


void printMatrix(const char area[X_LIMIT][Y_LIMIT]) {
    for (int i = 0; i < X_LIMIT; i++) {
        for (int j = 0; j < Y_LIMIT; j++) {
            printf("%c ", area[i][j]);
        }
        putchar('\n');
    }
}


int checkIsAllBlocked(const char area[X_LIMIT][Y_LIMIT], int x, int y) {
    int ret = 1;
    if ((x == 0 || area[x - 1][y] != '.')
        && (x == X_LIMIT - 1 || area[x + 1][y] != '.')
        && (y == 0 || area[x][y - 1] != '.')
        && (y == Y_LIMIT - 1 || area[x][y + 1] != '.'))
        ret = 0;
    return ret;
}

int checkNumUsable(const char area[X_LIMIT][Y_LIMIT], int num, int x, int y) {
    int ret = 1;
    changeIndex(num, &x, &y);
    if (x >= X_LIMIT || x < 0 || y >= Y_LIMIT || y < 0) ret = 0;
    if (area[x][y] != '.') ret = 0;
    return ret;
}

void changeIndex(int num, int *x, int *y) {

    switch (num) {
        case UP:
            (*x)--;
            break;
        case RIGHT:
            (*y)++;
            break;
        case DOWN:
            (*x)++;
            break;
        case LEFT:
            (*y)--;
            break;
    }
}