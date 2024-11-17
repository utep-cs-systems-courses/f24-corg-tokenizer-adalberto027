#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h" // Asegúrate de que este archivo header esté bien configurado

int main() {
    void test_space_char() {
        printf("Testing space_char...\n");
        printf("space_char(' ') = %d (Expected: 1)\n", space_char(' '));
        printf("space_char('\\t') = %d (Expected: 1)\n", space_char('\t'));
        printf("space_char('a') = %d (Expected: 0)\n", space_char('a'));
    }
    
    // Prueba para non_space_char
    void test_non_space_char() {
        printf("\nTesting non_space_char...\n");
        printf("non_space_char(' ') = %d (Expected: 0)\n", non_space_char(' '));
        printf("non_space_char('\\t') = %d (Expected: 0)\n", non_space_char('\t'));
        printf("non_space_char('a') = %d (Expected: 1)\n", non_space_char('a'));
    }
    
    // Prueba para token_start
    void test_token_start() {
        printf("\nTesting token_start...\n");
        char str1[] = "   hello world";
        char *start = token_start(str1);
        printf("token_start(\"   hello world\") = %s (Expected: 'hello world')\n", start);
    
        char str2[] = "       ";
        start = token_start(str2);
        printf("token_start(\"       \") = %p (Expected: NULL)\n", start);
    }
    
    // Prueba para token_terminator
    void test_token_terminator() {
        printf("\nTesting token_terminator...\n");
        char str[] = "hello world";
        char *terminator = token_terminator(str);
        printf("token_terminator(\"hello world\") points to: '%c' (Expected: ' ')\n", *terminator);
    }

}
