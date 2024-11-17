#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"

int main() {
    // Prueba para space_char
    printf("Testing space_char...\n");
    printf("space_char(' ') = %d (Expected: 1)\n", space_char(' '));
    printf("space_char('a') = %d (Expected: 0)\n", space_char('a'));

    // Prueba para non_space_char
    printf("\nTesting non_space_char...\n");
    printf("non_space_char(' ') = %d (Expected: 0)\n", non_space_char(' '));
    printf("non_space_char('a') = %d (Expected: 1)\n", non_space_char('a'));

    // Prueba para token_start
    printf("\nTesting token_start...\n");
    char str1[] = "   hello world";
    char *start = token_start(str1);
    printf("token_start(\"   hello world\") = %s (Expected: 'hello world')\n", start);

    // Prueba para token_terminator
    printf("\nTesting token_terminator...\n");
    char str2[] = "hello world";
    char *end = token_terminator(str2);
    printf("token_terminator(\"hello world\") = %c (Expected: ' ')\n", *end);

    // Prueba para count_tokens
    printf("\nTesting count_tokens...\n");
    char str3[] = "  hello world this is a test  ";
    printf("count_tokens(\"  hello world this is a test  \") = %d (Expected: 5)\n", count_tokens(str3));

    // Prueba para copy_str
    printf("\nTesting copy_str...\n");
    char str4[] = "hello";
    char *copy = copy_str(str4, 5);
    printf("copy_str(\"hello\", 5) = %s (Expected: 'hello')\n", copy);
    free(copy); // Liberar memoria asignada dinámicamente

    return 0;
}
