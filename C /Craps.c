#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Status
{
    CONTINUE,
    WON,
    LOST
};

//Prototype

int rollDice(void);// lancia dado, calcola la somma e visualizza i risultati

double bankBalance(double balance); // chiede il saldo del giocatore

int doYouWantToPlay(void); // chiede al giocatore se vuole giocare

double startGame(double euro, double balance); // chiede al giocatore la scommessa

double bet(double euro, double balance); // chiede la scommessa del giocatore

enum Status playGame(void); // gioca una partita di craps


int main(void)
{
    int answer;
    double euro;
    double balance;
    enum Status gameStatus;

    srandom(time(NULL));
    puts("<<<<<<<<<Welcome to the game of craps>>>>>>>>>>>");

    printf("1. Enter your bank balance: \n");
    scanf("%lf", &balance);

    balance = bankBalance(balance);
    printf("2. Your bank balance is: %.2lf\n", balance);

    balance = startGame(euro, balance);
    
    while (balance > 0)
    {
        gameStatus = playGame();
        if (gameStatus == WON)
        {
            balance += euro;
            puts("<<<<<<Player wins");
            printf("Your bank balance is: %.2lf\n", balance);
            puts("Do you want to play again? :  \n");
            printf("1 = Yes\n");
            printf("2 = No\n");
            scanf("%d", &answer);
            if (answer == 2)
            {
                printf("<<<Game over\n");
                return 1;
            }
            else{
                balance = startGame(euro, balance);
            }

    
        }
        else
        {
            balance -= euro;
            puts("<<<<<<Player loses");
            printf("Your bank balance is: %.2lf\n", balance);

            puts("Do you want to play again? :  \n");
            printf("1 = Yes\n");
            printf("2 = No\n");
            scanf("%d", &answer);
            if (answer == 2)
            {
                printf("<<<Game over\n");
                return 1;
            }
            else{
                balance = startGame(euro, balance);
            }
           
        }
    }

    
    

    return 0;
}

int rollDice(void)
{
    int num1 = 1 + (random() % 6);
    int num2 = 1 + (random() % 6);
    int sum = num1 + num2;
    printf("Player rolled %d + %d = %d\n", num1, num2, sum);
    return sum;
}
double bankBalance(double balance)
{
    return balance;
}

int doYouWantToPlay(void)
{
    int answer;
    printf("Do you want to play? :  \n");
    printf("1 = Yes\n");
    printf("2 = No\n");
    scanf("%d", &answer);

    
    return answer;
}   

double startGame(double euro, double balance)
{
    int answer;
    answer = doYouWantToPlay();

    
    if (answer == 1)
    {
       printf("Enter your bet: \n");
       scanf("%lf", &euro);

        if (euro > balance)
        {
            printf("You don't have enough money to bet\n");
            printf("Enter your bet: \n");
            scanf("%lf", &euro);
        }
        else
        {
            balance = bet(euro, balance);
            printf("Your bank balance is: %.2lf\n", balance);
        }
    }
    else
    {
        printf("<<<Game over\n");
        return 1;
    }
    return balance;
}

double bet(double euro, double balance)
{
    balance -= euro;
    return balance;
}   

enum Status playGame(void)
{

    int myPoint;
    int sum = rollDice();
    enum Status gameStatus;

    switch (sum)
    {
        case 7:
        case 11:
            gameStatus = WON;
            break;
        case 2:
        case 3:
        case 12:
            gameStatus = LOST;
            break;

        default:
            gameStatus = CONTINUE;
            myPoint = sum;
            printf("Point is %d\n", myPoint);
            break;
    }

    while (gameStatus == CONTINUE)
    {
        sum = rollDice();

        if (sum == myPoint)
        {
            gameStatus = WON;
        }
        else
        {
            if (sum == 7)
            {
                gameStatus = LOST;
            }
        }
    }

    return gameStatus;
}