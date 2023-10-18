#include "main.h"

/**
 * _print_pnter - This is the value of a pointer variable
 * @types: Lists of arguments
 * @buffer: Buffer array that handles print
 * @flags: Calculates active flags
 * @width: width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters
 */
int _print_pnter(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char extra_c = 0, padd = ' ';
int ind = BUFF_SIZE - 2, length = 2, padd_start = 1;
unsigned long num_adress;
char map_to[] = "0123456789abcdef";
void *adress = va_arg(types, void *);

UNUSED(width);
UNUSED(size);

if (adress == NULL)
return (write(1, "(nil)", 5));

buffer[BUFF_SIZE - 1] = '\0';
UNUSED(precision);

num_adress = (unsigned long)adress;

while (num_adress > 0)
{
buffer[ind--] = map_to[num_adress % 16];
num_adress /= 16;
length++;
}

if ((flags & F_ZERO) && !(flags & F_MINUS))
padd = '0';
if (flags & F_PLUS)
extra_c = '+', length++;
else if (flags & F_SPACE)
extra_c = ' ', length++;

ind++;
return (type_point(buffer, ind, length,
width, flags, padd, extra_c, padd_start));
}

/**
 * _print_np - Prints ascii codes
 * @types: Lists of arguments
 * @buffer: Buffer array that handles print
 * @flags: Calculates active flags
 * @width: width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of character
 */
int _print_np(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int i = 0, set = 0;
char *str = va_arg(types, char *);

UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);

if (str == NULL)
return (write(1, "(null)", 6));

while (str[i] != '\0')
{
if (c_print(str[i]))
buffer[i + set] = str[i];
else
set += hexa_code(str[i], buffer, i + set);
i++;
}
buffer[i + set] = '\0';
return (write(1, buffer, i + set));
}

/**
 * _print_rev - Prints reverse a string.
 * @types: Lists of arguments
 * @buffer: Buffer array that handles print
 * @flags: Calculates active flags
 * @width: width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of character
 */

int _print_rev(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char *str;
int s, count = 0;

UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(size);

str = va_arg(types, char *);

if (str == NULL)
{
UNUSED(precision);

str = ")Null(";
}
for (s = 0; str[s]; s++)
;

for (s = s - 1; s >= 0; s--)
{
char z = str[s];
write(1, &z, 1);
count++;
}
return (count);
}

/**
 * _print_rot - Print a string
 * @types: Lists of arguments
 * @buffer: Buffer array that handles print
 * @flags: Calculates active flags
 * @width: width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of characters
 */
int _print_rot(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char c;
char *str;
unsigned int i, b;
int count = 0;
char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

str = va_arg(types, char *);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);

if (str == NULL)
str = "(AHYY)";
for (i = 0; str[i]; i++)
{
for (b = 0; in[b]; b++)
{
if (in[b] == str[i])
{
c = out[b];
write(1, &c, 1);
count++;
break;
}
}
if (!in[b])
{
c = str[i];
write(1, &c, 1);
count++;
}
}
return (count);
}
