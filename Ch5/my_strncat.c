#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* Exercise 5-3: Write a pointer version of strncat.
   Compile with -std=c99 to avoid warning about mixed declarations and
   code.
  */

void my_strncat(char* s, char* t, int n);


int main(int argc, char** argv)
{
  if(argc == 4){
    int len_s1 = strlen(argv[1]);
    int total_len = len_s1 + strlen(argv[2]);
    char* s1 = (char*)malloc(sizeof(total_len));
    s1 = argv[1];
    char* s2 = argv[2];
    int limit = atoi(argv[3]);
    my_strncat(s1,s2,limit);
    printf("%s\n",s1);
  }
  else{
    printf("Error: strcat needs 3 arguments, received %d",argc - 1);
  }
  return 0;
}

void my_strncat(char* s, char* t,int n)
{
  int i = 0;
  while(*s != '\0')
    {
      s++;
    }
  while(i < n && (*s++ = *t++) != '\0')
  {
    i++;
  }
  *s = '\0';
}
