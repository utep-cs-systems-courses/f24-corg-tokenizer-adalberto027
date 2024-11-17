#include <string.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

int space_char(char c) {
    return c == ' ' || c == '\t';
}

int non_space_char(char c) {
    return !space_char(c);
}

char *token_start(char *str) {
    while (*str && space_char(*str)) {
        str++;
    }
    return (*str) ? str : NULL;
}

char *token_terminator(char *token) {
    while (*token && non_space_char(*token)) {
        token++;
    }
    return token;
}

int count_tokens(char *str) {
    int count = 0;
    while ((str = token_start(str))) {
        count++;
        str = token_terminator(str);
    }
    return count;
}

char *copy_str(char *inStr, short len) {
    static char buffer[256]; // Tamaño máximo del buffer.
    if (len >= sizeof(buffer)) {
        len = sizeof(buffer) - 1; // Limita la longitud al tamaño del buffer.
    }
    strncpy(buffer, inStr, len);
    buffer[len] = '\0';
    return buffer;
}

