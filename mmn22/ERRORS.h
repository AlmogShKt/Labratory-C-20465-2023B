/**
 * The following lines define error codes that can be used to identify different types of errors.
 * Created by Almog Shtaigmann
 */

#define ERROR_CODE_0 0
#define ERROR_CODE_1 1
#define ERROR_CODE_2 2
#define ERROR_CODE_3 3
#define ERROR_CODE_4 4
#define ERROR_CODE_5 5
#define ERROR_CODE_6 6
#define ERROR_CODE_7 7
#define ERROR_CODE_8 8
#define ERROR_CODE_9 9

#define ERROR_CODE_10 10
#define MMAX 1000

/* Defines a structure for an error, which consists of an error ID and an error message.
*/
typedef struct {
    int error_id; /*The ID of the error.*/
    char error_msg[MMAX]; /*The error message associated with the error.*/
} Error;







