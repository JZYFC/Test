//
// Created by JZYFC on 2022/3/21.
//

#ifndef TEST_DSSTRING_H
#define TEST_DSSTRING_H

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int str_compare(const char *ptr1, const char *ptr2);

int str_replace(const char *in, char *out, int outlen, const char *oldstr, const char *newstr);


#define BLOCK_SIZE 4    // 可由用户定义的块大小
#define BLS_BLANK '#'   // 用于空白处的补齐字符

typedef struct _block {
    char ch[BLOCK_SIZE];    //块的数据域
    struct _block *next;    //块的指针域
} Block;

typedef struct {
    Block *head;        // 串的头指针
    Block *tail;        // 串的尾指针
    int len;            // 串的当前长度
} BLString;

//字符串初始化函数：
void blstr_init(BLString *T);

bool blstr_substr(BLString src, int pos, int len, BLString *sub);
bool blstr_substr_ver1(BLString src, int pos, int len, BLString *sub);
void str_to_blstr(const char * str, BLString* desc);

#endif //TEST_DSSTRING_H
