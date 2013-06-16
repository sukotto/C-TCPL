#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000
/* Exercise 1-19. Write a function reverse that reverses the character string
   s. Use it to write a program that reverses its input a line at a time. */
int getaline(char* line, int maxline);
char* reverse(char* line, int length);
int main(void)
{
  int len;
  char line[MAXLINE];
  while((len = getaline(line,MAXLINE)) > 0)
    {
      char* reversed = reverse(line,len);
      printf("%s\n",reversed);
      free(reversed);
    }
  return 0;
}

char* reverse(char* line, int length)
{
  int i;
  char* reversed = malloc(length * sizeof(char));
  for(i = 0;i < length - 1;i++)
    {
      reversed[length - 2 - i] = line[i];
    }
  reversed[length - 1] = '\0';
  return reversed;
}

/* getaline: read a line into s, return length */
int getaline(char s[], int lim)
{
  int c, i;
  for(i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n';i++)
    {
      s[i] = c;
    }
  if(c == '\n')
    {
      s[i] = c;
      i++;
    }
  s[i] = '\0';
  return i;
}
