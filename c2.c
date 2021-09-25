#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int *array;
    int row;
    int col;
} two_dimensional_array;

two_dimensional_array *construct_two_dimensional_array(int row, int col);

void insert_into_array(two_dimensional_array *array, int value, int row, int col);

int read_from_array(two_dimensional_array *array, int row, int col);

void traverse_array(two_dimensional_array *array);

void destroy_array(two_dimensional_array *array);

void out_of_index_error(void);

void malloc_error(void);

/*
**输入:"二维数组"的行数和列数
**输出:一个完成初始化的"二维数组"
**函数作用:根据所给的行数和列数，构造一个"二维数组"
**提醒:这个函数需要用到动态内存分配
*/
two_dimensional_array *construct_two_dimensional_array(int row, int col) {
    two_dimensional_array *ret = malloc(sizeof(int) * (row * col + 2));
    ret->array = (int *) calloc(row * col, sizeof(int));
    ret->row = row;
    ret->col = col;
    // ret cannot be NULL
    if (ret == NULL) malloc_error();
    return ret;
}

/*
**输入:指向"二维数组"的指针array，待插入的值value,要插入到的行row，要插入到的列col
**输出:无
**函数作用:根据所给的行数和列数，将value插入到"二维数组"中
*/
void insert_into_array(two_dimensional_array *array, int value, int row, int col) {
    if (row > array->row || col > array->col || row * col == array-> row * array->col) out_of_index_error();
    array->array[row * (array->col) + col ] = value;
}

/*
**输入:指向"二维数组"的指针array，要读取元素所处的行row，要读取元素所处的列col
**输出:查找到的元素
**函数作用:根据所给的行数和列数，将二维数组中的值读出
*/
int read_from_array(two_dimensional_array *array, int row, int col) {
    return array->array[row * array->col + col];
}

/*
**输入:指向"二维数组"的指针array
**输出:无
**函数作用:打印"二维数组"
*/
void traverse_array(two_dimensional_array *array) {
    int row = array->row;
    int col = array->col;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("%d\t", read_from_array(array, i, j));
        }
        printf("\n");
    }
}

/*
**输入:指向"二维数组"的指针array
**输出:无
**函数作用:释放分配的内存，销毁"二维数组"
*/
void destroy_array(two_dimensional_array *array) {
    free(array->array);
    free(array);
    array = NULL;
}

/*
**输入:无
**输出:无
**函数作用:当内存分配出现错误时，调用此函数，打印错误信息并退出程序
**打印错误信息printf一个错误信息即可就可以，如:内存分配出错
*/
void malloc_error() {
    printf("内存分配出错");
}

/*
**输入:无
**输出:无
**函数作用:当数组索引出现错误时，调用此函数，打印错误信息并退出程序
**解释:索引错误其实就是越界，如两列两行的数组非要访问它第三列第二行的元素
**打印错误信息printf一个错误信息即可就可以，如:访问越界
*/
void out_of_index_error() {
    printf("访问越界");
}

/*
**调试你的程序，至少完成以下步骤:
**构造一个"二维数组"
**通过insert_into_array函数向"二维数组"插入一些值
**通过read_from_array函数校验插入的值
**通过traverse_array函数遍历"二维数组"
**通过destroy_array函数销毁"二维数组"
*/
int main() {
    two_dimensional_array *array = construct_two_dimensional_array(3, 4);
    printf("%d\n", array->row);
    printf("%d\n", array->col);
    insert_into_array(array, 1, 0, 1);
    insert_into_array(array, 2, 1, 2);
    insert_into_array(array, 3, 2, 3);
    printf("%d\n", read_from_array(array, 1, 2));
    printf("%d\n", read_from_array(array, 2, 3));
    traverse_array(array);
    destroy_array(array);
}