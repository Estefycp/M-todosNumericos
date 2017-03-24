//Linear Fit
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{

    double x[] = {10.2,11.4,11.5,12.5,13.1,13.4,13.6,15,15.2,15.3,15.6,16.4,16.5,17,17.1};
    double y[] = {69.81,82.75,81.75,80.38,85.89,75.32,69.81,78.54,81.29,99.2,86.35,110.23,106.55,85.50,90.02};
    int i,j,k,n;
    cout<<"\n Cuantos partes de datos ingresaran?\n";
    cin>>n;
    double a0,a1,error,EE;
    //cout<<"\n Pon los valores X\n";
    //for (i=0;i<n;i++)
       // cin>>x[i];
    //cout<<"\n Pon los valores Y\n";
    //for (i=0;i<n;i++)
        //cin>>y[i];
    double xsum=0,x2sum=0,ysum=0,xysum=0;
    for (i=0;i<n;i++)
    {
        xsum=xsum+x[i];
        ysum=ysum+y[i];
        x2sum=x2sum+pow(x[i],2);
        xysum=xysum+x[i]*y[i];

    }


    a0=(n*xysum-xsum*ysum)/(n*x2sum-xsum*xsum); // pendiente
    a1=(x2sum*ysum-xsum*xysum)/(x2sum*n-xsum*xsum); // interseccion



    cout<<"La regresion linear es y= "<<a0<<"x + "<<a1<<endl;


    //coeficiente de correlación

     double suma=0.0;
        for(int i=0; i<n; i++){
            suma+=x[i];
        }
        double mediaX=suma/n;

        suma=0.0;
        for(int i=0; i<n; i++){
            suma+=y[i];
        }
        double mediaY=suma/n;

        double pxy, sx2, sy2,err;
        pxy=sx2=sy2=0.0;
        for(int i=0; i<n; i++){
            err+=pow((y[i]-mediaY),2);
            pxy+=(x[i]-mediaX)*(y[i]-mediaY);
            sx2+=(x[i]-mediaX)*(x[i]-mediaX);
            sy2+=(y[i]-mediaY)*(y[i]-mediaY);
        }
    cout<<"\n Coeficiente de la relacion: "<<pxy/sqrt(sx2*sy2)<<"\n";




    EE=sqrt(err/(n - 2));
    cout<<"\n Error estandar "<<  EE;



    return 0;



}
