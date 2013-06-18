#include <stdio.h>
#include <stdlib.h>

/* Exercise 2-4. Write an alternate version of squeeze(s1,s2) that deletes
   each character in s1 that matches any character in s2 */
void squeeze(char s1[], char s2[]);
void removeChar(char s[], int c);

int main(int argc, char** argv)
{
  if(argc != 3)
    {
      printf("Error: squeeze takes two strings as command line arguments\n");
      return 0;
    }
  char* s1 = argv[1];
  char* s2 = argv[2];
  squeeze(s1,s2);
  printf("%s %s\n",s1,s2);
  return 0;
}

void removeChar(char s[], int c)
{
  int i, j;
  for(i = j = 0;s[i] != '\0';i++)
    {
      if(s[i] != c)
	{
          s[j++] = s[i];
        }
    }
  s[j] = '\0';
}

void squeeze(char s1[], char s2[])
{
  int i;
  for(i = 0;s2[i] != '\0';i++)
    {
      removeChar(s1, s2[i]);
    }
}
