#include <iostream>
#include <fstream>

using namespace std;
void wypisz(double* tab,int n){
    for (int i = 0; i < n; ++i) {
        cout << tab[i] << ", ";
    }
    cout << endl;
}
void matrixProcedure(const double * lowDiagonal, double * diagonal, const double * upDiagonal, int n){
    for(int i = 1; i<n; i++){
        diagonal[i] = diagonal[i] - lowDiagonal[i-1]*(1.0/diagonal[i-1])*upDiagonal[i-1];
    }
}

void vectorProcedure(double *b, const double * lowDiagonal, const double * diagonal, const double * upDiagonal, int n){
    for(int i = 1; i<n; i++){
        b[i] = b[i] - lowDiagonal[i-1]*(1.0/diagonal[i-1])*b[i-1];
    }
    cout << "Wektor r:" << endl;
    wypisz(b,n);
    b[n-1] = b[n-1]*1.0/diagonal[n-1];
    for(int i = n-2; i>=0; i--){
        b[i] = (1.0/diagonal[i])*(b[i]-upDiagonal[i]*b[i+1]);
    }
}






int main() {
    ifstream plik("dane.txt");
    double *lowDiagonal, *diagonal, *upDiagonal, *b;
    int n = 6;
    lowDiagonal = new double[n-1]{1./3., 1./5., 1./7., 1./9., 1./11.};
    diagonal = new double[n]{10., 20., 30., 30., 20., 10.};
    upDiagonal = new double[n-1]{1. / 2., 1. / 4., 1. / 6., 1. / 8., 1. / 10. };
    b = new double[n]{31., 165./4., 917./30., 851./28., 3637./90., 332./11.};

    matrixProcedure(lowDiagonal, diagonal, upDiagonal, 6);
    cout << "Wektor ni: "<< endl;
    wypisz(diagonal, n-1);

    vectorProcedure(b, lowDiagonal, diagonal, upDiagonal, 6);
    cout << "Rozwiazanie: ";
    for (int i = 0; i < 6; ++i) {
        cout << b[i] << " ";
    }

    return 0;
}
