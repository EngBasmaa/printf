#include "main.h"
int Handl_prnt(const char *ftt, int *iptr, va_list lst, char h_buf[],
		int flags, int w, int prs, int size);
/**
 * _printf - to produce output according to a format
 *
 * @format: character string of character
 *
 * Return: the number of characters printed
*/
int _printf(const char *format, ...)
{
	int i, prntd = 0, prntdchrs = 0;
	int flags, w, prs, size, buf_in = 0;
	va_list lst;
	char h_buf[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(lst, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			h_buf[buf_in++] = format[i];
			if (buf_in == BUFF_SIZE)
				pr_Buff(h_buf, &buf_in);
			prntdchrs++;
		}
		else
		{
			pr_Buff(h_buf, &buf_in);
			flags = g_flags_fn(format, &i);
			w = g_width_fn(format, &i, lst);
			prs = g_precision_fn(format, &i, lst);
			size = g_size_fn(format, &i);
			++i;
			prntd = Handl_prnt(format, &i, lst, h_buf,
					flags, w, prs, size);
			if (prntd == -1)
				return (-1);
			prntdchrs = prntdchrs + prntd;
		}
	}

	pr_Buff(h_buf, &buf_in);
	va_end(lst);

	return (prntdchrs);
}
