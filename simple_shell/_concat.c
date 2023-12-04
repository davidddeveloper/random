#include "main.h"

/**
 * main - concatenates two strings
 *
 * Return: 0 always
 */
int main(void)
{
	char *a = "hey";
	char *b = "there";
	char *ptr = a;
	//move pointer to the end
	while (*a != '\0')
		a++;

	//append b to a
	while (*b != '\0')
	{
		*a = *b;
		b++;
		a++;
	}

	//null terminate string
	*b = '\0';

	
	return (0);
}
