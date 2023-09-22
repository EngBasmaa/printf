#include "main.h"
#include <unistd.h>
#include <stdarg.h>
/**
 * pr_pointer_fn - prints the value of a poiter variable
 * @lst: arguments list
 * @h_buf: buffer array to handle print
 * @flags: to calculate active flags
 * @w: width
 * @prs: specification precision
 * @size: specifier size
 * Return: number of the printed chars
 */
int pr_pointer_fn(va_list lst, char h_buf[], int flags,
				  int w, int prs, int size)
{
	int pad_start = 1;
	char add_c = 0, pad = '';
	int l = 2;
	int index = BUFF_SIZE - 2;
	unsigned long nmb_add;
	char arr[] = "0123456789abcdef";
	void *add = va_arg(lst, void *);

	/*for '0x' there is length = 2*/
	UNUSD(prs);
	UNUSD(w);
	UNUSD(size);
	if (add == NULL)
		return (write(1, "(nil)", 5));
	h_buf[BUFF_SIZE - 1] = '\0';
	nmb_add = (unsigned long)add;
	while (nmb_add > 0)
	{
		h_buf[index--] = arr[nmb_add % 16];
		nmb_add = nmb_add / 16;
		l++;
	}
	if ((flags & ZERO_FM) && !(flags & MINUS_FM))
		pad = '0';
	else if (flags & BF_PLUS)
		add_c = '+', l++;
	else if (flags & BF_SPACE)
		add_c = '', l++;
	index++;
	return (write_pointer_fn(h_buf, index, l,
							 w, flags, pad, add_c, pad_start));
}
/**
 * print_LU_hexa - print a hexadecimal number in lower or upper
 * @lst: arguments list
 * @arr: values array to map the number
 * @h_buf: the array of buffer to handle print
 * @flags:  of int type to calculate active flags
 * @flg_chr: of char type to calculate active flags
 * @w:  width
 * @prs: specification precision
 * @size: specification size
 * Return: number of printed chars
 */
int pr_hexa_LU_fn(va_list lst, char arr[], char h_buf[],
				  int flags, char flg_chr, int w, int prs, int size)
{
	int k = BUFF_SIZE - 2;
	unsigned long int nmb = va_arg(lst, unsigned long int);
	unsigned long int k_nmb = nmb;

	UNUSD(w);

	nmb = conv_size_unsgnd_fn(nmb, size);

	if (nmb == 0)
		h_buf[k--] = '0';

	h_buf[BUFF_SIZE - 1] = '\0';

	while (nmb > 0)
	{
		h_buf[k--] = arr[nmb % 16];
		nmb = nmb / 16;
	}

	if (flags & HASHTAG_H && k_nmb != 0)
	{
		h_buf[k--] = flg_chr;
		h_buf[k--] = '0';
	}

	k++;

	return (write_unsigned_fn(0, k, h_buf, flags, w, prs, size));
}
/**
 * pr_hexa_upper_fn - prints an unsigned number in upper hexadecimal notation
 * @lst: arguments lista
 * @h_buf: buffer array to handle print
 * @flags:  to calculate active flags
 * @w: to get width
 * @prs: specification precision
 * @size: specifier size
 * Return: number of printed chars
 */
int pr_hexa_upper_fn(va_list lst, char h_buf[],
					 int flags, int w, int prs, int size)
{
	return (pr_hexa_LU_fn(lst, "0123456789ABCDEF", h_buf,
						  flags, 'X', w, prs, size));
}
/**
 * pr_hexadecimal_fn - to print an unsigned hexadecimal number notation
 * @lst: Lista of arguments
 * @h_buf: Buffer array to handle print
 * @flags:  to calculate active flags
 * @w: to get width
 * @prs: specification precision
 * @size: specifier size
 * Return: num of printed chars
 */
int pr_hexadecimal_fn(va_list lst, char h_buf[],
					  int flags, int w, int prs, int size)
{
	return (pr_hexa_LU_fn(lst, "0123456789abcdef", h_buf,
						  flags, 'x', w, prs, size));
}
/**
 * pr_octal_fn - to print an unsigned number in octal notation
 * @lst: arguments lista
 * @h_buf: buffer array to handle print
 * @flags:  to calculate active flags
 * @w: get width
 * @prs: specification precision
 * @size: specifier size
 * Return: num of chars printed
 */
int pr_octal_fn(va_list lst, char h_buf[],
				int flags, int w, int prs, int size)
{
	int k = BUFF_SIZE - 2;
	unsigned long int nmb = va_arg(lst, unsigned long int);
	unsigned long int k_nmb = nmb;

	UNUSD(w);
	nmb = conv_size_unsgnd_fn(nmb, size);

	if (nmb == 0)
		h_buf[k--] = '0';

	h_buf[BUFF_SIZE - 1] = '\0';

	while (nmb > 0)
	{
		h_buf[k--] = (nmb % 8) + '0';
		nmb = nmb / 8;
	}

	if (flags & HASHTAG_H && k_nmb != 0)
		h_buf[k--] = '0';

	k++;

	return (write_unsigned_fn(0, k, h_buf, flags, w, prs, size));
}
