#include "monty.h"
#define MAX_CHAR 80

/* global variable <essential> make available in this file */
trackg_t essential;

/**
 * opcode_handler - call the right function to handle the corresponding opcode
 *
 * @opcode: the opcode to executed
 *
 * Return: nothing
 */
void opcode_handler(char *opcode)
{
	unsigned int idx;
	instruction_t oppcode_funcs[] = {
		{"pall", pall_opcode}, {"pint", pint_opcode}, {"pop", pop_opcode},
		{"swap", swap_opcode}, {"add", add_opcode}, {"nop", nop_opcode},
		{"sub", sub_opcode}, {"div", div_opcode}, {"mul", mul_opcode},
		{"mod", mod_opcode}, {"pchar", pchar_opcode}, {"pstr", pstr_opcode},
		{"rotl", rotl_opcode}, {"rotr", rotr_opcode}};

	for (idx = 0; idx < sizeof(oppcode_funcs) / sizeof(oppcode_funcs[0]); idx++)
	{
		if (_strcmp(opcode, oppcode_funcs[idx].opcode))
		{
			oppcode_funcs[idx].f(&essential.st_top, essential.line_num);
			return;
		}
	}

	dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n",
			essential.line_num, opcode);

	fclose(essential.fp);
	exit(EXIT_FAILURE);
}

/**
 * read_tok_run - reads the monty bytecode file line by line, tokenize it
 * and execute the instructions it founds
 *
 * @fp: file pointer, pointing to the open monty bytecode file in memory
 *
 * Return: nothing
 */
void read_tok_run(FILE *fp)
{
	char buffer[MAX_CHAR], *opcode, *num;
	char *endptr;
	char *push_oc = "push";

	essential.line_num = 0;
	essential.stack_size = 0;
	essential.st_top = NULL;
	essential.st_bottom = NULL;

	while (fgets(buffer, sizeof(buffer), fp))
	{
		essential.line_num++;
		opcode = strtok(buffer, " ");

		if (opcode[0] == '#' || opcode[0] == '\n')
			continue;

		if (_strcmp(push_oc, opcode))
		{
			num = strtok(NULL, " ");

			if (num == NULL || (strtol(num, &endptr, 10) == 0 && num == endptr))
			{
				dprintf(STDERR_FILENO, "L%u: usage: push integer\n", essential.line_num);
				fclose(fp);
				stack_free_all(essential.st_top);
				exit(EXIT_FAILURE);
			}

			essential.data = atoi(num);
			push_opcode(&essential.st_top, essential.line_num);
		}
		else
		{
			opcode_handler(opcode);
		}
	}
}

/**
 * main - entry point of the program
 *
 * @ac: number of arguments passed from the terminal
 * @av: pointer to the arguments passed to the program from
 *		the terminal
 *
 * description: reads and interpret byte code from a monty file
 *				with the extension .m from top to buttom
 *
 * Return: 0 for success 1 if any error occcure
 */
int main(int ac, char **av)
{
	FILE *fp;

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(av[1], "r");

	if (fp == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	essential.fp = fp;
	read_tok_run(essential.fp);

	stack_free_all(essential.st_top);
	fclose(fp);

	return (EXIT_SUCCESS);
}
