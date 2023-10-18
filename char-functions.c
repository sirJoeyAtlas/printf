#include "main.h"

/**
 * _print_c - prints a character
 * @types: Lists of arguments
 * @buffer: Buffer array that handles print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: size specifier
 * Return: Number of characters
 */
int _print_c(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (type_char(c, buffer, flags, width, precision, size));
}

/**
 * _print_s - Prints a string
 * @types: List a of arguments
 * @buffer: Buffer array that handles print
 * @flags:  Calculates active flags
 * @width: width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters
 */
int _print_s(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int length = 0, i;
char *str = va_arg(types, char *);

UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
if (str == NULL)
{
str = "(null)";
if (precision >= 6)
str = "      ";
}
while (str[length] != '\0')
length++;

if (precision >= 0 && precision < length)
length = precision;

if (width > length)
{
if (flags & F_MINUS)
{
write(1, &str[0], length);
for (i = width - length; i > 0; i--)
write(1, " ", 1);
return (width);
}
else
{
for (i = width - length; i > 0; i--)
write(1, " ", 1);
write(1, &str[0], length);
return (width);
}
}
return (write(1, str, length));
}

/**
 * _print_p - Prints a percent sign
 * @types: Lists of arguments
 * @buffer: Buffer array that handles print
 * @flags: Calculates active flags
 * @width: width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters
 */
int _print_p(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 * _print_integar - Prints integars
 * @types: Lists of arguments
 * @buffer: Buffer array that handles print
 * @flags: Calculates active flags
 * @width: width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters
 */
int _print_integar(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
int is_negative = 0;
long int n = va_arg(types, long int);
unsigned long int num;

n = _size_nom(n, size);

if (n == 0)
buffer[i--] = '0';

buffer[BUFF_SIZE - 1] = '\0';
num = (unsigned long int)n;

if (n < 0)
{
num = (unsigned long int)((-1) * n);
is_negative = 1;
}

while (num > 0)
{
buffer[i--] = (num % 10) + '0';
num /= 10;
}
i++;
return (type_num(is_negative, i, buffer, flags, width, precision, size));
}

/**
 * _print_b - Prints an unsigned number
 * @types: Lists of arguments
 * @buffer: Buffer array that handles print
 * @flags: Calculates active flags
 * @width: width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of character
 */
int _print_b(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
unsigned int v, w, x, sum;
unsigned int a[32];
int count;

UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);

v = va_arg(types, unsigned int);
w = 2147483648;
a[0] = v / w;
for (x = 1; x < 32; x++)
{
w /= 2;
a[x] = (v / w) % 2;
}
for (x = 0, sum = 0, count = 0; x < 32; x++)
{
sum += a[x];
if (sum || x == 31)
{
char z = '0' + a[x];
write(1, &z, 1);
count++;
}
}
return (count);
}
