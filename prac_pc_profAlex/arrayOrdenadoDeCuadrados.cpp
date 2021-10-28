/**
Programa que obtiene un arreglo ordenado
a partir del cuadrado de los elementos
de otro array ordenado(con numeros + y -)
**/

#include<iostream>
#include<vector>
using namespace std;

vector<int> ordenarCuadrados(vector<int> vec)
{
    int ini = 0, fin = vec.size()-1, cuad1, cuad2;
    vector<int> sol;

    cuad1 = vec[ini]*vec[ini];
    cuad2 = vec[fin]*vec[fin];

    while(ini <= fin)
    {
        if(cuad1 > cuad2)
        {
            sol.insert(sol.begin(),cuad1);
            ini++;
            cuad1 = vec[ini]*vec[ini];
        }
        else
        {
            sol.insert(sol.begin(),cuad2);
            fin--;
            cuad2 = vec[fin]*vec[fin];
        }
    }
    return sol;

}

void imprimirVec(vector<int> vec)
{
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}

int main()
{
    vector<int> vec = {-4,-3,1,2,3};
    imprimirVec(ordenarCuadrados(vec));
    return 0;
}
