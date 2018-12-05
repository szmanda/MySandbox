#include "punkt.h"
#include <iostream>

using namespace std;

Punkt::Punkt(float xx, float yy){
    cout<<"Konstruktor(float,float)\n";
    x = xx;
    y = yy;
}
void Punkt::Przesun(float xx, float yy){
    cout<<"przesun(float,float)\n";
    x += xx;
    y += yy;
}
/*void Punkt::Wyswietl(){
    cout<<"\n\tx = "<<x<<"\ty = "<<y<<endl;
}*/
float Punkt::Odcieta(){
    cout<<"Odcieta()\n";
    return x;
}
float Punkt::Rzedna(){
    cout<<"Rzedna()\n";
    return y;
}
void Punkt::Skaluj(float skala){
    cout<<"Skaluj()\n";
    x *= skala;
    y *= skala;
}
void Punkt::Obracaj(float kat){

}
