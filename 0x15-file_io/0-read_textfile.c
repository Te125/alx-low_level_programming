#include "main.h"

/**
 * read_textfile - function that reads a text file
 * @filename: pointer to file
 * @letters: number of letters
 *
 * Return: 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	FILE *file;
	char buffer[1024];
	ssize_t total_letters_read = 0;
	size_t letters_read;

	if (filename == NULL)
	{
		fprintf(stderr, "Error: filename is NULL\n");
		return (0);
	}

	file = fopen(filename, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Failed to open file %s\n", filename);
		return (0);
	}

	while ((letters_read = fread(buffer, sizeof(char), sizeof(buffer), file)) > 0)
	{
		ssize_t bytes_written = write(STDOUT_FILENO, buffer, letters_read);

		if (bytes_written < 0 || (size_t)bytes_written != letters_read)
		{
			fclose(file);
			fprintf(stderr, "Error: Failed to write to stdout\n");
			return (0);
		}

		total_letters_read += letters_read;
		if (total_letters_read >= (ssize_t)letters)
			break;
	}

	fclose(file);
	return (total_letters_read);
}
