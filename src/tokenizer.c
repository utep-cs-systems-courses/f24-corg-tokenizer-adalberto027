#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"

int space_char(char c) {
    return (c == ' ' || c == '\t');
}

int non_space_char(char c) {
    return (c != '\0' && !space_char(c));
}

char *token_start(char *str) {
    while (*str && !non_space_char(*str)) {
        str++;
    }
    return str;
}

char *token_terminator(char *token) {
    while (*token && non_space_char(*token)) {
        token++;
    }
    return token;
}

int count_tokens(char *str) {
    int count = 0;
    char *temp = token_start(str);

    while (*temp) {
        count++;
        temp = token_terminator(temp);
        temp = token_start(temp);
    }
    return count;
}

char *copy_str(char *inStr, short len) {
    char *str_copy = malloc((len + 1) * sizeof(char));
    if (!str_copy) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < len; i++) {
        str_copy[i] = inStr[i];
    }
    str_copy[len] = '\0'; // Null-terminate the string
    return str_copy;
}

char **tokenize(char *str) {
    int num_tokens = count_tokens(str);
    char **tokens = malloc((num_tokens + 1) * sizeof(char *));
    if (!tokens) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    char *token = str;
    for (int i = 0; i < num_tokens; i++) {
        token = token_start(token);
        char *token_end = token_terminator(token);
        int len = token_end - token;
        tokens[i] = copy_str(token, len);
        token = token_end;
    }
    tokens[num_tokens] = NULL; // Null-terminate the array
    return tokens;
}

void print_tokens(char **tokens) {
    int i = 0;
    while (tokens[i]) {
        printf("Token #%d: %s\n", i, tokens[i]);
        i++;
    }
}

void free_tokens(char **tokens) {
    int i = 0;
    while (tokens[i]) {
        free(tokens[i]);
        i++;
    }
    free(tokens);
}
