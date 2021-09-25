#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main(void) {
    char walk[10][10];
    char letter = 65;
    int direction;
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            walk[i][j] = '.';
        }
    }
    i = 0, j = 0;
    walk[i][j] = letter;
    while (letter < 90) {
        direction = rand() % 4;
        if (direction == 0) { //向右
            if (j < 9 && walk[i][j + 1] == '.') {
                j++;
                letter++;
                walk[i][j] = letter;
            }
        } else if (direction == 1) { //向下
            if (i < 9 && walk[i + 1][j] == '.') {
                i++;
                letter++;
                walk[i][j] = letter;
            }
        } else if (direction == 2) { //向左
            if (j > 0 && walk[i][j - 1] == '.') {
                j--;
                letter++;
                walk[i][j] = letter;
            }
        } else if (direction == 3) {//向上
            if (i > 0 && walk[i - 1][j] == '.') {
                i--;
                letter++;
                walk[i][j] = letter;
            }
        }
        if ((j >= 9 || walk[i][j + 1] != '.') &&
            (j <= 0 || walk[i][j - 1] != '.') &&
            (i >= 9 || walk[i + 1][j] != '.') &&
            (i <= 0 || walk[i - 1][j] != '.'))
            break;
    }
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%c ", walk[i][j]);
        }
        printf("\n");
    }
    return 0;
}
