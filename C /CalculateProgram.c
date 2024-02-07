#include<stdio.h>

int main(){
    int num1;
    int num2;

    printf("Enter Two Numbers: \n");// inserire i due numeri
    scanf("%d%d",&num1, &num2);

    // somma dei due numeri
    printf("Sum is: %d\n", num1 + num2);
 

    //prodotto dei due numeri
    printf("Product is:%d\n", num1 * num2);

    // differenza dei due numeri
    printf("Difference is: %d\n", num1 - num2);
    int diff = num1 - num2;

    // divisione dei due numeri 
    printf("Division is: %d\n", num1 / num2);
    //calcola il resto della divisione
    printf("Rest is: %d\n", num1 % num2);
    
    return 0;
}