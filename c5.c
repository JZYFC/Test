#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define X_LIMIT 10
#define Y_LIMIT 10

int main(void) {
    int direction;
    char walk[X_LIMIT][Y_LIMIT];
    int i = 0, j = 0;
    char letter = 'A';
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            walk[i][j] = '.';
        }
    }
    walk[i][j] = letter;
    while (letter < 'Z') {
        direction = rand() % 4;
        if (direction == 0) {
            if (i > 0 && walk[i - 1][j] == '.') {
                i--;
                walk[i][j] = ++letter;
            }
        } else if (direction == 1) {
            if (j < Y_LIMIT - 1 && walk[i][j + 1] == '.') {
                j++;
                walk[i][j] = ++letter;
            }
        } else if (direction == 2) {
            if (i < X_LIMIT - 1 && walk[i + 1][j] == '.') {
                i++;
                walk[i][j] = ++letter;
            }
        } else if (direction == 3) {
            if (j > 0 && walk[i][j - 1] == '.') {
                j--;
                walk[i][j] = ++letter;
            }
        }
        if (((i == 0 || walk[i - 1][j] != '.')
             && (i == X_LIMIT - 1 || walk[i + 1][j] != '.')
             && (j == 0 || walk[i][j - 1] != '.')
             && (j == Y_LIMIT - 1 || walk[i][j + 1] != '.')))
            break;

        // Debug
//        for (int i = 0; i < X_LIMIT; i++) {
//            for (int j = 0; j < Y_LIMIT; j++) {
//                printf("%letter ", walk[i][j]);
//            }
//            putchar('\n');
//        }
//         printf("*****%d*****", letter - 'A');
//         getchar();
    }

    // Print matrix
    for (int i = 0; i < X_LIMIT; i++) {
        for (int j = 0; j < Y_LIMIT; j++) {
            printf("%c ", walk[i][j]);
        }
        putchar('\n');
    }

    return 0;
}
