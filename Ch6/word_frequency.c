#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* Exercise 6-4 Write a program that prints the distinct words in its input
   sorted into decreasing order of frequency of occurrence. Precede each word
   by its count.  */

#define MAXWORDS 10000

struct word{
  char *word;
  int count;
}words[MAXWORDS];

int wordcmp(const void* pa, const void* pb)
{
  struct word a = *(const struct word*)pa;
  struct word b = *(const struct word*)pb;
  if (a.count < b.count)
    return 1;
  else if(a.count > b.count)
    return -1;
  else return 0;
}

int main(int argc, char** argv)
{
  int i,j,found;
  int wordCount = 0;
  for(i = 1;i < argc;i++)
    {
      char* temp = argv[i];
      found = 0;
      for(j=0;j < wordCount;j++)
	{
	  if(strcmp(words[j].word, temp) == 0){
	    words[j].count++;
            found = 1;
            break;
	  }
	}
      if(!found){
	words[wordCount].word = temp;
        words[wordCount].count = 1;
        wordCount++;
      }
    }
  printf("Before sorting:\n");
  for(i = 0;i < wordCount;i++)
    {
      printf("%d %s\n",words[i].count, words[i].word);
    }
  qsort(words,wordCount,sizeof(struct word),wordcmp);
  printf("After sorting:\n");
  for(i = 0;i < wordCount;i++)
    {
      printf("%d %s\n",words[i].count, words[i].word);
    }
  return 0;
}
