#include "StatystykaTestu.hh"


void StatystykaTestu::Accurate1()
{
    Accurate++;
}

void StatystykaTestu::failure1()
{
    failure++;
}

void StatystykaTestu::Wyswietl()
{
    double procenty = 100.0 * Accurate / (Accurate + failure);
    cout << "Ilosc dobrych odpowiedzi: " << Accurate << endl;
    cout << "Ilosc blednych odpowiedzi: " << failure << endl;
    cout << "Wynik procentowy poprawnych odpowiedzi: " << procenty <<"%"<< endl;
}
