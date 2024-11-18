#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"
#include "history.h"

#define MAX_INPUT_SIZE 100

int main() {
    char string[MAX_INPUT_SIZE];
    char *token;
    char select;
    List *history = init_history();

    if (history == NULL) {
        fprintf(stderr, "Failed to initialize history.\n");
        return 1;
    }

    printf("Welcome to the Tokenizer and History System!\n");
    while (1) {
        printf("\nEnter your selection:\n");
        printf("'1' to tokenize a new string\n'2' to print the history\n'3' to find an item in the history\n'q' to exit\n");
        printf("> ");
        scanf(" %c", &select);

        switch (select) {
        case '1': {
            printf("Enter string to be tokenized:\n> ");
            scanf(" %[^\n]", string);

            char **tokens = tokenize(string);
            if (tokens == NULL) {
                fprintf(stderr, "Failed to tokenize string.\n");
                break;
            }

            add_history(history, string);
            printf("\nTokens:\n");
            print_tokens(tokens);
            free_tokens(tokens);
            break;
        }
        case '2':
            printf("\nHistory:\n");
            print_history(history);
            break;

        case '3': {
            printf("Enter the ID of the item you are looking for:\n> ");
            int pos;
            scanf(" %d", &pos);

            token = get_history(history, pos);
            if (token == NULL) {
                printf("No history item found with ID: %d\n", pos);
                break;
            }

            printf("\nHistory Item with ID %d:\n", pos);
            char **item_tokens = tokenize(token);
            if (item_tokens != NULL) {
                print_tokens(item_tokens);
                free_tokens(item_tokens);
            }
            break;
        }
        case 'q':
            printf("Exiting system...\n");
            free_history(history);
            return 0;

        default:
            printf("Invalid input. Please try again.\n");
            break;
        }
    }
}
