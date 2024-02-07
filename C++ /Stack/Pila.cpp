#include "Pila.h"
#include <vector>
#include <iostream>
using namespace std;

Pila :: Pila(int n)
{
    max_elementi = n;
    nElementi = 0;
}

Pila :: ~Pila()
{
    // distruttore pulisce memoria
    elementi.clear();
}

int Pila :: push(int elemento)
{
    if (isFull())
    {
        return -1;
    }
    else
    {  
        this -> nElementi++;
        elementi.push_back(elemento);
        return 0;
    }
}

int Pila :: pop()
{
    if (isEmpty())
    {
        return -1;
    }
    else
    {

        int n = elementi.back();
        this -> nElementi--;
        elementi.pop_back();
        return n;
    }
}

bool Pila :: isEmpty()
{
    if(elementi.size() == 0)
    {
  
        return true;
    }
    else
    {
        return false;
    }
}


bool Pila :: isFull()
{

    if(nElementi == max_elementi)
    {
        return true;
    }
    else
    {
        return false;
    }
   
}



void Pila :: stampaPila()
{
    for(int i = 0; i < (this->nElementi); i++)
    {
        cout << elementi[i] << endl;
    }

    return;
}                       