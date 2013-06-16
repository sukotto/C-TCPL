#include <stdio.h>
/* Write a program to copy input to output, replacing each tab with \t, 
   each backspace with \b and each backslash with \ */
int main(void)
{
  
  int c; //int is used because char is not big enough for EOF
  while((c = getchar()) != EOF)
    {
      if(c == '\t')
	{
	  printf("\\t");
	}
      else if(c == '\b')
	{
          printf("\\b");
	}
      else if(c == '\\')
	{
          printf("\\\\");
	}
      else
	{
        putchar(c);
	}
    }
}
