#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define ZERO_FM 4
#define SHORT_FMS 1
#define LONG_FMS 2
#define BF_SPACE 16
#define BF_PLUS 2
#define BS_LONG 2
#define HASHTAG_H 8
#define BUFF_SIZE 1024
#define MINUS_FM 1
#define UNUSD(x) (void)(x)
/**
 * struct ftt - defines a struct
 * @ftt: format
 * @iptr: a function used
*/
struct ftt
{
	char ftt;
	int (*iptr)(va_list, char[], int, int, int, int);
} ftt;
/**
 * typedef struct ftt ft_t - defines a struct function
 * ftt: its formatt
 * @ft_t: function of struct formatt
 */
typedef struct ftt ft_t;
int Handl_prnt(const char *ftt, int *iptr, va_list lst, char h_buf[],
		int flags, int w, int prs, int size);
int Handl_write_chr(char c, char buffer[],
		int flags, int w, int prs, int size);
int write_number_fn(int posit, int index, char buff[],
		int flag, int w, int prs, int size);
int write_n_fn(int index, char buff[], int flag,
		int w, int prec, int length, char padding, char extra_c);
int write_pointer_fn(char buff[], int index, int l,
		int w, int flag, char padding, char extra_c, int padd_start);
int write_unsigned_fn(int neg, int index, char buff[],
		int flag, int w, int prs, int size);
void pr_Buff(char buffer[], int *buf_in);
int pr_char_fn(va_list lst, char h_buf[],
		int flags, int w, int prs, int size);
int pr_string_fn(va_list lst, char h_buf[],
		int flags, int w, int prs, int size);
int pr_percent_fn(va_list lst, char h_buf[],
		int flags, int w, int prs, int size);
int pr_unsigned_fn(va_list lst, char h_buf[],
		int flags, int w, int prs, int size);
int pr_int_fn(va_list lst, char h_buf[],
		int flgs, int w, int prs, int size);
int pr_binary_fn(va_list lst, char h_buf[],
		int flags, int w, int prs, int size);
int pr_octal_fn(va_list lst, char h_buf[],
		int flags, int w, int prs, int size);
int pr_hexadecimal_fn(va_list lst, char h_buf[],
		int flags, int w, int prs, int size);
int pr_hexa_upper_fn(va_list lst, char h_buf[],
		int flags, int w, int prs, int size);
int pr_non_printable_fn(va_list lst, char h_buf[],
		int flags, int w, int prs, int size);
int pr_hexa_LU_fn(va_list lst, char map[], char h_buf[],
		int flags, char flg_chr, int w, int prs, int size);
int pr_pointer_fn(va_list lst, char h_buf[],
		int flags, int w, int prs, int size);
int g_flags_fn(const char *format, int *i);
int g_width_fn(const char *format, int *i, va_list lst);
int g_precision_fn(const char *format, int *i, va_list lst);
int g_size_fn(const char *format, int *i);
int pr_reverse_fn(va_list lst, char h_buf[],
		int flags, int w, int prs, int size);
int pr_rotString_fn(va_list lst, char h_buf[],
		int flags, int w, int prs, int size);
int write_ch_fn(char ch, char h_buf[],
		int flag, int w, int prs, int size);
int write_number_fn(int posit, int index, char h_buf[],
		int flag, int w, int prs, int size);
int write_n_fn(int index, char h_buf[], int flag,
		int w, int prec, int l, char padding, char add_c);
int write_pointer_fn(char buff[], int index, int l,
		int w, int flag, char padding, char extra_c, int padd_start);
int write_unsigned_fn(int neg, int index, char h_buf[],
		int flag, int w, int prs, int size);
int k_printable_fn(char);
int app_hexa_fn(char, char[], int);
int k_digitchar_fn(char);
long int conv_size_number_fn(long int nmb, int size);
long int conv_size_unsgnd_fn(unsigned long int nmb, int size);
#endif /*MAIN.H*/
