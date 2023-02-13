#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

struct Person {
    char *name;
    int age;
    int height;
    int weight;
};

struct Person* Person_create(char *name,
        int age, int height, int weight);

void Person_destroy(struct Person *who);

void Person_print(struct Person *who);

int main(int argc, char *argv[]) {
    struct Person *joe = Person_create("Joe Alex", 32, 64, 140);

    struct Person *frank = Person_create("Frank Blank", 20, 72, 180);

    // print them out and where they are in memory
    printf("Joe is at memory location %p:\n", (void *)joe);
    Person_print(joe);

    printf("Frank is at memory location %p:\n", (void *)frank);
    Person_print(frank);

    // make everyone age 20 years and print them again
    joe->age += 20;
    joe->height -= 2;
    joe->weight += 40;
    Person_print(joe);

    frank->age += 20;
    frank->weight += 20;
    // free(frank), frank = NULL;
    Person_print(frank);

    // destroy them both so we clean up
    Person_destroy(joe);
    Person_destroy(frank);

    return EXIT_SUCCESS;
}

struct Person* Person_create(char *name,
        int age, int height, int weight) {
    struct Person *who = malloc(sizeof(*who));
    assert(who != NULL);

    *who = (struct Person) { name, age, height, weight };

    return who;
}

void Person_destroy(struct Person *who) {
    assert(who != NULL);

    // free(who->name);  // Error: the string is stored at static constant area.
    free(who);
}

void Person_print(struct Person *who) {
    assert(who != NULL);

    printf("Name: %s\n\tAge: %d\n\tHeight: %d\n\tWeight: %d\n",
            who->name, who->age, who->height, who->weight);
}
