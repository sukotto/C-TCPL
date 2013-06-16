#include <stdio.h>
/* Exercise 1-14 Write a program to print a histogram of the frequencies of
   different alphabetic characters in its input (case-insensitive) */
void printBar(int n);

int main(void)
{
  int c;
  int i;
  int letter[26];
  //Initialise letter array
  for(i = 0;i < 26;i++)
    {
      letter[i] = 0;
    }
  while((c = getchar()) != EOF)
    {
      if(c >= 'A' && c <= 'Z')
	{
	  letter[c - 'A']++;
        }
      else if(c >= 'a' && c <= 'z')
	{
          letter[c - 'a']++;
        }
    }
  printf("Histogram of letter frequencies (case-insensitive)\n");
  for(i = 0;i < 26;i++)
    {
      printf("%c ",(i + 'a'));
      printBar(letter[i]);
      printf("\n");
    } 
  return 0;
}

void printBar(int n)
{
  while(n > 0)
    {
      putchar('*');
      n--;
    }
}

