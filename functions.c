#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include "holberton.h"
/**
*case_d - print the decimal format
*@p : int
*Return: the number of elements printed
*/
int case_d(long int p)
{
	char buffer[20];
	int cont = 0;

	if (p == INT_MIN)
	{
		p *= -1;
		_itos(p * is_neg(p), buffer, cont, -1);
		write(1, buffer, _strlen(buffer));
		return (_strlen(buffer));
	}
	else
	{
		_itos(p * is_neg(p), buffer, cont, is_neg(p));
		write(1, buffer, _strlen(buffer));
		return (_strlen(buffer));
	}

}
/**
* case_s - Print the string format
*@f : String coming
*Return: the number of elements printed
*/
int case_s(char *f)
{
	char *g = "(null)";

	if (f == 0)
	{
		write(1, g, 6);
		return (6);
	}
	write(1, f, _strlen(f));
	return (_strlen(f));
}
/**
* case_b - Print the string format
*@f : String coming
*Return: the number of elements printed
*/
int case_b(long int p)
{
	char *g = "0";
	int num;

	num = dec_to_bin(p);
	if (num == 0)
	{
		write(1, g, 1);
		return (1);
	}
	return (num);
}
/**
*switche_int - Switch of all the format numbers
*@c : A char
*@args : the int arguments
*Return: the number of elements printed
*/
int switche_int(char c, int args)
{
	long int p = 0;
	char x;

	switch (c)
	{
	case 'd':
		p = args;
		return (case_d(p));
	case 'i':
		p = args;
		return (case_d(p));
	case 'c':
		x = args;
		write(1, &x, 1);
		return (1);
	case 'b':
		p = args;
		return (case_b(p));
	default:
		exit(2);
	}
}
/**
*switche_string - The switch for the strings
*@c : A char
*@args : a pointer
*Return: the number of elements printed
*/
int switche_string(char c, char *args)
{
	char *f;

	switch (c)
	{
	case 's':
		f = args;
		return (case_s(f));
	default:
		exit(2);
	}
}
