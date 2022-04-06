#include <stdio.h>
#include <locale.h>

int input(){

    int a;
    printf("%s", "Введите возраст: ");
    scanf("%d", &a);
    if (a > 0 && a < 100){
        return a;
    }
    else{
        printf("Ошибка ввода.");
        return -1;
    }
}

char* sw(int k){
    int b = k;
    if (!(k > 10 && k < 20)){
        b = k%10;
    };

    switch(b){
        case 1: return ("год   ");
        case 2: return ("года   ");
        case 3: return ("года   ");
        case 4: return ("года   ");
        case 11: return ("лет   ");
        case 12: return ("лет   ");
        case 13: return ("лет   ");
        case 14: return ("лет   ");
        default: return ("лет   ");

    }
}

int output(){
    int age;
    age = input();

    if(age == -1){
        return age;
    }
    else if(age < 18){
        printf("%s %d %s", "Вам сейчас:", age, sw(age));
        printf("%s %d %s", "Вам до совершеннолетия:", 18 - age, sw(18 -age));
        printf("%s %d %s", "Вам до пенсии:", 60-age, sw(60 - age));
    }
    else if(age == 18){
        printf("%s %d %s", "Вам сейчас:", age, sw(age));
        printf("%s", "Вы совершеннолетний!   ");
        printf("%s %d %s", "Вам до пенсии:", 60-age, sw(60 - age));
    }
    else if(age > 18 && age < 60){
        printf("%s %d %s", "Вам сейчас:", age, sw(age));
        printf("%s %d %s", "Вы совершеннолетний уже:", age - 18, sw(age - 18));
        printf("%s %d %s", "Вам до пенсии:", 60-age, sw(60 - age));
    }
    else if (age == 60){
        printf("%s %d %s", "Вам сейчас:", age, sw(age));
        printf("%s %d %s", "Вы совершенно летний уже:", age - 18, sw(age - 18));
        printf("%s", "Вы пенсионер!   ");
    }
    else{
        printf("%s %d %s", "Вам сейчас:", age, sw(age));
        printf("%s %d %s", "Вы совершенно летний уже:", age - 18, sw(age - 18));
        printf("%s %d %s", "Вы на пенсии уже:", age - 60, sw(age - 60));
    }
    return 1;
}

int main(){
    setlocale(LC_ALL, "Rus");
    output();

    return 0;
}
