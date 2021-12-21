#include<bits/stdc++.h>
using namespace std;
#define tipo long long

tipo arr[10015], posiciones[10015],
    aux[10015], LCP[10015];
tipo inc, size;
string cadena;

bool compara(tipo x, tipo y)
{
    if (posiciones[x] != posiciones[y])
        return posiciones[x] < posiciones[y];

    x= x+inc; y= y+inc;

    if(x < size && y < size)
        return (posiciones[x] < posiciones[y]);
    else
        return (x > y);
}

void suffixArray()
{
    for (tipo i = 0; i < size; i++)
        arr[i] = i, posiciones[i] = cadena[i];

    for (inc = 1;; inc <<= 1)
    {
        sort(arr, arr + size, compara);
        for (tipo i = 0; i < size-1; i++)
            aux[i+1] = aux[i] + compara(arr[i], arr[i+1]);
        for (tipo i = 0; i < size; i++)
            posiciones[arr[i]] = aux[i];
        if (aux[size - 1] == size - 1)
            break;
    }
}

void crearLCP()
{
    for (tipo i = 0, k = 0; i < size; i++)
    {
        if (posiciones[i] != size-1)
        {
            tipo j = arr[posiciones[i] + 1];
            while (cadena[i + k] == cadena[j + k]) k++;
            LCP[posiciones[i]] = k;
            if (k) k--;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> cadena;
    size = cadena.size();

    suffixArray();
    crearLCP();

    tipo k;
    cin>>k;
    tipo ant = 0;
    tipo sum = 0;

    for (tipo i = 0; i < size; i++)
    {
        if (sum + (size-arr[i]) - ant >= k)
        {
            tipo j = ant;
            string rpta = cadena.substr(arr[i], j);
            while (sum < k)
            {
                rpta += cadena[arr[i]+j];
                sum++;
                j++;
            }
            return cout << rpta, 0;
        }
        sum += (size-arr[i]) - ant;
        ant = LCP[i];
    }
    return 0;
}
