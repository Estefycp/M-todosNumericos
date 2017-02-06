#include <iostream>
#include <cmath>
#define TIMES 1000
#define errorMin 1E-12

using namespace std;
double a,b,xr,raiz;

typedef double (* funcEv)(double x);


double biseccion(funcEv func, double a , double b ){

    double x1= func(a);
    double x2= func(b);

    int i = 0;

    while (i < TIMES) {
        xr = (a+b)/2;
        double fxr= func(xr);

        if(abs(fxr) <= errorMin){
            raiz=xr;
            return raiz;
        }

        if(x1*fxr<0){
            b=xr;

        }

        if((x1*fxr)>0){
            a=xr;

        }
        i++;
    }

    return raiz;
}


double funcion(double x){
   return (x*x)+(2*x)-1;
}


int main(void)
{
    cout<<biseccion((funcEv)funcion ,-1,1) <<endl;
    return 0;

}
