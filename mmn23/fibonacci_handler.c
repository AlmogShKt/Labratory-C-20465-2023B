//
// Created by Almog Shtaigmann on 04/05/2023.
//
#include <stdio.h>

typedef struct node {
    unsigned long fib_value;      /* A pointer to a string variable to store the Fibonacci number. */
    struct node *next;  /* A pointer to the next node in the list. */
    struct node *prev;  /* A pointer to the previous node in the list. */
} Node;


int create_fibonacci(Node **head, int n);
void print_list(Node **head, FILE *file_ptr, int n);


