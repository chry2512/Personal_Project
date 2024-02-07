#include <string>
// guardia di inclusione
#ifndef PERSONA_H // il preprocessore controlla se la costante PERSONA_H è definita da qualche parte
#define PERSONA_H // definisce la costante PERSONA_H

using namespace std;


class Persona
{

    public:
        Persona(string, string, string, int, double, string);
        Persona();
        string getCognome();
        string getNome();
        string getCodFiscale();
        string getResidenza();
        int getAnni();
        double getReddito();
        void setReddito(double);
        void setCognome(string);
        void setNome(string);
        void setCodFiscale(string);
        void setResidenza(string);
        void setAnni(int);

    private:
        string cognome;
        string nome;
        string codFiscale;
        int anni;
        double reddito;
        string residenza;
};

#endif // PERSONA_H
