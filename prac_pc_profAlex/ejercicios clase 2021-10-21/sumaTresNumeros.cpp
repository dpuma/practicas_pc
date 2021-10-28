#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool sumaDosNumeros(vector<long> &numeros, int ini, int fin, long target)
{
    unordered_multimap<long,int> lista;

    long dato, aux;
    for(int i = ini; i <= fin; i++)
    {
        dato = numeros[i];
        aux = target - dato;

        if(lista.find(aux) != lista.end()) // si existe un elemento en la pos aux
        {
            cout << lista.find(aux)->second+1 << " " << i+1;
            return true;
        }
        else
        {
            lista.insert(make_pair(dato, i));
        }
    }
    return false;
}

int main()
{
    int n;
    long target, dato, aux;
    vector<long> numeros;

    cin >> n >> target;

    for(int i = 0; i < n; i++)
    {
        cin >> dato;
        numeros.push_back(dato);
    }

    for(int i = 0; i < n-2; i++)
    {
        dato = numeros[i];
        aux = target - dato;

        bool haySumaDosNum = sumaDosNumeros(numeros,i+1, n-1, aux);

        if(haySumaDosNum)
        {
            cout << " " << i+1 << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
