#include <stdio.h>
#include <stdlib.h>
#include "history.h"

#define MAXTOKENS 100

List* init_history() {
    List *history = (List*)malloc(sizeof(List));
    if (history != NULL) {
        history->root = NULL;
    }
    return history;
}

void add_history(List *list, char *str) {
    static int pos_id = 1;
    Item *new_item = (Item*)malloc(sizeof(Item));
    if (list == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }

    int len = 0;
    while (*(str + len) != '\0' && *(str + len) != '\n') {
        len++;
    }

    new_item->str = (char*)malloc((len + 1) * sizeof(char));
    if (new_item->str == NULL) {
        fprintf(stderr, "Memory allocation for new_item->str failed.\n");
        free(new_item);
        return;
    }

    for (int i = 0; i < len; i++) {
        new_item->str[i] = str[i];
    }
    new_item->str[len] = '\0';
    new_item->next = NULL;

    if (list->root == NULL) {
        new_item->id = pos_id;
        list->root = new_item;
    } else {
        Item *current = list->root;
        while (current->next != NULL) {
            current = current->next;
        }
        new_item->id = current->id + 1;
        current->next = new_item;
    }
    pos_id++;
}

char* get_history(List *list, int id) {
    Item *current = list->root;
    if (list == NULL || list->root == NULL) {
        return NULL;
    }
    while (current != NULL) {
        if (current->id == id) {
            return current->str;
        }
        current = current->next;
    }
    return NULL;
}

void print_history(List *list) {
    if (list == NULL || list->root == NULL) {
        printf("Nothing is in the history.\n");
        return;
    }

    Item *current = list->root;
    printf("Printing History:\n");
    while (current != NULL) {
        if (current->str != NULL) {
            printf("[ID: %d] %s\n", current->id, current->str);
        } else {
            printf("[ID: %d] NULL\n", current->id);
        }
        current = current->next;
    }
}

void free_history(List *list) {
    if (list == NULL) {
        return;
    }
    Item *current = list->root;
    while (current != NULL) {
        Item *temp = current;
        current = current->next;
        free(temp->str);
        free(temp);
    }
    free(list);
}
