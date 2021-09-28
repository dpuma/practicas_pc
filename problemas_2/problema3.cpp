#include<iostream>
using namespace std;

int main()
{
    int n, s, acum;
    while(cin >> n)
    {
        if (n == 0) break;

        while(n > 9)
        {
            acum = 0;
            do {
                acum += n%10;
                n /= 10;
            } while(n);
            n = acum;
        }

        cout << n << endl;
    }
    return 0;
}
