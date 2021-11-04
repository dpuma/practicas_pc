#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    map<int,int> mapa;
    int cantSol, maxSol, tiempoSol;

    cin >> cantSol >> maxSol;
    while(cantSol--)
    {
        cin >> tiempoSol;
        if(mapa.find(tiempoSol) != mapa.end())
        {
            mapa[tiempoSol]++;
            mapa[tiempoSol+1000]--;
        }
        else
        {
            mapa.insert(make_pair(tiempoSol,1));
            mapa.insert(make_pair(tiempoSol+1000,-1));
        }
    }

    map<int,int>::iterator it = mapa.begin();
    int maximo = it->second;
    int actual = it->second;

    for(it = ++mapa.begin(); it != mapa.end(); it++)
    {
        actual = actual + it->second;
        if(actual > maximo)
            maximo = actual;
    }
    cout << maximo << endl;
    return 0;
}
