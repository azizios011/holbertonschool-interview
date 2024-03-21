#include "lists.h"

/**
 * is_palindrome - Checks if a linked list is a palindrome
 * @head: Double pointer to the head of the linked list
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow = *head, *fast = *head, *second_half = NULL;
	listint_t *prev_slow = *head;
	listint_t *mid_node = NULL;
	int is_palindrome = 1;

	if (*head != NULL && (*head)->next != NULL)
	{
		while (fast != NULL && fast->next != NULL)
		{
			fast = fast->next->next;
			prev_slow = slow;
			slow = slow->next;
		}

		if (fast != NULL)
		{
			mid_node = slow;
			slow = slow->next;
		}

		second_half = slow;
		prev_slow->next = NULL;
		second_half = reverse_list(&second_half);

		is_palindrome = compare_lists(*head, second_half);

		second_half = reverse_list(&second_half);

		if (mid_node != NULL)
		{
			prev_slow->next = mid_node;
			mid_node->next = second_half;
		}
		else
			prev_slow->next = second_half;
	}
	return (is_palindrome);
}

/**
 * reverse_list - Reverses a linked list
 * @head: Pointer to pointer of the head of the list
 * Return: Pointer to the new head of the reversed list
 */
listint_t *reverse_list(listint_t **head)
{
	listint_t *prev = NULL, *next = NULL, *current = *head;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	*head = prev;
	return (*head);
}

/**
 * compare_lists - Compares two linked lists
 * @head1: Pointer to the head of the first linked list
 * @head2: Pointer to the head of the second linked list
 * Return: 1 if both lists are equal, 0 otherwise
 */
int compare_lists(listint_t *head1, listint_t *head2)
{
	listint_t *temp1 = head1;
	listint_t *temp2 = head2;

	while (temp1 && temp2)
	{
		if (temp1->n == temp2->n)
		{
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		else
			return (0);
	}

	if (temp1 == NULL && temp2 == NULL)
		return (1);

	return (0);
}
