#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* Exercise 5-3: Write a pointer version of strcat.
   Compile with -std=c99 to avoid warning about mixed declarations and
   code.
  */

void my_strcat(char* s, char* t);


int main(int argc, char** argv)
{
  if(argc == 3){
    int len_s1 = strlen(argv[1]);
    int total_len = len_s1 + strlen(argv[2]);
    char* s1 = (char*)malloc(sizeof(total_len));
    s1 = argv[1];
    char* s2 = argv[2];
    my_strcat(s1,s2);
    printf("%s\n",s1);
  }
  else{
    printf("Error: strcat needs 3 arguments, received %d",argc);
  }
  return 0;
}

void my_strcat(char* s, char* t)
{
  while(*s != '\0')
    {
      s++;
    }
  while((*s++ = *t++) != '\0');
}
