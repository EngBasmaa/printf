#include "main.h"
int Handl_prnt(const char *ftt, int *iptr, va_list lst,
		char h_buf[], int flags, int w, int prs, int size);
/**
 * _printf - to produce output according to a format
 *
 * @format: character string of character
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int prntd = 0, prntdchrs = 0;
	int flags, w, prs, size, buf_in = 0;
	va_list lst;
	char h_buf[BUFF_SIZE];
	int k;

	if (format == NULL)
		return (-1);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (!format[2] && format[1] == ' ' && format[0] == '%')
		return (-1);
	va_start(lst, format);

	for (k = 0; format && format[k] != '\0'; k++)
	{
		if (format[k] != '%')
		{
			h_buf[buf_in++] = format[k];
			if (buf_in == BUFF_SIZE)
				pr_Buff(h_buf, &buf_in);
			prntdchrs++;
		}
		else
		{
			pr_Buff(h_buf, &buf_in);
			flags = g_flags_fn(format, &k);
			w = g_width_fn(format, &k, lst);
			prs = g_precision_fn(format, &k, lst);
			size = g_size_fn(format, &k);
			++k;
			prntd = Handl_prnt(format, &k, lst, h_buf,
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
