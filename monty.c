#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	FILE *f_ptr;
	list *top = malloc(sizeof(list));
	int line_num = 0;
	char *token;
	char str[10];
	int i, data;

	top->next = NULL;
	top->prev = NULL;
	f_ptr = fopen(argv[1], "r");
	if (f_ptr == NULL)
		printf("%s can't be opened.\n", argv[1]);
	while(fgets(str, 50, f_ptr) != NULL)
	{
		line_num++;
		token = strtok(str, " ");
		for (i = 0; i < 2; i++)
		{
			if (!strncmp(str, operations[i].opcode, 4))
			{
				if (!strncmp(str, "push", 4))
				{
					token = strtok(NULL, " ");
					if (token == NULL)
					{
						error_status = 1;
						operations[i].f(&top, line_num);
						continue;
					}
					data = line_num * 10 + atoi(token);
					operations[i].f(&top, (line_num * 10 + atoi(token)));
				}
				else
					operations[i].f(&top, line_num);
			}
		}
	}
	fclose(f_ptr);
}
