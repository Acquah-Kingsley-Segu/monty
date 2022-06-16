#ifndef MONTY_H
#define MONTY_H
/**
 * struct doubly_list - doubly linked list representation of stack (queue)
 * @data: integer to store
 * @prev: pointer to the previous node in the stack (or queue)
 * @next: pointer to the next node in the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queue, LIFO, FIFO
 */
typedef struct doubly_list
{
	int data;
	struct doubly_list* prev;
	struct doubly_list* next;	
} list;

/**
 * struct instruction - opcode and function performance
 * @opcode: command or action to perform
 * @f: function to perform opcode action
 *
 * Description: instruction to be performed on the stack or queue
 */
typedef struct instruction
{
	char *opcode;
	void (*f)(list **structure, unsigned int num);
} inst;

/* Funtion Prototypes */

extern void push(list **top, unsigned int data);
extern void pall(list **top, unsigned int);
extern void pint(list **top, unsigned int);
extern void pop(list **top, unsigned int);
extern void swap(list **top, unsigned int);
extern void add(list **top, unsigned int);
extern void nop(list **top, unsigned int);
extern void sub(list **top, unsigned int);
extern void _div(list **top, unsigned int);
extern void _mul(list **top, unsigned int);
extern void mod(list **top, unsigned int);
extern void pchar(list **top, unsigned int);
extern void pstr(list **top, unsigned int);
extern void rotl(list **top, unsigned int);
extern void rotr(list **top, unsigned int);

/* List of opcodes and their respective functions */

extern inst operations[2]; /* Opcode --> function */
extern int error_status; /* To check if an error took place */
#endif
