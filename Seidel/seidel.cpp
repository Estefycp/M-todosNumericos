#include <iostream>
#include <cmath>
using namespace std;


void Seidel(int size){
	double EPSILON = 0.00001; // error iterativo como tolerancia
	double A[size][size];
	double B[size];
	double S[size]; //Lista con las soluciones
	double OS[size];  //Lista con las antiguas soluciones
	double E[size]; //Lista con el error de cada variable
  
  
	cout<<"Pon las constante del lado derecho : " << endl;
  for(int i = 0; i < size; i++) {
      cin >> B[i];
  }
  cout<<"Pon la fila de los coeficientes: " << endl;
  for(int i = 0; i < size; i++) {
      for(int j = 0; j < size; j++) {
          cin>>A[i][j];
      }
  }
	for (int i = 0; i < size; ++i)
	{
		S[i] = 0;
		OS[i] = -999999;
		E[i] = (S[i]-OS[i]);
	}

	bool errorCheck = false;
	for (int i = 0; i < size; ++i)
	{
		if(E[i] <= EPSILON){
			errorCheck = true;
			break;
		}
	}

	int counter=0;

	while(!errorCheck){
		for (int i = 0; i < size; ++i)
		{
			double sum = 0;
			for (int j = 0; j < size; ++j)
			{
				if (j != i)
				{
					sum += A[i][j]*S[j];
				}
			}
			OS[i] = S[i];
			S[i] = (B[i] - sum)/A[i][i];
			E[i] = (S[i]-OS[i]);
		}

		for (int i = 0; i < size; ++i)
		{
			if(abs(E[i]) > EPSILON){
				break;
			}
			errorCheck = true;
		}
		counter++;
	}

	cout << "La solución es : " << endl;
	for (int i = 0; i < size; ++i)
	{
		cout<<"x("<<i<<") = "<<S[i]<<"\n";
	}
}

int main(){
	int size;
	int solutions[] = {7,6,12};
	int n, l;
	float x [n];
	cout<<"Enter the value of n : " << endl;
	cin>>n;
	gaussSeidel(n);
	cout<<"The Solution is : " << endl;
	return 0;
}
