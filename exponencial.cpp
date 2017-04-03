//La regresi�n exponencial es un m�todo de regresi�n polinomial
//en el cual la funci�n de ajuste es una funci�n exponencial del tipo y = a*b^x
//La regresi�n exponencial aunque no es lineal, es linealizable tomando logaritmos
//con el cambio de variable v = logy = log(a*b^x) = loga + xlogb.
#include <iostream>
#include <fstream>
#include <cmath>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

void min_squares(vector<double> &x, vector<double> &y) {
  double xs = 0.0, ys = 0.0, lnys = 0.0, xlnys = 0.0, xsq;
  int n = x.size();

  // Setup calculations
  for (int i = 0; i < n; i++) {
    xs += x[i];
    ys += y[i];
    lnys += log(y[i]);
    xlnys += x[i] * log(y[i]);
    xsq += pow(x[i], 2);
  }
  double xmean = xs / n;
  double ymean = ys / n;
  double lnymean = lnys / n;

  double a1 = (n * xlnys - xs * lnys) / (n * xsq - pow(xs, 2));
  double a0 = lnymean - a1 * xmean;

  cout << "EQUATION" << endl;
  cout << "y = " << exp(a0) << "e^" << a1 << "x" << endl;
  double st = 0.0, sr = 0.0;
  for (int i = 0; i < n; i++) {
    sr += pow(y[i] - exp(a0) * exp(a1 * x[i]), 2);
    st += pow(y[i] - ymean, 2);
  }

  // Standard error
  double serr = sqrt(sr / (n - 2));
  cout << "STANDARD ERROR" << endl;
  cout << serr << endl;
  // Determination coefficient
  double r = sqrt((st - sr) / st);
  cout << "CORRELATION COEFFICIENT" << endl;
  cout << r << endl;
  cout << "DETERMINATION COEFFICIENT" << endl;
  cout << pow(r, 2) << endl;
}

int main() {

  ifstream file_x;
  ifstream file_y;
  file_x.open("x.txt");
  file_y.open("y.txt");

  if (file_x.is_open() & file_y.is_open()) {
      vector<double> x, y;
      while (!file_x.eof() && !file_y.eof()) {
        x.push_back(0);
        file_x >> x[x.size() - 1];
        y.push_back(0);
        file_y >> y[y.size() - 1];
      }
      file_x.close();
      file_y.close();

      min_squares(x, y);
  }
  else {
    cerr << "Problem with the file. Cannot be opened" << endl;
  }

  return 0;
}
