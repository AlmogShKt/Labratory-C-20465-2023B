/**
* Created by Almog Shtaigmann on 04/05/2023.
*/
#include <stdio.h>

/**
*@struct node
@brief A structure representing a node in the linked list.
@var node::fib_value
A pointer to a string variable to store the Fibonacci number.
@var node::next
A pointer to the next node in the list.
@var node::prev
A pointer to the previous node in the list.
*/
typedef struct node {
    unsigned long fib_value;      /* A pointer to a string variable to store the Fibonacci number. */
    struct node *next;  /* A pointer to the next node in the list. */
    struct node *prev;  /* A pointer to the previous node in the list. */
} Node;

/*Create fibonacci linked list*/
int create_fibonacci(Node **head, int n);

/*Print the list, to std and to provided File*/
void print_list(Node *head, FILE *file_ptr, int n);

/*free all nodes in the list*/
void free_list(Node **list_head);


int handle_file(Node *head, char *file_name , int n);
