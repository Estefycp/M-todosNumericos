#include <iostream>
#include <cmath>

using namespace std;
double E = 0.0001;

void bairstow( double *arr, double *arrOr, int size, double r, double s ) {
    arr[size-1] = arrOr[size-1];
    arr[size-2] = arr[size-1] * r + arrOr[size-2];

    for ( int i = size - 3; i >= 0; i-- ) {
        arr[i] = ( arr[i + 1] * r ) + ( arr[i + 2] * s ) + arrOr[i];
    }
    return;
}

int main() {
    double arrVal[] = {2, -10, 10, 5, -5, 15};
    int size = sizeof(arrVal) / sizeof(arrVal[0]);
    int count = 1;

    double arrB[size];
    double arrC[size];

    double r = -1;
    double s = -1;

    double dr;
    double ds;

    do {
        bairstow( arrB, arrVal, size, r, s );
        bairstow( arrC, arrB, size, r, s );
        dr = ( -arrB[1] * arrC[2] - arrC[3] * -arrB[0] ) / ( arrC[2] * arrC[2] - arrC[1] * arrC[3] );
        ds = ( -arrB[0] * arrC[2] - arrC[1] * -arrB[1] ) / ( arrC[2] * arrC[2] - arrC[1] * arrC[3] );

        double errorR = ( dr / r ) * 100;
        double errorS = ( ds / s ) * 100;

        if ( abs(errorR) <= E && abs(errorS) <= E ) {
            break;
        }
        r += dr;
        s += ds;
        count++;
    } while (true);

    double x1 = ( r + sqrt( r * r + 4 * s ) ) / 2;
    double x2 = ( r - sqrt( r * r + 4 * s ) ) / 2;

    cout << "Root 1: " << x1 << endl
    << "Root 2: " << x2 << endl;

    cout << "r: " << r << endl
    << "s: " << s << endl;

    for ( int i = 0; i < size; i++ ) {
        cout << "Coeficientes de la funcion con menor grado " << arrC[i] << endl;
    }
    return 0;
}
