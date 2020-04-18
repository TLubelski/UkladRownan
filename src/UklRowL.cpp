#include "UklRowL.hh"

using namespace std;

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


Wektor UklRowL::oblicz() const
{
    return ( A.odwrotnosc() * b );
}

Wektor UklRowL::wekt_bledu() const
{
    return A * oblicz() - b;
}

ostream &operator<<(ostream &strm, const UklRowL &Uklad)
{
    MacierzKw macierz = Uklad.get_macierz();
    Wektor wolny = Uklad.get_wektor_wolny();

    for(int i = 0; i < ROZMIAR; i++)
    {
        strm << macierz[i] << "  " << "|x_" << i+1 << "|";

        if(i == 1)
            strm << " = ";
        else
            strm << "   ";

        strm << "|" << wolny[i] << "|" << endl;
    }
    return strm;
}


istream &operator>>(istream &strm, UklRowL &Uklad)
{
    MacierzKw temp_m;
    Wektor temp_w;

    strm >> temp_m;
    temp_m = temp_m.transpozycja(); //powrot do postacie nietransponowanej
    Uklad.set_macierz( temp_m );
    
    strm >> temp_w;
    Uklad.set_wektor_wolny(temp_w);

    return strm;
}