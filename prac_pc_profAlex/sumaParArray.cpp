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

int main()
{
    int n = 6;
    int target = 13;
    int A[6] = {1,2,7,9,11,15};

    int ini = 0;
    int fin = n-1;


    if(sumaParArray(A, n, ini, fin, target))
        cout << ini << " " << fin << endl;
    else
        cout << "imposible" << endl;
    return 0;
}
