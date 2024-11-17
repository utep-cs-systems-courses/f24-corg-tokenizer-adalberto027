#include <stdio.h>
#include "tokenizer.h"

int main() {
    // Prueba para space_char
    printf("Testing space_char...\n");
    printf("space_char(' ') = %d (Expected: 1)\n", space_char(' '));
    printf("space_char('a') = %d (Expected: 0)\n", space_char('a'));

    return 0;
}
