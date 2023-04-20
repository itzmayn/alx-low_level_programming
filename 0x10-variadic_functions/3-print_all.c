#include "variadic_functions.h"

/**
 * print_char - Prints a char.
 * @arg: A list of arguments pointing to
 *       the character to be printed.
 */
void print_char(va_list arg)
{
  char character;

  character = va_arg(arg, int);

  printf("%c", character);
}

/**
 * print_int - Prints an int.
 * @arg: A list of arguments pointing to
 *         the integer to be printed.
 */
void print_int(va_list arg)
{
  int integer;

  integer = va_arg(arg, int);

  printf("%d", integer);
}

/**
 * print_float - Prints a float.
 * @arg: A list of arguments pointing to
 *           the float to be printed.
 */
void print_float(va_list arg)
{
  float floating_point;

  floating_point = va_arg(arg, double);

  printf("%f", floating_point);
}

/**
 * print_string - Prints a string.
 * @arg: A list of arguments pointing to
 *           the string to be printed.
 */
void print_string(va_list arg)
{
  char *string;

  string = va_arg(arg, char *);

  if (string == NULL)
  {
    printf("(nil)");
    return;
  }

  printf("%s", string);
}

/**
 * print_all - prints anything
 * @format: format of input
 *
 * Return: nothing
 */
void print_all(const char * const format, ...)
{
  va_list args;

  int i = 0, j = 0;

  char *separator = "";

  printer_t functions[] = {
    {"c", print_char},
    {"i", print_int},
    {"f", print_float},
    {"s", print_string}
  };

  va_start(args, format);

  while (format && (*(format + i)))
  {
    j = 0;

    while (j < 4 && (*(format + i) != *(functions[j].symbol)))
    {
      j++;
    }

    if (j < 4)
    {
      printf("%s", separator);
      functions[j].print(args);
      separator = ", ";
    }

    i++;
  }

  printf("\n");

  va_end(args);
}
