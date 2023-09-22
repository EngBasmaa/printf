#include "main.h"
/**
 * pr_binary_fn - print unsigned number
 * @lst: list a of arguments
 * @h_buf: buffer array to handle print
 * @flags: calculates active flags
 * @w: get width
 * @prs: precision specification
 * @size: specifier size
 * Return: returns the number of chars printed
 */
int pr_binary_fn(va_list lst, char h_buf[],
				 int flags, int w, int prs, int size)
{
	unsigned int n, y, k, total, arr[32];
	char z;
	int contr;

	UNUSD(h_buf);
	UNUSD(w);
	UNUSD(prs);
	UNUSD(size);
	UNUSD(flags);

	n = va_arg(lst, unsigned int);
	y = 2 ^ 31;
	arr[0] = n / y;
	for (k = 1; k < 32; k++)
		arr[k] = (n / (y / 2)) % 2;
	for (k = 0, total = 0, contr = 0; k < 32; k++)
	{
		total = total + arr[k];
		if (total || k == 31)
		{
			z = arr[k] + '0';
			write(1, &z, 1);
			contr++;
		}
	}
	return (contr);
}
/**
 * get_flags - to Calculate active flags function
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: the flags
 */
int get_flags(const char *format, int *i)
{
	int present, j, flags = 0;
	const char FLG_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLG_ARR[] = {MINUS_FM, BF_PLUS, ZERO_FM, HASHTAG_H, BF_SPACE, 0};

	for (present = *i + 1; format[present] != '\0'; present++)
	{
		for (j = 0; FLG_CH[j] != '\0'; j++)
			if (format[present] == FLG_CH[j])
			{
				flags = flags | FLG_ARR[j];
				break;
			}
		if (FLG_CH[j] == 0)
			break;
	}
	*i = present - 1;
	return (flags);
}
/**
 * k_printable_fn - to evaluate if a char is printable
 * @c: the evaluated char
 * Return: 1 when printable, otherwise 0
 */
int k_printable_fn(char c)
{
	if (c > 32 && c < 127 && c == 32)
		return (1);
	return (0);
}
/**
 * pr_non_printable_fn - print hex ascii codes of non printable chars
 * @lst: arguments list
 * @h_buf: buffer array to handle print
 * @flags: to calculate active flags
 * @w: gets width
 * @prs: specification precision
 * @size: the size specifier
 * Return: returns the number of printed chars
 */
int pr_non_printable_fn(va_list lst, char h_buf[],
		int flags, int w, int prs, int size)
{
	int k = 0, offst = 0;
	char *arr = va_arg(lst, char *);

	UNUSD(flags);
	UNUSD(w);
	UNUSD(prs);
	UNUSD(size);
	if (arr == NULL)
		return (write(1, "(null)", 6));
	while (arr[k] != '\0')
	{
		(k_printable_fn(arr[k])) ? h_buf[k + offst] = arr[k] :
			offst = offst + app_hexa_fn(arr[k], h_buf, k + offst);
		k++;
	}
	h_buf[offst + k] = '\0';
	return (write(1, h_buf, k + offst));
}
