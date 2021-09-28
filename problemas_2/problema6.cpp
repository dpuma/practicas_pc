#include<iostream>
using namespace std;

int main()
{
    int T, N, S, acum_mile, acum_juice, i, j;

    cin >> T;
    for(i = 0; i < T; i++)
    {
        cin >> N;
        acum_mile = acum_juice = 0;

        for(j = 0; j < N; j++)
        {
            cin >> S;
            if(S != 0)
            {
                acum_mile += ( ((S/30)) +1)*10;
                acum_juice += ( ((S/60)) +1)*15;
            }
        }
        if(acum_mile < acum_juice)
            cout << "Case " << i+1 << ": Mile " << acum_mile << endl;
        else if(acum_juice < acum_mile)
            cout << "Case " << i+1 << ": Juice " << acum_juice << endl;
        else
            cout << "Case " << i+1 << ": Mile Juice " << acum_mile << endl;
    }
    return 0;
}
