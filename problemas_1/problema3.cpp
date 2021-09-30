#include <iostream>
#define VUELTA 40
using namespace std;

int main()
{
    int ini, n1, n2, n3, acum=0;

    while(cin >> ini >> n1 >> n2 >> n3)
    {
        if(ini == 0 && n1 == 0 && n2 == 0 && n3 == 0)
            continue;
        acum += 2*VUELTA;
        if (n1 <= ini)
            acum += ini-n1;
        else
            acum += ini + (VUELTA - n1);

        acum += VUELTA;
        if(n2 >= n1)
            acum += n2-n1;
        else
            acum += n2 + (VUELTA - n1);

        if(n3 <= n2)
            acum += n2 - n3;
        else
            acum += n2 + (VUELTA - n3);

        cout << (360*acum)/40 << endl;
        acum = 0;
    }
    return 0;
}
