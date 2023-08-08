#include "main.h"

/**
 * append_text_to_file - function that appends a text at the end of a file.
 * @filename: name of the file
 * @text_content: NULL terminated string to add at the end of the file
 *
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	FILE *fp;
	size_t d, len;

	if (filename == NULL)
	{
		return (-1);
	}
	fp = fopen(filename, "a");
	if (fp == NULL)
	{
		return (-1);
	}
	if (text_content != NULL)
	{
		len = strlen(text_content);
		d = fwrite(text_content, sizeof(char), len, fp);

		if (d != len)
		{
			fclose(fp);
			return (-1);
		}
	}
	fclose(fp);
	return (1);
}
