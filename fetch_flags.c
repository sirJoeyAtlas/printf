#include "main.h"

/**
 * fetch_flags - active flags
 * @format: Formatted strings
 * @e: take a parameter.
 * Return: Flags
 */
int fetch_flags(const char *format, int *e)
{
int a, cur_f;
int flags = 0;
const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

for (cur_f = *e + 1; format[cur_f] != '\0'; cur_f++)
{
for (a = 0; FLAGS_CH[a] != '\0'; a++)
if (format[cur_f] == FLAGS_CH[a])
{
flags |= FLAGS_ARR[a];
break;
}

if (FLAGS_CH[a] == 0)
break;
}

*e = cur_f - 1;

return (flags);
}
