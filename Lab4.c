#include <stdio.h>
#include <math.h>

double input()
{
    double pogr;
    printf ("Input pogr: ");
    scanf ("%lf", &pogr);
    return pogr;
};

double fib (int k)
{
    double f1, f2, t;
    f1 = 1;
    f2 = 1;
    for (int i = 2; i<k; i++)
    {
        t=f1;
        f1=f2;
        f2+=t;
    }
    return f2;
};

double lim ()
{
    int n;
    double pogr1,s;
    pogr1 = input();
    n = 1;
    s = 1;
    while (fabs(fib(n+2)/fib(n+1)-fib(n+1)/fib(n)) >= pogr1)
    {
          printf("%s %d \n", "Poryadok: ", n);
          s = (fib(n+1))/(fib(n));
          printf("%s %f \n", "Otnosheniye: ", s);
          n += 1;
    }
};

int main ()
{
    lim();
    return 0;
}
