#include "main.h"

/**
 * _print_u - Prints an unsigned number
 * @types: Lists of arguments
 * @buffer: Buffer array that handle print
 * @flags: Calculates active flags
 * @width: width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters
 */
int _print_u(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);

num = _size_unsignd(num, size);

if (num == 0)
buffer[i--] = '0';

buffer[BUFF_SIZE - 1] = '\0';

while (num > 0)
{
buffer[i--] = (num % 10) + '0';
num /= 10;
}
i++;
return (type_unsgned(0, i, buffer, flags, width, precision, size));
}

/**
 * _print_o - prints an unsigned number in octal notation
 * @types: Lists of arguments
 * @buffer: Buffer array that handles print
 * @flags: Calculates active flags
 * @width: width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters
 */
int _print_o(va_list types, char buffer[],
int flags, int width, int precision, int size)
{

int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = num;

UNUSED(width);

num = _size_unsignd(num, size);

if (num == 0)
buffer[i--] = '0';
buffer[BUFF_SIZE - 1] = '\0';

while (num > 0)
{
buffer[i--] = (num % 8) + '0';
num /= 8;
}
if (flags & F_HASH && init_num != 0)
buffer[i--] = '0';

i++;

return (type_unsgned(0, i, buffer, flags, width, precision, size));
}

/**
 * _print_hexaD - Prints an unsigned number in hexadecimal notation
 * @types: Lists of arguments
 * @buffer: Buffer array that handles print
 * @flags: Calculates active flags
 * @width: width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters
 */
int _print_hexaD(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (_print_hex(types, "0123456789abcdef", buffer,
flags, 'x', width, precision, size));
}

/**
 * _print_hexaU - Prints an unsigned number in upper hexadecimal notation
 * @types: Lists of arguments
 * @buffer: Buffer array that handles print
 * @flags: Calculates active flags
 * @width: width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters
 */
int _print_hexaU(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (_print_hex(types, "0123456789ABCDEF", buffer,
flags, 'X', width, precision, size));
}

/**
 * _print_hex - Prints a hexadecimal number in lower or upper
 * @types: Lists of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array that handles print
 * @flags: Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: width
 * @precision: Precision specification
 * @size: Size of specifier
 * Return: Number of characters
 */
int _print_hex(va_list types, char map_to[], char buffer[],
int flags, char flag_ch, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = num;

UNUSED(width);

num = _size_unsignd(num, size);

if (num == 0)
buffer[i--] = '0';

buffer[BUFF_SIZE - 1] = '\0';

while (num > 0)
{
buffer[i--] = map_to[num % 16];
num /= 16;
}

if (flags & F_HASH && init_num != 0)
{
buffer[i--] = flag_ch;
buffer[i--] = '0';
}
i++;

return (type_unsgned(0, i, buffer, flags, width, precision, size));
}
