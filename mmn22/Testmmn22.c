#include <stdio.h>
#include <string.h>

#define VALID_CHARS "A B C D E , - 0 1 2 3 4 5 6 7 8 9 \n"

void main(){
    char c[] = VALID_CHARS;
    char c2 = '\n';
    int i = 0;
    char vaild_chars[] = VALID_CHARS;
    for (i; i < strlen(VALID_CHARS); i++) {
        if (vaild_chars[i] == c2)
            printf( "ERROR_CODE_0 __ %d", i);
    }


    return ;
}