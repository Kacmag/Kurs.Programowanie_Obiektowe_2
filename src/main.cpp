#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include "example.h"
#include "exampleConfig.h"


#include <iostream>

#include <fstream>
#include "WyrazenieZesp.hh"
#include "StatystykaTestu.hh"

using namespace std;



void WykonajTest(istream &rStrmWej)
{
  StatystykaTestu stat;

  WyrazenieZesp WyrZ_PytanieTestowe;
  LZespolona Wynik;
  LZespolona Obliczono;
  do
  {
    rStrmWej >> WyrZ_PytanieTestowe;

    if (rStrmWej.good())
    {    
      cout << "Podaj wynik (w postaci liczby zespolonej w nawiasach): ";
      cout << WyrZ_PytanieTestowe << endl;

      for (int i = 0; i < 3; i++)
      {
        
        cin >> Wynik;
        if (cin.fail())
        {
          cout << "Wynik jest niepoprawny lub zostal zle zapisany" << endl;
          cin.clear();
          cin.ignore(1024, '\n');
        }
        else
        {
          break;
        }
      }

      if ((Obliczono = WyrZ_PytanieTestowe.Oblicz()) == Wynik)
      {
         cout << "Odpowiedz jest prawidlowa" << endl;
        stat.Accurate1();
      }
      else
      {
        cout << "Odpowiedz nie jest prawidlowa, wynik to: " << Obliczono << endl;
        stat.failure1();
      }
    }
    else
    {
      rStrmWej.clear();
      rStrmWej.ignore(1024, '\n'); 
    }
  } while (!rStrmWej.eof());
 stat.Wyswietl();
}






int main(int argc, char **argv)
{

  if (argc < 2) {
    cerr << endl;
    cerr << " Brak pliku zawierajacego dane." << endl;
    cerr << endl;
    return 1;
  }

  ifstream  PlikTestu(argv[1]);

  if (PlikTestu.is_open() == false) {

    cerr << " Brak pliku zawierajacego dane." << endl;

    return 1;
  }

  cout << endl;
  cout << " Rozpoczecie testu: " << argv[1] << endl;
  cout << endl;

  WykonajTest(PlikTestu);
  

  PlikTestu.close();
  
  
}
