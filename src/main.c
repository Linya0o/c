#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

typedef bool (*comare_cb) (int a, int b);
int* bubble_sort(int *array, int size, comare_cb cmp);
bool sorted_order(int a, int b);
bool reverse_order(int a, int b);
void test_sorting(int *array, int size, comare_cb cmp);

int main(int argc, char *argv[]) {
    int nums[] = { 4, 1, 7, 3, 2, 0, 8 };
    int len = sizeof(nums) / sizeof(int);

    test_sorting(nums, len, sorted_order);
    test_sorting(nums, len, reverse_order);

    return EXIT_SUCCESS;
}

void test_sorting(int *array, int size, comare_cb cmp) {
    int *sorted = bubble_sort(array, size, cmp);

    for (int i = 0; i < size; i++) {
        printf("%d ", sorted[i]);
    }
    printf("\n");
}

int* bubble_sort(int *array, int size, comare_cb cmp) {
    assert(array != NULL);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (cmp(array[j], array[j+1])) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    return array;
}

bool sorted_order(int a, int b) {
    return a > b;
}

bool reverse_order(int a, int b) {
    return b > a;
}
