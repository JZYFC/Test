//
// Created by JZYFC on 2022/3/21.
//
#include <stdio.h>
#include "dsstring.h"

int main() {
    BLString b;
    blstr_init(&b);
    BLString b2;
    blstr_init(&b2);
    str_to_blstr("abcdefghijklmnopqrstuvwxyABCDEFGHIJKLMNOPQRSTUVWXY012345678abcdefghij", &b);
    bool ret = blstr_substr(b, 13, 50, &b2);
    return 0;
}