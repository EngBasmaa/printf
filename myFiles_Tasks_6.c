#include "main.h"
#include <unistd.h>
#include <stdarg.h>
/**
 * pr_binary_fn - print unsigned number
 * @lst: list a of arguments
 * @h_buf: buffer array to handle print
 * @flags: calculates active flags
 * @w: get width
 * @prs: precision specification
 * @size: specifier size
 * return: number of chars pronted
 */
int pr_binary_fn(va_list lst, char h_buf[],
				 int flags, int w, int prs, int size)
{
	unsigned int arr[32];
	unsigned int n, y;
	unsigned int k;
	unsigned int total;
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

	/**
	 * get_flags - Calculates active flags
	 * @format: Formatted string in which to print the arguments
	 * @i: take a parameter.
	 * Return: the flags
	 */
	int get_flags(const char *format, int *i)
	{
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
					flags = flags | FLG_ARR[j];
					break;
				}
			if (FLG_CH[j] == 0)
				break;
		}

		*i = present - 1;

		return (flags);
	}
