#include <stdio.h>

struct date{
    int year;
    int month;
    int day;
};

struct test{   
    int number;
    char name[20];
    double grade;
    struct date date1;
};

int main(void){
    struct test test1;
    printf("%lu\n", sizeof(test1));
    return 0;
}