#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_SET_SIZE 1
/*Return the new size to allocate in to the dynamic memory, the size of the set + 1 * sizeof int */
#define ENLARGE_SIZE(new_set_size) ((new_set_size + DEFAULT_SET_SIZE) * sizeof(int))

int *get_set(int *set, int *current_set_size);

void print_set(const int *set, int current_set_size);

int search_number(const int *set, int number, int set_size);

int *copy_set(int *set, int size);

int main() {
    int *set = NULL;
    int current_set_size = 0;
    /*First initialize set with 0 bits of memory, in case that the set will be empty*/
    set = (int *) malloc(DEFAULT_SET_SIZE * sizeof(int));

    printf("\n Hi! Welcome to My_set By Almog Shtaigmann\n");
    printf("Please enter a number for the set. (to STOP enter a letter or press ctrl+d) \n");

    /*Iterate until to user stop to enter new number to the set*/
    set = get_set(set, &current_set_size);
    if (!set) {
        printf("Failed while add new members into the set..");
        exit(0);
    }
    if (current_set_size)
        print_set(set, current_set_size);
    free(set);

    return 0;
}

int *get_set(int *set, int *current_set_size) {
    int new_member = 0, *temp_set = NULL;

    while (scanf("%d", &new_member) == 1) {
        printf("You entered - %d\n", new_member);
        if (!search_number(set, new_member, *current_set_size)) {
            temp_set = copy_set(set, *current_set_size);
            (*current_set_size)++;
            set = realloc(set, (*current_set_size) * sizeof(int));

            if (set != NULL) {
                set[*current_set_size - 1] = new_member;
                printf("Successfully entered new member to the set! \n");
                printf("The set size is: %d \n", *current_set_size);
            } else {
                printf("Error occurred while realloc.. please re-enter the last numbe ");

                /*Restore the values of set in case of error*/
                free(set);
                set = copy_set(temp_set,*current_set_size);
            }
        } else
            printf("this number is already in the set :)\n");
        printf("Please enter a number for the set. (to STOP enter a letter or press ctrl+d) \n");
    }
    free(temp_set);
    return set;
}

/*Check if the number is already exist in the set*/
int search_number(const int *set, int number, int set_size) {
    int i;
    for (i = 0; i < set_size; i++) {
        if (set[i] == number)
            return 1;
    }
    return 0;
}

int *copy_set(int *set, int size) {
    int *copy = malloc(size * sizeof(int));
    if (copy != NULL) {
        for (int i = 0; i < size; i++) {
            copy[i] = set[i];
        }
    }
    return copy;
}


void print_set(const int *set, int current_set_size) {
    int i;
    printf("The set is:\n");
    for (i = 0; i < current_set_size; i++) {
        printf("%d ", set[i]);
    }
    printf("\n");
}