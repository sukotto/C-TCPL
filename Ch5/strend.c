#include <stdio.h>
#include <string.h>
/* Exercise 5-4 strend(s,t) returns 1 if the string t occurs at the end of
   string s, and zero otherwise */
int strend(char* s,char *t);

int main(int argc, char** argv)
{
  if(argc != 3){
    printf("Error: strend takes 2 arguments but received %d\n",argc-1);
  }
  else{
    int result = -1;
    char* s = argv[1];
    char* t = argv[2];
    result = strend(s,t);
    printf("%d \"%s\" \"%s\"\n",result,s,t);
    result = strend(t,s);
    printf("%d \"%s\" \"%s\"\n",result,t,s);
  }
  return 0;
}

int strend(char* s, char* t)
{
  int s_len = strlen(s);
  int t_len = strlen(t);
  int i,j;
  for(i = s_len - 1,j = t_len - 1; 
         i > ((s_len - t_len) - 1) && j >= 0;i--,j--)
    {
      if(s[i] != t[j])
	return 0;
    }
  return 1;
}
