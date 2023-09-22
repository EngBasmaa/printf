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
 * Return: the flags
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */ /* 1 2 4 8  16 */
	int present;
	int j;
	int flags = 0;
	const char FLG_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLG_ARR[] = {MINUS_FM, BF_PLUS, ZERO_FM, HASHTAG_H, BF_SPACE, 0};

	for (present = *i + 1; format[present] != '\0'; present++)
	{
		for (j = 0; FLG_CH[j] != '\0'; j++)
			if (format[present] == FLG_CH[j])
			{
				flags |= FLG_ARR[j];
				break;
			}
		if (FLG_CH[j] == 0)
			break;
	}

	*i = present - 1;

	return (flags);
}
