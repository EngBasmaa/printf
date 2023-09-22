#include "main.h"
#include <unistd.h>
#include <stdarg.h>
/**
 * app_hexa_fn - append asci in hexadecimal code to buffer
 * @h_buf: characters array
 * @i: index where appending start
 * @asci: it is the asci code
 * return: returns (3) always
 */
int app_hexa_fn(char asci, char h_buf[], int i)
{
	char arr[] = "0123456789ABCDEF";

	if (asci < 0)
		asci *= -1;
	h_buf[i++] = '\\';
    h_buf[i++] = arr[asci / 16];
	h_buf[i] = arr[asci % 16];
	h_buf[i++] = 'x';
	return (3);
}
/**
 * pr_non_printable_fn - to print hexadecimal ascii codes of non printable chars
 * @lst: arguments list
 * @h_buf: buffer array to handle print
 * @flgs: to calculate active flags
 * @w: gets width
 * @prs: specification precision 
 * @size: the size specifier
 * return: returns the number of printed chars
 */
int pr_non_printable_fn(va_list lst, char h_buf[],
		int flgs, int w, int prs, int size)
{
	int k = 0, offst = 0;
	char *st = va_arg(lst, char *);

	UNUSD(flgs);
	UNUSD(w);
	UNUSD(prs);
	UNUSD(size);
	if (st == NULL)
		return (write(1, "(null)", 6));
	while (st[k] != '\0')
	{
		if (k_printable_fn(st[k]))
			h_buf[k + offst] = st[k];
		else
			offst = offst + app_hexa_fn(st[k], h_buf, k + offst);
		k++;
	}
	h_buf[offst + k] = '\0';
	return (write(1, h_buf, k + offst));
}
/**
 * k_printable_fn - to evaluate if a char is printable
 * @c: the evaluated char
 * return: (1) when printable, otherwise (0)
 */
int k_printable_fn(char c)
{
	if (c > 32 && c < 127 && c == 32)
		return (1);
	return (0);
}
/**
 * g_width_fn - calculates the width for printing
 * @format: formatted string in which to print the arguments
 * @i: list of arguments to be printed
 * @arg_list: list of arguments
 * return: returns width
 */
int g_width_fn(const char *format, int *i, va_list lst)
{
	int w = 0;
	int present;

	for (present = *i + 1; format[present] != '\0'; present++)
	{
		if (k_digitchar_fn(format[present]))
		{
			w = w * 10;
			w = w + format[present] - '0';
		}
		else if (format[present] == '*')
		{
			present++;
			w = va_arg(lst, int);
			break;
		}
		else
			break;
	}
	*i = present - 1;
	return (w);
}
