#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include "holberton.h"
/**
* case_r - Print the string format
*@f : String coming
*Return: the number of elements printed
*/
int case_r(char *f)
{
	char *g = "(null)";

	if (f == 0)
	{
		write(1, g, 6);
		return (6);
	}
	rev_string(f);
	write(1, f, _strlen(f));
	return (_strlen(f));
}
/**
 * _strlen - A function to count the lenght of an array
 * @s : array
 * Return: an int of the lenght of an array
 */

int _strlen(char *s)
{
	int m = 0;
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		m = m + 1;
	}
	return (m);
}
/**
 * dec_to_bin - A function to count the lenght of an array
 * @n : integer
 * Return: string to string of binary
 */

int dec_to_bin(long int n)
{
	int c = 0, d = 0, count = 0, i = 0, j = 0, flag = 0;
	char *string;

	count = 0;
	string = malloc(32 + 1);
	if (string == NULL)
		exit(1);

	for (c = 31; c >= 0; c--)
	{
		d = n >> c;

		if (d & 1)
			*(string + count) = 1 + '0';
		else
			*(string + count) = 0 + '0';

		count++;
	}
	*(string + count) = '\0';
	for (i = 0; string[i]; i++)
	{
		if (string[i] == '1')
			flag = 1;
		if (flag == 1)
		{
			write(1, &string[i], 1);
			j++;
		}
	}
	free(string);
	return (j);
}
