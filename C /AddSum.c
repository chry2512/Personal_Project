#include<stdio.h>

int main(){
    
    int a,b; // numeri inseriti dall'utente

    printf("Enter First Number: \n"); // print message
    scanf("%d",&a); // scan num insert user

    printf("Enter  Second Number: \n");// print message
    scanf("%d", &b);// scan number insert user

    int sum = a + b; // calculate sum

    printf("Sum is: %d\n", sum); // print sum
    return 0;
} // end main