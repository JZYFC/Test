#include <stdio.h>
#include <stdlib.h>
#include "lab51.h" // 请不要删除本行头文件，否则检查不通过

int main(void) {
    char code;
    struct part inventory[MAX_PARTS];
    int partCnt = 0;
    for (;;) {
        printf("Enter operation code:");
        scanf(" %c", &code);
        while (getchar() != '\n');
        switch (code) {
            case 'i':
                insert(inventory, &partCnt);
                break;
            case 's':
                search(inventory, partCnt);
                break;
            case 'u':
                update(inventory, partCnt);
                break;
            case 'p':
                print(inventory, partCnt);
                break;
            case 'q':
                return 0;
            default:
                printf("Illegal code\n");
        }
        printf("\n");
        printf("Enter 'i': insert,'s':search,'u':update,'p':print,'q':exit \n");
    }
}