#include "main.h"
/**
 * app_hexa_fn - append asci in hexadecimal code to buffer
 * @h_buf: characters array
 * @i: index where appending start
 * @asci: it is the asci code
 * Return: returns (3) always
 */
int app_hexa_fn(char asci, char h_buf[], int i)
{
	char arr[] = "0123456789ABCDEF";

	if (asci < 0)
		asci = asci * (-1);
	h_buf[i++] = '\\';
	h_buf[i++] = 'x';
	h_buf[i++] = arr[asci / 16];
	h_buf[i] = arr[asci % 16];
	return (3);
}
/**
 * g_width_fn - calculates the width for printing
 * @format: formatted string in which to print the arguments
 * @i: list of arguments to be printed
 * @lst: list of arguments
 * Return: returns width
 */
int g_width_fn(const char *format, int *i, va_list lst)
{
	int present, w = 0;

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
