#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int htoi(char* hex);
/* Exercise 2-3  Convert a string of hexadecimal digits to a decimal number 
 using a command line argument 
   (Compile with '-lm' flag e.g. 'gcc -Wall htoi.c -o htoi -lm' to avoid 
    errors regarding the 'pow' function)*/
int main(int argc, char** argv)
{
  if(argc != 2)
    {
      printf("Error: htoi needs one hexadecimal number as a command"
	     "line argument\n");
      return 0;
    }
  char* hexadecimal = argv[1];
  int decimal = htoi(hexadecimal); 
  printf("hexadecimal %s is %d in decimal numbers\n",argv[1],decimal);
  return 0;
}

int htoi(char* hex)
{
  //Remove optional "0x" or "0X" from the hexadecimal string
  if(hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X'))
    {
      hex += 2;
    }
  int i = 0; 
  int dec[strlen(hex)];
  int exponent = 0;
  int sum = 0;
  /* Fill an array with an integer for each digit in hex 
     from '0' to 'F' */
  while(hex[i] != '\0')
    {
      if(hex[i] >= '0' && hex[i] <= '9')
	{
	  dec[i] = hex[i] - '0';
        }
      else if(hex[i] >= 'a' && hex[i] <= 'f')
	{
          dec[i] = hex[i] - 'a' + 10;
        }
      else if(hex[i] >= 'A' && hex[i] <= 'F')
	{
          dec[i] = hex[i] - 'A' + 10;
        }
      i++;
    }
  /* Get the decimal value */
  for(i = strlen(hex) - 1;i >= 0;i--,exponent++)
    {
      sum += dec[i] * pow(16, exponent);
    }
  return sum;
}
