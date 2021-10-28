
/**
programa que dado un tamaño de segmento k (ventana)
calcula la secuencia de maximos valores de la ventana
que se desliza a traves de un array
**/

#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> vec)
{
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}

int main()
{
    vector<int> A = {1,3,-1,-3,5,3,6,7};
    int k = 3, mayor = A[0];
    vector<int> sol;

    for(int i = 1; i < k; i++)
        if(A[i] > mayor)
            mayor = A[i];
    sol.push_back(mayor);

    for(int i = 1; i <= A.size()-k; i++)
    {
        mayor = A[i];
        for(int j = i+1; j < i+k; j++)
        {
            if(A[j] > mayor)
                mayor = A[j];
        }
        sol.push_back(mayor);
    }
    print(sol);
    return 0;
}
