#include <stdio.h>
#include <math.h>

int calcPerimeter(int a, int b);
void dayPrinter(int days);
double distanceBetweenPoints(int x1, int x2, int y1, int y2);
void secondsPrinter(int seconds);
int checkMultiplied(int x, int y);
void printMonth(int month);
void printAllDivisableNumbers(int num);

int main() {
    
    printf("Perimeter 5 10: %d\n", calcPerimeter(5, 10));
    dayPrinter(400);

    printf("\nDistance between (0,0) and (3,4): %f\n", distanceBetweenPoints(0, 3, 0, 4));
    
    secondsPrinter(3665);

    printf("\ncheck multiplied 4&12 %d\n", checkMultiplied(4, 12));
    printf("check multiplied 7&3 %d\n", checkMultiplied(7, 3));
    
    printf("\nMonth 10: ");
    printMonth(10);
    
    printf("\nNumbers up to 100 divisible by 25:\n");
    printAllDivisableNumbers(25);
    return 0;
}

int calcPerimeter(int a,int b){
    return (a+b)*2;
}
void dayPrinter(int days){
    int years = days /365;
    int months = (days % 365) / 30;
    int day = (days % 365) % 30;

    printf("Years : %d , Months : %d , Days : %d",years,months,day);
}
double distanceBetweenPoints(int x1,int x2,int y1,int y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
void secondsPrinter(int seconds){
    int Hours = seconds /(60*60);
    int Minutes = (seconds % (60*60)) / 60;
    int Seconds = seconds % 60;

    printf("Hours : %d , Minutes : %d , Seconds : %d",Hours,Minutes,Seconds);
}
int checkMultiplied(int x,int y){
    if (x == 0 | y == 0){
        return 0;
    }
    if(x % y == 0 || y % x ==0){
        return 1;
    }else{
        return 0;
    }
}
void printMonth(int month){
    switch (month)
    {
    case 1:
        printf("january");
        break;
    case 2:
        printf("february");
        break;
    case 3:
        printf("march");
        break;
    case 4:
        printf("april");
        break;
    case 5:
        printf("may");
        break;
    case 6:
        printf("june");
        break;
    case 7:
        printf("july");
        break;
    case 8:
        printf("august");
        break;
    case 9:
        printf("september");
        break;
    case 10:
        printf("october");
        break;
    case 11:
        printf("november");
        break;
    case 12:
        printf("december");
        break;
    }
}

void printAllDivisableNumbers(int num){
    for (int i = num;i<=100;i+=num){
        printf("%d ",i);
    }
}

