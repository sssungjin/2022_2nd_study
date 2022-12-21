#include <stdio.h>

int main()
{
    printf("short : %d\n", sizeof(short));
    printf("int : %d\n", sizeof(int));
    printf("long : %d\n", sizeof(long));
    printf("float : %d\n", sizeof(float));
    printf("double : %d\n", sizeof(double));
}

char *str = “programming”;

string str = “programming”;

char[] str = {'p', 'r', 'o', 'g', 'r', 'a', 'm', 'm', 'i', 'n', 'g'};

enum day
{
    SUN,
    MON,
    TUE,
    WED,
    THU,
    FRI,
    SAT
};

type day is(SUN, MON, TUE, WED, THU, FRI, SAT);

subtype workday is day range MON..FRI;

today : workday;

today : = TUE;

type
    student = record
        name : packed array[1..20] of char;
number : integer;
address : packed array[1..30] of char
              end;

struct student
{
    char name[20];
    int number;
    char address[30];
};
struct student A;

type student is record
    name : string(1..20);
    number : integer;
    address : string(1..30);
end record;
A : student;


union product {
float liter;
int number;
char name[10];
};
union product A;

01 int a=3;
02 int *ptr;
03 ptr = &a;
04 printf("%d", *ptr);
