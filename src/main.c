#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    printf("%d %% %d : %d\n", -5, 2, -5 % 2);
    printf("%d %% %d : %d\n", -5, -2, -5 % -2);
    printf("%d %% %d : %d\n", 5, -2, -5 % -2);

    int a[5] = { 0 }, i = 0;
    a[i++] += 2;    // undefined behavior
    printf("i : %d, a[0] : %d\n", i, a[0]);
    return EXIT_SUCCESS;
}
