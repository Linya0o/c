#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    /* counting qualified scores*/
    int scores[] = { 6, 3, 5, 8, 4, };
    int num_passing = 0, total_grades = 0;

    for (size_t i = 0; i < sizeof(scores)/sizeof(int); i++) {
        int grade = scores[i];
        switch (grade) {
            case 9: case 8: case 7: case 6:
                // fallthrough
                num_passing++;
            default:
                total_grades++;
                break;
        }
    }
    printf("%d out of %d grades are qualified.\n", num_passing, total_grades);

    return EXIT_SUCCESS;
}
