#include <stdio.h>

#define SIZE 4

/*The function get number, and calc how many bits are equal to 1 in even places*/
int count_bits(unsigned long number) {
    int i, count = 0;
    /*unsigned long is 8 bits, for each bit there is another 8 bits*/
    /*We increment i by 2 to skip on the odd bits*/
    for (i = 0; i < sizeof(number) * 8; i += 2) {
        /*Demo, lets say number is -> 0101
         *so
         *0101 >> 0 & 1 = 1 - > count =1
         * 0101>>2 = 0001 & 1 = 1 -> count =2
         * will return 2.
         * */
        if ((number >> i) & 1)
            count++;
    }
    return count;
}

int main() {
    unsigned long numers[SIZE];
    int i;
    printf("\nHi, lets get some numbers to clac how many bits are in the even place.\n");
    printf("\nPlease enter %d numbers", SIZE);
    for (i = 0; i < SIZE; i++) {
        printf("\n%d->", i + 1);
        scanf("%lu", &numers[i]);
        printf("\nYou entered for number #%d ->%lu", i + 1, numers[i]);
    }
    for (i = 0; i < SIZE; i++) {
        printf("\nIn number %d there is bit in the even place", i);
    }
    return 0;
}
