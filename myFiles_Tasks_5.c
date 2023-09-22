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

	nmb = convert_size_unsgnd(nmb, size);

	if (nmb == 0)
		h_buf[i--] = '0';

	h_buf[BUFF_SIZE - 1] = '\0';

	while (nmb > 0)
	{
		h_buf[i--] = (nmb % 10) + '0';
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
	if (n == 0)
		h_buf[i--] = '\0';
	nmb = (unsigned long int)n;
	while (nmb > 0)
	{
		h_buf[k--] = (nmb % 10) + '0';
		nmb = nmb / 10;
	}
	if (n < 0)
	{
		nmb = (unsigned long int)((-1) * n);
		neg = 1;
	}
	
	k++;
	return (write_number_fn(neg, k,
				h_buf, flgs, w, prs, size));
}
/**
 * pr_reverse_fn -prints reverse string
 * @lst: arguments list
 * @h_buf: buffer array to handle print
 * @flgs: calculates active flags
 * @w: gets width
 * @prs: precision specification
 * @size: the size specifier
 * return: number of chars printed
 */
int pr_reverse_fn(va_list lst, char h_buf[],
		int flgs, int w, int prs, int size)
{	
	int i;
	int j;
	char *str;
	int contr = 0;
	
	UNUSD(w);
	UNUSD(size);
	UNUSD(h_buf);
	UNUSD(flgs);
	
	str = va_arg(lst, char *);
	if (str == NULL)
	{
		str = "(NULL)";
		UNUSD(prs);
	}
	for (i = 0; str[i]; i++)
		;
	for (j = j - 1; j >= 0; j--)
	{
		char z = str[j];
		write(1, &z, 1);
		contr++;
	}
	return (contr);
}
/**
 * pr_rotstring_fn - print a string in rot123
 * @lst: arguments list
 * @h_buf: buffer array for print handling
 * @flgs: calculate flags active
 * @w:  width
 * @prs: precision specification
 * @size: size specifier
 * return: num of printed chars
 */
int pr_rotstring_fn(va_list lst, char h_buf[],
		int flgs, int w, int prs, int size)
{	
	unsigned int j;
	char x;
	int contr;
	char *pt_s;
	unsigned int i;
	char i_arr[] =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char o_arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	
	contr = 0;
	UNUSED(h_buf);
	UNUSED(flgs);
	UNUSED(w);
	UNUSED(prs);
	UNUSED(size);
	pt_s = va_arg(lst, char *);
	if (pt_s == NULL)
		pt_s = "(AHYY)";
	for (i = 0; pt_s[i]; i++)
	{
		for (j = 0; i_arr[j]; j++)
		{
			if (i_arr[j] == pt_s[i])
			{
				x = o_arr[j];
				write(1, &x, 1);
				contr++;
				break;
			}
		}
		if (!i_arr[j])
		{
			x = pt_s[i];
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
 * arg_lst: list of arguments
 * return: returns the precision of printing
 */
int g_precision_fn(const char *format, int *i, va_list arg_lst)
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
			prs = va_arg(arg_lst, int);
			break;
		}
		else if (k_digitchar_fn(format[present]))
		{
			prs *= 10;
			prs += format[present] - '0';
		} 
		else
			break;
	}
	*i = present - 1;
	return (prs);
}
