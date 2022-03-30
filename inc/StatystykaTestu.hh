#ifndef STATYSTYKATESTU_HH
#define STATYSTYKATESTU_HH

#include <iostream>

using namespace std;

class StatystykaTestu {
    private:
    int Accurate;
    int failure;
    double procent;
   
    public:
    StatystykaTestu()
    {
        Accurate=0;
        failure=0;
        procent=0;
    }
    void Accurate1();
    void failure1();
    void Wyswietl();
};


#endif

