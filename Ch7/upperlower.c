#include <stdio.h>
#include <ctype.h>
#include <string.h>
/* Exercise 7-1 Write a program that converts upper case to lower or lower 
   to upper, depending on the name it is invoked with */
int main(int argc,char** argv)
{
  int c;
  char* mode = argv[1];
  if(strcmp("lower",mode)==0){
    while((c = getchar())!= EOF)
      putchar(tolower(c));
  }
  else if(strcmp("upper",mode)==0){
    while((c = getchar()) != EOF)
      putchar(toupper(c));
  }
  return 0;
}
