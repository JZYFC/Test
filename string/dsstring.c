//
// Created by JZYFC on 2022/3/21.
//

#include "dsstring.h"

int str_compare(const char *ptr1, const char *ptr2) {
    char *p1 = (char *) ptr1;
    char *p2 = (char *) ptr2;
    while (*p1 != '\0' && *p2 != '\0') {
        char t1 = (char) (*p1 >= 'a' ? *p1 - 32 : *p1);
        char t2 = (char) (*p2 >= 'a' ? *p2 - 32 : *p2);
        if (t1 != t2) {
            return *p1 - *p2;
        }
        p1++;
        p2++;
    }
    if (*p1 == '\0' && *p2 == '\0') {
        return 0;
    } else if (*p1 != 0) {
        return *p1;
    } else return -*p2;
}

int str_replace(const char *in, char *out, int outlen, const char *oldstr, const char *newstr) {
    if (in == NULL || out == NULL || oldstr == NULL || newstr == NULL
        || outlen <= 0
        || *in == '\0' || *oldstr == '\0')
        return 0;

    size_t inIndex = 0;
    size_t outIndex = 0;
    size_t oldIndex = 0;
    size_t newIndex = 0;
    size_t newLen = 0;
    size_t remain = 0;

    while (newstr[newIndex++] != '\0') newLen++;
    while (in[inIndex++] != '\0') remain++;
    newIndex = 0;
    inIndex = 0;

    int cnt = 0;

    while (in[inIndex] != '\0') {
        if (in[inIndex] == *oldstr) {
            int flag = 0;
            oldIndex++;
            while (oldstr[oldIndex] != '\0') {
                if (in[inIndex + oldIndex] == oldstr[oldIndex])
                    oldIndex++;
                else {
                    flag = 1;
                    break;
                }
            }
            if (flag) break;
            if (oldstr[oldIndex] == '\0') {
                if (outIndex - 1 + newLen + remain - oldIndex >= outlen - 1 &&
                    !(in[inIndex + 1] == '\0' && outIndex + newLen == outlen - 1))
                    break;
                inIndex += oldIndex;
                while (newstr[newIndex] != '\0') {
                    out[outIndex] = newstr[newIndex++];
                    outIndex++;
                }
                newIndex = 0;
                cnt++;
            }
            remain -= oldIndex;
            oldIndex = 0;
            continue;
        }
        out[outIndex] = in[inIndex];
        remain--;
        outIndex++;
        if (outIndex >= outlen - 1 && in[inIndex + 1] != '\0') break;
        inIndex++;
    }
    while (in[inIndex] != '\0') {
        out[outIndex++] = in[inIndex++];
    }
    out[outIndex] = '\0';
    return cnt;
}

void blstr_init(BLString *T) {
    T->len = 0;
    T->head = NULL;
    T->tail = NULL;
}

void str_to_blstr(const char *str, BLString *desc) {
    size_t blockIndex = 0;
    desc->head = (Block *) calloc(1, sizeof(Block));
    Block *curr = desc->head;
    while (*str != '\0') {
        curr->ch[blockIndex++] = *str;
        desc->len++;
        if (blockIndex == BLOCK_SIZE && *(str + 1) != '\0') {
            blockIndex = 0;
            curr->next = (Block *) calloc(1, sizeof(Block));
            curr = curr->next;
        }
        str++;
    }
    while (curr->ch[BLOCK_SIZE - 1] == '\0') {
        curr->ch[blockIndex++] = BLS_BLANK;
    }
    desc->tail = curr;
    desc->tail->next = NULL;
}

bool blstr_substr_ver1(BLString src, int pos, int len, BLString *sub) {
    if (src.len == 0 || src.head == NULL || src.tail == NULL || pos < 0 || len < 0) return false;
    Block *curr = src.head;
    size_t maxLen = src.len - pos;
    size_t tmpIndex = 0;
    if (maxLen > len) maxLen = len;
    char *tmp = (char *) calloc(maxLen + 1, sizeof(char));
    bool found = false;
    while (curr != src.tail->next) {
        int blockIndex = 0;
        if (!found) {
            while (blockIndex < BLOCK_SIZE) {
                if (!pos) {
                    found = true;
                    break;
                }
                pos--;
                blockIndex++;
            }
        }
        if (found) {
            while (blockIndex < BLOCK_SIZE && tmpIndex < maxLen) {
                tmp[tmpIndex] = curr->ch[blockIndex];
                tmpIndex++;
                blockIndex++;
            }
        }
        curr = curr->next;
    }
    if (!found) {
        free(tmp);
        return false;
    }
    tmp[tmpIndex] = '\0';
    str_to_blstr(tmp, sub);
    free(tmp);
    return true;
}

bool blstr_substr(BLString src, int pos, int len, BLString *sub) {
    if (src.head == NULL || src.tail == NULL || pos < 0 || sub == NULL) return false;
    Block *curr = src.head;

    bool found = false;
    size_t subBlockIndex = 0;
    sub->head = (Block *) malloc(sizeof(Block));
    sub->tail = sub->head;
    Block *subCurr = sub->head;
    if (subCurr == NULL) return false;
    subCurr->next = NULL;

    while (curr != NULL) {
        int blockIndex = 0;
        if (!found) {
            while (blockIndex < BLOCK_SIZE) {
                if (!pos) {
                    found = true;
                    break;
                }
                pos--;
                blockIndex++;
            }
        }
        if (found) {
            while (blockIndex < BLOCK_SIZE && sub->len < len && curr->ch[blockIndex] != BLS_BLANK) {
                subCurr->ch[subBlockIndex] = curr->ch[blockIndex];
                subBlockIndex++;
                sub->len++;
                bool endFlag = false;
                if (curr->next == NULL &&
                    (blockIndex + 1 == BLOCK_SIZE || curr->ch[blockIndex + 1] == BLS_BLANK)) {
                    endFlag = true;
                }
                if (sub->len == len || endFlag) break;
                if (subBlockIndex == BLOCK_SIZE) {
                    subBlockIndex = 0;
                    subCurr->next = (Block *) malloc(sizeof(Block));
                    if (subCurr->next == NULL) return false;
                    subCurr = subCurr->next;
                    subCurr->next = NULL;
                }
                blockIndex++;
            }
        }
        curr = curr->next;
    }
    while (subBlockIndex < BLOCK_SIZE) {
        subCurr->ch[subBlockIndex] = BLS_BLANK;
        subBlockIndex++;
    }
    sub->tail = subCurr;
    sub->tail->next = NULL;
    return true;
}


