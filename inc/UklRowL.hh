#ifndef UKL_ROW_L_HH
#define UKL_ROW_L_HH

#include "Wektor.hh"
#include "MacierzKw.hh"

#include <iostream>

class UklRowL
{
private:
    MacierzKw A;
    Wektor b;

public:
    UklRowL(){}
    UklRowL(MacierzKw A, Wektor b);


    const Wektor & get_wektor_wolny() const;
    void set_wektor_wolny(const Wektor & W_n);

    const MacierzKw & get_macierz() const;
    void set_macierz(const MacierzKw & M_n);

    Wektor oblicz() const;
};

std::ostream &operator<<(std::ostream &strm, const UklRowL &Uklad);
std::istream &operator>>(std::istream &strm, UklRowL &Uklad);

#endif