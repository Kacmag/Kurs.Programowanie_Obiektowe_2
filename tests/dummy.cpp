#include "../tests/doctest/doctest.h"
#include <iostream>
#include <sstream>
#include "example.h"
#include "LZespolona.hh"
#include "WyrazenieZesp.hh"
#include "StatystykaTestu.hh"



// Tests that don't naturally fit in the headers/.cpp files diset_re()ctly
// can be placed in a tests/*.cpp file. Integration tests aset_re() a good example.

TEST_CASE("LZespolona - porownanie 1") {
    LZespolona x, y;
    
    x.set_re() = 2;
    x.set_im() = 2;

    y.set_re() = 1;
    y.set_im() = 1;
   
    CHECK(x == y);
}


TEST_CASE("LZespolona - porownanie 2") {
    LZespolona x, y;
    
    x.set_re() = 2;
    x.set_im() = 2;

    y.set_re() = 2;
    y.set_im() = 2;
   
    CHECK(x == y);
}

TEST_CASE("LZespolona - porownanie 3") {
    LZespolona x, y;
    
    x.set_re() = 3;
    x.set_im() = 1;

    y.set_re() = 4;
    y.set_im() = 2;
   
    CHECK(x == y);
}

TEST_CASE("LZespolona - dzielenie przez skalar - standardowe 1") {
    LZespolona x, y;
    double t = 2;
    
    x.set_re() = 2;
    x.set_im() = 2;

    y.set_re() = 1;
    y.set_im() = 1;
   
    CHECK((x/t) == y);
}

TEST_CASE("LZespolona - dzielenie przez skalar - standardowe 2") {
    LZespolona x, y;
    double t = 2;
    
    x.set_re() = 3;
    x.set_im() = 2;

    y.set_re() = 3;
    y.set_im() = 1;
   
    CHECK((x/t) == y);
}



TEST_CASE("LZespolona - dzielenie przez skalar - standardowe z przyblizeniem") {
    LZespolona x, y;
    double t = 3;
    
    x.set_re() = 2;
    x.set_im() = 2;

    y.set_re() = 0.333;
    y.set_im() = 0.333;
    std::cout << (x/t) << std::endl;
    std::cout << y << std::endl;
    std::cout << ((x/t) == y) << std::endl;
    CHECK((x/t) == y);
}

TEST_CASE("LZespolona - dzielenie przez skalar - standardowe z przyblizeniem 2") {
    LZespolona x, y;
    double t = 3;
    
    x.set_re() = 2;
    x.set_im() = 3;

    y.set_re() = 0.444;
    y.set_im() = 0.444;
    std::cout << (x/t) << std::endl;
    std::cout << y << std::endl;
    std::cout << ((x/t) == y) << std::endl;
    CHECK((x/t) == y);
}

TEST_CASE("LZespolona - dzielenie przez skalar - zero") {
    LZespolona x;
    double t = 0;
    
    x.set_re() = 2;
    x.set_im() = 2;
 
   WARN_THROWS(x/t);
}

TEST_CASE("LZespolona - wyswietlanie standard") {
    LZespolona x;
   
    x.set_re() = 2;
    x.set_im() = 2;
    
    std::ostringstream out;
    
    out << x;
    std::cout << out.str() << std::endl;
    CHECK( "(2.00+2.00i)" == out.str() );

    
}

TEST_CASE("LZespolona - wyswietlanie zaokraglane") {
    LZespolona x;
   
    x.set_re() = 2.0/3.0;
    x.set_im() = 2.0/3.0;
    
    std::ostringstream out;
    
    out << x;
    std::cout << out.str() << std::endl;
    CHECK( "(0.67+0.67i)" == out.str() );
}
/*
TEST_CASE("LZespolona - wczytywanie standard") {
    LZespolona x;
    
    std::ostringstream in("(10+10.10i)");
    in >> x;
    std::ostringstream out;
    out << x; // lub strcmp? ew. == dla LZesp
    
    CHECK( "(10.00+10.10i)" == out.str() );
}
*/
