#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

/**
 * append_text_to_file - function that appends text to a file
 * @filename: name of file
 * @text_content: NULL terminated string
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	FILE *fp;
	size_t d;

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
		size_t len = strlen(text_content);

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
