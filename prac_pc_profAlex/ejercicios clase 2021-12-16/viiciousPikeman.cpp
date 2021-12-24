#include<bits/stdc++.h>
#define tipo long long
using namespace std;

int compara (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int main()
{
    tipo N, T, a, b, c, t;
    tipo total = 0;
    tipo penalidad = 0;
    tipo acumResuelto = 0;

    cin >> N >> T;
    cin >> a >> b >> c >> t;

    tipo tiempoResuelve[N];
    tiempoResuelve[0] = t;

    for(int i=1; i<N; i++)
    {
        tiempoResuelve[i] = ( ( (a*tiempoResuelve[i-1]) +b )%c )+1;
    }

    qsort(tiempoResuelve, N, sizeof(tipo), compara);

    for(int i = 0; i < N; i++)
    {
        if(tiempoResuelve[i] + total <= T)
        {
            total += tiempoResuelve[i];
            penalidad += total;
            acumResuelto++;
        }
        else
        {
            break;
        }
    }
    cout << acumResuelto << " " << penalidad%1000000007;
    return 0;
}
