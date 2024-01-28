#include "s21_sprintf.h"

#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  va_list ap;
  va_start(ap, format);
  int size = s21_strlen(format);
  int j = 0;
  for (int i = 0; i <= size; i++) {
    char buffer[4096] = "\0";
    if (format[i] == '%') {
      if (format[i + 1] == '%') str[j++] = '%';
      i += parser(buffer, &format[i + 1], ap);
      i++;
      j += s21_strlen(buffer);
    } else {
      str[j++] = format[i];
    }
    s21_strncat(str, buffer, s21_strlen(buffer));
  }
  va_end(ap);
  return 0;
}

void s21_spec_c(char *buffer, va_list ap) {
  int symbol = va_arg(ap, int);
  int size = strlen(buffer);
  buffer[size] = symbol;
}

int width(const char *sym, Form *form) {
  int wid = 0;
  if (*sym == '-') {
    sym++;
  }
  while (isdigit(*sym)) {
    wid = wid * 10 + (*sym - '0');
    sym++;
  }
  form->width = wid;
  return form->width;
}
int accuracy(const char *sym, int len, Form *form) {
  int accur = 0;
  for (int i = 0; i <= len; i++) {
    if (sym[i] == '.') {
      while (isdigit(sym[++i])) {
        accur = accur * 10 + (sym[i] - '0');
      }
    }
  }
  form->acc = accur;
  return accur;
}
int find_spec_len(Form *form, const char *sym) {
  //возвращает длину от процента до конца спецификатора
  int length = 0;
  for (; (form->specifier = specificator(sym[length])) == 0 && sym[length] != 0;
       length++) {
  };
  return length;
}
int parser(char *buffer, const char *sym,
           va_list ap) {  //полностью обрабатывает строчку,
  Form form = {0};
  int spec_length = find_spec_len(&form, sym);  //длина до спецификатора
  flags(sym, spec_length, &form);
  int accuracy(const char *sym, int len, Form *form);
  length(&sym[spec_length - 1], &form);
  if (form.specifier == 'c') {
    s21_spec_c(buffer, ap);
  }
  if (form.specifier == 'd') {
    s21_spec_d(buffer, ap, &form);
  }
  if (form.specifier == 'u') {
    s21_spec_u(buffer, ap, &form);
  }
  if (form.specifier == 'o') {
    s21_spec_o(buffer, ap, &form);
  }
  if (form.specifier == 'X') {
    s21_spec_X(buffer, ap, &form);
  }
  if (form.specifier == 'x') {
    s21_spec_x(buffer, ap, &form);
  }
  if (form.specifier == 'f') {
    s21_spec_f(buffer, ap, &form);
  }
  if (form.specifier == 's') {
    s21_spec_s(buffer, ap);
  }
  if (accuracy(sym, spec_length, &form)) {
    realize_acc(buffer, &form);
  }

  if (width(sym, &form)) {
    buffer = realise_width(buffer, &form);
  }
  return spec_length;
}

int flags(const char *sym, int len, Form *form) {
  int res = 0;
  int flags_length = 0;
  for (int i = 0; res == 0 && i <= len; i++) {
    switch (sym[i]) {
      case '-':
        form->min = 1;
        flags_length++;
        break;
      case '+':
        form->plus = 1;
        flags_length++;
        break;
      case ' ':
        form->space = 1;
        flags_length++;
        break;
      case '#':
        form->sharp = 1;
        flags_length++;
        break;
      case '0':
        form->zero = 1;
        flags_length++;
        break;
      default:
        res = 1;
    }
  }
  return flags_length;
}

int length(const char *sym, Form *form) {
  switch (*sym) {
    case 'h':
      form->length = 'h';
      break;
    case 'l':
      form->length = 'l';
      break;
  }
  return form->length;
}
int specificator(const char sym) {
  int spec = 0;
  switch (sym) {
    case 'c':
      spec = 'c';
      break;
    case 'd':
      spec = 'd';
      break;
    case 'i':
      spec = 'd';
      break;
    case 'f':
      spec = 'f';
      break;
    case 's':
      spec = 's';
      break;
    case 'u':
      spec = 'u';
      break;
    case 'g':
      spec = 'g';
      break;
    case 'G':
      spec = 'G';
      break;
    case 'e':
      spec = 'e';
      break;
    case 'E':
      spec = 'E';
      break;
    case 'o':
      spec = 'o';
      break;
    case 'x':
      spec = 'x';
      break;
    case 'X':
      spec = 'X';
      break;
    case 'p':
      spec = 'p';
      break;
    case 'n':
      spec = 'n';
      break;
  }
  return spec;
}

void s21_itoa(long int num, char *src, int base) {
  int cel;
  int rem;
  char rem_sym = '0';
  int j = 0;
  int is_negative = 0;
  if (num == 0) {
    src[j] = '0';
  }
  if (num < 0) {
    is_negative = 1;
    num *= -1;
  }
  while (num > 0) {
    cel = num / base;
    rem = num % base;
    if (rem > 9) {
      rem_sym = rem + 55;
    } else
      rem_sym = rem + '0';
    src[j] = rem_sym;
    num = cel;
    j++;
  }
  if (is_negative == 1) src[j++] = '-';
  s21_reverse(src);
}

void s21_reverse(char *src) {
  int beg = 0;
  int end = (s21_strlen(src)) - 1;
  while (beg < end) {
    char tmp = src[beg];
    src[beg] = src[end];
    src[end] = tmp;
    beg++;
    end--;
  }
  src[s21_strlen(src)] = '\0';
}

void s21_spec_d(char *buffer, va_list ap, Form *form) {
  int num = va_arg(ap, int);
  if (num >= 0) {
    if (form->plus) {
      *buffer = '+';
      buffer++;
    }
    if (form->plus == 0 && form->space) {
      *buffer = ' ';
      buffer++;
    }
  }
  s21_itoa(num, buffer, 10);
}

void s21_spec_s(char *buffer, va_list ap) {
  char *string = NULL;
  string = va_arg(ap, char *);
  s21_strncat(buffer, string, s21_strlen(string));
}

void s21_spec_u(char *buffer, va_list ap, Form *form) {
  unsigned short int us_num = 0;
  unsigned long int ul_num = 0;
  unsigned int ui_num = 0;
  switch (form->length) {
    case 'h':
      us_num = va_arg(ap, unsigned int);
      s21_itoa_for_unsigned(us_num, buffer, 10);
      break;
    case 'l':
      ul_num = va_arg(ap, unsigned long int);
      s21_itoa_for_unsigned(ul_num, buffer, 10);
      break;
    default:
      ui_num = va_arg(ap, unsigned int);
      s21_itoa_for_unsigned(ui_num, buffer, 10);
  }
}
char *realise_width(char *buffer, Form *form) {
  char space = ' ';
  char *result = calloc(form->width + 1, sizeof(char));
  int len_str = s21_strlen(buffer);
  int curr_len = len_str;
  if (result != s21_NULL) {
    if (len_str < form->width) {
      for (int i = 0; i < form->width; i++) {
        if (form->zero == 1) {
          space = '0';
        }
        if (form->min) {
          curr_len = form->width;
        }
        if (form->zero && form->min) {
          space = ' ';
        }
        result[i] = space;
      }
      for (int j = 0; j < form->width; j++) {
        if (buffer[j] == '\0') {
          continue;
        }
        result[j + (form->width - curr_len)] = buffer[j];
      }
      if (form->zero == 1) {
        for (s21_size_t h = 0; h < s21_strlen(result); h++) {
          if (result[h] == '-' && result[0] != '-') {
            char c = result[h];
            result[h] = result[0];
            result[0] = c;
          }
        }
      }
    } else {
      result = buffer;
    }
    s21_strcpy(buffer, result);
    free(result);
  }
  return buffer;
}

void s21_itoa_forlong(unsigned long num, char *src, int base) {
  unsigned long cel;
  int rem;
  char rem_sym = '0';
  int j = 0;
  int is_negative = 0;
  if (num == 0) {
    src[j] = '0';
  }
  while (num > 0) {
    cel = num / base;
    rem = num % base;
    if (rem > 9) {
      rem_sym = rem + 55;
    } else
      rem_sym = rem + '0';
    src[j] = rem_sym;
    num = cel;
    j++;
  }
  if (is_negative == 1) src[j++] = '-';
  s21_reverse(src);
}

void s21_spec_o(char *buffer, va_list ap, Form *form) {
  if (form->sharp) {
    *buffer = '0';
    buffer++;
  }
  unsigned int num = va_arg(ap, unsigned int);
  s21_itoa_forlong(num, buffer, 8);
}

void s21_spec_X(char *buffer, va_list ap, Form *form) {
  unsigned int num = va_arg(ap, unsigned int);
  if (form->sharp && num != 0) {
    *buffer++ = '0';
    *buffer++ = 'X';
  }
  s21_itoa_forlong(num, buffer, 16);
}

void s21_spec_x(char *buffer, va_list ap, Form *form) {
  unsigned int num = va_arg(ap, unsigned int);
  if (form->sharp && num != 0) {
    *buffer++ = '0';
    *buffer++ = 'x';
  }

  s21_itoa_forlong_x(num, buffer, 16);
}

void s21_itoa_forlong_x(unsigned long num, char *src, int base) {
  unsigned long cel;
  int rem;
  char rem_sym = '0';
  int j = 0;
  int is_negative = 0;
  if (num == 0) {
    src[j] = '0';
  }
  while (num > 0) {
    cel = num / base;
    rem = num % base;
    if (rem > 9) {
      rem_sym = rem + 55;
    } else
      rem_sym = rem + '0';

    if (rem_sym > 64 && rem_sym < 91) {
      rem_sym = rem_sym + 32;
    }

    src[j] = rem_sym;
    num = cel;
    j++;
  }
  if (is_negative == 1) src[j++] = '-';
  s21_reverse(src);
}

void s21_spec_f(char *buffer, va_list ap, Form *form) {
  double int_part, fract_part;
  double num = va_arg(ap, double);
  fract_part = modf(num, &int_part);
  char temp[1000000];
  int fract_acc = 0;
  s21_itoa((int)int_part, buffer, 10);
  s21_strncat(buffer, ".", 1);
  if (form->acc == 0) form->acc = 6;
  if (fract_part < 0) fract_part *= -1.0;

  if (fract_part != 0.0) {
    while (fract_part < 0.1) {
      fract_part *= 10;
      s21_strncat(buffer, "0", 1);
      fract_acc++;
    }
    for (int i = form->acc;
         fract_part < pow(10, (double)(form->acc)) && fract_acc <= form->acc;
         fract_part *= 10) {
      s21_memset(temp, 0, 1000000);
      s21_itoa((int)fract_part, temp, 10);
      fract_part =
          roundf(fract_part * pow(10, (double)(i))) / pow(10, (double)(i));
      i--;
      fract_acc++;
    }
    s21_strncat(buffer, temp, form->acc);
  } else {
    for (int i = 0; i < form->acc; i++) {
      s21_strncat(buffer, "0", 1);
    }
  }
}

void s21_itoa_for_unsigned(unsigned long long int num, char *src, int base) {
  long int cel;
  long int rem;
  char rem_sym = '0';
  int j = 0;
  int is_negative = 0;
  if (num == 0) {
    src[j] = '0';
  }
  while (num > 0) {
    cel = num / base;
    rem = num % base;
    if (rem > 9) {
      rem_sym = rem + 55;
    } else
      rem_sym = rem + '0';
    src[j] = rem_sym;
    num = cel;
    j++;
  }
  if (is_negative == 1) src[j++] = '-';
  s21_reverse(src);
}

char *realize_acc(char *buffer, Form *form) {
  char *result;
  int len_str = strlen(buffer);
  result = calloc(form->acc + 1, sizeof(char));
  if (result != s21_NULL) {
    if (buffer[0] == '-') {
      form->acc += 1;
    }
    char c = '0';
    if (len_str < form->acc) {
      for (int i = 0; i < form->acc; i++) {
        result[i] = c;
      }
      for (int j = 0; j < len_str; j++) {
        result[j + (form->acc - len_str)] = buffer[j];
      }
      for (int y = form->acc; y > 0; y--) {
        if (result[y] == '-') {
          if (result[0] == '-') {
            y++;
          }
          result[0] = result[y];
          result[y] = c;
        }
      }
    } else {
      result = buffer;
    }
    s21_strcpy(buffer, result);
    free(result);
  }
  return buffer;
}

char *s21_strcpy(char *str1, const char *str2) {
  int size = strlen(str2);
  for (int i = 0; i < size; i++) {
    str1[i] = str2[i];
  }
  return str1;
}
