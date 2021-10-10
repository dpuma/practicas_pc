#include <iostream>
#include <set>
using namespace std;

int main()
{
    multiset<int> datos;
    int casos;

    while(cin >> casos)
    {
        if(casos == 0)
            return 0;

        long sol = 0;
        while(casos--)
        {
            int cant, val;
            cin >> cant;

            while(cant--){
                cin >> val;
                datos.insert(val);
            }
            sol += (*datos.rbegin()) - (*datos.begin());
            datos.erase(datos.begin());
            datos.erase(datos.find(*datos.rbegin()));
        }
        cout << sol << endl;
        datos.clear();
    }
}
