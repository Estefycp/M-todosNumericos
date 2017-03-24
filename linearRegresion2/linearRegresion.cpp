#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
    double x[] = {10.2,11.4,11.5,12.5,13.1,13.4,13.6,15,15.2,15.3,15.6,16.4,16.5,17,17.1};
    double y[] = {69.81,82.75,81.75,80.38,85.89,75.32,69.81,78.54,81.29,99.2,86.35,110.23,106.55,85.50,90.02};
    int i,j,k,n;
    cout<<"\n Cuantos pares de datos ingresaran?\n";
    cin>>n; //en este caso son 15
    double a0=0,a1=0,error=0,EE=0,xsum=0,x2sum=0,ysum=0,xysum=0,mediaX=0,mediaY=0;

    for (i=0;i<n;i++)
    {
        xsum=xsum+x[i];
        ysum=ysum+y[i];
        x2sum=x2sum+pow(x[i],2);
        xysum=xysum+x[i]*y[i];
    }
        mediaX=xsum/n;
        mediaY=ysum/n;
        a1=(n*xysum-xsum*ysum)/(n*x2sum-xsum*xsum); // pendiente
        a0=(mediaY-a1*mediaX); // interseccion

    cout<<"La regresion linear es y= "<<a1<<"x + "<<a0<<endl;

    //coeficiente de correlación
        double st=0,sr=0;
     
        for(int i=0; i<n; i++){
            sr+=pow((y[i]-a0-a1*x[i]),2);
            st+=(y[i]-mediaY)*(y[i]-mediaY);
        }
        
    cout<<"\n Coeficiente de la relacion: "<<sqrt((st-sr)/st)<<"\n";
    
    EE=sqrt(sr/(n - 2));
    
    cout<<"\n Error estandar "<<  EE;
    return 0;

}
