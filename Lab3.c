#include <stdio.h>
#include <math.h>
int main(){

    double a;
    double b;
    double c;
    double result1;
    double result2;

    printf("Enter odds a b c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    double Discr = (b*b) - (4*a*c);

    if(Discr < 0){
        printf("No solutions");
    }
    else if(Discr == 0){
        result1 = -b/(2*a);
        printf("Only decision: %.3lf", result1);
        return 1;
    }
    else{
        result1 = (-b + sqrt(Discr))/(2*a);
        result2 = (-b - sqrt(Discr))/(2*a);
        printf( "%s %.3lf %s %.3lf", "First decision:", result1, "Second decision:", result2);
        return 1;
    }
}
