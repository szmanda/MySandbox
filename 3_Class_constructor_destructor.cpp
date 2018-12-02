#include <iostream>

using namespace std;

/* --- deklaracja klasy punkt --- */
class punkt{
    /* deklaracja składowych prywatnych */
    int x;
    int y;

    /* deklaracja składowych publicznych */
public:
    void init(int, int);
    // void przesun(int, int); przeniesione poniżej, dodano definicję
    // void wyswietl();

    //definicja wewnątrz klasy
    void przesun(int xx, int yy){
        // tu nie jest wymagany człon punkt::
        x += xx;
        y += yy;
    }
    void wyswietl(){
    cout<<"\tx = "<<x;
    cout<<"\ty = "<<y;
    }
};
void punkt::init(int xx, int yy){ //definicja poza klasą
    //przy definiowaniu funkcji wewnątrz klasy człon punkt::
    //nie jest wymagany
    x = xx; y = yy;
}

int main(){

    cout<<" 3. Klasa, konstruktor i destruktor"<<endl;
    /*
    W C++ programowanie obiektowe opiera się na pojęciu klasy
    będącej uogólnieniem typu definiowanego przez użytkownika*.
    W indealnie zaprogramowanym obiektowo środowisku wszystkie
    dane są zawsze prywatne, zamknięte w konkretnych obiektach
    a dostęp do nich możliwy jest tylko przez sodtępne metody
    i funkcje.

    * - do typów definiowanych przez użytkownika zalicza się
    oprócz klas także: struktury, unie, wyliczenia jednak
    zdecydowanie najczęściej używa się klas.


    1. Deklaracja i definicja klasy:
    Deklaracja klasy precyzuje jakie elementy składowe są związane
    z daną klasą. domyślnie wszystkie elementy są traktowane jako
    prywatne (private keyword), można jednak zadeklarować składowe
    publiczne (public keyword) zob. class punkt

    Definicja klasy składa się natomiast z definicji wszystkich
    składowych. W definicjach tych podaje się nazwę klasy bazowej przy
    użyciu operatora zakresu (::). Wewnątrz definicji wszystkie
    funkcje i dane są dostępne (publiczne i prywatne) bez poprzedzania
    ich nazwą klasy. (zob. void punkt::init)


    2. Korzystanie z klasy:
    */
    punkt a, b; // deklaracja obiektu należącego do klasy punkt

    a.init(5,7); // wywołanie funkcji init() na obiekcie a;
    b.init(1,4);
    b.przesun(-3,9);
    b.wyswietl();

    /*
    3. Przypisywanie obiektów:
    Możliwe jest także przypisywanie obiektów pewnego typu innym
    obiektom tego samego typu. Operacja polega ta na kopiowaniu
    wszystkich wartości (również prywatnych) do innego obiektu.
    Jeśli wśród tych danych znajdują się wskaźniki, zostaną
    skopiowane tylko ich wartości a nie dane przez nie wskazywane.

    (Gdy zachodzi konieczność przekopiowania także tych danych można
    przeciążyć operatora podstawienia dla danej klasy)


    4. Konstruktor i destruktor:
    ...
    */

    return 0;
}
