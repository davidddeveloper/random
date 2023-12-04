#include <stdio.h>
/**
 * str_len - calculates the length of a string
 * @str: the string
 *
 * Return: the length
 */

int str_len(char *str)
{
	int len = 0, counter;

	for (counter = 0; *str++ != '\0'; counter++)
		len++;
	for (counter = 0; counter <= len; counter++)
		*str--;

	return (len);
}
