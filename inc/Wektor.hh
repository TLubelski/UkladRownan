#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>

/*Definicja rozmiaru wektora/macierzy*/
#define ROZMIAR 3 

/*Klasa opisujaca macierz kwadratowa*/
class Wektor
{
private:
    double tab[ROZMIAR];

public:
    /*KONSTRUKTORY*/
    Wektor();
    Wektor(double x, double y, double z);
    Wektor(double *tab);

    /*OPERATORY*/
    const double &operator[](int index) const;
    double &operator[](int index);
    
    bool operator==(const Wektor &W2) const;
    bool operator!=(const Wektor &W2) const;

    const Wektor operator+(const Wektor &W2) const;
    const Wektor & operator+=(const Wektor &W2);

    const Wektor operator-(const Wektor &W2) const;
    const Wektor & operator-=(const Wektor &W2);

    double operator*(const Wektor &W2) const; //iloczyn skalarny

    /*API*/
    double dlugosc() const;
};

/*OPERATORY ZEWNETRZNE*/
Wektor operator*(double l1, const Wektor W2); //mnozenie przez liczbe

std::ostream & operator<<(std::ostream &strm, const Wektor &W);
std::istream & operator>>(std::istream &strm, Wektor &W);


#endif