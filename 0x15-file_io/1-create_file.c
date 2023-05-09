#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

/**
 * create_file - function that creates a file.
 * @filename: pointer to file
 * @text_content: pointer to the NULL
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd;

	if (filename == NULL)
	{
		fprintf(stderr, "Error: filename is NULL\n");
		return (-1);
	}

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

	if (fd == -1)
	{
		fprintf(stderr, "Error: Failed to create file %s\n", filename);
		return (-1);
	}

	if (text_content != NULL)
	{
		ssize_t bytes_written = write(fd, text_content, strlen(text_content));

		if (bytes_written == -1)
		{
			fprintf(stderr, "Error: Failed to write to file %s\n", filename);
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
