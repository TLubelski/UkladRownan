#include "Wektor.hh"
#include <cmath>
#include <regex>
#include <sstream>

using namespace std;

/*KONSTRUKTORY*/

Wektor::Wektor()
{
    for (int i = 0; i < ROZMIAR; i++)
        tab[i] = 0;
}

Wektor::Wektor(double x, double y, double z)
{
    tab[0] = x;
    tab[1] = y;
    tab[2] = z;
}

Wektor::Wektor(double *tab)
{
    for (int i = 0; i < ROZMIAR; i++)
        this->tab[i] = tab[i];
}

/*OPERATORY*/

const double & Wektor::operator[](int index) const
{
    if (index < 0 || index >= ROZMIAR)
    {
        cerr << "[!] Index out of range in Wektor" << endl;
        exit(1);
    }
    return tab[index];
}

double & Wektor::operator[](int index)
{
    if (index < 0 || index >= ROZMIAR)
    {
        cerr << "[!] Index out of range in Wektor" << endl;
        exit(1);
    }
    return tab[index];
}

bool Wektor::operator==(const Wektor &W2) const
{
    bool wynik = true;
    for (int i = 0; i < ROZMIAR; i++)
    {
        if (tab[i] != W2.tab[i])
            wynik = false;
    }
    return wynik;
}

bool Wektor::operator!=(const Wektor &W2) const
{
    return !(*this == W2);
}

const Wektor Wektor::operator+(const Wektor &W2) const
{
    Wektor temp;
    for (int i = 0; i < ROZMIAR; i++)
        temp.tab[i] = tab[i] + W2.tab[i];
    return temp;
}

const Wektor & Wektor::operator+=(const Wektor &W2)
{
    *this = *this + W2;
    return *this;
}

const Wektor Wektor::operator-(const Wektor &W2) const
{
    Wektor temp;
    for (int i = 0; i < ROZMIAR; i++)
        temp.tab[i] = tab[i] - W2.tab[i];
    return temp;
}

const Wektor &  Wektor::operator-=(const Wektor &W2)
{
    *this = *this - W2;
    return *this;
}

double Wektor::operator*(const Wektor &W2) const //iloczyn skalarny
{
    double temp;
    for (int i = 0; i < ROZMIAR; i++)
    {
        temp += tab[i] * W2.tab[i];
    }
    return temp; 
}

/*API*/

double Wektor::dlugosc() const
{
    double suma = 0;
    for (int i = 0; i < ROZMIAR; i++)
        suma += pow(tab[i], 2);
    return sqrt(suma);
}

/*OPERATORY ZEWNETRZNE*/

Wektor operator*(double l1, const Wektor W2) //mnozenie przez liczbe
{
    Wektor temp;
    for (int i = 0; i < ROZMIAR; i++)
        temp[i] = W2[i] * l1;
    return temp;
}


ostream & operator<<(ostream & strm, const Wektor &W)
{
    strm << "|";
    for(int i = 0; i < ROZMIAR-1; i++)
        strm << W[i] << " ";
    
    strm << W[ROZMIAR-1];
    strm << "|";    

    return strm;
}

istream & operator>>(istream &strm, Wektor &W)
{   
    string wzor_s = "\\|";
    string liczba = "-?\\d+.?\\d*";

    //zbudowanie wzoru regexa o odpowienim rozmiarze
    for (int i = 0; i < ROZMIAR-1; i++) 
    {
        wzor_s += liczba;
        wzor_s += "\\s";
    }
    wzor_s += liczba;
    wzor_s += "\\|";
    regex wzor(wzor_s); //inicjalizacja walasciwego regexa

    //oczyt ze strumienia
    stringstream ss;
    string input;
    smatch wynik;
    getline(strm,input);
    ss << input;

    char trash;
    if( regex_search(input, wynik, wzor) ) //oczyt danych jesli pasuja
    {
        ss >> trash;
        for (int i = 0; i < ROZMIAR; i++)
            ss >> W[i];
    }
    else //jesli nie to blad
    {
        cerr << "[!] Incorrect input in Wektor" << endl;
        exit(1); //albo strm.setstate(ios::failbit);
    }

    return strm;
}