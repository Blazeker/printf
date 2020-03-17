#include "holberton.h"
/**
 * rev_string - isdigit
 * @s: integer
 * Return: prints alphabet
*/
void rev_string(char *s)
{
	int i = 0;
	int len = 0;
	char save = 0;
	int final = 0;

	for (i = 0; s[i] != '\0'; i++)
		len++;
	final = len - 1;

	for (i = final; i >= (final - i); i--)
	{
		save = s[(final - i)];
		s[(final - i)] = s[i];
		s[i] = save;
	}
}
/**
 * is_neg - isneg
 * @num: integer
 * Return: an int
*/
int is_neg(long int num)
{
	if (num < 0)
		return (-1);
	return (1);
}
/**
 * _itos - isdigit
 * @num: integer
 * @string: an pointer
 * @cont: an int
 * @sign: an int
*/
void _itos(long int num, char *string, int cont, int sign)
{
	if (num == 0)
	{
		if (sign == -1)
		{
			string[0] = '-';
			string[1] = '\0';
		}
		else
			string[0] = '\0';
		rev_string(string - cont);
	}
	else
	{
		string[0] = (num % 10) + '0';
		num /= 10;
		_itos(num, string + 1, cont + 1, sign);
	}
}
