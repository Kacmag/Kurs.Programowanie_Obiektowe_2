#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <iostream>
#include <math.h>

using namespace std;

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
class  LZespolona {
  private:
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
  public:
  double &set_re()
  {
    return re;
  }
  double &set_im()
  {
    return im;
  }
  double get_re()
  {
    return re;
  }
  double get_im()
  {
    return im;
  }

  LZespolona()
  {
    re=0;
    im=0;
  }
  void Wyswietl();
  bool Wczytaj(std::istream &rStrmWe);
  LZespolona Sprzezenie() ;
  double modul();

  LZespolona  operator + ( LZespolona  Skl2);
  LZespolona  operator * (  LZespolona  Skl2);
  LZespolona  operator - ( LZespolona  Skl2);
  LZespolona  operator / (  double Skl2);
  LZespolona  operator / ( LZespolona  Skl2);



  bool operator == (  LZespolona  Skl2) const;
  bool operator != (  LZespolona  Skl2);





};


/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */





ostream & operator <<(ostream &Wyj, LZespolona Skl);
istream & operator >>(istream &Wej, LZespolona &Skl);







#endif