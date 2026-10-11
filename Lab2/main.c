#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void printOddEven(int x,int y){
    while(x <=y){
        if(x%2==0){
            printf("%d is Even\n",x);
        }else{
            printf("%d is Odd\n",x);
        }
        x++;
    }
}
void getFactorial(){
    int x;
    printf("Enter the number to get the factorial :");
    scanf("%d",&x);
    int factorial = 1;
    int OGValue = x;
    while(x>0){
        factorial *=x;
        x--;
    }
    printf("%d! is %d\n",OGValue,factorial);
}
void getMultiplicationTable(){
    int x;
    printf("Enter the number to get the Multiplication table:");
    scanf("%d",&x);
    for(int i = 1; i<=10;i++){
        printf("%d * %d = %d\n",x,i,x*i);
    }
}
void printTriangle(char Symbol,int len){
    for(int i = 0;i<len;i++){
        for(int j = 0;j <=i;j++){
            printf("%c",Symbol);
        }
        printf("\n");
    }
}
void printPyramid(char Symbol,int len){
    for(int i = 0;i<len*2;i+=2){
        for(int j = 0;j <=(len*2-i)/2;j++){
            printf(" ");
        }
        for(int j = 0;j <=i;j++){
            printf("%c",Symbol);
        }
        printf("\n");
    }
}
void primeInRange(int x, int y){
    printf("Prime numbers: ");
    for(int i = x; i<=y;i++){
        if(i != 2 && i%2==0){
            continue;
        }
        if (i <2){
            continue;
        }
        int prime = 1;
        for(int j = 2;j*j <= i;j++){
            if(i % j == 0){
                prime = 0;
                break;
            }
        }
        if(prime){
            printf(" %d",i);
        }
    }
}

void isLeapYear(int year){
    if(year %4 ==0){
        printf("\n %d is a leap year",year);
    }else{
        printf("\n %d is not a leap year",year);
    }
}
void isVowel(char c){
    if(c == 'a' || c == 'A'||c == 'e'||c == 'E'||c == 'i'||c == 'I'||c == 'o'||c == 'O'||c == 'u'||c == 'U'){
        printf("\n %c is a vowel",c);
    }else{
        printf("\n %c is not a vowl",c);
    }
}
void guessTheNumber(){
    int num = rand() % 100;
    int userGuess = -1;
    while(userGuess != num){
        printf("\nGuess the number : ");
        scanf("%d",&userGuess);
        if(userGuess == num){
            printf("Congrats you win!");
            break;
        }else{
            if(num > userGuess){
                printf("Wrong answer try higher!");
            }else{
                printf("Wrong answer try lower!");
            }
        }
    }
}

int main() {
    printOddEven(1,10);
    getFactorial();
    getMultiplicationTable();
    printTriangle('*',5);
    printPyramid('*',5);
    primeInRange(1,100);
    isLeapYear(2024);
    isVowel('a');
    guessTheNumber();
}