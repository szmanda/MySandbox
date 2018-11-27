#include <iostream>

using namespace std;

struct Test2Z3{
    int n;
    float x;
};

void zad2Z1(void);
void zad2Z2pointers(int * a, int * b);
void zad2Z2references(int & a, int & b);

void zad2Z3pointers(Test2Z3 * aaa); // wymaga struct test2z3{};
void zad2Z3references(Test2Z3 & aaa); // wymaga struct test2z3{};


int main(){

    zad2Z1();   //zwykłe wejście/wyjście

    int a = 4, b = 3;
    zad2Z2pointers(&a, &b); // zwraca a=3, b=4
    zad2Z2references(a,b);  // zwraca a=4, b=3

    Test2Z3 abc;
    zad2Z3pointers(&abc); // wyzerowanie struktury Test2Z3
    cout<<"po wyzerowaniu: \nn = "<<abc.n<<"\nx = "<<abc.x<<endl;
    abc.n = 7;
    abc.x = 8;
    zad2Z3references(abc);
    cout<<"po wyzerowaniu: \nn = "<<abc.n<<"\nx = "<<abc.x<<endl;

    cout<<"---\nZadanie 2.4 przeciazenie funkcji\npatrz kod\n";
    /* Zadanie 2.4 - przeciążenie funkcji
    Określanie które z wywołań są poprawne:

    Dane są funkcje:
    zad2Z4(int);
    zad2Z4(float);
    zad2Z4(int,float);
    zad2Z4(float,int);

    int g,h;
    float j,k;
    char l;
    double m;

    Oraz wywołania:
    zad2Z4(g);
    zad2Z4(j);
    zad2Z4(g,j);
    zad2Z4(j,g);
    zad2Z4(l); wywołanie możliwe dopiero po przekształceniu char na typ int lub float
    zad2Z4(g,h); (dwuznaczne) konwersja (float)g lub (float)h
    zad2Z4(g,l); możliwe po konwersji (char)l na (float)l
    zad2Z4(g,m); możliwe po konwersji (double)m do (float)m z utratą precyzji
    zad2Z4(m,m); (dwuznaczne) konwersja jednego double na int,
    a drugiego na float, lub odwrotnie
    */

    cout<<"---\nZadanie 2.5 new/delete\npatrz kod\n";
    /* Zad 2.5
    Uprość kod C, w C++ (new, delete):
    int * adi;
    double * add;
    adi = malloc(sizeof(int));
    add = malloc(sizeof(double)*100);
    */
    int * adi = new int;
    double * add = new double[100];

    // i sprzątanie:
    delete adi;
    delete add;


    return 0;
}

void zad2Z1(void){
    cout<<"---\nZadanie 2.1"<<endl;

    int n;
    float x;

    cout<<"Podaj jedna liczbe calkowita i jedna wymierna\n";
    cin>>n>>x;
    cout<<n<<" razy "<<x<<" rowna sie "<<n*x<<endl;
}
void zad2Z2pointers(int * a, int * b){
    // Przekazanie zmiennych poprzez ich adresy
    cout<<"---\nZadanie 2.2 wskazniki"<<endl;
    int c;
    c = *a;
    *a = *b;
    *b = c;
    cout<<"a = "<<*a<<"\tb = "<<*b<<endl;
}
void zad2Z2references(int & a, int & b){
    // Przekazanie zmiennych poprzez referencje
    cout<<"---\nZadanie 2.2 referencje"<<endl;
    int c;
    c = a;
    a = b;
    b = c;
    cout<<"a = "<<a<<"\tb = "<<b<<endl;
}
void zad2Z3pointers(Test2Z3 * aaa){
    cout<<"---\nZadanie 2.3 wskazniki"<<endl;
    // zerowanie danego Test2Z3
    aaa->n = 0;
    aaa->x = 0;

}
void zad2Z3references(Test2Z3 & aaa){
    cout<<"---\nZadanie 2.3 referencje"<<endl;
    // zerowanie danego Test2Z3
    aaa.n = 0;
    aaa.x = 0;
}
