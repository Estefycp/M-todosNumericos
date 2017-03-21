#include<iostream>
#include<cmath>

using namespace std;

void jacobi(int n, int l, float* x){
  float a [n][n];
  float b [n];
  float c [n];
  int m = 1;
  cout<<"Pon las constantes del lado derecho : " << endl;
  for(int i = 0; i < n; i++) {
      cin >> b[i];
  }
  cout<<"Pon la fila de coeficients : " << endl;
  for(int i = 0; i < n; i++) {
      x[i] = 0;
      for(int j = 0; j < n; j++) {
          cin >> a[i][j];
      }
  }
  do {
    for (int i = 0; i < n; i++){
      c[i] = b[i];
      for(int j = 0; j < n; j++) {
        if(i != j) {
          c[i] = c[i] - a[i][j] * x[j];
        }
      }
    }
    for(int i = 0; i < n; i++) {
        x[i] = c[i]/a[i][i];
    }
    m++;
  } while(m <= l);
}

int main() {
    int n, l;
    float x [n];
    cout<<"Enter the value of n : " << endl;
    cin>>n;
    cout<<"Enter the number of iterations : " << endl;
    cin>>l;
    jacobi(n, l, x);
    cout<<"The Solution is : " << endl;
    for(int i = 0; i < n; i++) {
      cout<<"x("<<i<<") = "<<x[i]<<"\n";
    }

}
