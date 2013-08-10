#include <stdio.h>
#include <stdlib.h>
int my_strncmp(char* s,char* t,int n);

int main(int argc, char** argv)
{
  if(argc != 4){
    printf("Error: my_strncmp takes 3 arguments, but received %d\n",argc - 1);
    return 0;
  }
  char* s = argv[1];
  char* t = argv[2];
  int n = atoi(argv[3]);
  int result = my_strncmp(s,t,n);
  printf("%d\n",result);
  return 0;
}


/* my_strncmp: return < 0 if s < t, 0 if s == t , >0 if s>t */
int my_strncmp(char* s,char* t,int n)
{
  int i;
  for(i = 0;i < n && *s == *t;s++,t++,i++)
    {
      if(*s == '\0'){
	return 0;
      }
    }
  if(i == n){
    s--;
    t--;
  }
  return *s - *t;
}
