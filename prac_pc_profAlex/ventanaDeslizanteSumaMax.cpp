/**
programa que dado un tamaño de segmento k (ventana)
calcula la maxima suma de k elementos contiguos en un array
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
    vector<int> A = {2,3,4,1,5};
    int k = 3, maximo = 0;

    for(int i = 0; i < k; i++)
        maximo += A[i];

    int tmp = maximo;

    for(int i = 1; i <= A.size()-k; i++)
    {
        tmp = tmp - A[i-1] + A[i+k-1];
        if(tmp > maximo)
            maximo = tmp;
    }
    cout << maximo << endl; // salida: 10
    return 0;
}
