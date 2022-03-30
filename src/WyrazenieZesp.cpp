#include <iostream>
#include "WyrazenieZesp.hh"

/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */

bool WyrazenieZesp::WczytajWyrazenieZesp( std::istream &rStrmWe)
{
  char znak;

  Arg1.Wczytaj(rStrmWe);
  rStrmWe >> znak;

  switch (znak)
  {
  case '+':
    Op = Dodawanie;
    break;
  case '-':
    Op = Odejmowanie;
    break;
  case '*':
    Op = Mnozenie;
    break;
  case '/':
    Op = Dzielenie;
    break;
  default:
    return false;
    break;
  }

  Arg2.Wczytaj( rStrmWe);
  return rStrmWe.fail() == false;
}

void WyrazenieZesp::Wyswietl()
{
  Arg1.Wyswietl();
  switch (Op)
  {
  case Dodawanie:
  {
    cout << " + ";
  }
  break;
  case Dzielenie:
  {
    cout << " / ";
  }
  break;
  case Mnozenie:
  {
    cout << " * ";
  }
  break;
  case Odejmowanie:
  {
    cout << " - ";
  }
  break;
  }
  Arg2.Wyswietl();
  

  


}

LZespolona WyrazenieZesp::Oblicz()
{
  LZespolona Wynik;
  switch (Op)
  {
  case Dodawanie:
  {
    Wynik = Arg1 + Arg2;
  }
  break;
  case Dzielenie:
  {
    Wynik = Arg1 / Arg2;
  }
  break;
  case Mnozenie:
  {
    Wynik = Arg1 * Arg2;
  }
  break;
  case Odejmowanie:
  {
    Wynik = Arg1 - Arg2;
  }
  break;
  }

  return Wynik;
}


ostream & operator <<(ostream &Wyj, WyrazenieZesp WyrZ)
{
  Wyj<<WyrZ.get_Arg1();
switch (WyrZ.get_Op())
  {
  case Dodawanie:
  {
    Wyj << " + ";
  }
  break;
  case Dzielenie:
  {
    Wyj << " / ";
  }
  break;
  case Mnozenie:
  {
    Wyj << " * ";
  }
  break;
  case Odejmowanie:
  {
    Wyj << " - ";
  }
  break;
  }
    Wyj<<WyrZ.get_Arg2();

    return Wyj;
}

istream & operator >>(istream &Wej, WyrazenieZesp &WyrZ)
{
  char znak;
  Wej>>WyrZ.set_Arg1();
  Wej >> znak;

  switch (znak)
  {
  case '+':
    WyrZ.set_Op() = Dodawanie;
    break;
  case '-':
    WyrZ.set_Op() = Odejmowanie;
    break;
  case '*':
    WyrZ.set_Op() = Mnozenie;
    break;
  case '/':
    WyrZ.set_Op() = Dzielenie;
    break;
  default:
    Wej.setstate(ios::failbit);
    break;
  }
   Wej>>WyrZ.set_Arg2();

 return Wej;
}