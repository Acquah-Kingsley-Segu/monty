#include "monty.h"
#include <stdlib.h>

inst operations[2] = {
			{"push", &push},
			{"pall", &pall}	
		     };

char *token = " ";
int error_status = 0;
