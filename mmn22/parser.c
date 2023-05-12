/**

This program is a parser for complex number manipulation commands.
The program will get a string and parse it according to the defined rules.
The program will check if the input is valid and if so it will perform the command.

 Created by Almog Shtaigmann on 25/03/2023.
**/

#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "parser.h"
#include "ERRORS.h"

#define MAXLEN 1000
#define amount_of_commands 9
#define VALID_CHARS "A B C D E , - 0 1 2 3 4 5 6 7 8 9 \n "

/**

Determines if a string contains only whitespace characters from a given starting position.
@param command A pointer to a character array representing the input string to be checked for whitespace.
@param position An integer representing the starting position within the command array to begin checking for whitespace.
@return An integer value of 1 if the string contains only whitespace characters from the given starting position to the end, and 0 otherwise.
*/
int is_only_spaces(char *command, int position) {
    int i = position;
    /*find thelast char in thae command that he is not spase*/
    while (isspace(command[i])) {
        i++;
    }
    /*If this place is not the end of the command -> is not all spaces*/
    if (i < strlen(command) - 1)
        return 0;
    return 1;
}

/**

Determines if a given character is valid according to a predefined set of valid characters.
@param ch A character to be checked for validity.
@return An integer value of ERROR_CODE_0 if the character is valid, and ERROR_CODE_10 otherwise.
*/
int is_valid_char(char ch) {
    int i;
    char vaild_chars[] = VALID_CHARS;
    for (i = 0; i < strlen(VALID_CHARS); i++) {
        if (vaild_chars[i] == ch || ch == '\0')
            return ERROR_CODE_0;
    }
    return ERROR_CODE_10;
}


/**

Skips over whitespace and/or commas in a given command string from a given starting position, and checks for errors in the process.
@param command A pointer to a character array representing the command string to be processed.
@param position A pointer to an integer representing the starting position within the command array to begin skipping over whitespace/commas.
@param comma_required An integer representing whether a comma is required in the skipped section of the command string.
@param end_of_command An integer representing whether the end of the command string has been reached.
@return An integer value representing any errors encountered during the whitespace/comma skipping process.
*/
int skip_space_comma(char *command, int *position, int comma_required, int end_of_command) {
    int count_comma = 0, error = 0, temp_pos = *position;
    /*Iterate until found char that is not space or comma*/
    while (isspace(command[temp_pos]) || command[temp_pos] == ',') {
        if (error)
            break;
        if (command[temp_pos] == ',')
            count_comma++;
        /*If there is more then 1 comma - return the relevant error*/
        if (count_comma > 1) {
            error = ERROR_CODE_6;
        }
        temp_pos++;
        /*If arrived to the end of command but */
        if (strlen(command) - 1 == *position) {
            error = ERROR_CODE_9;
        }
/*        if((void *) command[*position] == NULL && !end_of_command)
            error = ERROR_CODE_9; */
    }

    if (command[temp_pos])
        if (comma_required && !count_comma)
            error = ERROR_CODE_7;

    if (!comma_required && count_comma)
        error = ERROR_CODE_8;

    if (end_of_command && count_comma) {
        error = ERROR_CODE_5;
    }

    *position = temp_pos;
    return error;
}

int is_valid_end_of_command(char *command, int position) {
    int temp_pos = position + 1, error = ERROR_CODE_0;
    if (is_only_spaces(command, position))
        return error;
    else return ERROR_CODE_5;
}

float get_float_number(char *command, int parser_position) {
    return atof(&command[parser_position]);

}

int skip_float_number(char *command, int parser_position) {
    int end_of_float = 0;
    while (!end_of_float) {
        if (isdigit(command[parser_position]) || command[parser_position] == '.' || command[parser_position] == '-')
            parser_position++;
        else end_of_float = 1;
    }
    return parser_position;
}

int get_command_name(char *command, char *command_name, int *parser_position) {
    char commands_valid_name[][MAXLEN] = {
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
    int i = 0, j = 0, error = ERROR_CODE_0, command_name_is_valid = 0;
    /*Find the where the command name start*/
    error = skip_space_comma(command, &j, 0, 0);

    while (!isspace(command[j]) && command[j] != ',') {

        /*Only if the char is valid*/
        if (is_valid_char(command[j])) {
            command_name[i++] = command[j];
            j++;
        } else {
            if (isupper(command[j]))
                error = ERROR_CODE_1;
            else
                error = ERROR_CODE_10;
            return error;
        }

    }
    command_name[i] = '\0';

    for (i = 0; i < amount_of_commands; i++) {
        if (strcmp(command_name, commands_valid_name[i]) == 0) {
            command_name_is_valid = 1;
            break;
        }
    }
    if (!command_name_is_valid) {
        return 1;
    }
    error = skip_space_comma(command, &j, 0, 0);
    *parser_position = j;

    return error;
}

int
get_variable_name(char *command, int *variable_index, int *parser_position, int comma_required, int end_of_command) {
    int i, temp_index = 0, error = 0, new_pos = *parser_position + 1;
    temp_index = abs('A' - command[*parser_position]);
    if (temp_index > 5) {
        /*A - " " is 65*/
        if (temp_index == 65)
            error = ERROR_CODE_4;
        else
            error = ERROR_CODE_2;
    } else {
        *variable_index = temp_index;
        error = skip_space_comma(command, &new_pos, comma_required, end_of_command);
    }
    *parser_position = new_pos;

    /*Make Sure that the next char is valid*/
    if (!error)
        error = is_valid_char(command[*parser_position]);

    if ((void *) command[*parser_position] == NULL && !end_of_command)
        error = ERROR_CODE_4;

    return error;
}

int get_float_part(char *command, float *real_number, int *parser_position, int comma_required, int end_of_command) {
    int i, temp_position = *parser_position, error = 0, start_pos = 0;
    char is_float[] = "", *endptr;
    float hold_palce;
    char first_char = command[temp_position];
    if (!isdigit(first_char) && first_char != '-') {
        if (command[temp_position] == '\0')
            error = ERROR_CODE_4;
        else
            error = ERROR_CODE_3;
    } else {
        *real_number = get_float_number(command, *parser_position);

        if (*real_number == 0.0) {
            start_pos = temp_position;
        }
        temp_position = skip_float_number(command, temp_position);
        if (start_pos == temp_position) {
            error = ERROR_CODE_3;
        }
        error = skip_space_comma(command, &temp_position, comma_required, end_of_command);
        *parser_position = temp_position;
    }

    return error;
}

