#include <stdlib.h>
#include <string.h>
/**
 * argstostr - funcion that concatenates all arguments
 * @ac: int
 * @av: pointer to pointer array
 *
 * Return: 0.
 */

char *argstostr(int ac, char **av)
{
	int i, j, len = 0, k = 0;
	char *str;

	if (ac == 0 || av == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < ac; i++)
	{
		len += strlen(av[i]) + 1;
	}

	str = malloc(sizeof(char) * len);

	if (str == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
		{
			str[k++] = av[i][j];
		}
		str[k++] = '\n';
	}

	str[k] = '\0';

	return (str);
}
