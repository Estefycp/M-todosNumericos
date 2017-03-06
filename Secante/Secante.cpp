#include <iostream>
#include <cmath>
#define ERRORMIN 1E-12
using namespace std;

//Metodo de Secante A00344189 Estefy A00344175 Carlos Rueda

double f (double x)
{
     return (x*x*x)-(3*x*x)-4*x+2;
}
int main ()
{
   double temp, x1, x2,  error;
    int i = 0;
   cout<<"Valor de error: ";
   cin>>error;
   cout<<"valor de (x0): ";
   cin>>x1;
   cout<<"Valor de (x1): ";
   cin>>x2;
   cout<<endl;


   do{
      
      temp = x1;
      x1= x2;
      x2 = x1 - (x1-temp) * f(x1) / (f(x1) - f(temp));
      i++;   
   } while ( fabs (x1-x2) > error );
  cout<<endl<<"La raiz mas proxima es :  "<<x2<< " con " << i << " iteraciones" endl;
}
