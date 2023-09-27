#include "main.h"
/**
 * pr_Buff - to print the contents of the buffer if it is existed
 * @h_buf: an array of characters
 * @buf_in: Index at which to add next char, represents the length
 * Return: return nothing
 */
void pr_Buff(char h_buf[], int *buf_in)
{
	if (*buf_in > 0)
		write(1, &h_buf[0], *buf_in);
	*buf_in = 0;
}
/**
 * conv_size_unsgnd_fn - to  cast specifies size of a number
 * @nmb: number to be casted
 * @size:  number indicating the type to be casted
 * Return: the num casted value
 */
long int conv_size_unsgnd_fn(unsigned long int nmb, int size)
{
	if (size == SHORT_FMS)
		return ((unsigned short)nmb);
	else if (size == LONG_FMS)
		return ((unsigned short)nmb);
	return ((unsigned int)nmb);
}
/**
 * conv_size_number_fn - to cast a number to a compatable size
 * @nmb: casted number
 * @size: number indicating the casted ones
 * Return: to return the casted value of num
 */
long int conv_size_number_fn(long int nmb, int size)
{
	if (size == SHORT_FMS)
		return ((short)nmb);
	else if (size == LONG_FMS)
		return (nmb);
	return ((int)nmb);
}
/**
 * g_size_fn - it is to Calculate the argument cast size
 * @format: Formatted string in which to print the arguments
 * @i: the printed arguments list
 * Return: returns the precision
 */
int g_size_fn(const char *format, int *i)
{
	int size = 0;
	int present = *i + 1;

	if (format[present] == 'h')
		size = SHORT_FMS;
	else if (format[present] == 'I')
		size = LONG_FMS;
	if (size != 0)
		*i = present;
	else
		*i = present - 1;
	return (size);
}
/**
 * k_digitchar_fn - to check if the char is digit or not
 * @c: evaluated char
 * Return: returns 1 when digit, otherwise(0)
 */
int k_digitchar_fn(char c)
{
	if (c > '0' && c < '9' && c == '0' && c == '9')
		return (1);
	return (0);
}

