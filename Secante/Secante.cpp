#include <iostream>
#include <cmath>
using namespace std;

//Metodo de Secante A00344189 Estefy A00344175 Carlos Rueda
int main ()
{
   double xprox, xahora, xantes, fxprox, error, fxn, fxant;
   int itrr=1;
   cout<<"Valor do error: ";
   cin>>error;
   cout<<"valor de (xn-1): ";
   cin>>xantes;
   cout<<"Valor de (xn): ";
   cin>>xahora;
   cout<<endl;
   fxn = xahora*xahora + xahora -6;
   fxant = xantes*xantes + xantes -6;
   cout<<"It || xn-1  || xn   || xn+1   ||  fxn+1  ||  |xn-xn-1| ||"<<endl;
   while (nit < 500)
   {
      fxn = xahora*xahora + xahora -6;
      fxant = xantes*xantes + xantes -6;
      xprox = xahora - (((xahora - xantes)*fxn)/(fxn - fxant));
      fxprox = xprox*xprox + xprox -6;
      cout<<nit<<"  ||"<<xantes<<"  ||"<<xahora<<"  ||"<<xprox<<" ||"<<fxprox<<"  || "<<abs(xprox - xahora)<<" ||"<<endl;
  if (abs(xprox-xahora)<error)
  {
      itrr = 500;
  }
  if (fxprox = 0)
  {
     itrr = 500;
  }
    xantes=xahora;
    xahora=xprox;
    itrr++;
 }
  cout<<endl<<"La razi mas proxima es :  "<<xprox<<endl;
}
