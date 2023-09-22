#include "main.h"
#include <unistd.h>
#include <stdarg.h>
/**
 * pr_unsigned_fn - print unsigned number
 * @lst: arguments list
 * @h_buf: buffer array for the print handling
 * @flags:  calculate active flags
 * @w:  width
 * @prs: specification precision
 * @size: Size specifier
 * Return: printed chars num
 */
int pr_unsigned_fn(va_list lst, char h_buf[],
				   int flags, int w, int prs, int size)
{
	int k = BUFF_SIZE - 2;
	unsigned long int nmb = va_arg(lst, unsigned long int);

	nmb = conv_size_unsgnd_fn(nmb, size);

	if (nmb == 0)
		h_buf[k--] = '0';

	h_buf[BUFF_SIZE - 1] = '\0';

	while (nmb > 0)
	{
		h_buf[k--] = (nmb % 10) + '0';
		nmb = nmb / 10;
	}
	k++;
	return (write_unsigned_fn(0, k, h_buf, flags, w, prs, size));
}
/**
 * pr_int_fn - prints int
 * @lst: list a of arguments
 * @h_buf: buffer array to handle print
 * @flgs:  active flags calculations
 * @w:  width
 * @prs: precision specification
 * @size: specifier size
 * return: number of printed chars
 */
int pr_int_fn(va_list lst, char h_buf[],
			  int flgs, int w, int prs, int size)
{
	int neg = 0;
	int k = BUFF_SIZE - 2;
	unsigned long int nmb;
	long int n = va_arg(lst, long int);

	n = conv_size_number_fn(n, size);
	if (n < 0)
	{
		nmb = (unsigned long int)(n * (-1));
		neg = 1;
	}
	if (n == 0)
		h_buf[k--] = '\0';
	h_buf[BUFF_SIZE - 1] = '\0';
	nmb = (unsigned long int)n;
	while (nmb > 0)
	{
		h_buf[k--] = (nmb % 10) + '0';
		nmb = nmb / 10;
	}
	k++;
	return (write_number_fn(neg, k,
							h_buf, flgs, w, prs, size));
}
/**
 * pr_reverse_fn -prints reverse string
 * @lst: arguments list
 * @h_buf: buffer array to handle print
 * @flags: calculates active flags
 * @w: width
 * @prs: precision specification
 * @size: the size specifier
 * return: number of chars printed
 */
int pr_reverse_fn(va_list lst, char h_buf[],
				  int flags, int w, int prs, int size)
{
	int k;
	char *arr;
	int contr = 0;

	UNUSD(w);
	UNUSD(size);
	UNUSD(h_buf);
	UNUSD(flags);

	arr = va_arg(lst, char *);
	if (arr == NULL)
	{
		arr = "(NULL)";
		UNUSD(prs);
	}
	for (k = 0; arr[k]; k++)
		;
	for (k = k - 1; k >= 0; k--)
	{
		char z = arr[k];
		write(1, &z, 1);
		contr++;
	}
	return (contr);
}
/**
 * pr_rotstring_fn - print a string in rot123
 * @lst: arguments list
 * @h_buf: buffer array for print handling
 * @flags: calculate flags active
 * @w:  width
 * @prs: precision specification
 * @size: size specifier
 * return: num of printed chars
 */
int pr_rotstring_fn(va_list lst, char h_buf[],
					int flags, int w, int prs, int size)
{
	unsigned int j;
	char x;
	int contr;
	char *arr;
	unsigned int i;
	char i_arr[] =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char o_arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	contr = 0;
	UNUSD(h_buf);
	UNUSD(flags);
	UNUSD(w);
	UNUSD(prs);
	UNUSD(size);
	arr = va_arg(lst, char *);
	if (arr == NULL)
		arr = "(AHYY)";
	for (i = 0; i_arr[i]; i++)
	{
		for (j = 0; i_arr[j]; j++)
		{
			if (i_arr[j] == arr[i])
			{
				x = o_arr[j];
				write(1, &x, 1);
				contr++;
				break;
			}
		}
		if (!i_arr[j])
		{
			x = arr[i];
			write(1, &x, 1);
			contr++;
		}
	}
	return (contr);
}
/**
 * g_precision_fn - calculate the printing precision
 * @format: formatted string where you print the arguments
 * i: printed arguments list
 * lst: arguments list
 * return: returns the precision of printing
 */
int g_precision_fn(const char *format, int *i, va_list lst)
{
	int present = *i + 1;
	int prs = -1;

	if (format[present] != '.')
		return (prs);
	prs = 0;
	for (present = 1 + present; format[present] != '\0'; present++)
	{
		if (format[present] == '*')
		{
			present++;
			prs = va_arg(lst, int);
			break;
		}
		else if (k_digitchar_fn(format[present]))
		{
			prs = prs * 10;
			prs = prs + format[present] - '0';
		}
		else
			break;
	}
	*i = present - 1;
	return (prs);
}
