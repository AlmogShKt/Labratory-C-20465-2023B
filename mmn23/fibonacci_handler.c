/**
* Created by Almog Shtaigmann on 04/05/2023.
*/
#include "fibonacci_handler.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


/**
 * Creates a new node for a linked list with the given data.
 *
 * @param value       The data to be stored in the new node.
 * @return new_node - A pointer to the newly created node.
 */
Node *create_node(unsigned long int value) {
    /* Allocate memory for the new node */
    Node *new_node = (Node *) malloc(sizeof(Node));

    /*Only if the allocation seceded*/
    if (new_node != NULL) {
        /*Set the value of the new node*/
        new_node->fib_value = value;

        /* Set the next pointer to NULL */
        new_node->next = NULL;

        /* Return a pointer to the newly created node */
        return new_node;
    } else
        return NULL;
}

/**
 * Inserts a new node containing the given string data into the circular linked list.
 *
 * @param head      A pointer to a pointer to the head node of the linked list.
 * @param value      The string data to be stored in the new node.
 */
void insert_node(Node **head, unsigned long int value) {
    Node *new_node = create_node(value);  /* create a new node */
    if (new_node != NULL) {
        if (*head == NULL) {  /* if the list is empty, set the new node as the head node */
            *head = new_node;
            new_node->next = *head;

        } else {  /* otherwise, traverse the list to find the last node, and append the new node to it */
            Node *temp = *head;
            while (temp->next != *head) {
                temp = temp->next;
            }
            /*Closing the 'circle'*/
            temp->next = new_node;
            new_node->prev = temp;
            new_node->next = *head;
            (*head)->prev = new_node;
        }
    } else {
        return;
    }
}

/**
Generates a linked list of Fibonacci numbers up to the given n.
@param head A pointer to a pointer to the head of the linked list.
@param n The number of Fibonacci numbers to generate.
@return 0 if successful, 1 if memory allocation failed.
*/
int create_fibonacci(Node **head, int n) {
    int long i, a,b,c;

    /* If n is 0, insert "1" into the list and return. */
    if (n == 0) {
        insert_node(head, 1);
        return 0;
    }

    /* If n is 1, insert "1" twice into the list and return. */
    if (n == 1) {
        insert_node(head, 1);
        insert_node(head, 1);
        return 0;
    }

    /* Insert "1" and "1" into the list to start the sequence. */
    insert_node(head, 1);
    insert_node(head, 1);
    a = 1;
    b = 1;

    /*Calculate the n fib' numbers*/
    for (i = 2; i < n; i++) {
        c = a + b;
        a = b;
        b = c;
        /*printf("fib number %lu is %lu\n", i, c);*/
        /*Insert the new number into the linked list*/
        insert_node(head, c);
    }
    /*If the head is null - error occurred while insert the new number into the list*/
    if (head == NULL)
        return 1;
    else
        return 0;
}

/**

Prints the contents of a linked list representing the Fibonacci sequence in reverse order.
@param head A pointer to the head of the linked list.
@param file_ptr A pointer to a file where the Fibonacci sequence will be printed.
@param n The length of the Fibonacci sequence to print.
*/
void print_list(Node **head, FILE *file_ptr, int n) {
    int i;
    unsigned long int current_node_value;
    Node *temp_node = *head;

    fprintf(file_ptr, "\nHere is all the %d numbers the sequence:\n", n);
    if (n != 0) {
        for (i = 0; i < n; i++) {
            /*Print all the number from the biggest to the lowest*/
            temp_node = temp_node->prev;
            current_node_value = temp_node->fib_value;

            /*Print to std*/
            printf("%lu\n", current_node_value);

            /*Print to file*/
            fprintf(file_ptr, "%lu \n", current_node_value);
        }
    } else {
        /*Print to std*/
        printf("%lu\n", temp_node->fib_value);

        /*Print to file*/
        fprintf(file_ptr, "%lu \n", temp_node->fib_value);
    }
}

/**

@brief Frees the memory allocated for a linked list of Node structs.
This function frees the memory allocated for a linked list of Node structs,
starting from the head node and traversing the list until the end node is reached.
*/
void free_list(Node *head) {
    Node *current = head;
    Node *next;

    while (current != NULL && current->prev != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

