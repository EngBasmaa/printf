#include "main.h"
/**
 * pr_string_fn - Prints a string
 * @lst: list a of arguments
 * @h_buf: buffer array to handle print
 * @flags:  calculates active flags
 * @w: the width
 * @prs:  specification of precision
 * @size: the size specifier
 * Return: num of chars printed
 */
int pr_string_fn(va_list lst, char h_buf[],
				 int flags, int w, int prs, int size)
{
	int k, l = 0;
	char *arr = va_arg(lst, char *);

	UNUSD(h_buf);
	UNUSD(flags);
	UNUSD(w);
	UNUSD(prs);
	UNUSD(size);
	while (arr[l] != '\0')
		l++;
	if (arr == NULL)
	{
		arr = "(null)";
		if (prs >= 6)
			arr = " ";
	}
	if (prs < l && prs >= 0)
		l = prs;
	if (l < w)
	{
		if (flags & MINUS_FM)
		{
			write(1, &arr[0], l);
			for (k = w - l; k > 0; k--)
				write(1, " ", 1);
			return (w);
		}
		else
		{
			for (k = w - l; k > 0; k--)
				write(1, " ", 1);
			write(1, &arr[0], l);
			return (w);
		}
	}
	return (write(1, arr, l));
}
/**
 * pr_percent_fn - to print percentage sign
 * @lst: it is an arguments list
 * @h_buf: a buffer array to handle print
 * @flags:  to calculates active flags
 * @w: get width.
 * @prs:  specification of Precision
 * @size:  specifier Size
 * Return: num of chars are printed
 */
int pr_percent_fn(va_list lst, char h_buf[],
				  int flags, int w, int prs, int size)
{
	UNUSD(prs);
	UNUSD(size);
	UNUSD(lst);
	UNUSD(flags);
	UNUSD(w);
	UNUSD(h_buf);
	return (write(1, "%%", 1));
}
/**
 * handle_write_chr - Prints a string
 * @c: char types.
 * @h_buf: Buffer array to handle print
 * @flags:  Calculates active flags.
 * @w: get width.
 * @prs: precision specifier
 * @size: Size specifier
 * char is stored at left and paddind at buffer's right
 * Return: Number of chars printed.
 */
int Handl_write_chr(char c, char h_buf[],
					int flags, int w, int prs, int size)
{
	int k = 0;
	char pad = ' ';

	UNUSD(prs);
	UNUSD(size);

	if (flags & ZERO_FM)
		pad = '0';
	h_buf[k] = '\0';
	h_buf[k++] = c;
	if (w > 1)
	{
		h_buf[BUFF_SIZE - 1] = '\0';
		for (k = 0; k < w - 1; k++)
			h_buf[BUFF_SIZE - k - 2] = pad;

		if (flags & MINUS_FM)
			return (write(1, &h_buf[0], 1) + write(1,
						&h_buf[BUFF_SIZE - k - 1], w - 1));
		else
			return (write(1, &h_buf[BUFF_SIZE - k - 1], w - 1) +
					write(1, &h_buf[0], 1));
	}
	return (write(1, &h_buf[0], 1));
}
/**
 * pr_char_fn - prints a char
 * @lst: a list a of arguments
 * @h_buf: the buffer array to handle print
 * @flags:  to calculate active flags
 * @w: width
 * @prs:  specification Precision
 * @size:  specifier size
 * Return: Number of chars printed
 */
int pr_char_fn(va_list lst, char h_buf[],
			   int flags, int w, int prs, int size)
{
	char c = va_arg(lst, int);

	return (Handl_write_chr(c, h_buf, flags, w, prs, size));
}

