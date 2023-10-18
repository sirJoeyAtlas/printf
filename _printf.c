#include "main.h"

void _print_buff(char buffer[], int *buff_ins);

/**
 * _printf - This is the printf function
 * @format: This is the format.
 * Return: 0
 */
int _printf(const char *format, ...)
{
int i, printed = 0, printed_chars = 0;
int flags, width, precision, size, buff_ins = 0;
va_list list;
char buffer[BUFF_SIZE];

if (format == NULL)
return (-1);

va_start(list, format);

for (i = 0; format && format[i] != '\0'; i++)
{
if (format[i] != '%')
{
buffer[buff_ins++] = format[i];
if (buff_ins == BUFF_SIZE)
_print_buff(buffer, &buff_ins);

printed_chars++;
}
else
{
_print_buff(buffer, &buff_ins);
flags = fetch_flags(format, &i);
width = fetch_width(format, &i, list);
precision = fetch_precision(format, &i, list);
size = fetch_size(format, &i);
++i;
printed = _form_print(format, &i, list, buffer,
flags, width, precision, size);
if (printed == -1)
return (-1);
printed_chars += printed;
}
}
_print_buff(buffer, &buff_ins);
va_end(list);
return (printed_chars);
}

/**
 * _print_buff - It should print all the contents of the buffer
 * @buffer: An array of characters
 * @buff_ins: Index at which to add next char, represents the length.
 */
void _print_buff(char buffer[], int *buff_ins)
{
if (*buff_ins > 0)
write(1, &buffer[0], *buff_ins);
*buff_ins = 0;
}
