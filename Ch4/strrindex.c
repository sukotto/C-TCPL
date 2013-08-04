/* Exercise 4-1. Write the function strrindex(s,t), which returns the
   position of the rightmost occurrence of t in s, or -1 if there is none. */
#include <stdio.h>
#include <string.h>
int strrindex(char s[], char t[])
{
  int i,j,k;
  for(i = strlen(s)-1;i >= 0;i--)
    {
	for(j = i, k = strlen(t)-1;k >= 0 && s[j] == t[k];j--, k--)
	{
          if(k == 0){
	    return j;
	  }
	}
    }
  return -1;
}



int main(int argc, char** argv)
{
  char* t = argv[1];
  char* s = argv[2];
  int index = strrindex(s,t);
  printf("%d\n",index);
  return 0;
}
