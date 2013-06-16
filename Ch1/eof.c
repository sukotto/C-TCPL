#include <stdio.h>
/* Copy input to output; 2nd version */
int main(void)
{
  //Exercise 1-6. Verify that getchar()!=EOF is 0 or 1
  printf("Value of 'getchar()!=EOF' is %d\n",getchar()!=EOF);
  //Exercise 1-7. Print the value of EOF
  printf("Value of EOF = %d\n",EOF);

  return 0;
}
