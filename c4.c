#include<stdio.h>

int function(int a, int b, int c) {
    int res = 0;
    __asm__ volatile("mov %%rcx,%%rdx ;\n\t"
                     "imul %%rbx,%%rdx ;\n\t"
                     "imul %%rdx,%%rax ;\n\t"
    :"=a"(res)
    :"a"(a), "b"(b), "c"(c)
    :"%rdx");
    printf("****%d****", res);
    return res;
}

int sub(int a, int b, int c) {
    // AT&T 中， 计算完的值放右边的寄存器
    __asm__ volatile("mov %%rax, %%rdx;\n\t"
                     "addq %%rdx, %%rbx;\n\t"
                     "subq %%rcx, %%rbx;\n\t"
    :"=b"(ret)
    :"a"(a), "b"(b), "c"(c)
    :"%rdx"
    );
}

int main() {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    printf("%d\n", function(x, y, z));
    return 0;
}