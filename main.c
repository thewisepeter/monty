#include "monty.h"
#define MAX_LEN 1024

/**
 * main - monty
 * @argc: number of arguments
 * @argv: string with monty file
 *
 * Return: 0 (sucess)
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	stack_t *top = NULL;
	unsigned int line_number = 0;
	char data[MAX_LEN];
	bus_t bus = {NULL, NULL, NULL};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if(!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	bus.file = fp;

	while (fgets(data, MAX_LEN, fp) != NULL)
	{
		line_number++;
		bus.data = data;
		execute(bus.data, &top, line_number, fp);
	}
	free_stack(top);
	fclose(fp);

	return (0);
}
