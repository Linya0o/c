#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int i = 0;
    while (i < 25) {
        printf("%3d", i);
        i++;
    }

    return EXIT_SUCCESS;
}
