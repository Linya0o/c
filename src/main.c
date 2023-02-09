#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    freopen("in.dat", "r", stdin);
    freopen("out.dat", "w", stdout);

    int year = { 0 };
    scanf("%d", &year);
    printf("hello world %d\n", year);

    return EXIT_SUCCESS;
}
