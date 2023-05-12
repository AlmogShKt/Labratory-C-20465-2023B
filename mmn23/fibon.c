/**
* Created by Almog Shtaigmann on 04/05/2023.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>
#include "fibonacci_handler.h"

#define MAX_SIZE 1000
#define MAX_INT 20

int isFileExist(char path[]);

/**
@brief Main function of the mmn23 program.
This function is the main entry point of the mmn23 program. The program expects one command line argument, which is
the name of the file to output the Fibonacci sequence to. The program prompts the user to enter an integer 'n', which
is the number of Fibonacci numbers to generate. The program then generates the first n Fibonacci numbers and outputs
them to both the provided file and the terminal. If any errors occur during the program execution, the program will
output an error message to the terminal.
@param argc The number of command line arguments passed to the program.
@param argv An array of strings representing the command line arguments passed to the program.
*/
int main(int argc, char *argv[]) {
    Node *list_head = NULL; /* A pointer to the head node of the linked list containing the Fibonacci numbers. */
    FILE *file_ptr = NULL; /*A character array to store the name of the file to output the Fibonacci numbers to. */
    char file_name[MAX_SIZE]; /*A character array to store the name of the file to output the Fibonacci numbers to. */
    int n = 0; /*An integer representing the number of Fibonacci numbers to generate. */
    int error_found = 0; /*A flag indicating whether an error was found during the program execution. */
    char input[MAX_SIZE];
    int i = 0;
    /*Check if the correct number of command line arguments was passed to the program. */
    if ((argc - 1) == 1) {
        /*Get the file name from the command line argument. */
        strcpy(file_name, argv[1]);

        /* Check if the file exists. */
        if (isFileExist(file_name)) {
            printf("Hi there, and welcome to mmn23 !\n");
            printf("Please enter a number. This number will set the length of the fibonacci sequence size\n");

            printf("Enter the number of Fibonacci numbers to generate: ");

            /*Get the input from the user*/
            fgets(input, MAX_INT, stdin);
            /*Check if integer was provided on the input*/
            if (sscanf(input, "%d", &n) != 1) {
                /*There is no Integer in the input*/
                error_found = 1;
            } else {
                if (n > 92) {
                    printf("~~ERROR - n is too large, the program can't calculate this number\n");
                    exit(0);
                }
                /*For case the input was: 12as - there is integer but also invalid chars 'as'*/
                for (i = 0; i < strlen(input); i++) {
                    /*Ignore '-' , EOF, new line */
                    if (!isdigit(input[i]) && input[i] != '\n' && input[i] != EOF && input[i] != '-') {
                        /*The input contain some invalid chars*/
                        error_found = 1;
                        break;
                    }
                }
            }
            /*Print msg if needed*/
            if (error_found) {
                printf("~~ERROR - Invalid input - not a number\n");
                exit(1);
            } else if (n < 0) {
                printf("Invalid input - number less then 0\n");
                exit(1);
            }

            printf("Creating fibonacci sequence in size of %d\n", n);

            /* Generate the linked list containing the first n Fibonacci numbers. */
            error_found = create_fibonacci(&list_head, n);

            /* If the linked list was successfully created, output the Fibonacci sequence to the file and the terminal. */
            if (!error_found) {
                handle_file(list_head, file_name, n);
                printf("After Handle file\n");
            } else {

                /* Output an error message if the linked list creation failed. */
                printf("~~ERROR- Memory allocation failed\n");
            }
        } else {
            if (argc == 2)
                printf("~~ERROR- Could not open provided file name: %s \n", file_name);


        }
    } else {
        /** Output an error message if an incorrect number of command line*/
        if (argc == 1)
            printf("~~ERROR- file name is missing");
        else
            printf("~~ERROR- Too many arguments was provided in the command");
    }
    printf("before calling free list\n");
    free_list(list_head, n);
    printf("after calling free list\n");
    exit(0);
    return 0;
}

/**
 * @brief This function checks if the provided file is exist in the system
 * @param path the path to file
 * @return 0 if the file dose not exist , 1 if the file exist
 */
int isFileExist(char path[]) {
    FILE *file_ptr = fopen(path, "r");
    if (file_ptr == NULL) {
        /*File does not exist*/
        return 0;
    }
    fclose(file_ptr);
    return 1;
}
