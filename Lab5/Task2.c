#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    int real;
    int imaginary;
}Complex;

void addNumbers(){
    Complex no1;
    Complex no2;
    Complex result;
    printf("First number:\n");
    printf("Real: ");
    scanf("%d",&no1.real);
    printf("Imaginary: ");
    scanf("%d",&no1.imaginary);
    printf("Second number:\n");
    printf("Real: ");
    scanf("%d",&no2.real);
    printf("Imaginary: ");
    scanf("%d",&no2.imaginary);

    result = (Complex){.real = no1.real+no2.real, .imaginary = no1.imaginary+no2.imaginary};
    printf("\nRESULT: ");
    printf("(%d+%di)\n",result.real,result.imaginary);
}
void multiplyNumbers(){
    Complex no1;
    Complex no2;
    Complex result;
    printf("First number:\n");
    printf("Real: ");
    scanf("%d",&no1.real);
    printf("Imaginary: ");
    scanf("%d",&no1.imaginary);
    printf("Second number:\n");
    printf("Real: ");
    scanf("%d",&no2.real);
    printf("Imaginary: ");
    scanf("%d",&no2.imaginary);

    result = (Complex){
        .real = (no1.real * no2.real) - (no1.imaginary * no2.imaginary),
        .imaginary = (no1.real * no2.imaginary) + (no1.imaginary * no2.real)
    };
    printf("\nRESULT: ");
    printf("(%d+%di)\n",result.real,result.imaginary);
}


int main(){
    int mode = 0;
    while(mode ==0){
        printf("What would you like to do?\n1 -> Add 2 complex numbers\n2 -> multiply 2 complex numbers\n3 -> Exit\n");
        scanf("%d",&mode);
        switch (mode)
        {
        case 1:
            addNumbers();
            mode = 0;
            break;
        case 2:
            multiplyNumbers();
            mode = 0;
            break;
        case 3:
            return 0;
            break;
        default:
            printf("Please choose from 1 -> 3\n");
            mode=0;
        }
    }
    

}