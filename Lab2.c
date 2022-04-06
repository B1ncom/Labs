#include <time.h>
#include <stdio.h>

int main(){

    int hours;
    hours = (time(NULL)%(3600*24));
    hours /= 3600;

    int minute;
    minute = (time(NULL)%3600);
    minute /= 60;

    int seconds;
    seconds = (time(NULL)%60);

    printf("%02d.%02d.%02d",hours + 3, minute, seconds);
}
