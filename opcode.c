#include "monty.h"
#include <stdlib.h>

inst operations[16] = {
			{"push", &push},
			{"pall", &pall},
			{"pint", &pint},
			{"pop", &pop},
			{"swap", &swap},
			{"add", &add},
			{"nop", &nop},
			{"sub", &sub},
			{"div", &_div},
			{"mul", &_mul},
			{"div", &_div},
			{"mod", &mod},
			{"pchar", &pchar},
			{"pstr", &pstr},
			{"rotl", &rotl},
			{"rotr", &rotr}
		     };

int error_status = 0;
int data = 0;
