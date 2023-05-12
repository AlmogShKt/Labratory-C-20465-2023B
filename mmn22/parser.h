int get_command_name(char *command, char *command_name, int *parser_position);

int get_last_space(char *command, int *position, int comma_required);

int get_variable_name(char *command, int *variable_index, int *parser_position, int comma_required, int end_of_command);

int get_float_part(char *command, float *real_number, int *parser_position, int comma_required, int end_of_command);

int is_valid_end_of_command(char *command, int position);