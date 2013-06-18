#include <stdio.h>
#include <stdlib.h>

/* Exercise 2-5. Write the function any(s1,s2), which returns the first 
   location in the string s1 where any character from the string s2 occurs,
   or -1 if s1 contains no characters from s2 */

int findLocation(char s[], int c);
int any(char s1[], char s2[]);

int main(int argc, char** argv)
{
  int location = 0;
  if(argc != 3)
    {
      printf("Error: squeeze takes two strings as command line arguments\n");
      return 0;
    }
  char* s1 = argv[1];
  char* s2 = argv[2];
  location = any(s1,s2);
  printf("%d %s %s\n",location, s1,s2);
  return 0;
}

/* Returns the location of a character c if it is found in s, or -1 if not
   found anywhere.  */
int findLocation(char s[], int c)
{
  int i;
  for(i = 0 ;s[i] != '\0';i++)
    {
      if(s[i] == c)
	{
          return i;
        }
    }
  return -1;
}

/* Returns the first location in s1 where any character in s2 occurs, or -1 */
int any(char s1[], char s2[])
{
  int i;
  int min = 1000000;
  int location = 0;
  int found = 0;
  for(i = 0;s2[i] != '\0';i++)
    {
      location = findLocation(s1, s2[i]);
      if(location != -1)
	{
	  found = 1;
          if(location < min)
	   {
	    min = location;
           }
        }
    }
  if(found == 0)
    {
      return -1;
    }
  else
    {
      return min;
    }
}
