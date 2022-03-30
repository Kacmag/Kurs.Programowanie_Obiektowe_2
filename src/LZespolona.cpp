#include "LZespolona.hh"
#include <iostream>

using namespace std;

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona LZespolona::operator + (  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.set_re() = re + Skl2.get_re();
  Wynik.set_im() = im + Skl2.get_im();
  return Wynik;
}

LZespolona LZespolona::operator*(  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.set_re() = (re * Skl2.get_re()) - (im * Skl2.get_im());
  Wynik.set_im() = (re * Skl2.get_im()) - (im * Skl2.get_re());
  return Wynik;
}

LZespolona LZespolona::operator - (  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.set_re() = re - Skl2.get_re();
  Wynik.set_im() = im - Skl2.get_im();
  return Wynik;
}

LZespolona LZespolona::operator/(  double  Skl2)
{
  LZespolona  Wynik;

  Wynik.set_re() = re/Skl2;
  Wynik.set_im() = im/Skl2;
  return Wynik;
}






LZespolona LZespolona::Sprzezenie()
{
  LZespolona Wynik;
  Wynik.set_re() = re;
  Wynik.set_im() = im *-1;
  return Wynik;
}



double LZespolona::modul()
{
  double Wynik;
  Wynik = (sqrt(re*re+im*im));

  Wynik=Wynik*Wynik;
  return Wynik;
}

LZespolona LZespolona::operator / (  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik= (*this) * Skl2.Sprzezenie() / Skl2.modul();
  return Wynik;
}



void LZespolona::Wyswietl()
{
  if(im<0)
  {
   
    cout<<"("<<re<<im<<"i)";
  }
  else
  {
  cout<<"("<<re<<"+"<<im<<"i)";
  }
}

bool LZespolona::Wczytaj(std::istream &rStrmWe)
{
  char znak1, znak2, znak3;

  rStrmWe >> znak1;
  if (znak1 != '(')
  {
    return false;
  }
  rStrmWe >> re;
  if (rStrmWe.fail())
  {
    return false;
  }
  rStrmWe >> im;
  if (rStrmWe.fail())
  {
    return false;
  }
  rStrmWe >> znak2;
  if (znak2 != 'i')
  {
    return false;
  }
  rStrmWe >> znak3;
  if (znak3 != ')')
  {
    return false;
  }

  return true;
}

ostream &operator<<(ostream &Wyj, LZespolona Skl)
{
  Wyj << "(" << Skl.get_re() << showpos << Skl.get_im() << noshowpos << "i)";
  return Wyj;
}

istream &operator>>(istream &Wej, LZespolona &Skl)
{
  char znak1, znak2, znak3;


  Wej >> znak1;
  if (znak1 != '(')
  {

    Wej.setstate(ios::failbit);
  }
  Wej >> Skl.set_re();


  Wej >> Skl.set_im();

  Wej >> znak2;
  if (znak2 != 'i')
  {
    Wej.setstate(ios::failbit);
  }
  
  Wej >> znak3;
  if (znak3 != ')')
  {
    Wej.setstate(ios::failbit);
  }

  return Wej;
}

bool LZespolona::operator == (  LZespolona  Skl2)
{


  if(re == Skl2.get_re() && im == Skl2.get_im())
  {
    return true;
  }

  return false;

}

bool LZespolona::operator != (  LZespolona  Skl2)
{
  if(re != Skl2.get_re() || im != Skl2.get_im())
  {
    return true;
  }


  return false;

}
