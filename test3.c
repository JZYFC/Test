#include <stdio.h>
#include <stdlib.h>
#include "lab52.h" // 请不要删除本行头文件，否则检查不通过

int main(void) {
    int input;
    GoodsList *pList;
    init_list(&pList);
    while (1) {
        puts("1.显示所有商品的信息\n"
             "2.修改某个商品的信息\n"
             "3.插入某个商品的信息\n"
             "4.删除某个商品的信息\n"
             "5.查找某个商品的信息\n"
             "6.商品存盘并退出系统\n"
             "7.对商品价格进行排序\n"
             "8.(慎用)删除所有内容\n"
             "其他.不存盘并退出系统");
        printf("请输入数据:");
        scanf(" %d", &input);
        switch (input) {
            case 1:
                output_all_items(pList);
                break;
            case 2: {
                GoodsInfo gf = read_goods_info();
                char id[MAX_ID_LEN];
                puts("请输入原商品id");
                read_line(id, MAX_ID_LEN);
                change_item(pList, id, gf);
                break;
            }
            case 3: {
                GoodsInfo gf = read_goods_info();
                int i;
                puts("请输入要插入的位置(0.将商品信息插入到链表尾部; 1.将商品信息插入到链表头部; i.将商品信息插入到链表中间第i号位置, 例如：输入3，应该在第二个节点后插入新节点)");
                scanf("%d", &i);
                insert_item(pList, gf, i);
                break;
            }
            case 4: {
                char id[MAX_ID_LEN];
                puts("请输入商品id");
                read_line(id, MAX_ID_LEN);
                delete_item(pList, id);
                break;
            }
            case 5: {
                char id[MAX_ID_LEN];
                puts("请输入商品id");
                read_line(id, MAX_ID_LEN);
                search_item(pList, id);
                break;
            }
            case 6:
                save_to_file(pList);
                goto exit;
            case 7:
                bubble_sort(pList);
                break;
            case 8:
                destory_list_and_file(&pList);
                break;
            default:
                goto exit;
        }
    }
    exit:
    destory_list(&pList);
    return 0;
}