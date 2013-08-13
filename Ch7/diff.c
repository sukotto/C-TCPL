#include <stdio.h>
#include <string.h>
/* Exercise 7-6. Write a program to compare two files, printing the first line
   where they differ.  */
#define MAX 1000

/* getline: read a line, return length */
int getline(char *line, int max,FILE *fp)
{
  if(fgets(line,max,fp)==NULL)
    return 0;
  else
    return strlen(line);
}

int main(int argc, char** argv)
{
  char line1[MAX];
  char line2[MAX];
  char* filename1 = argv[1];
  char* filename2 = argv[2];
  FILE *fp1 = fopen(filename1,"r");
  FILE *fp2 = fopen(filename2,"r");
  int linecount = 0;
  while(getline(line1,MAX,fp1) != 0 && getline(line2,MAX,fp2)!=0)
    {
      linecount++;
      if(strcmp(line1,line2) != 0){
        printf("line number: %d\n",linecount);
	printf("%s: %s\n%s: %s\n",filename1,line1,filename2,line2);
        break; 
      }
    }
  fclose(fp1);
  fclose(fp2);
  return 0;
}
