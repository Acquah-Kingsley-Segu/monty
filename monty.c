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
	int i, error = 1, data = 0;

	top->next = NULL;
	top->prev = NULL;
	if (argc < 2)
	{
		fwrite("USAGE: monty file\n", 1, 18, stderr);
		exit(EXIT_FAILURE);
	}
	f_ptr = fopen(argv[1], "r");
	if (f_ptr == NULL)
	{
		fwrite("Error: Can't open file ", 1, 24, stderr);
		fwrite(argv[1], 1, strlen(argv[1]), stderr);
		fwrite("\n", 1, 1, stderr);
		exit(EXIT_FAILURE);
	}
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
				error = 0;
			}
		}
		if (error)
		{
			fwrite("L", 1, 1, stderr);
			fwrite(":unknown instruction ", 1, 21, stderr);
			fwrite(token, 1, strlen(token), stderr);
			fwrite("\n", 1, 1, stderr);
			exit(EXIT_FAILURE);
		}
	}
	fclose(f_ptr);

	return (0);
}
