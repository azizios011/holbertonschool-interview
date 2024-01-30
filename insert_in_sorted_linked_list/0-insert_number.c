#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
* insert_node - a function in C that inserts a number into a sorted singly linked list.
* @head: is a double pointer on the lisiint_t.
* @number: is the nubmber that will being insert it.
* Return: the address of the 'new node', or 'NUL'L if it failed
*/
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new_node = malloc(sizeof(listint_t));

    if ( new_node == NULL)
    {
        return NULL;
    }

    new_node->n = number;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
    }

    else if (number <= (*head)-> n)
    {
        new_node->next = *head;
        *head = new_node;
    }

    else
    {
        listint_t * current = *head;

        while (current->next != NULL && current->next->n < number)
        {
            current = current->next;
        }

        new_node->next = current->next;
        current->next = new_node;
    }
    return new_node;
}
