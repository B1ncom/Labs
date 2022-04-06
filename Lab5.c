#include <stdio.h>
#include <locale.h>

int input(){

    int a;
    printf("%s", "������� �������: ");
    scanf("%d", &a);
    if (a > 0 && a < 100){
        return a;
    }
    else{
        printf("������ �����.");
        return -1;
    }
}

char* sw(int k){
    int b = k;
    if (!(k > 10 && k < 20)){
        b = k%10;
    };

    switch(b){
        case 1: return ("���   ");
        case 2: return ("����   ");
        case 3: return ("����   ");
        case 4: return ("����   ");
        case 11: return ("���   ");
        case 12: return ("���   ");
        case 13: return ("���   ");
        case 14: return ("���   ");
        default: return ("���   ");

    }
}

int output(){
    int age;
    age = input();

    if(age == -1){
        return age;
    }
    else if(age < 18){
        printf("%s %d %s", "��� ������:", age, sw(age));
        printf("%s %d %s", "��� �� ���������������:", 18 - age, sw(18 -age));
        printf("%s %d %s", "��� �� ������:", 60-age, sw(60 - age));
    }
    else if(age == 18){
        printf("%s %d %s", "��� ������:", age, sw(age));
        printf("%s", "�� ����������������!   ");
        printf("%s %d %s", "��� �� ������:", 60-age, sw(60 - age));
    }
    else if(age > 18 && age < 60){
        printf("%s %d %s", "��� ������:", age, sw(age));
        printf("%s %d %s", "�� ���������������� ���:", age - 18, sw(age - 18));
        printf("%s %d %s", "��� �� ������:", 60-age, sw(60 - age));
    }
    else if (age == 60){
        printf("%s %d %s", "��� ������:", age, sw(age));
        printf("%s %d %s", "�� ���������� ������ ���:", age - 18, sw(age - 18));
        printf("%s", "�� ���������!   ");
    }
    else{
        printf("%s %d %s", "��� ������:", age, sw(age));
        printf("%s %d %s", "�� ���������� ������ ���:", age - 18, sw(age - 18));
        printf("%s %d %s", "�� �� ������ ���:", age - 60, sw(age - 60));
    }
    return 1;
}

int main(){
    setlocale(LC_ALL, "Rus");
    output();

    return 0;
}
