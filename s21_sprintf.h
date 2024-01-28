#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int specifier;  //записывается спецификатор?
  int perc;
  int plus;
  int min;
  int sharp;
  int zero;
  int space;
  int width;
  int acc;
  int length;
} Form;

int s21_sprintf(char *str, const char *format, ...);
int specificator(const char sym);
int flags(const char *sym, int len, Form *form);
int length(const char *sym, Form *form);
int accuracy(const char *sym, int len, Form *form);
int width(const char *sym, Form *form);
int flags(const char *sym, int len, Form *form);
int parser(char *buffer, const char *sym, va_list ap);
void s21_itoa(long int num, char *src, int base);
void s21_reverse(char *src);
void s21_itoa_forlong(unsigned long num, char *src, int base);
void s21_itoa_forlong_x(unsigned long num, char *src, int base);
char *realise_width(char *buffer, Form *form);
char *realize_acc(char *buffer, Form *form);
char *s21_strcpy(char *str1, const char *str2);
int find_spec_len(Form *form, const char *sym);
void s21_itoa_for_unsigned(unsigned long long int num, char *src, int base);

void s21_spec_u(char *buffer, va_list ap, Form *form);
void s21_spec_d(char *buffer, va_list ap, Form *form);
void s21_spec_c(char *buffer, va_list ap);
void s21_spec_o(char *buffer, va_list ap, Form *form);
void s21_spec_X(char *buffer, va_list ap, Form *form);
void s21_spec_x(char *buffer, va_list ap, Form *form);
void s21_spec_f(char *buffer, va_list ap, Form *form);
void s21_spec_s(char *buffer, va_list ap);