#include <iostream>
#include <string>
using namespace std;

class Matriz{
    private:
        int n;
        double matriz[10][10];
        double matrizB[10][10];
        double matrizC[10][10];
        double matrizD[10][10];
    public:
        Matriz(int);
        void generarMatriz(double matriz[][10], int, int, string);
        void multiplicarMatriz();
        void sumarMatriz();
        void accederMatriz();
        void imprimirMatriz(double matriz[][10], int, int, string);
};