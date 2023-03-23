#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_SET_SIZE 1
/* Macro to calculate the new size to allocate in the dynamic memory,
   the size of the set + 1 * sizeof int */
#define ENLARGE_SIZE(new_set_size) ((new_set_size + DEFAULT_SET_SIZE) * sizeof(int))

/* Function prototypes */
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

    /*Get the set for get_set function*/
    set = get_set(set, &current_set_size);

    /*In case of error with realloc in get_set*/
    if (!set) {
        printf("Failed while add new members into the set..");
        exit(0);
    }
    /*Print the set only if there is numbes in the set*/
    if (current_set_size)
        print_set(set, current_set_size);

    free(set);

    return 0;
}

/**
 * Adds new integers to a set and returns the updated set.
 *
 * @param set               A pointer to an integer array representing the set.
 * @param current_set_size  A pointer to an integer representing the current size of the set.
 *
 * @return                  A pointer to the updated integer array representing the set**/
int *get_set(int *set, int *current_set_size) {
    int new_member = 0, *temp_set = NULL;

    while (scanf("%d", &new_member) == 1) {
        printf("You entered - %d\n", new_member);
        if (!search_number(set, new_member, *current_set_size)) {
            /*Create a copy of the set, in case of error while adding new member*/
            temp_set = copy_set(set, *current_set_size);

            /* Increase the set size and reallocate memory */
            (*current_set_size)++;
            set = realloc(set, (*current_set_size) * sizeof(int));

            /* If reallocation is successful, add new number to the set */
            if (set != NULL) {
                set[*current_set_size - 1] = new_member;
                printf("Successfully entered new member to the set! \n");
                printf("The set size is: %d \n", *current_set_size);
            }
                /* If reallocation fails, print an error message and restore the original set */
            else {
                printf("Error occurred while realloc.. please re-enter the last numbe ");

                /* Restore the values of set in case of error */
                free(set);
                set = copy_set(temp_set, *current_set_size);
            }
        }
            /* If the number is already in the set, print a message */
        else
            printf("this number is already in the set :)\n");

        printf("Please enter a number for the set. (to STOP enter a letter or press ctrl+d) \n");
    }
    /* Free the memory for temp_set */
    free(temp_set);

    return set;
}

/**
 * Check if a given number already exists in a set.
 *
 * @param set       A pointer to an integer array representing the set.
 * @param number    An integer representing the number to check.
 * @param set_size  An integer representing the current size of the set.
 *
 * @return          1 if the number exists in the set, 0 otherwise. */
int search_number(const int *set, int number, int set_size) {
    int i;
    for (i = 0; i < set_size; i++) {
        if (set[i] == number)
            return 1;
    }
    return 0;
}

/**
 * Create a copy of a given set.
 *
 * @param set       A pointer to an integer array representing the set to be copied.
 * @param set_size  An integer representing the current size of the set.
 *
 * @return          A pointer to the copied integer array. */
int *copy_set(int *set, int set_size) {
    int *copy = malloc(set_size * sizeof(int));
    if (copy != NULL) {
        for (int i = 0; i < set_size; i++) {
            copy[i] = set[i];
        }
    }
    return copy;
}

/**
 * Print the elements of a given set.
 *
 * @param set               A pointer to an integer array representing the set to be printed.
 * @param current_set_size  An integer representing the current size of the set. */
void print_set(const int *set, int current_set_size) {
    int i;
    printf("The set is:\n");
    for (i = 0; i < current_set_size; i++) {
        printf("%d ", set[i]);
    }
    printf("\n");
}
