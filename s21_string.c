#include "s21_string.h"
#ifdef __APPLE__
#define MAX_ERROR 107
char *errors[107] = {"Undefined error: 0",
                     "Operation not permitted",
                     "No such file or directory",
                     "No such process",
                     "Interrupted system call",
                     "Input/output error",
                     "Device not configured",
                     "Argument list too long",
                     "Exec format error",
                     "Bad file descriptor",
                     "No child processes",
                     "Resource deadlock avoided",
                     "Cannot allocate memory",
                     "Permission denied",
                     "Bad address",
                     "Block device required",
                     "Resource busy",
                     "File exists",
                     "Cross-device link",
                     "Operation not supported by device",
                     "Not a directory",
                     "Is a directory",
                     "Invalid argument",
                     "Too many open files in system",
                     "Too many open files",
                     "Inappropriate ioctl for device",
                     "Text file busy",
                     "File too large",
                     "No space left on device",
                     "Illegal seek",
                     "Read-only file system",
                     "Too many links",
                     "Broken pipe",
                     "Numerical argument out of domain",
                     "Result too large",
                     "Resource temporarily unavailable",
                     "Operation now in progress",
                     "Operation already in progress",
                     "Socket operation on non-socket",
                     "Destination address required",
                     "Message too long",
                     "Protocol wrong type for socket",
                     "Protocol not available",
                     "Protocol not supported",
                     "Socket type not supported",
                     "Operation not supported",
                     "Protocol family not supported",
                     "Address family not supported by protocol family",
                     "Address already in use",
                     "Can't assign requested address",
                     "Network is down",
                     "Network is unreachable",
                     "Network dropped connection on reset",
                     "Software caused connection abort",
                     "Connection reset by peer",
                     "No buffer space available",
                     "Socket is already connected",
                     "Socket is not connected",
                     "Can't send after socket shutdown",
                     "Too many references: can't splice",
                     "Operation timed out",
                     "Connection refused",
                     "Too many levels of symbolic links",
                     "File name too long",
                     "Host is down",
                     "No route to host",
                     "Directory not empty",
                     "Too many processes",
                     "Too many users",
                     "Disc quota exceeded",
                     "Stale NFS file handle",
                     "Too many levels of remote in path",
                     "RPC struct is bad",
                     "RPC version wrong",
                     "RPC prog. not avail",
                     "Program version wrong",
                     "Bad procedure for program",
                     "No locks available",
                     "Function not implemented",
                     "Inappropriate file type or format",
                     "Authentication error",
                     "Need authenticator",
                     "Device power is off",
                     "Device error",
                     "Value too large to be stored in data type",
                     "Bad executable (or shared library)",
                     "Bad CPU type in executable",
                     "Shared library version mismatch",
                     "Malformed Mach-o file",
                     "Operation canceled",
                     "Identifier removed",
                     "No message of desired type",
                     "Illegal byte sequence",
                     "Attribute not found",
                     "Bad message",
                     "EMULTIHOP (Reserved)",
                     "No message available on STREAM",
                     "ENOLINK (Reserved)",
                     "No STREAM resources",
                     "Not a STREAM",
                     "Protocol error",
                     "STREAM ioctl timeout",
                     "Operation not supported on socket",
                     "Policy not found",
                     "State not recoverable",
                     "Previous owner died",
                     "Interface output queue is full"};
#endif

#ifdef __unix__
#define MAX_ERROR 134
char *errors[134] = {"Success",
                     "Operation not permitted",
                     "No such file or directory",
                     "No such process",
                     "Interrupted system call",
                     "Input/output error",
                     "No such device or address",
                     "Argument list too long",
                     "Exec format error",
                     "Bad file descriptor",
                     "No child processes",
                     "Resource temporarily unavailable",
                     "Cannot allocate memory",
                     "Permission denied",
                     "Bad address",
                     "Block device required",
                     "Device or resource busy",
                     "File exists",
                     "Invalid cross-device link",
                     "No such device",
                     "Not a directory",
                     "Is a directory",
                     "Invalid argument",
                     "Too many open files in system",
                     "Too many open files",
                     "Inappropriate ioctl for device",
                     "Text file busy",
                     "File too large",
                     "No space left on device",
                     "Illegal seek",
                     "Read-only file system",
                     "Too many links",
                     "Broken pipe",
                     "Numerical argument out of domain",
                     "Numerical result out of range",
                     "Resource deadlock avoided",
                     "File name too long",
                     "No locks available",
                     "Function not implemented",
                     "Directory not empty",
                     "Too many levels of symbolic links",
                     "Unknown error 41",
                     "No message of desired type",
                     "Identifier removed",
                     "Channel number out of range",
                     "Level 2 not synchronized",
                     "Level 3 halted",
                     "Level 3 reset",
                     "Link number out of range",
                     "Protocol driver not attached",
                     "No CSI structure available",
                     "Level 2 halted",
                     "Invalid exchange",
                     "Invalid request descriptor",
                     "Exchange full",
                     "No anode",
                     "Invalid request code",
                     "Invalid slot",
                     "Unknown error 58",
                     "Bad font file format",
                     "Device not a stream",
                     "No data available",
                     "Timer expired",
                     "Out of streams resources",
                     "Machine is not on the network",
                     "Package not installed",
                     "Object is remote",
                     "Link has been severed",
                     "Advertise error",
                     "Srmount error",
                     "Communication error on send",
                     "Protocol error",
                     "Multihop attempted",
                     "RFS specific error",
                     "Bad message",
                     "Value too large for defined data type",
                     "Name not unique on network",
                     "File descriptor in bad state",
                     "Remote address changed",
                     "Can not access a needed shared library",
                     "Accessing a corrupted shared library",
                     ".lib section in a.out corrupted",
                     "Attempting to link in too many shared libraries",
                     "Cannot exec a shared library directly",
                     "Invalid or incomplete multibyte or wide character",
                     "Interrupted system call should be restarted",
                     "Streams pipe error",
                     "Too many users",
                     "Socket operation on non-socket",
                     "Destination address required",
                     "Message too long",
                     "Protocol wrong type for socket",
                     "Protocol not available",
                     "Protocol not supported",
                     "Socket type not supported",
                     "Operation not supported",
                     "Protocol family not supported",
                     "Address family not supported by protocol",
                     "Address already in use",
                     "Cannot assign requested address",
                     "Network is down",
                     "Network is unreachable",
                     "Network dropped connection on reset",
                     "Software caused connection abort",
                     "Connection reset by peer",
                     "No buffer space available",
                     "Transport endpoint is already connected",
                     "Transport endpoint is not connected",
                     "Cannot send after transport endpoint shutdown",
                     "Too many references: cannot splice",
                     "Connection timed out",
                     "Connection refused",
                     "Host is down",
                     "No route to host",
                     "Operation already in progress",
                     "Operation now in progress",
                     "Stale file handle",
                     "Structure needs cleaning",
                     "Not a XENIX named type file",
                     "No XENIX semaphores available",
                     "Is a named type file",
                     "Remote I/O error",
                     "Disk quota exceeded",
                     "No medium found",
                     "Wrong medium type",
                     "Operation canceled",
                     "Required key not available",
                     "Key has expired",
                     "Key has been revoked",
                     "Key was rejected by service",
                     "Owner died",
                     "State not recoverable",
                     "Operation not possible due to RF-kill",
                     "Memory page has hardware error"};
#endif

/* ------------------------
  void *memchr(const void *str, int c, size_t n)
  Выполняет поиск первого вхождения символа c (беззнаковый тип)
  в первых n байтах строки, на которую указывает аргумент str
------------------------ */
void *s21_memchr(const void *str, int c, s21_size_t n) {
  unsigned char *s = (unsigned char *)str;
  unsigned char *ptr = s21_NULL;
  for (s21_size_t i = 0; i < n && s[i] != '\0'; i++) {
    if (s[i] == (unsigned char)c) {
      ptr = &s[i];
      break;
    }
  }
  return ptr;
}

/* ------------------------
  int memcmp(const void *str1, const void *str2, size_t n)
  Сравнивает первые n байтов str1 и str2.
------------------------ */
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  s21_size_t i;
  int res = 0;
  if (n != 0) {
    for (i = 0;
         i < n - 1 && ((unsigned char *)str1)[i] == ((unsigned char *)str2)[i];
         i++)
      ;
    res = (((unsigned char *)str1)[i] - ((unsigned char *)str2)[i]);
  }
  return res;
}

/* ------------------------
  void *memcpy(void *dest, const void *src, size_t n)
  Копирует n символов из src в dest.
------------------------ */
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  const char *src_ptr = (const char *)src;
  char *dst_ptr = (char *)dest;
  while (n--) {
    *dst_ptr++ = *src_ptr++;
  }
  return dest;
}

/* ------------------------
  void *memset(void *str, int c, size_t n)
  Копирует символ c (беззнаковый тип) в первые n символов строки,
  на которую указывает аргумент str.
------------------------ */
void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *symbol = (unsigned char *)str;
  if (str != s21_NULL) {
    for (s21_size_t i = 0; i < n; i++) {
      symbol[i] = c;
    }
  }
  return str;
}

/* ------------------------
  char *strncat(char *dest, const char *src, size_t n)
  Добавляет строку, на которую указывает src, в конец строки,
  на которую указывает dest, длиной до n символов.
------------------------ */
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  const char *buf = src;
  int size = s21_strlen(dest);
  s21_size_t i = 0;
  for (i = 0; i < n && buf[i] != '\0'; i++) {
    dest[size + i] = src[i];
  }
  return dest;
}

/* ------------------------
  char *strchr(const char *str, int c)
  Выполняет поиск первого вхождения символа c (беззнаковый тип) в строке,
  на которую указывает аргумент str.
------------------------ */
char *s21_strchr(const char *str, int c) {
  const char *src = str;
  int size = s21_strlen(str);
  char *ptr = s21_NULL;
  for (int i = 0; i <= size; i++) {
    if (src[i] == (unsigned char)c) {
      ptr = (char *)&src[i];
      break;
    }
  }
  return ptr;
}

/* ------------------------
  int strncmp(const char *str1, const char *str2, size_t n)
  Сравнивает не более первых n байтов str1 и str2.
------------------------ */
int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  s21_size_t i;
  int res = 0;
  if (n != 0) {
    for (i = 0; i < n - 1 && str1[i] == str2[i]; i++)
      ;
    res = (str1[i] - str2[i]);
  }
  return res;
}

/* ------------------------
  char *strncpy(char *dest, const char *src, size_t n)
  Копирует до n символов из строки, на которую указывает src, в dest.
------------------------ */
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *temp = dest;
  while (n && (*dest++ = *src++)) n--;
  while (n--) *dest++ = 0;
  return temp;
}

/* ------------------------
  size_t strcspn(const char *str1, const char *str2)
  Вычисляет длину начального сегмента str1,
  который полностью состоит из символов, не входящих в str2.
------------------------ */
s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t lenght = 0;
  int count = 0;
  for (s21_size_t i = 0; i < s21_strlen(str1); i++) {
    for (s21_size_t j = 0; j < s21_strlen(str2); j++) {
      if (str1[i] == str2[j]) {
        count = 1;
      }
    }
    if (count) {
      break;
    } else {
      lenght++;
    }
  }
  return lenght;
}

/* ------------------------
  char *strerror(int errnum)
  Выполняет поиск во внутреннем массиве номера ошибки errnum
  и возвращает указатель на строку с сообщением об ошибке.
------------------------ */
char *s21_strerror(int errnum) {
  static char unknown_error[1500];
  sprintf(unknown_error, "Unknown error: %d", errnum);
  return (errnum >= 0 && errnum <= MAX_ERROR) ? errors[errnum] : unknown_error;
}

/* ------------------------
  size_t strlen(const char *str)
  Вычисляет длину строки str, не включая завершающий нулевой символ.
------------------------ */
s21_size_t s21_strlen(const char *str) {
  s21_size_t length = 0;
  for (; *(str + length); length++) {
  }
  return length;
}

/* ------------------------
  char *strpbrk(const char *str1, const char *str2)
  Находит первый символ в строке str1,
  который соответствует любому символу, указанному в str2.
------------------------ */
char *s21_strpbrk(const char *str1, const char *str2) {
  for (s21_size_t i = 0; i < s21_strlen(str1); i++) {
    for (s21_size_t j = 0; j < s21_strlen(str2); j++) {
      if (str1[i] == str2[j]) {
        return (char *)&str1[i];
      }
    }
  }
  return 0;
}

/* ------------------------
  char *strrchr(const char *str, int c)
  Выполняет поиск последнего вхождения символа c (беззнаковый тип) в строке,
  на которую указывает аргумент str.
------------------------ */
char *s21_strrchr(const char *str, int c) {
  const char *src = str;
  int size = s21_strlen(str);
  char *ptr = s21_NULL;
  for (int i = size; i >= 0; i--) {
    if (src[i] == (unsigned char)c) {
      ptr = (char *)&src[i];
      break;
    }
  }
  return ptr;
}

/* ------------------------
  char *strstr(const char *haystack, const char *needle)
  Находит первое вхождение всей строки needle (не включая завершающий нулевой
символ), которая появляется в строке haystack.
------------------------ */
char *s21_strstr(const char *haystack, const char *needle) {
  char *res = s21_NULL;
  if (s21_strlen(haystack) >= s21_strlen(needle)) {
    for (s21_size_t i = 0; i <= s21_strlen(haystack) - s21_strlen(needle);
         i++) {
      int found = 1;
      for (s21_size_t j = i, k = 0; needle[k]; k++, j++) {
        if (haystack[j] != needle[k]) {
          found = 0;
          break;
        }
      }
      if (found) {
        res = (char *)haystack + i;
        break;
      }
    }
  }
  return res;
}

/* ------------------------
  char *strtok(char *str, const char *delim)
  Разбивает строку str на ряд токенов, разделенных delim.
------------------------ */
char *s21_strtok(char *str, const char *delim) {
  static char *ptr = s21_NULL;
  if (str) ptr = str;
  char *res = s21_NULL;
  if (ptr) {
    while (*ptr && s21_strchr(delim, *ptr)) ptr++;
    if (*ptr) {
      res = ptr;
      while (*ptr && !s21_strchr(delim, *ptr)) ptr++;
      if (*ptr) *ptr++ = 0;
    } else {
      ptr = s21_NULL;
    }
  }
  return res;
}

/* ---------------------------------------------
  Part 5. Дополнительно.
  Реализация специальных функций обработки строк
------------------------------------------------- */

/* ------------------------
  void *to_upper(const char *str)
  Возвращает копию строки (str), преобразованной в верхний регистр
------------------------ */
void *s21_to_upper(const char *str) {
  if (!str) return s21_NULL;
  char *upper = s21_NULL;
  int length = s21_strlen(str);
  if ((upper = calloc(length + 1, sizeof(char))) != s21_NULL) {
    for (s21_size_t i = 0; i < s21_strlen(str); i++) {
      int ch = str[i];
      if (ch > 96 && ch < 123) {
        ch = ch - 32;
      }
      upper[i] = ch;
    }
  }
  return upper;
}

/* ------------------------
  void *to_lower(const char *str)
  Возвращает копию строки (str), преобразованной в нижний регистр
------------------------ */
void *s21_to_lower(const char *str) {
  if (!str) return s21_NULL;
  char *lower = s21_NULL;
  int length = s21_strlen(str);
  if ((lower = calloc(length + 1, sizeof(char))) != s21_NULL) {
    for (s21_size_t i = 0; i < s21_strlen(str); i++) {
      int ch = str[i];
      if (ch > 64 && ch < 91) {
        ch = ch + 32;
      }
      lower[i] = ch;
    }
  }
  return lower;
}

/* ------------------------
  void *insert(const char *src, const char *str, size_t start_index)
  Возвращает новую строку, в которой указанная строка (str) вставлена
  в указанную позицию (start_index) в данной строке (src)
------------------------ */
void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if ((!src) || (!str)) return s21_NULL;
  char *arr = s21_NULL;
  s21_size_t length = s21_strlen(src) + s21_strlen(str) + 1;
  int length_str = s21_strlen(str);

  if (start_index > s21_strlen(src)) return s21_NULL;

  if (((arr = calloc(length, sizeof(char))) != s21_NULL)) {
    for (s21_size_t i = 0; i < start_index; i++) {
      arr[i] = src[i];
    }

    for (s21_size_t i = start_index, j = 0; i < (length_str + start_index);
         i++, j++) {
      arr[i] = str[j];
    }

    for (s21_size_t i = (length_str + start_index); i <= length - 1; i++) {
      arr[i] = src[i - length_str];
    }
  }

  return arr;
}

//вспомогательная функция для s21_trim
char *s21_strpbrk_end(const char *str1, const char *str2) {
  char *array = s21_NULL;
  for (s21_size_t i = 0; i < s21_strlen(str1); i++) {
    for (s21_size_t j = 0; j < s21_strlen(str2); j++) {
      if (str1[i] == str2[j]) {
        array = (char *)&str1[i];
      }
    }
  }
  return array;
}

/* ------------------------
  void *trim(const char *src, const char *trim_chars)
  Возвращает новую строку, в которой удаляются все
  начальные и конечные вхождения набора
  заданных символов (trim_chars) из данной строки (src)
------------------------ */
void *s21_trim(const char *src, const char *trim_chars) {
  if ((!src) || (!trim_chars)) return s21_NULL;
  char *array = s21_NULL;
  if ((array = calloc(s21_strlen(src) + 1, sizeof(char))) != s21_NULL) {
    s21_strncpy(array, src, s21_strlen(src) + 1);
    printf("in func %s\n", array);
    int match = 0;
    int stop = 0;
    for (s21_size_t i = 0; i < s21_strlen(array) && stop == 0; i++) {
      match = 0;
      for (s21_size_t j = 0; j < s21_strlen(trim_chars); j++) {
        if (array[i] == trim_chars[j]) {
          match = 1;
        }
      }

      if (match == 0) {
        array = (char *)&array[i];
        stop = 1;
      }
    }
    for (s21_size_t i = s21_strlen(array) - 1; i > 0; i--) {
      char *rez = (char *)s21_strpbrk_end(array, trim_chars);
      if ((rez != s21_NULL) && (array[i] == *rez)) {
        array[i] = '\0';
      } else
        break;
    }
  }
  return array;
}
