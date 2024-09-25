#include <stdio.h>
#include <string.h>

int main() {
    char input[256];  // Buffer store the input of the user we can change the number of cracteres

    for (;;) {
        // Show gratter than sign
        printf("> ");
      
        // read the user input
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;  // exit if there is no input
        }

        // remove the enter a the end of the line
        input[strcspn(input, "\n")] = 0;

        // exit ends the program
        if (strcmp(input, "exit") == 0) {
            break;
        }

        // return the input
        printf("%s\n", input);
    }

    return 0;
}

