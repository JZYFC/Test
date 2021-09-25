#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double average(int num, const char * arguments);

int main(void) {
    printf("%.2lf", average(3, "1,2,3"));
    return 0;
}

double average(int num, const char * arguments) {

//    Only for C99 and above(except Microsoft C/C++ Compiler)
//    double nums[num];
//    char str[length + 1];

    unsigned length = strlen(arguments);
    double *nums = (double *) malloc(sizeof(double) * num);
    char *str = (char *) malloc(sizeof(char) * (length + 1));
    char c;
    int cnt = 0;
    int index = 0;
    double sum = 0;

    if (arguments[0] == '\0') return 0;
    for (int i = 0; i < length + 1; ++i) {
        c = arguments[i];
        if (c == ',' || c == '\0') {
            str[index] = '\0';
            nums[cnt++] = atof(str);
            strset(str, 0);
            index = 0;
        } else {
            str[index++] = c;
        }
    }

    for (int i = 0; i < cnt; ++i) sum += nums[i];

    free(nums);
    free(str);

    return sum / cnt;
}