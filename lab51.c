//
// Created by JZYFC on 2021/9/30.
//

#include <stdio.h>
#include <stdlib.h>
#include "lab51.h"


void insert(struct part inv[], int *np) {

    int newPartNum;

    if (*np == MAX_PARTS) {
        printf("Database is full ;can`t add more parts.\n");
        return;
    }

    printf("Enter the part number: ");
    scanf("%d", &newPartNum);

    if (find_part(newPartNum, inv, *np) >= 0) {
        printf("Part already exists.\n");
        return;
    }

    inv[*np].number = newPartNum;
    printf("Enter part name: ");
    read_line(inv[*np].name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &inv[*np].on_hand);
    *np += 1;
}

void search(const struct part inv[], int np) {
    int partNum;
    int invPos;

    printf(("Enter the part number:"));
    scanf("%d", &partNum);

    invPos = find_part(partNum, inv, np);
    if (invPos >= 0) {
        printf("Part name: %s\n", inv[invPos].name);
        printf("Quantity on hand: %d\n", inv[invPos].on_hand);
    } else {
        printf("Part not found.\n");
    }
}

void update(struct part inv[], int np) {
    int partNum;
    int invPos;
    int handCntChange;

    printf(("Enter the part number:"));
    scanf("%d", &partNum);

    invPos = find_part(partNum, inv, np);
    if (invPos >= 0) {
        printf("Enter the change in quantity on hand: ");
        scanf("%d", &handCntChange);
        inv[invPos].on_hand += handCntChange;
    } else {
        printf("part not exist.\n");
    }
}

void print(const struct part inv[], int np) {
    printf("Part Number        Part Name                       "
           "Quantity On Hand\n");
    for (int i = 0; i < np; ++i) {
        printf("%7d            %-25s%11d\n", inv[i].number, inv[i].name, inv[i].on_hand);
    }
}