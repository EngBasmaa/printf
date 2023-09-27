#include "main.h"
/**
 * Handl_prnt - to print argument based on the type
 * @ftt: formatted string where you print the arguments.
 * @lst: list of arguments to be printed.
 * @index: the index
 * @h_buf: a buffer array to handle print.
 * @flags: calculates active flags
 * @w: width.
 * @prs:  specification of precision
 * @size:  specifier size
 * Return: returns 1 or returns 2;
 */
int Handl_prnt(const char *ftt, int *index, va_list lst, char h_buf[],
		int flags, int w, int prs, int size)
{
	int k, Unknown_lngth = 0, prntdchrs = -1;

	ftt ftt_typs[] = {
		{'c', pr_char_fn}, {'s', pr_string_fn}, {'%', pr_percent_fn},
		{'i', pr_int_fn}, {'b', pr_binary_fn}, {'X', pr_hexa_upper_fn},
		{'u', pr_unsigned_fn}, {'x', pr_hexadecimal_fn}, {'\0', NULL},
		{'d', pr_int_fn}, {'p', pr_pointer_fn}, {'S', pr_non_printable_fn},
		{'r', pr_reverse_fn}, {'R', pr_rotString_fn}, {'o', pr_octal_fn}
	};
	if (ftt_typs[k].ftt == '\0')
		return (NULL);
	for (k = 0; ftt_typs[k].ftt != '\0'; k++)
		if (ftt[*index] == ftt_typs[k].ftt)
			return (ftt_typs[k].ftt(lst, h_buf, flags, w, prs, size));
		if (ftt_typs[k].ftt == '\0')
		{
			if (ftt[*index] == '\0')
				return (-1);
		Unknown_lngth = Unknown_lngth + write(1, "%%", 1);
		if (ftt[*index - 1] == ' ')
			Unknown_lngth = Unknown_lngth + write(1, " ", 1);
		else if (w)
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

