#include "3-calc.h"
#include <stdlib.h>

/**
 * op_add - Returns the sum of a and b.
 * @a: first integer.
 * @b: second integer.
 * Return: Sum of a and b.
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - Returns the difference of a and b.
 * @a: first integer.
 * @b: second integer.
 * Return: Difference of a and b.
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - Returns the product of a and b.
 * @a: first integer.
 * @b: second integer.
 * Return: Product of a and b.
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - Returns the result of the division of a by b.
 * @a: first integer.
 * @b: second integer.
 * Return: Result of the division of a by b.
 */
int op_div(int a, int b)
{
	return (a / b);
}

/**
 * op_mod - Returns the remainder of the division of a by b.
 * @a: first integer.
 * @b: second integer.
 * Return: Remainder of the division of a by b.
 */
int op_mod(int a, int b)
{
	return (a % b);
}
