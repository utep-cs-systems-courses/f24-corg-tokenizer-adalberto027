#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "history.h"

List* init_history() {
    List *history = (List*)malloc(sizeof(List));
    if (history != NULL) {
        history->root = NULL;
    }
    return history;
}

void add_history(List *list, char *str) {
    static int pos_id = 1;

    if (list == NULL || str == NULL) {
        fprintf(stderr, "Invalid list or string.\n");
        return;
    }

    int len = strlen(str);
    Item *new_item = (Item*)malloc(sizeof(Item));
    if (new_item == NULL) {
        fprintf(stderr, "Memory allocation for new_item failed.\n");
        return;
    }

    new_item->str = (char*)malloc((len + 1) * sizeof(char));
    if (new_item->str == NULL) {
        fprintf(stderr, "Memory allocation for new_item->str failed.\n");
        free(new_item);
        return;
    }

    strcpy(new_item->str, str);
    new_item->id = pos_id++;
    new_item->next = NULL;

    if (list->root == NULL) {
        list->root = new_item;
    } else {
        Item *current = list->root;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_item;
    }
}

char* get_history(List *list, int id) {
    if (list == NULL || list->root == NULL) {
        return NULL;
    }

    Item *current = list->root;
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
        printf("[ID: %d] %s\n", current->id, current->str);
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

