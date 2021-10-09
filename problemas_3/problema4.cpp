#include<iostream>
#include<vector>
using namespace std;

int main()
{
    string expresion;
    while (getline(cin, expresion) && expresion.size())
    {
        vector<char>lista;
        auto it = lista.begin();
        for (int i = 0; i < expresion.size(); i++)
        {
            if (expresion[i] == '[')
                it = lista.begin();
            else if (expresion[i] == ']')
                it = lista.end();
            else {
                it = lista.insert(it, expresion[i]);
                it++;
            }
        }
        for (it = lista.begin(); it != lista.end(); it++)
            cout << *it;
    }
    return 0;
}
