#include "main.h"
#include <unistd.h>
#include <stdarg.h>
/**
 * pr_binary_fn - print unsigned number
 * @lst: list a of arguments
 * @h_buf: buffer array to handle print
 * @flgs: calculates active flags
 * @w: get width
 * @prs: precision specification
 * @size: specifier size
 * return: number of chars pronted
 */
int pr_binary_fn(va_list lst, char h_buf[],
		int flgs, int w, int prs, int size)
{	
	unsigned int arr[32];
	unsigned int x, y;
	unsigned int i;
	unsigned int total;
	char z;
	int contr;
	
	UNUSD(h_buf);
	UNUSD(w);
	UNUSD(prs);
	UNUSD(size);
	UNUSD(flgs);
	
	x = va_arg(lst, unsigned int);

	y = 2147483648;
	arr[0] = x / y;
	for (i = 1; i < 32; i++)
		arr[i] = (x / (y / 2)) % 2;
	for (i = 0, total = 0, contr = 0; i < 32; i++)
	{
		total = total + arr[i];
		if (total || i == 31)
		{
			z = arr[i] + '0';
			write(1, &z, 1);
			contr++;
		}
	}
	return (contr);
}
/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, curr_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[curr_i] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = curr_i - 1;

	return (flags);
}








