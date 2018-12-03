#include "punkt.h"
#include <iostream>

using namespace std;

Punkt::Punkt(float xx, float yy){
    x = xx;
    y = yy;
}
Punkt::Przesun(float xx, float yy){
    x += xx;
    y += yy;
}
Punkt::Wyswietl(){
    cout<<"\n\tx = "<<x<<"\ty = "<<y<<endl;
}