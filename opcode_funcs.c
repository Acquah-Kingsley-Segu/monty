#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * push - add a data to the stack
 * @top: pointer to top pointer in stack
 * @line_num: line from which read was made
 *
 */
void push(list **top, unsigned int line_num)
{
        list *node = malloc(sizeof(list));

        if (top == NULL || *top == NULL)
                return;
	if (error_status == 1)
	{
		printf("L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}
        node->data = data;
        node->next = NULL;
        node->prev = *top;
        (*top)->next = node;
        *top = node;
}

/**
 * pall - prints all the items in a list
 * @top: pointer to top pointer of a stack
 * @line_num: line from which read was made
 */
void pall(list **top, unsigned int line_num)
{
        list *trav = malloc(sizeof(list));

        if (top == NULL)
	{
		printf("L%d: usage: pass a top pointer\n", line_num);
                exit(EXIT_FAILURE);
	}
        if (trav == NULL)
                return;
        trav = *top;
        while (trav->prev != NULL)
        {
                printf("%d\n", trav->data);
                trav = trav->prev;
        }
}

/**
 * pint - prints element at top of stack
 * @top: pointer to the top pointer of the stack
 * @line_num: line from which read was made
 */
void pint(list **top, unsigned int line_num)
{
	if (top == NULL || *top == NULL)
	{
		printf("L%u: can't pint, stack is empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*top)->data);
}

/**
 * pop - removes the element at the top of the stack
 * @top: pointer to the top pointer of the stack
 * @line_num: line from which read was made
 */
void pop(list **top, unsigned int line_num)
{
	list *trav;
	if (top == NULL || *top == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}
	trav = *top;
	*top = (*top)->prev;
	free(trav);
}

/**
 * swap - swaps the top two elements in a stack
 * @top: pointer to the top pointer of a stack
 * @line_num: line from which read was made
 */
void swap(list **top, unsigned int line_num)
{
	list *trav;
	int temp = 0;

	if (top == NULL || *top == NULL)
		exit(EXIT_FAILURE);
	trav = *top;
	while (trav != NULL)
	{
		temp++;
		trav = trav->prev;
	}
	if (temp < 2)
	{
		printf("L%u: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	temp = (*top)->data;
	(*top)->data = (*top)->prev->data;
	(*top)->prev->data = temp; 
}

/** 
 * add - adds the top two elements in the stack and insert in the second top
 * @top: pointermto the top pointer of a stack
 * @line_num: line from which read was made
 */
void add(list **top, unsigned int line_num)
{
	list *trav;
	int size = 0;

	if (top == NULL || *top == NULL)
		exit(EXIT_FAILURE);
	trav = *top;
	while (trav != NULL)
	{
		size++;
		trav = trav->prev;
	}
	if (size < 2)
	{
		printf("L%u: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	(*top)->prev->data = (*top)->prev->data + (*top)->data;
	pop(&(*top), line_num);
}

/**
 * nop - does nothing
 * @top: pointer to head pointer
 * @line_num: line from which read was made
 */
void nop(list **top, unsigned int line_num)
{
	if (top == NULL)
		exit(EXIT_FAILURE);
	exit((line_num));
}

/**
 * sub - substracts top from second top element and store in second top element
 * @top: pointer to top pointer of the stack
 * @line_num: line from which read was made
 */
void sub(list **top, unsigned int line_num)
{
	list *trav;
	int size = 0;

	if (top == NULL || *top == NULL)
		exit(EXIT_FAILURE);
	trav = *top;
	while (trav != NULL)
	{
		size++;
		trav = trav->prev;
	}
	if (size < 2)
	{
		printf("L%u: can't sub, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	(*top)->prev->data = (*top)->prev->data - (*top)->data;
	pop(&(*top), line_num);
}

/**
 * div - divides second top element with top element and store in second
 * @top: pointer to the top pointer of a stack
 * @line_num: line from which read was made
 */
void _div(list **top, unsigned int line_num)
{
	list *trav;
	int size = 0;

	if (top == NULL || *top == NULL)
		exit(EXIT_FAILURE);
	trav = *top;
	while (trav != NULL)
	{
		size++;
		trav = trav->prev;
	}
	if (size < 2)
	{
		printf("L%u: can't div, stack too short\n", (line_num / 10));
		exit(EXIT_FAILURE);
	}
	if ((*top)->data == 0)
	{
		printf("L%u: division by zero", line_num);
		exit(EXIT_FAILURE);
	}
	(*top)->prev->data /= (*top)->data;
	pop(&(*top), line_num);
}

/**
 * mul - multiples second top element with the top element of stack
 * @top: pointer to the top pointer of the stack
 * @line_num: line from which read was made
 */
void _mul(list **top, unsigned int line_num)
{
	list *trav;
	int size = 0;

	if (top == NULL || *top == NULL)
		exit(EXIT_FAILURE);
	trav = *top;
	while (trav != NULL)
	{
		size++;
		trav = trav->prev;
	}
	if (size < 2)
	{
		printf("L%u: can't mul, stack too short\n", (line_num / 10));
		exit(EXIT_FAILURE);
	}
	(*top)->prev->data *= (*top)->data;
	pop(&(*top), 1);
}

/**
 * mul - multiples second top element with the top element of stack
 * @top: pointer to the top pointer of the stack
 * @line_num: line from which read was made
 */
void mod(list **top, unsigned int line_num)
{
	list *trav;
	int size = 0;

	if (top == NULL || *top == NULL)
		exit(EXIT_FAILURE);
	trav = *top;
	while (trav != NULL)
	{
		size++;
		trav = trav->prev;
	}
	if (size < 2)
	{
		printf("L%u: can't mod, stack too short\n", (line_num / 10));
		exit(EXIT_FAILURE);
	}
	if ((*top)->data == 0)
	{
		printf("L%u: division by zero", (line_num / 10));
		exit(EXIT_FAILURE);
	}
	(*top)->prev->data %= (*top)->data;
	pop(&(*top), 1);
}

/**
 * pchar - print the char at the top of the stack
 * @top: pointer to the top pointer of the stack
 * @line_num: line from which read was made
 */
void pchar(list **top, unsigned int line_num)
{
	if (top == NULL || *top == NULL)
	{
		printf("L%u: can't pchar, stack empty\n", (line_num / 10));
		exit(EXIT_FAILURE);
	}
	if ((*top)->data < 0 || (*top)->data > 127)
	{
		printf("L%u: can't pchar, value out of range\n", (line_num / 10));
		exit(EXIT_FAILURE);
	}
	fputc((*top)->data, stdout);
	fputc('\n', stdout);
}

/**
 * pstr - prints the string starting at the top of the stack
 *	  stops if 0 or number > 127
 * @top: pointer to the top pointer of the list
 * @line_num: line from which read was made
 */
void pstr(list **top, unsigned int line_num)
{
	list *trav;

	if (top == NULL)
		exit(line_num - line_num);
	if (*top == NULL)
		fputc('\n', stdout);
	trav = *top;
	while (trav != NULL)
	{
		if (trav->data <= 0 || trav->data > 127)
		{
			break;
		}
		fputc(trav->data, stdout);
		trav = trav->prev;
	}
	fputc('\n', stdout);
}

/**
 * rotl - rotates the stack to the top (in the left direction)
 * @top: pointer to the pointer of the stack
 */
void rotl(list **top, unsigned int line_num)
{
	list *trav = *top;
	int temp = (*top)->data;

	if (top == NULL || *top == NULL)
	{
		printf("L%u: can't rotl, stack empty\n", (line_num / 10));
		exit(EXIT_FAILURE);
	}
	while (trav->prev != NULL)
	{
		trav->data = (trav->prev)->data;
		trav = trav->prev;
	}
	trav->data = temp;
}

/**
 * rotr - rotates the stack to the bottom (in the right direction)
 * @top: pointer to the pointer of the structure
 * @line_num: line from which read was made
 */
void rotr(list **top, unsigned int line_num)
{
	list *trav = *top;
	int temp;

	if (top == NULL || *top == NULL)
	{
		printf("L%u: can't rotr, stack empty\n", (line_num / 10));
		exit(EXIT_FAILURE);
	}
	while (trav->prev != NULL)
		trav = trav->prev;
	temp = trav->next->data;
	while (trav->next != NULL)
	{
		trav->data = trav->next->data;
		trav = trav->next;
	}
	trav->data = temp;
}
