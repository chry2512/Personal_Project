#include "Persona.h"
#include <string>

using namespace std;

//definizione file implementazione classe Persona

Persona :: Persona()
{
    //costruttore vuoto x Poliformismo
}

Persona :: Persona(string cognome, string nome, string codFiscale, int anni, double reddito, string residenza)
{
    this->cognome = cognome;
    this->nome = nome;
    this->codFiscale = codFiscale;
    this->anni = anni;
    this->reddito = reddito;
    this->residenza = residenza;
}

string Persona :: getCognome()
{
    return  this->cognome;
}

string Persona :: getNome()
{
    return this->nome;
}

string Persona :: getCodFiscale()
{
    return this->codFiscale;
}

string Persona :: getResidenza()
{
    return this->residenza;
}

int Persona :: getAnni()
{
    return this->anni;
}

double Persona :: getReddito()
{
    return this->reddito;
}

void Persona :: setReddito(double reddito)
{
    this->reddito = reddito;
}

void Persona :: setCognome(string cognome)
{
    this->cognome = cognome;
}

void Persona :: setNome(string nome)
{
    this->nome = nome;
}

void Persona :: setCodFiscale(string codFiscale)
{
    this->codFiscale = codFiscale;
}

void Persona :: setResidenza(string residenza)
{
    this->residenza = residenza;
}

void Persona :: setAnni(int anni)
{
    this->anni = anni;
}



