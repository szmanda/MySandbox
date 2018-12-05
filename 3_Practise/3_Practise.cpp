#include "punkt.h"
#include <iostream>

using namespace std;

int main()
{
    cout<<"---\nZadanie 3.1"<<endl;
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
    // zob. pliki punkt.h; punkt.cpp
    Punkt * pun = new Punkt(0,0);

    pun->Przesun(5,-2);
    pun->Przesun(-12,4);
    //pun->Wyswietl();

    cout<<"---\nZadanie 3.2"<<endl;
    /*
    Zadanie 3.2
    Zmodyfikować klasę punkt, nie zawierającą funkcji Wyswietl, a zamiast niej aby zachować hermetyzację danych
    napisać w zamian dwie funkcjie Odcieta i Rzedna zwracjające odpowiednio odciętą i rzędną punktu.
    Zaadoptowanwać program testowy z poprzedniego zadania
    */

    cout<<"\tx = "<<pun->Odcieta()<<endl;
    cout<<"\tx = "<<pun->Rzedna()<<endl;
    /*
    Utworzenie funkcji dostępu (tutaj Ocieta i Rzedna) umożliwia wymuszenie zachowanie hermetyzacji danych.
    Dzięki takim publiczmym funkcjom zwracających prywatne zmienne można zachować bezpieczeństwo przed nadpisaniem
    oraz kontrolę nad tym w jaki sposób zmienna ma być dostępna poza klasą.
    */

    cout<<"---\nZadanie 3.3"<<endl;
    /*
    Zadanie 3.3
    Dodać do poprzedniej klasy nowe funkcje skłądowe:
        - Skaluj wykonującą skalowanie o podanym w argumencie współczynniku;
        - Obracaj wykonującą obrót o kąt podany w argumencie;
        - Promien i Teta obliczające współżędne punktu.
    */
    pun->Skaluj(4);

    delete pun;


    return 0;
}
