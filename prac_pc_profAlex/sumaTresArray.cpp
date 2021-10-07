#include <iostream>
using namespace std;

bool sumaParArray(int A[], int n, int& ini, int& fin, int target)
{
    while(ini < fin)
    {
        int suma = A[ini] + A[fin];
        if(suma > target)
            fin--;
        else if (suma < target)
            ini++;
        else
            return true;
    }
    return false;
}

void sumaTresArray(int A[], int n, int target)
{
    int pivot = 0, ini, fin;
    bool flag = false;

    for(int pivot = 0; pivot < n-3; pivot++)
    {
        ini = pivot+1;
        fin = n-1;
        if (sumaParArray(A, n, ini, fin, target-A[pivot]))
        {
            cout << pivot << " " << ini << " " << fin << endl;
            flag = true;
        }
    }
    if (flag == false)
        cout << "no se encontro" << endl;
}


int main()
{
    int n = 6;
    int target = 27;
    int A[6] = {1,2,7,9,11,15};

    int ini = 0;
    int fin = n-1;

    sumaTresArray(A, n, target);
    return 0;
}
