#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h> /* compile with -lm option to use math.h */

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
/* Exercises 4-3, 4-4 and 4-5 of K & R */

int getop(char[]);
void push(double);
double pop(void);
double peek(void);
void dup(void);
void swap(void);

/* reverse Polish calculator */
int main()
{
  int type;
  double op2;
  int op2int;
  char s[MAXOP];
 
  while((type = getop(s)) != EOF)
    {
      switch(type){
      case NUMBER:
	push(atof(s));
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2 = pop();
        if(op2 != 0.0)
          push(pop() / op2);
        else
          printf("error: zero divisor\n");
        break;
      case '%':
        op2int = (int)pop();
        push((int)pop() % op2int);
        break;
      case '\n':
        printf("\t%.8g\n",pop());
        break;
      case 'p':
        op2 = pop();
        printf("%f\n",op2);
        push(op2);
        break;
      case 'd':
        dup();
        break;
      case 's':
        swap();
        break;
      case '^':
        op2int = (int)pop();
        push(pow(pop(),op2int));
        break;
      default:
        printf("error: unknown command %s\n", s);
        break;
      }
    }

  return 0;
}

#define MAXVAL 100 /* maximum depth of val stack */
int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f)
{
  if(sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n",f);
}

/* pop: pop and return top value from stack  */
double pop(void)
{
  if(sp > 0)
    return val[--sp];
  else{
    printf("error: stack empty\n");
    return 0.0;
  }
}

#include <ctype.h>
int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand  */
int getop(char s[])
{
  int i, c;
  
  while((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if(!isdigit(c) && c != '.' && c != '-')
    return c; /* not a number  */
  i = 0;
  if(c == '-'){ /* check if minus operator or start of negative number */
    c = getch();
    if(!isdigit(c)){/* If followed by a space then it's an operator  */
      ungetch(c);
      return '-';
    }
    else{/* Else it's the negative sign of a number  */
      s[i] = '-';
      s[++i] = c;
    }
  }
  if(isdigit(c)) /* collect integer part  */
    while(isdigit(s[++i] = c = getch()))
      ;
  if(c == '.') /* collect fraction part  */
    while(isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if(c != EOF)
    ungetch(c);
  return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch  */
int bufp = 0;      /* next free position in buf  */

int getch(void) /* get a (possibly pushed back) character  */
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input  */
{
  if(bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}

/* peek - print the top element of the stack without popping */
double peek(void)
{
  return val[sp-1];
}

/* dup - duplicate the top element of the stack  */
void dup()
{
  val[sp] = val[sp-1];
  sp++;
}

/* swap the top two elements of the stack  */
void swap()
{
  double temp;
  if(sp < 2){
    printf("error: swap needs 2 or more elements on the stack\n");
  }
  temp = val[sp-1];
  val[sp-1] = val[sp-2];
  val[sp-2] = temp;
}
