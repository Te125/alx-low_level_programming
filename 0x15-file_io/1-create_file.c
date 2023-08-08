#include "main.h"

/**
 * create_file - function that creates a file
 * @filename: pointer to point to the text
 * @text_content: pointer to string content
 *
 * Return: On success 1, On failure -1
 */
int create_file(const char *filename, char *text_content)
{
	int fp;
	ssize_t d;
	size_t len;
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
		len = strlen(text_content);
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
