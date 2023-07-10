#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

/**
 * create_file - function that creates a file
 * @filename: name of the file to create
 * @text_content: NULL terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fp;
	ssize_t d;
	mode_t p = S_IRUSR | S_IWUSR;

	if (filename == NULL)
	{
		return (-1);
	}

	fp = open(filename, O_WRONLY | O_CREAT | O_TRUNC, p);
	if (fp == -1)
	{
		perror("Error creating the file");
		return (-1);
	}

	if (text_content != NULL)
	{
		size_t len = strlen(text_content);

		d = write(fp, text_content, len);
		if (d == -1 || (size_t)d != len)
		{
			perror("Error writing to the file");
			close(fp);
			return (-1);
		}
	}

	if (close(fp) == -1)
	{
		perror("Error closing the file");
		return (-1);
	}

	return (1);
}
