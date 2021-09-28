#include<iostream>
const int INF = 10001;
using namespace std;

int main()
{
    int N, B, H, W, p, a, menor_p;
    bool flag_p, flag_a;
    int i, j;

    while(true)
    {
        cin >> N >> B >> H >> W;
        menor_p = INF;
        for(i = 0; i < H; i++)
        {
            flag_p = flag_a = false;

            // verifica presupuesto
            cin >> p;
            if ((p*N) < B)
                flag_p = true;

            // verifica camas
            for(j=0; j < W; j++)
            {
                cin >> a;
                if (a >= N)
                    flag_a = true;
            }

            // se verifican ambas condiciones
            if(flag_p && flag_a)
            {
                if (p < menor_p)
                    menor_p = p;
            }
        }
        if(menor_p == INF)
            cout << "stay home" << endl;
        else
            cout << menor_p*N << endl;
    }
}
