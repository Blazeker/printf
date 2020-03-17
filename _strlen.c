#include "holberton.h"

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
