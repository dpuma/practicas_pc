#include<iostream>
#include<map>
using namespace std;

int main()
{
    map<string,int> sufijos;
    string palabra;
    cin >> palabra;

    for(int i = 0; i < palabra.size(); i++)
        sufijos.insert(make_pair(palabra.substr(i), i));

    for (auto it : sufijos)
        cout << it.second << "," << it.first << endl;

    return 0;
}
