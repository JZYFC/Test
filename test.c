#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char const *argv[]) {
    int a = 0;
    int b = 8;
    int *p = &a;
    printf("&a:%p, &b:%p, *(p+1):%d", p, &b, *(p - 1));
    return 0;
}
