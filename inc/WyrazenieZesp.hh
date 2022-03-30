#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH


#include <iostream>
#include "LZespolona.hh"


/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator { Dodawanie, Odejmowanie, Mnozenie, Dzielenie };



/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
class WyrazenieZesp {
  private:
  LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Opertor wyrazenia arytmetycznego
  LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego
  public:
  
  
  LZespolona   &set_Arg1()
  {
    return Arg1;
  }
  Operator &set_Op()
  {
    return Op;
  }
  LZespolona   &set_Arg2()
  {
    return Arg2;
  }


  LZespolona   &get_Arg1()
  {
    return Arg1;
  }
  Operator &get_Op()
  {
    return Op;
  }
  LZespolona   &get_Arg2()
  {
    return Arg2;
  }
  
 
  bool WczytajWyrazenieZesp( std::istream &rStrmWe);
  void Wyswietl();
  LZespolona Oblicz();
};


/*
 * Funkcje ponizej nalezy zdefiniowac w module.
 *
 */




ostream & operator <<(ostream &Wyj, WyrazenieZesp WyrZ);
istream & operator >>(istream &Wej, WyrazenieZesp &WyrZ);

#endif
