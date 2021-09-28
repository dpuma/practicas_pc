#include<iostream>
using namespace std;

int main()
{
    string caso;
    int t, i, inc, acum;
    cin >> t;

    while(t--)
    {
        cin >> caso;
        acum = inc = 0;
        for(i = 0; i < caso.size(); i++)
        {
            if(caso[i]=='O')
            {
                inc++;
                acum += inc;
            }
            else
                inc = 0;
        }
        cout << acum << endl;
    }
    return 0;
}
