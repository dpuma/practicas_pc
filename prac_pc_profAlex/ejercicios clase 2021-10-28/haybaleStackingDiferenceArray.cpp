#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    int n, casos, ini, fin, mid;

    cin >> n >> casos;
    vector<int> datos(n+1, 0);

    while(casos--)
    {
        cin >> ini >> fin;
        datos[ini]++;
        datos[fin+1]--;
    }
    cout << endl;
    for(int i = 1; i < datos.size(); i++)
        datos[i] += datos[i-1];

    sort(datos.begin(), datos.end());
    mid = datos.size()>>1;
    cout << datos[mid] << endl;

    return 0;
}
