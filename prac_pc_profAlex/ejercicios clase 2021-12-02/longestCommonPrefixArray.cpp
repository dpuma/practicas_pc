#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main()
{
    map<string,int> sufijos;
    string palabra;
    cin >> palabra;

    for(int i = 0; i < palabra.size(); i++)
        sufijos.insert(make_pair(palabra.substr(i), i)); // SuffixArray

    vector<string> vecSufijos;
    for (auto it : sufijos)
        vecSufijos.push_back(it.first);

    vector<int> LCP;
    string string1, string2;
    int sizeMenor;
    LCP.push_back(0);

    for(int i = 1; i < vecSufijos.size(); i++)
    {
        string1 = vecSufijos[i-1];
        string2 = vecSufijos[i];

        int j = 0;
        while(j < string1.size() && j < string2.size() && string1[j] == string2[j])
            j++;
        LCP.push_back(j);
    }

    for(int i = 0; i < LCP.size(); i++)
        cout << LCP[i] << " ";

    return 0;
}
