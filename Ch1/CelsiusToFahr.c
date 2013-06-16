#include <stdio.h>
/* "The C Programming Language - Chapter 1, Exercise 1.4
 Print Celsius-Fahr table for celsius = 0, 10, ..., 300; floating-point 
version*/
int main(void)
{
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 10;
  
  fahr = lower;
  printf("Celsius-Fahrenheit\n");
  printf("===================\n");
  while(fahr <= upper)
    {
      fahr = (celsius * 9.0/5.0) + 32;
      printf("%6.1f       %3.0f\n", celsius, fahr);
      celsius = celsius + step;
    }
  return 0;
}
