#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - coordinates the workflow of the program
 * @argc: number of arguments passed to function call
 * @argv: list of argument passed
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	FILE *f_ptr;
	list *top = malloc(sizeof(list));
	int line_num = 0;
	char *token;
	char str[10];
	int i, data = 0;

	top->next = NULL;
	top->prev = NULL;
	if (argc < 2)
	{
		printf("A bytecode file must be passed.\n");
		exit(EXIT_FAILURE);
	}
	f_ptr = fopen(argv[1], "r");
	if (f_ptr == NULL)
		printf("%s can't be opened.\n", argv[1]);
	while (fgets(str, 50, f_ptr) != NULL)
	{
		line_num++;
		token = strtok(str, " ");
		/*op_len = strlen(token);*/
		for (i = 0; i < 16; i++)
		{
			if (!strncmp(str, operations[i].opcode, 4))
			{
				token = strtok(NULL, " ");
				if (!strncmp(str, "push", 4))
				{
					if (token == NULL)
					{
						error_status = 1;
						operations[i].f(&top, line_num);
					}
					data = line_num * 10 + atoi(token);
					operations[i].f(&top, data);
				}
				else
				{
					operations[i].f(&top, line_num);
				}
			}
		}
	}
	fclose(f_ptr);

	return (0);
}
