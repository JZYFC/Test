#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NAME 12

typedef struct Node {
    char name[NAME];    //姓名
    int score;          //分数
    struct Node *next;
} Linked_List_Node;

typedef struct {
    Linked_List_Node *head;
    int length;
} Linked_List;

Linked_List_Node *linked_list_node_construct(char name[], int score);

Linked_List *linked_list_construct();

void add_node_to_head(Linked_List *linkedList, Linked_List_Node *node);

void add_node_to_bottom(Linked_List *linkedList, Linked_List_Node *node);

void delete_linked_list_node_by_name(Linked_List *linkedList, char name[]);

void print_linked_list_nodes(Linked_List *linkedList);

/*
**输入:姓名name与成绩score
**输出:构造完的链表节点的指针
**函数作用:通过姓名和成绩构造一个链表节点
*/
Linked_List_Node *linked_list_node_construct(char name[], int score) {
    Linked_List_Node *linkedListNode = malloc(sizeof(Linked_List_Node));
    strcpy(linkedListNode->name, name);
    linkedListNode->score = score;
    linkedListNode->next = NULL;
    return linkedListNode;
}

/*
**输入:无
**输出:初始化头指针与长度的链表指针
**函数作用:返回一个已经初始化头指针与长度的链表指针
*/
Linked_List *linked_list_construct() {
    Linked_List *list = malloc(sizeof(Linked_List));
    list->head = linked_list_node_construct("_HEAD", -1);
    return list;
}

/*
**输入:指向链表的指针linkedList和指向链表节点的指针node
**输出:无
**函数作用:通过头插法的方式将一个节点插入到链表之中
*/
void add_node_to_head(Linked_List *linkedList, Linked_List_Node *node) {
    Linked_List_Node *tmp = linkedList->head;
    linkedList->head = node;
    node->next = tmp;
}

/*
**输入:指向链表的指针linkedList和指向链表节点的指针node
**输出:无
**函数作用:通过尾差法的方式将一个节点插入到链表之中
*/
void add_node_to_bottom(Linked_List *linkedList, Linked_List_Node *node) {
    Linked_List_Node *tmp = linkedList->head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = node;
    node->next = NULL;
}

/*
**输入:指向链表的指针linkedList和姓名name
**输出:无
**函数作用:删除链表中队名与给定队名一致的节点
*/
void delete_linked_list_node_by_name(Linked_List *linkedList, char name[]) {
    Linked_List_Node *tmp = linkedList->head;
    Linked_List_Node *prev = NULL;
    while (strcmp(tmp->name, name) != 0) {
        prev = tmp;
        tmp = tmp->next;
    }
    prev->next = tmp->next;
    free(tmp);
    tmp = NULL;
}

/*
**输入:指向链表的指针linkedList
**输出:无
**函数作用:遍历链表，打印每位支队伍的队名以及得分
*/
void print_linked_list_nodes(Linked_List *linkedList) {
    Linked_List_Node *tmp = linkedList->head;
    printf("****** Start print ******\n");
    while (tmp != NULL) {
        if (strcmp(tmp->name, "_HEAD" )!= 0)
            printf("%s:%d\n", tmp->name, tmp->score);
        tmp = tmp->next;
    }
    printf("****** End print ******\n");
}


/*
**调试你的程序，要求如下:
**构造一个空链表
**插入4个链表节点，分别是: (name:Jack score:77),(name:Alice score:82),(name:Joseph score:90),(name:ha score:91)
**遍历一遍链表，打印所有的节点信息
**删除姓名为ha所对应的节点
**重新遍历一遍链表，打印所有的节点信息
*/
int main() {
    Linked_List *list = linked_list_construct();

    Linked_List_Node *jack = linked_list_node_construct("Jack", 77);
    Linked_List_Node *alice = linked_list_node_construct("Alice", 82);
    Linked_List_Node *joseph = linked_list_node_construct("joseph", 90);
    Linked_List_Node *ha = linked_list_node_construct("ha", 91);

    add_node_to_bottom(list, jack);
    add_node_to_head(list, alice);
    add_node_to_bottom(list, joseph);
    add_node_to_bottom(list, ha);

    print_linked_list_nodes(list);
    delete_linked_list_node_by_name(list, "ha");
    print_linked_list_nodes(list);
    return 0;
}