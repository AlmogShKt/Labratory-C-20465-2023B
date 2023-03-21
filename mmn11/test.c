#include <stdio.h>
#include <string.h>

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

int main()
{
    char str1[10], str2[10];
    int k;

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
    return 0;
}