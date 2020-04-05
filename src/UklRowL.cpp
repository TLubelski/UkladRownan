#include "UklRowL.hh"



UklRowL::UklRowL(MacierzKw A, Wektor b)
{
    this->A = A;
    this->b = b;
}

const Wektor & UklRowL::get_wektor_wolny() const
{
    return b;
}

void UklRowL::set_wektor_wolny(const Wektor &W_n)
{
    b = W_n;
}

const MacierzKw & UklRowL::get_macierz() const
{
    return A;
}


void UklRowL::set_macierz(const MacierzKw &M_n)
{
    A = M_n;
}