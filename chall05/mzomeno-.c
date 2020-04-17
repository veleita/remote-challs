#include <stdio.h>

short ft_ie_except_after_c(char *str)
{
  /*
  * First, we make the first letter lowercase by applying the following mask:
  * 32 = 00100000
  * Thus, if bit 5 was 0 (uppercase letters always have their bit five put to 0),
  * we would set it to 1 (so the resultant byte would be the correspondant
  * lowercase letter). Else, the byte would remain the same.
  *
  * Note that uppercase letters in the middle of the word are not taken into account
  */
  /**
   ** I wanted to put the following line of code into the function:
   ** *str |= 32;
   ** But it doesn’t compile. It throws a segfault error, I haven’t figured out why
   **/
  while (*str)
    { 
      /*
       * Now, we check out the "cie" cases
       */
      if (*str == 'c' && *(str + 1) == 'i' && *(str + 2) == 'e')
      return (0);
      /*
       * Then, we check out the "ei" cases which aren’t preceeded by ’c’
       */
      if (*str == 'e' && *(str + 1) == 'i' && *(str - 1) != 'c')
      return (0);
      /*
       * I am aware that these two conditions could have been put together
       * with an || separator, but for the sake of legibility I will leave
       * the code like that
       */
      str++;
    }
  /*
   * For every possible combination of letters that hasn’t been checked out,
   * the rule is considered to be followed and the program returns true (1).
   */
  return (1);
}

int main()
{
  char *word = "juicier";

  printf ("%s == %d", word, ft_ie_except_after_c(word));
  return (0);
}
