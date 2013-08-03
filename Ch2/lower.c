#include <stdio.h>
/* Exercise 2-10. Rewrite the function lower, using a conditional expression.
   This program tests the lower function by taking a string as a command line 
   argument and converting it to lower case. */
int lower(int c)
{
  return c >= 'A' && c <= 'Z'?c + 'a' - 'A':c;
}

int main(int argc, char** argv)
{
  char* s = argv[1];
  int i = 0;
  for(i = 0;s[i] != '\0';i++)
    {
      s[i] = lower(s[i]);
    }
  printf("%s\n",s);
  return 0;
}
