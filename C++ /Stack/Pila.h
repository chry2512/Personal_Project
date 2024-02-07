// guardia di inclusione

#ifndef PILA_H
#define PILA_H
#include <vector>

using namespace std;

class Pila
{
    public:
        Pila(int); // costruttore
        ~Pila(); // distruttore
        int push(int);
        int pop();
        bool isEmpty();
        bool isFull();
        void stampaPila();
    private:

    vector<int> elementi; // contenitore vettore
    int nElementi;
    int max_elementi;


};

#endif // PILA_H