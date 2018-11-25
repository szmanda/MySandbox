#include <iostream>

using namespace std;

//referencje
int fun1(int &val);
//arg domniemane
int fun2(int valA, char ch = 'A', float valB = 7.9);
//przeciazanie funkcji
int fun3(int valA);
int fun3(int valA, int valB);
int fun3(float valA);
//funkcja otwarta
inline int fun4(int a, int b);

int main()
{
    cout<<endl<<" 2. Specyficzne elementy C++"<<endl;

    /*
    1. Mechanizmy wejścia/wyjścia

    cout<<value1<<value2<<...;
    wysyła do strumienia wyjścia cout (stdout) kolejne wartości

    cin>>value1>>value2>>...;
    odczytuje ze strumienia wejścia cin (stdin) kolejne wartości
    typy tych wartości mogą być różne bez konieczności jawnej konwersji
    ze string.
    */
    int userInput;
    cout<<"\n Podaj wartosc: ";
    cin>>userInput;
    cout<<"\n\tPodana wartosc to "<<userInput<<".\n"<<"\n\tTrzykrotnosc tej wartosci to "<<userInput*3<<".\n";

    /*
        2. Trochę o zapisach w tym pliku:

        "using namespace" informuje o używanej przestrzeni nazw
        (w tym wypadku std) bez tej deklaracji zapis cout należy zastąpić
        std::cout (i analogicznie z cin) aby informacja przekazana do
        kompilatora była jednoznaczna teorytycznie możliwym jest inne znaczenie
        cout w innej przestszeni nazw

        podobną funkcję ma załączenie biblioteki na początku dokumentu
        #include <iostream> informuje o używaniu przez ten program biblioteki
        iostream, którą kompilator musi wgrać przed interpretacją samego pisanego
        tutaj kodu

        C++ zawsze wumaga funkcji main(), nie może ona być metodą, w przeciwieństwie do C#
        gdzie istnieje taka możliwość

        W C++ nie ma obowiązku umieszczania deklaracji na początku funkcji
        lub bloku. Inicjalizacji zmiennych można dokonać w każdym momencie
        po jej zadeklarowaniu, ale przed odczytaniem jej wartości (aby uniknąć błędu)

        Natomiast wymagane jest aby funkcje i klasy zapisywane poniżej main() miały swój
        nagłówek powielony powyżej

    3. Przekazywanie zmiennej przez referencje

    C++ umożliwia także przekazywanie zmiennej do funkcji przez referencje
    za pomocą symbolu &, domyślnie do funkcji jest przesyłana kopia zmiennej,
    natomiast przesłanie referencji umożliwi kożystanie z jej oryginału
    (podobnie jak przy użyciu wskaźnika do zmiennej) [zob. fun1()]
    */

    fun1(userInput);
    cout<<"\twartosc = "<<userInput;

    /*
    4. Argumenty domniemane

    Obsługiwane są również tzw argumenty domniemywane. Muszą one znajdować się na końcu
    listy argumentów wraz z wartościami domniemanymi.  W przypadku wywołania funkcji z
    mniejszą niż przewidziana liczba argumentów, zostaną użyte wartości domniemane
    [zob. fun2()]

    Uwaga! wartości domyślne mogą znajdować się tylko w jednym miejscu. jeśli jest
    użyty nagłówek przed main() to przed samym ciałem funkcji nie ponawiam już tych
    deklaracji. to samo miałoby miejsce przy rozdzielaniu na plik nagłówkowy .h i .cpp
    Generalnie ma to sens, ponieważ ewentualnej zmiany można dokonać tylko w jednymm miejscu.
    Nie może więc to powodować utraty integralności tych wartości.
    */
    cout<<endl;
    fun2(123,'C',12.3);
    fun2(123,'C');
    fun2(123);
    cout<<endl;

    /*
    5. Przeciążanie funkcji:

    C++ umożliwia tzw. przeciązenie funkcji. Czyli wiele róznych funkcji o tej samej nazwie.
    Kompilator poznaje o którą funkcję chodzi po ilości i typie argumentów do niej przekazanych
    przy wywołaniu.
    */
    fun3(userInput);
    fun3(5,7);
    fun3(4.4f);

    /*
    6. Dynamiczne zarządzanie pamięcią

    Odbywa się przy użyciu operatorów new i delete
    new typZmiennej [n];
    przyciela w pamięci miejsce opzwalające na zapis
    n elementów typu TypZmiennej i zwraca wskaźnik do pierwszej z nich
    delete adres;
    zwalnia pamięć przedzieloną przy użyciu danego adresu
    */

    int * tabela = new int [4];
    delete tabela;

    /*
    7. Funkcje otwarte

    Są deklarowane przy użyciu słowa kluczowego: inline [zob. fun4()]
    Różnica pomiędzy funkcją otwartą, a zwykłą polega na miejscu zapisu
    instrukcji wykonywanech przez funkcję. Standardowo, funkcja jest zapisana
    osobno (tutaj: poza main()) a wywołanie jej jest tak na prawdę wskaźnikiem
    do miejsa w którym zapisamy jest kod funkcji. Funkcja otwatra (inline) podczas
    kompilacji jest cała przepisywana (często wielokrotnie) do miejsc jej wywołania
    zwiększa to rozmiary plików, ale nieco zwiększa wydajność (program, podczas
    wykonywania się, nie musi przeskawiwać do miejsca zapisu funkcji, gdyż jest ona
    po prostu poniżej)
    */

    fun4(1,2);

    return 0;
}

int fun1(int &val){
    cout<<"\tNadpisanie przez funkcje z przeslaniem przez referencje\n";
    val = 555;
    return 0;
}

int fun2(int valA, char ch, float valB){
    cout<<"\nZawartosc fun2(): "<<valA<<", "<<ch<<", "<<valB;
    return 0;
}
int fun3(int valA){
    cout<<"\n1 przeciazenie: "<<valA<<endl;
    return 0;
}
int fun3(int valA, int valB){
    cout<<"\n2 przeciazenie: "<<valA*valB<<endl;
    return 0;
}
int fun3(float valA){
    cout<<"\n3 przeciazenie: "<<valA/3.2<<endl;
    return 0;
}
inline int fun4(int a, int b){
    return (a+b);
}
