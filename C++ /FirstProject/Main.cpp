
#include <iostream>
#include <string>
#include <vector>
#include "Persona.h"
#include <fstream>


using namespace std;


int main()
{
    Persona p;
    double reddito;
    bool flagTrovato;

    string cognome;
    string nome;
    string codFiscale;
    string residenza;

    int anni;
    int nPersone;
    vector<Persona> persone;


    // fase input

    cout << "Quante persone vuoi inserire? "<< endl;  
    cin >> nPersone;

    for(int i = 0; i < nPersone; i++)
    {
        cout << "====Persona===== "<< i + 1 << "====" << endl;
        cout << "Inserisci il cognome: "<< endl;
        cin >> cognome;
        cout << "Inserisci il nome: "<< endl;
        cin >> nome;
        cout << "Inserisci il codice fiscale: "<< endl;
        cin >> codFiscale;
        cout << "Inserisci la residenza: "<< endl;
        cin >> residenza;
        cout << "Inserisci gli anni: "<< endl;
        cin >> anni;
        cout << "Inserisci il reddito: "<< endl;
        cin >> reddito;
        cin.ignore();

        p.setCognome(cognome);
        p.setNome(nome);
        p.setCodFiscale(codFiscale);
        p.setResidenza(residenza);
        p.setAnni(anni);
        p.setReddito(reddito);

        persone.push_back(p);

        cout << "===== Ricerca =====" << endl;  
        cout << "Inserisci il codice fiscale da ricercare: "<< endl;
        cin >> codFiscale;

        // fase di ricerca iterazione

        flagTrovato = false;

        for(int i = 0;(i < persone.size()) && (flagTrovato == false); i++)
        {
            if(persone[i].getCodFiscale() == codFiscale)
            {
                cout << "Persona trovata: "<< endl;
                cout << "Cognome: "<< persone[i].getCognome() << endl;
                cout << "Nome: "<< persone[i].getNome() << endl;
                cout << "Codice fiscale: "<< persone[i].getCodFiscale() << endl;
                cout << "Residenza: "<< persone[i].getResidenza() << endl;
                cout << "Anni: "<< persone[i].getAnni() << endl;
                cout << "Reddito: "<< persone[i].getReddito() << endl;
                flagTrovato = true;
            }

            if(!flagTrovato)
            {
                cout << "Persona non trovata"<< endl;
                cout << "il codice fiscale:"<<codFiscale<<"non esiste" <<endl;
            }
           
        }
        
    }
    return 0;
}