#include "shell.h"


/**
 * _strcmp -print
 * @s1: pointer
 * @s2: pointer
 * Return: 1 si c'est Ãgale et faux si c'est 0
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}