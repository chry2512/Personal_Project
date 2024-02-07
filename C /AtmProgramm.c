#include <stdio.h>


int withdrawal(int balance){

    int withdrawal;

    puts("How much do you want to withdraw?: ");
    scanf("%d", &withdrawal);

    int newBalance = balance + withdrawal;
     
    return newBalance;
}

int deposit(int balance){
    int newBalance = balance;
    int deposit;

    puts("How much do you want to deposit?: ");
    scanf("%d", &deposit);
    
    newBalance = newBalance - deposit;

    return newBalance;

}

int calculateBalance(int balance){
    int totalChargesMonth;
    int totalCreditsMonth;

    puts("How much are the total charges this month?: ");
    scanf("%d", &totalChargesMonth);

    puts("How much are the total credits this month?: ");
    scanf("%d", &totalCreditsMonth);

    int newBalance = balance + totalChargesMonth - totalCreditsMonth;

    return newBalance;

}

int choiseOperation(){
    int choise;
    
    puts("Which of these operations do you want to perform?");
    puts("1. Withdrawal");
    puts("2. Deposit");
    puts("3. Balance");

    scanf("%d", &choise);

    return choise;
}


int main(){

    int balance = 0;
    int exit = 0;   
    int limitCredit = 10000;
    int choise = 0;
    

    
    puts ("*******Welcome to Your Bank!*******");

    while (exit != 2)
    {

        choise = choiseOperation();

        switch (choise){
            case 1:
                balance = withdrawal(balance);
                printf("****Your new balance is: %d\n", balance);

                if (balance > limitCredit) {
                    puts("Credit limit exceeded");
                } else {
                    puts("Credit limit not exceeded");
                }
            
                break;
            case 2:
                balance = deposit(balance);
                printf("***Your new balance is: %d\n", balance);
                break;
            case 3:
                balance = calculateBalance(balance);
                printf("***Your new balance is: %d\n", balance);

                if(balance > limitCredit){
                    puts("Credit limit exceeded");

                }else{
                    puts("Credit limit not exceeded");
                }
              
                break;
            default:
                puts("******Sorry, Invalid operation: Thank you for using our services!");
                
                break;
        }

        puts("Do you want to perform another operation?");
        puts("1. Yes");
        puts("2. No");
        scanf("%d", &exit);      
        
    }
      
    puts("******Thank you for using our services!******");


    return 0;
}
