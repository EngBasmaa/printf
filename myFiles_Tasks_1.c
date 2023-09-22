#include "main.h"
#include <unistd.h>
#include <stdarg.h>
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
	int l = 0;
	int k;
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
 *
 * Return: Number of chars printed.
 */
int Handl_write_chr(char c, char h_buf[],
	int flags, int w, int prs, int size)
{ /* char is stored at left and paddind at buffer's right */
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
			return (write(1, &h_buf[0], 1) +
					write(1, &h_buf[BUFF_SIZE - k - 1], w - 1));
		else
			return (write(1, &h_buf[BUFF_SIZE - k - 1], w - 1) +
					write(1, &h_buf[0], 1));
	}

	return (write(1, &h_buf[0], 1));
}
/**
 * Handl_prnt - to print argument based on the type
 * @ft: formatted string where you print the arguments.
 * @lst: list of arguments to be printed.
 * @iptr: iptr pointer
 * @index: the index
 * @h_buf: a buffer array to handle print.
 * @flags: calculates active flags
 * @w: get width.
 * @prs:  specification of precision
 * @size:  specifier size
 *
 * Return: returns 1 or returns 2;
 */
int Handl_prnt(const char *ftt, int *index, va_list lst, char h_buf[],
		int flags, int w, int prs, int size)
{
    int k;
	int Unknown_lngth = 0;
	int prntdchrs;

	prntdchrs = -1;
	ftt ftt_typs[] = {
		{'c', pr_char_fn}, {'s', pr_string_fn}, {'%', pr_percent_fn},
		{'i', pr_int_fn}, {'b', pr_binary_fn}, {'X', pr_hexa_upper_fn},
		{'u', pr_unsigned_fn}, {'x', pr_hexa_fn}, {'\0', NULL},
		{'d', pr_int_fn}, {'p', pr_pointer_fn}, {'S', k_printable_fn},
		{'r', pr_reverse_fn}, {'R', pr_rotString_fn}, {'o', pr_octal_fn}
	};
	for (k = 0; ftt_typs[k].ftt != '\0'; i++)
		if (ftt[*index] == ftt_typs[k].ftt)
			return (ftt_typs[i].iptr(lst, h_buf, flags, w, prs, size));
	if (ftt_typs[k].ftt == '\0')
	{
		if (ftt[*index - 1] == ' ')
		{
			Unknown_lngth = Unknown_lngth + write(1, " ", 1);
		} else if (ftt[*index] == '\0')
			return (-1);
		Unknown_lngth = Unknown_lngth + write(1, "%%", 1);
		if (w)
		{
			--(*index);
			while (ftt[*index] != '%' && ftt[*index] != ' ')
				--(*index);
			if (ftt[*index] == ' ')
				--(*index);
			return (1);
		}
		Unknown_lngth = Unknown_lngth + write(1, &ftt[*index], 1);
		return (Unknown_lngth);
	}
	return (prntdchrs);
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
