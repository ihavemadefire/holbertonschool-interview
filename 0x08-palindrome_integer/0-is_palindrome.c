#include "palindrome.h"

/**
 * is_palindrome - checks for a palindrome
 * @n: the passed integer
 * Return: 1 if palindrome but if not 0
 */

int is_palindrome(unsigned long n)
{
  unsigned long int remainder = 0;
  unsigned long int reverse = 0;
  unsigned long int t = n;

  if (n < 10)
    {
      return (1);
    }
  while (t != 0)
    {
      remainder = t % 10;
      reverse = reverse * 10 + remainder;
      t /= 10;
    }
  if (reverse == n)
    {
      return (1);
    }
  return (0);
}
