#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab52.h" // 请不要删除本行头文件，否则检查不通过

int CurrentCnt; // 请不要删除本行的全局变量声明，否则检查不通过

int read_line(char str[], int n) {}

int save_to_file(GoodsList *L) {
    FILE *file = fopen(GOODS_FILE_NAME, "w+");
    int cnt = 0;
    if (file == NULL) return cnt;
    if (L->next == NULL) {
        fclose(file);
        return cnt;
    }
    L = L->next;
    while (L != NULL) {
        fprintf(file, "%s %s %d %s %d %d\n", L->data.goods_id, L->data.goods_name, L->data.goods_price,
                L->data.goods_discount, L->data.goods_amount, L->data.goods_remain);
        L = L->next;
        cnt++;
    }
    fclose(file);
    fflush(file);
    return cnt;
}

void init_list(GoodsList **pL) {
    *pL = (GoodsList *) calloc(1, sizeof(GoodsList));
    FILE *file = fopen(GOODS_FILE_NAME, "a+");
    if (file == NULL) return;
    GoodsList *current = *pL;
    GoodsList *tmp = (GoodsList *) calloc(1, sizeof(GoodsList));
    if (tmp == NULL) return;
    while (fscanf(file, "%s %s %d %s %d %d ", tmp->data.goods_id, tmp->data.goods_name, &(tmp->data.goods_price),
                  tmp->data.goods_discount, &(tmp->data.goods_amount), &(tmp->data.goods_remain)) != -1) {
        CurrentCnt++;
        current->next = tmp;
        current = tmp;
        tmp = (GoodsList *) calloc(1, sizeof(GoodsList));
        if (tmp == NULL) return;
    }
//    fflush(file);
    fclose(file);
}

bool insert_item(GoodsList *L, GoodsInfo item, int choice) {
    GoodsList *gl = (GoodsList *) malloc(sizeof(GoodsList));
    gl->data = item;
    if (choice == 0) {
        while (L->next != NULL) L = L->next;
        L->next = gl;
        CurrentCnt++;
        return true;
    } else {
        if (choice < 0) return false;
        int cnt = 0;
        while (cnt++ != choice - 1) {
            L = L->next;
            if (L == NULL) return false;
        }
        GoodsList *tmp = L->next;
        L->next = gl;
        gl->next = tmp;
        CurrentCnt++;
        return true;
    }
}

bool delete_item(GoodsList *L, char *goods_id) {
    GoodsList *prev = NULL;
    while (L != NULL) {
        if (strcmp(goods_id, L->data.goods_id) == 0) {
            prev->next = L->next;
            free(L);
            CurrentCnt--;
            return true;
        }
        prev = L;
        L = L->next;
    }
    return false;
}

GoodsList *search_item(GoodsList *L, char *goods_id) {
    GoodsList *ret = NULL;
    while (L != NULL) {
        if (strcmp(goods_id, L->data.goods_id) == 0) {
            ret = L;
        }
        L = L->next;
    }
    return ret;
}

bool change_item(GoodsList *L, char *goods_id, GoodsInfo new_info) {
    while (L != NULL) {
        if (strcmp(goods_id, L->data.goods_id) == 0) {
            L->data = new_info;
            return true;
        }
        L = L->next;
    }
    return false;
}

void output_one_item(GoodsList *p) {
    if (p == NULL) return;
    printf("商品ID：%s\n商品名称：%s\n商品价格：%d\n商品折扣：%s\n商品数量：%d\n商品剩余数量：%d\n",
           p->data.goods_id, p->data.goods_name, p->data.goods_price, p->data.goods_discount, p->data.goods_amount,
           p->data.goods_remain);
}

void output_all_items(GoodsList *L) {
    L = L->next;
    while (L != NULL) {
        output_one_item(L);
        L = L->next;
    }
}

void destory_list(GoodsList **pL) {
    while ((*pL) != NULL) {
        GoodsList *tmp = (*pL)->next;
        free((*pL));
        *pL = tmp;
    }
    CurrentCnt = 0;
    pL = NULL;
}

void destory_list_and_file(GoodsList **pL) {
    destory_list(pL);
    remove(GOODS_FILE_NAME);
}

void bubble_sort(GoodsList *L) {
    GoodsList *tail = NULL;
    GoodsList *i;
    bool isSwap = false;
    while (L->next != tail) {
        isSwap = false;
        i = L;
        while (i->next != tail) {
            if (i->data.goods_price > i->next->data.goods_price) {
                GoodsInfo tmp = i->data;
                i->data = i->next->data;
                i->next->data = tmp;
                isSwap = true;
            }
            i = i->next;
        }
        tail = i;
        if (!isSwap) return;
    }
}

GoodsInfo read_goods_info() {
    GoodsInfo gf;
    puts("请输入新商品信息（id、名称、价格、折扣、数量、剩余数量，以空格分割各信息）");
    scanf("%s %s %d %s %d %d", gf.goods_id, gf.goods_name, &gf.goods_price, gf.goods_discount, &gf.goods_amount,
          &gf.goods_remain);
    return gf;
}