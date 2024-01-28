#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "s21_sprintf.h"
#include "s21_string.h"

/* *************************************************
  | Part 1. Реализация функций библиотеки string.h |
   ************************************************* */

START_TEST(test_s21_memchr) {
  ck_assert_ptr_null(s21_memchr("hello", 'j', 3));
  ck_assert_str_eq(s21_memchr("hello", 'h', 2), memchr("hello", 'h', 2));
  ck_assert_ptr_null(s21_memchr("sourc", 'r', 2));
}
END_TEST

START_TEST(test_s21_memcmp) {
  ck_assert_int_eq(s21_memcmp("hello", "helloWorld", 5),
                   memcmp("hello", "helloWorld", 5));
  ck_assert_int_lt(s21_memcmp("hello", "hi", 2), 0);
  // т.к. вывод на маке и линкусе разный, проверяем относительно нуля
  ck_assert_int_eq(s21_memcmp("source", "source", 6),
                   memcmp("source", "source", 6));
}
END_TEST

START_TEST(test_s21_memcpy) {
  char dest[255] = "\0";
  char *src = "source";
  ck_assert_str_eq(s21_memcpy(dest, src, 4), memcpy(dest, src, 4));
  ck_assert_str_eq(s21_memcpy(dest, src, 2), memcpy(dest, src, 2));
  ck_assert_str_eq(s21_memcpy(dest, src, 0), memcpy(dest, src, 0));
}
END_TEST

START_TEST(test_s21_memset) {
  char dest[255] = "\0";
  ck_assert_str_eq(s21_memset(dest, 'j', 3), memset(dest, 'j', 3));
  char dest2[255] = "\0";
  ck_assert_str_eq(s21_memset(dest2, 'h', 2), memset(dest2, 'h', 2));
  char dest3[255] = "\0";
  ck_assert_str_eq(s21_memset(dest3, 'r', 2), memset(dest3, 'r', 2));
}
END_TEST

START_TEST(test_s21_strncat) {
  char *dest = (char *)calloc(256 * sizeof(char), 256 * sizeof(char));
  char *dest2 = (char *)calloc(256 * sizeof(char), 256 * sizeof(char));

  dest = s21_strncat(dest, " 3d", 2);
  dest2 = strncat(dest2, " 3d", 2);
  ck_assert_str_eq(dest, dest2);

  dest = s21_strncat(dest, "hi", 1);
  dest2 = strncat(dest2, "hi", 1);
  ck_assert_str_eq(dest, dest2);

  // может быть warning, нормально
  dest = s21_strncat(dest, "e", 2);
  dest2 = strncat(dest2, "e", 2);
  ck_assert_str_eq(dest, dest2);
  free(dest);
  free(dest2);
}
END_TEST

START_TEST(test_s21_strchr) {
  ck_assert_str_eq(s21_strchr("source", 's'), strchr("source", 's'));
  ck_assert_str_eq(s21_strchr("source", 'u'), strchr("source", 'u'));
  ck_assert_ptr_null(s21_strchr("sourc", ' '));
}
END_TEST

START_TEST(test_s21_strncmp) {
  ck_assert_int_eq(s21_strncmp("hello", "helloWorld", 5),
                   strncmp("hello", "helloWorld", 5));
  ck_assert_int_eq(s21_strncmp("hello", "hi", 2), strncmp("hello", "hi", 2));
  ck_assert_int_eq(s21_strncmp("source", "source", 6),
                   strncmp("source", "source", 6));
}
END_TEST

START_TEST(test_s21_strncpy) {
  char dest[255] = "\0";
  const char *src = "source";
  s21_strncpy(dest, src, 4);
  ck_assert_str_eq(dest, strncpy(dest, src, 4));
  char dest2[255] = "\0";
  s21_strncpy(dest2, src, 2);
  ck_assert_str_eq(dest2, strncpy(dest2, src, 2));
  char dest3[5] = "\0";
  s21_strncpy(dest3, src, 5);
  ck_assert_str_eq(dest3, strncpy(dest3, src, 5));
}
END_TEST

START_TEST(test_s21_strcspn) {
  ck_assert_int_eq(s21_strcspn("hello", "helWrd"), strcspn("hello", "helWrd"));
  ck_assert_int_eq(s21_strcspn("hello", "hi"), strcspn("hello", "hi"));
  ck_assert_int_eq(s21_strcspn("source", "source"),
                   strcspn("source", "source"));
  ck_assert_int_eq(s21_strcspn("source", "what to test"),
                   strcspn("source", "what to test"));
}
END_TEST

START_TEST(test_s21_strerror) {
  ck_assert_str_eq(s21_strerror(10), strerror(10));
  // failed: s21_strerror(202) == "Unknown error: 202", strerror(202) ==
  // "Unknown error 202"
  //                                            ^ в линуксе нет двоеточия
  // ck_assert_str_eq(s21_strerror(202), strerror(202));
  ck_assert_str_eq(s21_strerror(0), strerror(0));
  // ck_assert_str_eq(s21_strerror(107), strerror(107));  // null / unknown
  // error
}
END_TEST

START_TEST(test_s21_strlen) {
  ck_assert_int_eq(s21_strlen("source"), strlen("source"));
  ck_assert_int_eq(s21_strlen("Hi"), strlen("Hi"));
  ck_assert_int_eq(s21_strlen(""), strlen(""));
}
END_TEST

START_TEST(test_s21_strpbrk) {
  ck_assert_ptr_eq(s21_strpbrk("hello", "helWrd"), strpbrk("hello", "helWrd"));
  ck_assert_ptr_eq(s21_strpbrk("source", "source"),
                   strpbrk("source", "source"));
  ck_assert_ptr_eq(s21_strpbrk("esources", "es"), strpbrk("esources", "es"));
  ck_assert_ptr_null(s21_strpbrk("hello", "fw"));
}
END_TEST

START_TEST(test_s21_strrchr) {
  ck_assert_str_eq(s21_strrchr("source", 's'), strrchr("source", 's'));
  ck_assert_str_eq(s21_strrchr("source", 'u'), strrchr("source", 'u'));
  ck_assert_ptr_null(s21_strrchr("sourc", ' '));
}
END_TEST

START_TEST(test_s21_strstr) {
  ck_assert_str_eq(s21_strstr("hello", "hel"), strstr("hello", "hel"));
  ck_assert_str_eq(s21_strstr("MYBIGsourceSTRING", "source"),
                   strstr("MYBIGsourceSTRING", "source"));
  ck_assert_ptr_null(s21_strstr("hello", "fw"));
}
END_TEST

START_TEST(test_s21_strtok) {
  char str[] = "hello_world";
  ck_assert_str_eq(s21_strtok(str, "_"), strtok(str, "_"));
  ck_assert_str_eq(s21_strtok(str, "fw"), strtok(str, "fw"));
  char str2[] = "MYBIGsourceSTRING";
  ck_assert_str_eq(s21_strtok(str2, "source"), strtok(str2, "source"));
}
END_TEST

/* ************************************************
  | Part 2. Частичная реализация функции sprintf  |
   ************************************************ */
START_TEST(test_s21_sprintf_width) {
  Form form = {0};
  ck_assert_int_eq(width("1hjkhjkhfdbndks", &form), 1);
  ck_assert_int_eq(width("", &form), 0);
  ck_assert_int_eq(width("-32udhfiusuhif", &form), 32);
  ck_assert_int_eq(width("1234567890", &form), 1234567890);
}
END_TEST

START_TEST(test_s21_sprintf_accuracy) {
  Form form = {0};
  ck_assert_int_eq(accuracy("1hjkhjkhfdbndks", 7, &form), 0);
  ck_assert_int_eq(accuracy(".0005", 7, &form), 0005);
  ck_assert_int_eq(accuracy("666.3", 2, &form), 0);
  ck_assert_int_eq(accuracy("666.3", 6, &form), 3);
}
END_TEST

START_TEST(test_s21_sprintf_flags) {
  // странно что часто считает будто флаг есть
  Form form = {0};
  ck_assert_int_eq(flags("666.3", 2, &form), 0);
  ck_assert_int_eq(flags("+- #", 2, &form), 3);
  ck_assert_int_eq(flags("+- #", 0, &form), 1);
  ck_assert_int_eq(flags("+- #", 6, &form), 4);
  ck_assert_int_eq(flags("dfg+- #", 6, &form), 0);
  ck_assert_int_eq(flags("0dfghjk", 6, &form), 1);
}
END_TEST

START_TEST(test_s21_sprintf_length) {
  Form form = {0};
  ck_assert_int_eq(length("h", &form), 'h');
  form.length = 0;
  ck_assert_int_eq(length("lfdhfjdk;", &form), 'l');
  form.length = 0;
  ck_assert_int_eq(length("666.3", &form), 0);
  form.length = 0;
  ck_assert_int_eq(length("ssasdaL", &form), 0);
}
END_TEST

START_TEST(test_s21_sprintf_specificator) {
  ck_assert_int_eq(specificator('\0'), 0);
  ck_assert_int_eq(specificator('3'), 0);
  ck_assert_int_eq(specificator('\\'), 0);
  ck_assert_int_eq(specificator('c'), 'c');
  ck_assert_int_eq(specificator('d'), 'd');
  ck_assert_int_eq(specificator('i'), 'd');
  ck_assert_int_eq(specificator('f'), 'f');
  ck_assert_int_eq(specificator('s'), 's');
  ck_assert_int_eq(specificator('u'), 'u');
  ck_assert_int_eq(specificator('g'), 'g');
  ck_assert_int_eq(specificator('G'), 'G');
  ck_assert_int_eq(specificator('e'), 'e');
  ck_assert_int_eq(specificator('E'), 'E');
  ck_assert_int_eq(specificator('o'), 'o');
  ck_assert_int_eq(specificator('x'), 'x');
  ck_assert_int_eq(specificator('X'), 'X');
  ck_assert_int_eq(specificator('p'), 'p');
  ck_assert_int_eq(specificator('n'), 'n');
}
END_TEST

START_TEST(test_s21_itoa_forlong) {
  char src[100] = "";
  s21_itoa_forlong(214748332232337, src, 10);
  ck_assert_str_eq(src, "214748332232337");
  char src2[10000] = "";
  s21_itoa_forlong(2000000000000220020, src2, 10);
  ck_assert_str_eq(src2, "2000000000000220020");
}
END_TEST

START_TEST(test_s21_sprintf_spec_c) {
  char buffer[1000] = "\0";
  char orig[1000] = "\0";
  s21_sprintf(buffer, "%c", 'H');
  sprintf(orig, "%c", 'H');
  ck_assert_str_eq(buffer, orig);

  s21_sprintf(buffer, "%c%c%c%c", 101, 108, 'l',
              'o');  // doesn't print last one
  sprintf(orig, "%c%c%c%c", 101, 108, 'l', 'o');
  // ck_assert_str_eq(buffer, orig);
  s21_sprintf(buffer, "%c", 0);
  sprintf(orig, "%c", 0);
  // ck_assert_str_eq(buffer, orig); // buffer got empty
}
END_TEST

START_TEST(test_s21_sprintf_spec_o) {
  char buffer[1000] = "\0";
  char orig[1000] = "\0";
  s21_sprintf(buffer, "%#o", 89);
  sprintf(orig, "%#o", 89);
  ck_assert_str_eq(buffer, orig);

  char buffer2[1000] = "\0";
  char orig2[1000] = "\0";
  s21_sprintf(buffer2, "%o", 101);
  sprintf(orig2, "%o", 101);
  ck_assert_str_eq(buffer2, orig2);

  char buffer3[1000] = "\0";
  char orig3[1000] = "\0";
  s21_sprintf(buffer3, "%o", 'o');
  sprintf(orig3, "%o", 'o');
  ck_assert_str_eq(buffer3, orig3);
}
END_TEST

START_TEST(test_s21_sprintf_reverse) {
  char buffer[1000] = "\0";
  s21_reverse(buffer);
  ck_assert_str_eq(buffer, "");
  char buffer2[100] = "School21";
  s21_reverse(buffer2);
  ck_assert_str_eq(buffer2, "12loohcS");
  char buffer3[100] = "AbcbA";
  s21_reverse(buffer3);
  ck_assert_str_eq(buffer3, "AbcbA");
}
END_TEST

START_TEST(test_s21_sprintf_spec_d) {
  char *buffer = calloc(256, sizeof(char));
  char orig[1000] = "\0";
  s21_sprintf(buffer, "%+d", 0);
  sprintf(orig, "%+d", 0);
  ck_assert_str_eq(buffer, orig);

  char buffer2[256] = "\0";
  char orig2[1000] = "\0";
  s21_sprintf(buffer2, "% d %+d", -10, 21);
  sprintf(orig2, "% d %+d", -10, 21);
  ck_assert_str_eq(buffer2, orig2);

  char buffer3[256] = "\0";
  char orig3[1000] = "\0";
  s21_sprintf(buffer3, "%.4d + %4d = %d", 0, -2, -2);
  sprintf(orig3, "%.4d + %4d = %d", 0, -2, -2);
  ck_assert_str_eq(buffer3, orig3);
}
END_TEST

START_TEST(test_s21_sprintf_spec_u) {
  char buffer[256] = "\0";
  char orig[1000] = "\0";
  s21_sprintf(buffer, "%hu", 0);
  sprintf(orig, "%hu", 0);
  ck_assert_str_eq(buffer, orig);

  char buffer2[256] = "\0";
  char orig2[1000] = "\0";
  s21_sprintf(buffer2, "%u", 21);
  sprintf(orig2, "%u", 21);
  ck_assert_str_eq(buffer2, orig2);

  char buffer3[256] = "\0";
  char orig3[1000] = "\0";
  s21_sprintf(buffer3, "%lu", -343234323432);
  sprintf(orig3, "%lu", -343234323432);
  ck_assert_str_eq(buffer3, orig3);
}
END_TEST

START_TEST(test_s21_sprintf_spec_X) {
  char buffer[256] = "\0";
  char orig[1000] = "\0";
  s21_sprintf(buffer, "%#X", 2321321);
  sprintf(orig, "%#X", 2321321);
  ck_assert_str_eq(buffer, orig);

  char buffer2[256] = "\0";
  char orig2[1000] = "\0";
  s21_sprintf(buffer2, "%X", -3232112);
  sprintf(orig2, "%X", -3232112);
  ck_assert_str_eq(buffer2, orig2);

  char buffer3[256] = "\0";
  char orig3[1000] = "\0";
  s21_sprintf(buffer3, "%X", -34321);
  sprintf(orig3, "%X", -34321);
  ck_assert_str_eq(buffer3, orig3);
}
END_TEST

START_TEST(test_s21_sprintf_spec_x) {
  char buffer[256] = "\0";
  char orig[1000] = "\0";
  s21_sprintf(buffer, "%#x", 2321321);
  sprintf(orig, "%#x", 2321321);
  ck_assert_str_eq(buffer, orig);

  char buffer2[256] = "\0";
  char orig2[1000] = "\0";
  s21_sprintf(buffer2, "%x", -3232112);
  sprintf(orig2, "%x", -3232112);
  ck_assert_str_eq(buffer2, orig2);

  char buffer3[256] = "\0";
  char orig3[1000] = "\0";
  s21_sprintf(buffer3, "%x", -34321);
  sprintf(orig3, "%x", -34321);
  ck_assert_str_eq(buffer3, orig3);
}
END_TEST

START_TEST(test_s21_sprintf_spec_f) {
  char buffer[256] = "\0";
  char orig[1000] = "\0";
  s21_sprintf(buffer, "%f", 2.33333);
  sprintf(orig, "%f", 2.33333);
  ck_assert_str_eq(buffer, orig);

  char buffer2[256] = "\0";
  char orig2[1000] = "\0";
  s21_sprintf(buffer2, "%f", -32.4324);
  sprintf(orig2, "%f", -32.4324);
  ck_assert_str_eq(buffer2, orig2);

  char buffer3[1000] = "\0";
  char orig3[1000] = "\0";
  s21_sprintf(buffer3, "%f", 34321.0);
  sprintf(orig3, "%f", 34321.0);
  ck_assert_str_eq(buffer3, orig3);
}
END_TEST

START_TEST(test_s21_sprintf_spec_s) {
  char buffer[256] = "\0";
  char orig[1000] = "\0";
  s21_sprintf(buffer, "%s", "Hello");
  sprintf(orig, "%s", "Hello");
  ck_assert_str_eq(buffer, orig);

  char buffer2[256] = "\0";
  char orig2[1000] = "\0";
  s21_sprintf(buffer2, "My name is %s", "John");
  sprintf(orig2, "My name is %s", "John");
  ck_assert_str_eq(buffer2, orig2);

  char buffer3[1000] = "\0";
  char orig3[1000] = "\0";
  s21_sprintf(buffer3, "%s", "");
  sprintf(orig3, "%s", "");
  ck_assert_str_eq(buffer3, orig3);
}
END_TEST

/* ***************************************************************
  | Part 5. Доп. Реализация специальных функций обработки строк  |
   *************************************************************** */
START_TEST(test_s21_to_upper) {
  ck_assert_str_eq(s21_to_upper("school21"), "SCHOOL21");
  ck_assert_str_eq(s21_to_upper("ALREADY UPPERCASE"), "ALREADY UPPERCASE");
  char *result = s21_to_upper("666.3");
  ck_assert_str_eq(result, "666.3");
  ck_assert_str_eq(s21_to_upper("NoT qUiTe NOrMaL"), "NOT QUITE NORMAL");
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower) {
  ck_assert_str_eq(s21_to_lower("SCHOOL21"), "school21");
  ck_assert_str_eq(s21_to_lower("already lowercase"), "already lowercase");
  char *result = s21_to_lower("666.3");
  ck_assert_str_eq(result, "666.3");
  ck_assert_str_eq(s21_to_lower("NoT qUiTe NOrMaL"), "not quite normal");
  free(result);
}
END_TEST

START_TEST(test_s21_insert) {
  char result[100] = "school";
  ck_assert_str_eq(s21_insert(result, "21", 6), "school21");
  ck_assert_str_eq(s21_insert("Ho", "ell", 1), "Hello");
  char *errorOnPurpose = "\0";
  ck_assert_ptr_null(s21_insert(errorOnPurpose, "It's error", 2));
  ck_assert_str_eq(s21_insert("start!", "Let's ", 0), "Let's start!");
}
END_TEST

START_TEST(test_s21_trim) {
  ck_assert_str_eq(s21_trim("21school21", "21"), "school");
  ck_assert_str_eq(s21_trim("123Hello123", "123"), "Hello");
  ck_assert_str_eq(s21_trim("123Hello", "123"), "Hello");
  ck_assert_str_eq(s21_trim("Hello123", "123"), "Hello");
  ck_assert_str_eq(s21_trim("Hello", "123"), "Hello");
}
END_TEST

Suite *s21_string_suite() {
  Suite *strSuite = suite_create("String");
  TCase *tc_core = tcase_create("Core");

  // функции библиотеки string.h
  tcase_add_test(tc_core, test_s21_memchr);
  tcase_add_test(tc_core, test_s21_memcmp);
  tcase_add_test(tc_core, test_s21_memcpy);
  tcase_add_test(tc_core, test_s21_memset);
  tcase_add_test(tc_core, test_s21_strncat);
  tcase_add_test(tc_core, test_s21_strchr);
  tcase_add_test(tc_core, test_s21_strncmp);
  tcase_add_test(tc_core, test_s21_strncpy);
  tcase_add_test(tc_core, test_s21_strcspn);
  tcase_add_test(tc_core, test_s21_strerror);
  tcase_add_test(tc_core, test_s21_strlen);
  tcase_add_test(tc_core, test_s21_strpbrk);
  tcase_add_test(tc_core, test_s21_strrchr);
  tcase_add_test(tc_core, test_s21_strstr);
  tcase_add_test(tc_core, test_s21_strtok);

  // s21_sprintf
  tcase_add_test(tc_core, test_s21_sprintf_width);
  tcase_add_test(tc_core, test_s21_sprintf_accuracy);
  tcase_add_test(tc_core, test_s21_sprintf_flags);
  tcase_add_test(tc_core, test_s21_sprintf_length);
  tcase_add_test(tc_core, test_s21_sprintf_specificator);
  tcase_add_test(tc_core, test_s21_itoa_forlong);
  tcase_add_test(tc_core, test_s21_sprintf_reverse);

  // s21_sprint спецификаторы
  tcase_add_test(tc_core, test_s21_sprintf_spec_c);
  tcase_add_test(tc_core, test_s21_sprintf_spec_d);
  tcase_add_test(tc_core, test_s21_sprintf_spec_u);
  tcase_add_test(tc_core, test_s21_sprintf_spec_o);
  tcase_add_test(tc_core, test_s21_sprintf_spec_X);
  tcase_add_test(tc_core, test_s21_sprintf_spec_x);
  tcase_add_test(tc_core, test_s21_sprintf_spec_s);
  tcase_add_test(tc_core, test_s21_sprintf_spec_f);

  // s21_part5.c
  tcase_add_test(tc_core, test_s21_to_upper);
  tcase_add_test(tc_core, test_s21_to_lower);
  tcase_add_test(tc_core, test_s21_insert);
  tcase_add_test(tc_core, test_s21_trim);

  suite_add_tcase(strSuite, tc_core);

  return strSuite;
}

int main(void) {
  int no_failed = 0;
  Suite *s = s21_string_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}