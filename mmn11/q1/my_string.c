/*
Mmn 11 - Q1.
In this program Will be 3 new implements of functions from <string>.
The function are:
strcmp -> my_strcmp
strncmp -> my_strncmp
strchr -> my_strchr
*/
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 80

int my_strchr(const char str[], char c)
{
    int i = 0;
    /* search the char c until you reach to the end of the string*/
    while (str[i] != '\0')
    {
        /*When found the char, return the index*/
        if (str[i] == c)
            return i;
        /*Keep search for c in str*/
        i++;
    }
    /*THe char was not found -> return -1*/
    return -1;
}

int my_strncmp(char s1[], char s2[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (s1[i] != s2[i])
        {
            /* return difference between first differing characters */
            return s1[i] - s2[i];
        }
        /*if we arrived to the end of s1 => s1=s1 -> return 0*/
        else if (s1[i] == '\0')
        {
            return 0;
        }
    }
    return 0;
}

int my_strcmp(const char s1[], const char s2[])
{
    int i = 0;
    /*Keep go until you find difference between characters */
    while (s1[i] == s2[i])
    {
        /*If we in the end of the string -> s1=s1 -> return 0*/
        if (s1[i] == '\0')
            return 0;
        i++;
    }
    /*At this point, s1 ≠s2 , so return the difference between them*/
    return s1[i] - s2[i];
}

int main()
{
    char str1[MAX_SIZE], str2[MAX_SIZE];
    int k, result;
    char c;
    printf("Hi there!\n-------\n");

    printf("Function 1, my_strncmp\n");
    printf("Enter the first string\n");
    scanf("%s", str1);
    printf("Ok, str1 is: %s\n", str1);

    printf("Enter the second string\n");
    scanf("%s", str2);
    printf("Ok, str2 is: %s\n", str2);

    result = my_strcmp(str1, str2);

    printf("The result for my_strcmp(st1,str2) is: %d \n", result);
    printf("The result for strcmp(st1,str2) is: %d \n\n", strcmp(str1, str2));

    /*set str1,str2 as 0*/
    memset(str1, 0, sizeof(str1));
    memset(str2, 0, sizeof(str2));

    printf("\nFunction 2, my_strncmp\n");
    printf("Enter the first string\n");
    scanf("%s", str1);
    printf("Ok, str1 is: %s\n", str1);

    printf("Enter the second string\n");
    scanf("%s", str2);
    printf("Ok, str2 is: %s\n", str2);

    printf("enter the index\n");
    scanf("%d", &k);
    printf("Ok, k is: %d\n", k);

    printf("The result for my_strncmp(st1,str2,k) is: %d \n", my_strncmp(str1, str2, k));
    printf("The result for strncmp(st1,str2,k) is: %d \n\n", strncmp(str1, str2, k));

    /*set str1,str2 as 0*/
    memset(str1, 0, sizeof(str1));

    printf("\n\nFunction 3, my_strchr\n");
    printf("Enter a string and then char\n");
    scanf("%s %c", str1, &c);
    printf("Ok,str is: %s and c is: %c\n", str1, c);

    result = my_strchr(str1, c);

    printf("The result for my_strchr(st1,c) is: %d \n", result);

    return 0;
}
