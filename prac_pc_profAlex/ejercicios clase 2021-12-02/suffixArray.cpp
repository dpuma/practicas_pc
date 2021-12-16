#include<iostream>
#include<map>
using namespace std;

int main()
{
    map<string,int> prefijos;
    string palabra;
    cin >> palabra;

    for(int i = 0; i < palabra.size(); i++)
        prefijos.insert(make_pair(palabra.substr(i), i));

    for (auto it : prefijos)
        cout << it.second << "," << it.first << endl; // Sorted

    return 0;
}
