/***
Programa para verificar si un numero pertenece a una matriz
utilizando busqueda binaria
***/

#include<iostream>
using namespace std;

bool binarioMatriz(int mat[][4], int fil, int col, int val)
{
    int ini = 0, fin = fil*col, mid, x, y;

        while(ini < fin)
        {
            mid = (ini+fin)/2;
            x = mid/col;
            y = mid%col;

            if (val > mat[x][y])
                ini = mid+1;
            else if (val < mat[x][y])
                fin = mid;
            else
                return true;
        }
        return false;
}

int main()
{
    int mat[3][4] = {{1,3,5},
                     {7,9,11},
                     {13,15,17}};

    // Ejemplo 1:
    // Entrada: {{1,3,5},{7,9,11},{13,15,17}} , nro_a_buscar: 8
    // Salida : 0 (falso)

    cout << binarioMatriz(mat, 3, 4, 8) << endl;

    // Ejemplo 2:
    // Entrada: {{1,3,5},{7,9,11},{13,15,17}} , nro_a_buscar: 9
    // Salida : 1 (verdadero)
    cout << binarioMatriz(mat, 3, 4, 9) << endl;
    return 0;
}
