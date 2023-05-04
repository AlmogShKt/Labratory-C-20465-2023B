//
// Created by Almog Shtaigmann on 04/05/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "fibonacci_handler.h"

#define MAX_SIZE 1000

int isFileExist(char path[]);


int main(int argc, char *argv[]) {
    Node *list_head = NULL;
    FILE *file_ptr = NULL;
    char file_name[MAX_SIZE];
    int n;
    int error_found = 0;
    char welcome_file_msg[MAX_SIZE];


    if ((argc - 1) == 1) {
        strcpy(file_name, argv[1]);
        if (isFileExist(file_name)) {
            printf("Hi there, amd welcome to mmn23 !\n");
            printf("Please enter a number. This number will set the length of the fibonacci sequence size\n");
            scanf("%d", &n);
            printf("Creating fibonacci sequence in size of %d", n);

            error_found = create_fibonacci(&list_head, n);
            if (!error_found) {
                file_ptr = fopen(file_name, "w");
                strcpy(welcome_file_msg, "Hi again, This is mmn23. \
            \nThis program will get a file name ot path, and a number 'n' \
            \nThen the program will calculate the first n nu,ber in fibonacci sequence. \
            \nThe program will print the sequence from the biggest nu,ber to the lower in the terminal as well in the provided file.");
                fprintf(file_ptr, "%s", welcome_file_msg);
                print_list(&list_head, file_ptr, n);
            } else {
                printf("~~ERROR- Memory allocation failed");
            }
        }
    } else {
        if (argc == 1)
            printf("~~ERROR- file name is missing");
        if (argc > 2)
            printf("~~ERROR- Could not open provided file name: %s ", file_name);
    }

    return 0;
}


int isFileExist(char path[]) {
    FILE *file_ptr = fopen(path, "r");
    if (file_ptr == NULL) {

        return 0;
    }
    fclose(file_ptr);
    return 1;
}
