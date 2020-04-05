#include "Wektor.hh"
#include "MacierzKw.hh"
#include <iostream>

using namespace std;

int main()
{
    //######## TESTY WEKTOR ###########
    /*
    Wektor w1(1,2,3);
    Wektor w2(4,5,6);

    cout << "wysw: " << w1 << " " << w2 << endl;
    cout << "dod: " << w1 + w2 << endl;
    cout << "odejm: " << w1 - w2 << endl;
    cout << "index: " << w1[2] << endl;
    cout << "monoz przez liczbe: " << 3 * w1 << endl;
    cout << "mnoz skalar: " << w1 * w2 << endl;
    cout << "dl: " << w1.dlugosc() << endl;

    Wektor w3;
    cout << "podaj wektor: ";
    cin >> w3;
    cout << "podano: " << w3 << endl;
    if( w3 == w1 || w3 == w2)
        cout << "^ bylo" << endl;
    */


    //######### TESTY MACIERZ #########

    MacierzKw m1(Wektor(1,2,3), Wektor(4,5,6), Wektor(7,8,9));
    MacierzKw m2(Wektor(10,11,12), Wektor(13,14,15), Wektor(16,17,18));
    cout << m1 << endl;
    cout << "T:" << endl;
    cout << m1.transpozycja() << endl;
    cout << "+:" << endl;
    cout << m1 + m2 << endl;
    cout << "-:" << endl;
    cout << m2 - m1 << endl;
    cout << "*:" << endl;
    cout << m1 * m2 << endl;
    cout << m1;
    cout << "det:" << endl;
    cout << m1.wyznacznik() << endl;


    MacierzKw m3;
    cout << "Podaj macierz(wierszami): " << endl;
    cin >> m3;
    cout << "podano: " << endl;
    cout << m3;
    if( m3 == m1 || m3 == m2)
        cout << "Było" << endl;
    
}
