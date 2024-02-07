//CERT (C Secure Coding Standard)
// EVITA printf("Sum is: %d\n", num1 + num2); CON ESCAPE CHAR /N PER INSERIRE UNA NUOVA LINEA
// USA puts("Sum is: %d\n", num1 + num2); PER INSERIRE UNA NUOVA LINEA
// SE INVECE NON HO BISOGNO DI INSERIRE UNA NUOVA LINEA USA PRINTF CON LA STRINGA DI CONTROLLO %S  printf( "%s","WELCOME TO C!");

#include<stdio.h>
#include<stdbool.h>


bool calculate(){
    int num1;
    int rest;

    bool isEven = false;

    puts("Enter Number:");// inserire i due numeri
    scanf("%d",&num1);
    rest = num1 % 2;
    if(rest == 0){
        isEven = true;
    }
    return isEven;
}

int main (){
    if(calculate()){
        printf("%s","Number is Even");

    }else{
        printf("%s","Number is Odd");
    }
    return 0;
}