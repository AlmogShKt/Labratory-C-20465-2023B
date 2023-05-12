/**

@file mycomp.c
@brief This is the main file of a program that handles complex numbers and supports 9 different commands.
The program allows the user to enter commands from the keyboard ot from text file, and accordingly executes the appropriate
command on the appropriate complex number. The program supports 9 different commands: print_comp, read_comp,
add_comp, sub_comp, mult_comp_real, mult_comp_img, mult_comp_comp, abs_comp, and stop.
Created by Almog Shtaigmann on 25/03/2023.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "complex.h"
#include "parser.h"
#include "ERRORS.h"

#define MAXLEN 1200 /* Define maximum length for commands and inputs */
#define command_number 9 /* Define number of supported commands */

/**
 * This is the main function of the program.
 * This function lets the user to interact with the program.
 * @return 0;
 */
int main() {
    ComplexNumber complex_numbers[6] = {{0, 0},
                                        {0, 0},
                                        {0, 0},
                                        {0, 0},
                                        {0, 0},
                                        {0, 0}};

    char command[MAXLEN]; /*The input command */
    char command_name[MAXLEN]; /*The command name */
    int has_stopped = 0, command_size = 0; /*Some flags for the program */
    int variable_index_1, variable_index_2;
    int current_parser_position = 0, i;
    int error_found = 0, comma_required = 0, end_of_command = 0;;

/* Define a 2Dim array of commands name */
    char commands[][MAXLEN] = {
            "print_comp",
            "read_comp",
            "add_comp",
            "sub_comp",
            "mult_comp_real",
            "mult_comp_img",
            "mult_comp_comp",
            "abs_comp",
            "stop"
    };

/* Define an array of Error structs to store error codes and messages */
    Error errors[] = {
            {ERROR_CODE_0,  "No error"},
            {ERROR_CODE_1,  "Undefined command name"},
            {ERROR_CODE_2,  "Undefined complex variable"},
            {ERROR_CODE_3,  "Invalid parameter – not a number"},
            {ERROR_CODE_4,  "Missing parameter"},
            {ERROR_CODE_5,  "Extraneous text after end of command"},
            {ERROR_CODE_6,  "Multiple consecutive commas"},
            {ERROR_CODE_7,  "Missing comma"},
            {ERROR_CODE_8,  "Illegal comma"},
            {ERROR_CODE_9,  "End of line but no command was found"},
            {ERROR_CODE_10, "Undefined Input"}
    };

/* Will hold the complex number data */
    float real_number = 0.0, imaginary_number = 0.0;

    /* Print a welcome message */
    printf("Hi, Welcome to mmn22 by Almog Shtaigmann\n");
    printf("Lets start, follow the instruction below:\n\n");
    printf("-------------\n");
    printf("Enter command:");

    /* Loop over input commands */
    while (fgets(command, MAXLEN, stdin)) {
        command_size = strlen(command);
        /*Handle case of end of line is missing \0 - EOF */
        if (command_size > 0 && command_size < MAXLEN - 1 && command[command_size] != '\n') {
            command[command_size] = '\n';
            command[command_size + 1] = '\0';
        }
        printf("%s", command); /*Print the command name*/

        /* Get the name of the command and the position of the parser. */
        error_found = get_command_name((char *) &command, (char *) command_name, &current_parser_position);

        /*In this case, if we got error 9 its mean that missing parameter.*/
        if (error_found == ERROR_CODE_9)
            error_found = ERROR_CODE_4;
            /*Continue with the program only in case that no errors where found.*/
        else if (!error_found) {
            /*Finding the command position in the commands list, represented by i*/
            for (i = 0; i < command_number; i++) {
                if (strcmp(command_name, commands[i]) == 0) {
                    break;
                }
            }
            if (i != 8) {
                /*If the command is read_comp ot abs_comp, comma is not required after the var' name*/
                if (i == 0 || i == 7)
                    error_found = get_variable_name(command, &variable_index_1, &current_parser_position,
                                                    comma_required,
                                                    !end_of_command);
                else
                    error_found = get_variable_name(command, &variable_index_1, &current_parser_position,
                                                    !comma_required,
                                                    end_of_command);
                /*In this case, if we got error 9 its mean that missing parameter*/
                if (error_found == ERROR_CODE_9)
                    error_found = ERROR_CODE_4;

                /*If no error was found in the previous commands, execute the switch statement.*/
                if (!error_found) {
                    switch (i) {
                        case 0:
                            /*This case prints a complex number. The program first checks whether the end of the command has been reached without any errors*/
                            /*and if so, it prints the complex number stored in the array complex_numbers at the index variable_index_1.*/

                            /*Make sure that the end of the command is legal*/
                            error_found = is_valid_end_of_command(command, current_parser_position);
                            if (error_found)
                                break;

                            /*Execute the function only if there in no errors */
                            print_comp(complex_numbers[variable_index_1]);
                            break;
                        case 1:
                            /**
                             * This case reads a complex number from the command input.
                             * The program first extracts the real and imaginary parts of the complex number from the input using the get_float_part function.
                             * If the extraction is successful, it stores the real and imaginary parts in the real_number and imaginary_number variables, respectively.
                             * The program then checks for errors, including the validity of the comma, and if there are no errors,
                             * it stores the complex number in the complex_numbers array at the index variable_index_1 and prints it.
                             */
                            error_found = get_float_part(command,
                                                         &real_number, &current_parser_position, !comma_required,
                                                         end_of_command);
                            if (!error_found) {
                                error_found = get_float_part(command, &imaginary_number, &current_parser_position,
                                                             comma_required, end_of_command);

                                /*If the error is iLegal comma its mean that the coma is ERROR 5*/
                                if (error_found == ERROR_CODE_8)
                                    error_found = ERROR_CODE_5;
                            }
                            if (!error_found)
                                error_found = is_valid_end_of_command(command, current_parser_position);
                            /*If error found - stop and break from the switch*/
                            if (error_found)
                                break;

                            /*Execute the function only if there in no errors */
                            read_comp(&complex_numbers[variable_index_1], real_number, imaginary_number);
                            print_comp(complex_numbers[variable_index_1]);
                            break;

                        case 2:
                            /**
                             * This case adds two complex numbers.
                             * The program first extracts the index of the second complex number from the command input using the get_variable_name function.
                             * It then checks for errors and, if there are no errors, adds the two complex numbers and stores the result in the complex_numbers array at the index variable_index_1.
                             */
                            error_found = get_variable_name(command,
                                                            &variable_index_2, &current_parser_position, comma_required,
                                                            !end_of_command);
                            error_found = is_valid_end_of_command(command, current_parser_position);
                            if (error_found)
                                break;

                            /*Execute the function only if there in no errors */
                            add_comp(complex_numbers[variable_index_1], complex_numbers[variable_index_2]
                            );
                            break;
                        case 3:
                            /**
                             * This case subtracts two complex numbers.
                             * The program extracts the index of the second complex number from the command input using the get_variable_name function.
                             * It then checks for errors and, if there are no errors, subtracts the second complex number from the first complex number and stores the result in the complex_numbers array at the index variable_index_1.
                             */

                            error_found = get_variable_name(command,
                                                            &variable_index_2, &current_parser_position, comma_required,
                                                            !end_of_command);
                            error_found = is_valid_end_of_command(command, current_parser_position);
                            if (error_found)
                                break;
                            sub_comp(complex_numbers[variable_index_1], complex_numbers[variable_index_2]
                            );
                            break;
                        case 4:
                            /**
                             * This case multiplies a complex number by a real number.
                             * The program extracts the real number from the command input using the get_float_part function.
                             * It then checks for errors and, if there are no errors, multiplies the real number by the complex number and stores the result in the complex_numbers array at the index variable_index_1.
                             */

                            error_found = get_float_part(command,
                                                         &real_number, &current_parser_position, !comma_required,
                                                         end_of_command);
                            error_found = is_valid_end_of_command(command, current_parser_position);
                            if (error_found)
                                break;

                            /*Execute the function only if there in no errors */
                            mult_comp_real(complex_numbers[variable_index_1], real_number
                            );
                            break;
                        case 5:
                            /**
                             * This case multiplies a complex number by an imaginary number.
                             * The program extracts the imaginary number from the command input using the get_float_part function.
                             * It then checks for errors and, if there are no errors, multiplies the imaginary number by the complex number and stores the result in the complex_numbers array at the index variable_index_1.
                             */

                            error_found = get_float_part(command,
                                                         &imaginary_number, &current_parser_position, comma_required,
                                                         !end_of_command);
                            if (!error_found)
                                error_found = is_valid_end_of_command(command, current_parser_position);
                            if (error_found)
                                break;

                            /*Execute the function only if there in no errors */
                            mult_comp_img(complex_numbers[variable_index_1], imaginary_number
                            );
                            break;
                        case 6:
                            /**
                             * This case multiplies two complex numbers.
                             * The program extracts the index of the second complex number from the command input using the get_variable_name function.
                             * It then checks for errors and, if there are no errors, multiplies the two complex numbers and stores the result in the complex_numbers array at the index variable_index_1.
                             */

                            error_found = get_variable_name(command,
                                                            &variable_index_2, &current_parser_position, comma_required,
                                                            !end_of_command);
                            error_found = is_valid_end_of_command(command, current_parser_position);
                            if (error_found)
                                break;
                            mult_comp_comp(complex_numbers[variable_index_1],
                                           complex_numbers[variable_index_2]
                            );
                            break;
                        case 7:
                            /**
                             * This case calculates the absolute value of a complex number.
                             * The program checks for errors and, if there are no errors, calculates the absolute value of the complex number and stores the result in the complex_numbers array at the index variable_index_1.
                             */

                            error_found = is_valid_end_of_command(command, current_parser_position);
                            if (error_found)
                                break;

                            abs_comp(complex_numbers[variable_index_1]);
                            break;

                        default:
                            /*Unknown command*/
                            error_found = ERROR_CODE_1;
                            break;
                    }
                }
            } else if (i == 8) { /*In case that the command is stop*/

                /*Check if the STOP command is valid*/
                error_found = is_valid_end_of_command(command, current_parser_position);
                if (!error_found) {
                    /*stopping the program*/
                    printf("Ok, Stopping the app..\n");
                    has_stopped = 1;
                    exit(0);
                }
            }
        }

        /*Print the error*/
        if (error_found)
            printf("~~ERROR[%d]- %s~~\n", error_found, errors[error_found].error_msg);

        /*Set the parser position back to 0, to be ready for the next command line*/
        real_number = 0;
        imaginary_number = 0;
        current_parser_position = 0;
        error_found = 0;
        printf("-------------");
        printf("\nEnter command:");
    }

    /*For case that the program stop but not from the 'stop' command. (ex: EOF)*/
    if (!has_stopped) {
        printf("\nprogram has stopped with out the command 'stop'\n");
        exit(0);
    }
    return 0;
}


