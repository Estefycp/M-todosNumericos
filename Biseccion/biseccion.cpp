#include <stdexcept>
#include <iostream>
#include <cmath>
#define errorMin 1E-15

using namespace std;
double a,b,xr,raiz;

typedef double (* funcEv)(double x);


double biseccion(funcEv func, double a , double b ){

    xr = (a+b)/2;
    double x1= func(a);
    double x2= func(b);
    double fxr= func(xr);

    if(abs(fxr) <= errorMin){
        raiz=xr;
    }

    if(x1*fxr<0){
        b=xr;
        biseccion(func,a,b);
    }

    if((x1*fxr)>0){
        a=xr;
        biseccion(func,a,b);
    }

    return raiz;
}

<stdexcept>
double funcion(double x){
   return sin(x) + 2*x - 1;
}


int main(void)
{
    cout<<biseccion((funcEv)funcion ,-10,10) <<endl;
    return 0;

}
