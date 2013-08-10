#include <stdio.h>
#include <stdlib.h>
/* Exercise 5-5 version of the library function strncpy */
void my_strncpy(char* s, char* t, int n);

int main(int argc, char** argv)
{
  if(argc != 4){
    printf("Error: my_strncpy takes 3 arguments, but received %d\n",argc-1);
    return 0;
  }
  char* s = argv[1];
  char* t = argv[2];
  int limit = atoi(argv[3]);
  my_strncpy(s,t,limit);
  printf("%s\n",s);
  return 0;
}

void my_strncpy(char* s,char* t, int n)
{
  int i = 0;
  while((*s++ = *t++) && (i < n - 1))
    {
      i++;
    }
  *s = '\0';
}
