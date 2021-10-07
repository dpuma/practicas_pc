/***
Programa para encontrar dos posiciones de valores en un arreglo
que sumen un valor "target" determinado.

La entrada de datos es por consola

Entrada:
    1ra linea son 2 valores: tama�o del arreglo y la suma "target"
    2da linea son los valores del arreglo
Salida:
    Imprime 2 enteros: las posiciones de los valores,
    y si no encuentra la suma imprime "imposible"

Prueba 1:
    Entrada:
    4 8
    2 7 5 1
    Salida:
    4 2

Prueba 2:
    Entrada:
    4 100
    2 7 5 1
    Salida:
    imposible

***/

#include <iostream>
#include <algorithm>
using namespace std;

using namespace std;

void insertionSort(int *arr, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

bool sumaParArray(int*A, int n, int& ini, int& fin, int target)
{
    while(ini < fin)
    {
        int suma = A[ini] + A[fin];
        if(suma > target)
        {
            fin--;
        }
        else if (suma < target)
            ini++;
        else
        {
            return true;
        }
    }
    return false;
}

void imprimirArray(int* A, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n, target, dato;
    cin >> n >> target;
    int* A = new int[n];
    int* Ordenado = new int[n];

    for(int i = 0; i < n; i++)
    {
        cin >> dato;
        A[i] = dato;
        Ordenado[i] = dato;
    }

    int ini = 0;
    int fin = n-1;

    insertionSort(Ordenado,n);
    int flag = true;
    if(sumaParArray(Ordenado, n, ini, fin, target))
    {
        bool hayIni = false, hayFin = false;
        for(int i = 0; i < n; i++)
        {
            if(!hayIni && Ordenado[ini] == A[i])
            {
                ini = i;
                hayIni = true;
            }
            else if(!hayFin && Ordenado[fin] == A[i])
            {
                fin = i;
                hayFin = true;
            }
        }
    }
    else
    {
        cout << "imposible" << endl;
        flag = false;
    }

    if (flag == true)
        cout << ini+1 << " " << fin+1 << endl;

    return 0;
}
