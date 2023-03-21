#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_SET_SIZE 1
/*Return the new size to allocate in to the dynamic memory, the size of the set + 1 * sizeof int */
#define ENLARGE_SIZE(new_set_size) ((new_set_size + 1) * sizeof(int))

int get_set(int *set, int *current_set_size);

void print_set(const int *set, int current_set_size);

int search_number(const int *set, int number, int set_size);

int main() {
    int *set = NULL;
    int current_set_size = 0;
    /*First initialize set with 0 bits of memory, in case that the set will be empty*/
    set = malloc(0);

    printf("\n Hi! Welcome to My_set By Almog Shtaigmann\n");
    printf("Please enter a number for the set. (to STOP enter a letter or press ctrl+d \n");

    /*Iterate until to user stop to enter new number to the set*/
    if (get_set(set, &current_set_size)) {
        printf("Failed while add new members into the set..");
        exit(0);
    }
    if (current_set_size)
        print_set(set, current_set_size);


    return 0;
}

int get_set(int *set, int *current_set_size) {
    int new_member = 0, is_failed = 0, *temp_set;

    while (scanf("%d", &new_member) == 1) {
        printf("You entered - %d\n", new_member);
        if (!search_number(set, new_member, *current_set_size)) {

            temp_set = realloc(set, ENLARGE_SIZE(*current_set_size));
            if (temp_set != NULL) {
                set = temp_set;
                *(set + *current_set_size) = new_member;
                (*current_set_size)++;
                printf("Successfully entered new member to the set! \n");
                printf("The set size is: %d \n", *current_set_size);
            } else {
                is_failed = 1;
                printf("Error occurred while realloc.. ");
            }
            *(set);
        } else
            printf("this number is alredy in the set :)\n");
        printf("Please enter a number for the set. (to STOP enter a letter or press ctrl+d \n");
    }
    return is_failed;
}

/*Check if the number is already exist in the set*/
int search_number(const int *set, int number, int set_size) {
    int i;
    for (i = 0; i < set_size; i++) {
        if (*(set + i) == number)
            return 1;
    }
    return 0;
}

void print_set(const int *set, int current_set_size) {
    int i;
    printf("The set is:\n");
    for (i = 0; i < current_set_size; i++) {
        printf("%d ",*(set + i));
    }
}