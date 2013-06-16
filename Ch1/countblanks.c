#include <stdio.h>
/* Exercise 1-8 Write a program to count blanks, tabs and newlines
   Press Ctrl-D on Unix-based systems to see the result. */
int main(void)
{
  int c, blanks,tabs,newlines;
  c = 0;
  blanks = 0;
  tabs = 0;
  newlines = 0;
  while((c = getchar()) != EOF)
    {
      if(c == ' ')
	blanks++;
      else if(c == '\t')
        tabs++;
      else if(c == '\n')
        newlines++;
    }
  printf("%d blanks\n",blanks);
  printf("%d tabs\n", tabs);
  printf("%d newlines\n", newlines);
  return 0;
}
