#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int ch;
    while ((ch = getchar()) == ' ');
    putchar(ch);

    return EXIT_SUCCESS;
}
