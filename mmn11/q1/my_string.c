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

int my_strncmp(const char s1[], const char s2[], size_t n)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        if (s1[i] != s2[2])
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
    /*
    char s1[] = "kasl", s2[] = "kab";
    int result, result2;
    result = strcmp(s1, s2);
    printf("The original function returned: %d\n", result);

    result2 = my_strcmp(s1, s2);
    printf("MY function returned: %d", result2);

     _________________________*/

    char s1[] = "1234", s2[] = "123456", s3[10];
    int n;
    n = 3;
    int result, result2, res3;
    result = strncmp(s1, s2, n);
    printf("The original function returned: %d\n", result);

    result2 = my_strncmp(s1, s2, n);
    printf("MY function returned: %d\n", result2);

    res3 = tets1(s1, s2, 12);
    printf("MY function returned: %d\n", res3);

    return 0;
}
