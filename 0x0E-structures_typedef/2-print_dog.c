#include <stdio.h>
#include "dog.h"
#include <stdlib.h>

/**
 * print_dog - Prints a struct dog.
 * @d: A pointer to the struct dog to print.
 *
 * Return: Nothing.
 */
void print_dog(struct dog *d)
{
	if (d == NULL)
		return;

	printf("Name: %s\n", d->name != NULL ? d->name : "(nil)");
	printf("Age: %f\n", d->age);
	printf("Owner: %s\n", d->owner != NULL ? d->owner : "(nil)");
}
