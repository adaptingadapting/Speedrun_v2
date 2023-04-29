#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: stack to push an element into
 * @line_number: line number for error handling
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *number = NULL;
	stack_t *node = NULL;
	size_t i;

	number = strtok(NULL, delims);
	if (!number)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(1);
	}
	for (i = 0; number[i]; i++)
	{
		if (i == 0 && number[i] == '-')
			continue;
		if (number[i] > '9' || number[i] < '0')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(1);
		}
	}
	node = malloc(sizeof(stack_t));
	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(1);
	}
	node->n = atoi(number);
	node->prev= NULL;
	node->next = *stack;
	if (*stack)
	{
		(*stack)->prev = node;
	}
	*stack = node;
	return;
}

/**
 * pall - prints all in the stack
 * @stack: stack to be printed
 * @line_number: line number for error handling
 */

void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next; 
	}
	return;
}

/**
 * pint - prins the value at the top of the stack
 * @stack: stack to execute function on
 * @line_number: line number for error handling
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr,"L%u: can't pint, stack empty\n", line_number);
		exit(1);
	}
	printf("%d\n", (*stack)->n);
	return;
}

/**
 * pop - removes the top element of the stack
 * @stack: stack to remove the top element from
 * @line_number: line number for error handling
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	
  	if (!(*stack))
	{
		fprintf(stderr,"L%u: can't pop an empty stack\n", line_number);
		exit(1);
	}
	temp = (*stack)->next;
	free((*stack));
	*stack = temp;
	return;
}

/**
 * swap - swaps the frist two elements of the stack
 * @stack: stack to swap the two elements from
 * @line_number: line number for error handling
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	
	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u can't swap, stack too short", line_number);
		exit(1);
	}
	temp = (*stack)->next;
	(*stack)->prev = temp;
	(*stack)->next = temp->next;
	temp->prev = NULL;
	temp->next = *stack;
	*stack = temp;
	return;
}

/**
 * add - adds the first two elemnts of the stack
 * @stack: stack whose first two elements are to be added
 * @line_number: line number for erorr handling
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	
	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short", line_number);
		exit(1);
	}
	(*stack)->next->n += (*stack)->n;
	temp = (*stack)->next;
	free((*stack));
	*stack = temp;
	return;
}

/**
 * nop - does nothing
 * @stack: unused
 * @line_number: unused
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	return;
}
