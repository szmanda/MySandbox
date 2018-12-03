#include "punkt.h"
#include <iostream>

using namespace std;

int main()
{
    /*
    Zadanie 3.1:
    Zrealizować klasę punkt do obsługi punktów na płaszczyźnie. Klasa ma zawierać:
        - konstruktor, którego argumentami będą współżędne kartezjańskie punktu (typ float)
        - funkcja składowa przesun realizujace przesuniecie zdefiniiowane dwoma argumentami
        typu float
        - funkcję wyswietl, wyświetlajacą współrzędne punktu
    Współrzedne mają być zapisane w zmiennych prywatnych:
    Napisać oddzielnie:
        - plik źródłowy z deklaracją klasy;
        - plik śródłowy zawierający jej definicję
    */
    cout<<"---\nZadanie 3.1"<<endl;
    // zob. pliki punkt.h; punkt.cpp
    Punkt * pun = new Punkt(0,0);

    pun->Wyswietl();
    pun->Przesun(5,-2);
    pun->Wyswietl();
    pun->Przesun(-12,4);
    pun->Wyswietl();

    delete pun;


    return 0;
}