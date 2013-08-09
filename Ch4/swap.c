#include <stdio.h>
/* Exercise 4-14. Define a macro swap(t,x,y) that interchanges two 
   arguments of type t */
#define swap(t,x,y) {t temp = x; x = y; y = temp;}

int main(void)
{
  int a = 1;
  int b = 2;
  printf("a: %d, b:%d\n",a,b);
  swap(int, a,b);
  printf("a:%d, b:%d\n",a,b);
  return 0;
}
