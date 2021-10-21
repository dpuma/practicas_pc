#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int n;
    long target, dato, aux;
    unordered_multimap<long,int> lista;

    cin >> n >> target;

    for(int i = 0; i < n; i++)
    {
        cin >> dato;
        aux = target - dato;

        if(lista.find(aux) != lista.end()) // si existe un elemento en la pos aux
        {
            cout << lista.find(aux)->second+1 << " " << i+1 << endl;
            return 0;
        }
        else
        {
            lista.insert(make_pair(dato, i));
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
