#include "monty.h"

bus_t bus = {NULL, NULL, NULL};
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
	size_t size;
	ssize_t nchars_read = 1;
	stack_t *top = NULL;
	unsigned int line_number = 0;
	char *data = NULL;

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
	while (nchars_read > 0)
	{
		nchars_read = getline(&data, &size, fp);
		bus.data = data;
		line_number++;
		if (nchars_read > 0)
		{
			/* functions come in here */
		}
	}
	fclose(fp);

	return (0);
}
