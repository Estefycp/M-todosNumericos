#include <iostream>
#include <cmath>
#define ERRORMIN 1E-12
using namespace std;

//Metodo de Secante A00344189 Estefy A00344175 Carlos Rueda

double f (double x)
{
     return (x*x*x)-(3*x*x)-4*x+2;
}


double secante(double x0, double x1){
    double temp, error;
        int i = 0;
       cout<<"Valor de error: ";
       cin>>error;

       do{

          temp = x0;
          x0= x1;
          x1 = x0 - (x0-temp) * f(x0) / (f(x0) - f(temp));
          i++;
       } while ( fabs (x0-x1) > error );
     cout<<"La raiz mas proxima es :  "<<x1<< " con " << i << " iteraciones"<< endl;


}
int main ()
{
   cout<< secante(-2,1) << endl;
}

