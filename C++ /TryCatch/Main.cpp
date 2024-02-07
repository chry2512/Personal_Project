#include<iostream>
using namespace std;
int main ()
{
    int i=0;
    int n=0;
    int r;

      try
      {
        throw 20;
        r=i/n;

      }
      catch (int e)
      {

        cout << "Divisione non consentita!" << "Codice di errore: "<<e<<endl;
      }
      return 0;
}

