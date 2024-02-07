#include "Pila.h"
#include <iostream>


using namespace std;


int main()
{
    Pila pila(5);
    int m;

    if(!pila.isFull())
    {
        pila.push(10);
        
    }
    else
    {
        cout << "Pila piena" << endl;
    }

    if(!pila.isFull())
    {
        pila.push(20);
    }
    else
    {
        cout << "Pila piena" << endl;
    }

    if(!pila.isEmpty())
    {
        pila.stampaPila();
        m = pila.pop();
        cout << "Elemento estratto: " << m << endl;
        pila.stampaPila();
    }
    else
    {
        cout << "Pila vuota" << endl;
    }   
   
    return 0;
}