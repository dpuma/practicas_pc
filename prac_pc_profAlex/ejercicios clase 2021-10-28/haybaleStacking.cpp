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
        for(int i = ini; i <= fin; i++)
            datos[i]++;
    }
    sort(datos.begin(), datos.end());
    mid = datos.size()>>1;
    cout << datos[mid] << endl;

    return 0;
}
