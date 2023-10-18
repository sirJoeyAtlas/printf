#include "main.h"

/**
 * c_print - is char printable
 * @s: Character.
 * Return: 1 if s is printable, 0 otherwise
 */
int c_print(char s)
{
if (s >= 32 && s < 127)
return (1);
return (0);
}

/**
 * hexa_code - hexadecimal code
 * @buffer: Array of chars.
 * @r: character
 * @ascii_c: ASSCI CODE.
 * Return: Always 3
 */
int hexa_code(char ascii_c, char buffer[], int r)
{
char map_to[] = "0123456789ABCDEF";

if (ascii_c < 0)
ascii_c *= -1;

buffer[r++] = '\\';
buffer[r++] = 'x';

buffer[r++] = map_to[ascii_c / 16];
buffer[r] = map_to[ascii_c % 16];

return (3);
}

/**
 * c_digit - The character is a digit
 * @w: Character
 * Return: 1 if w is a digit, 0 otherwise
 */
int c_digit(char w)
{
if (w >= '0' && w <= '9')
return (1);

return (0);
}

/**
 * _size_num - shows a number to the specified size
 * @nom: Number
 * @size: Number indicating the type to be casted.
 * Return: Casted value of nom
 */
long int _size_nom(long int nom, int size)
{
if (size == S_LONG)
return (nom);
else if (size == S_SHORT)
return ((short)nom);

return ((int)nom);
}

/**
 * _size_unsignd - Casts a number to the specified size
 * @nom: Number
 * @size: Number indicating the type to be casted
 * Return: Casted value of nom
 */
long int _size_unsignd(unsigned long int nom, int size)
{
if (size == S_LONG)
return (nom);
else if (size == S_SHORT)
return ((unsigned short)nom);

return ((unsigned int)nom);
}
