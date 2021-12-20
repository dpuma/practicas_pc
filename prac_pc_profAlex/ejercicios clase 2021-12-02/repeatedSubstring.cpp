#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main()
{
    int casos, i, j, sum, sizeMenor;
    vector<string> vecSufijos;
    vector<int> LCP;
    string palabra, string1, string2;
    map<string,int> sufijos;

    cin >> casos;
    while(casos--)
    {
        cin >> palabra;

        for(i = 0; i < palabra.size(); i++)
            sufijos.insert(make_pair(palabra.substr(i), i)); // SuffixArray

        for (auto it : sufijos)
            vecSufijos.push_back(it.first);

        LCP.push_back(0);
        for(i = 1; i < vecSufijos.size(); i++)
        {
            string1 = vecSufijos[i-1];
            string2 = vecSufijos[i];

            j = 0;
            while(j < string1.size() && j < string2.size() && string1[j] == string2[j])
                j++;
            LCP.push_back(j);
        }

        sum = 0;
        for(i = 1; i < LCP.size(); i++)
        {
            if(LCP[i] > LCP[i-1])
                sum += LCP[i] - LCP[i-1];
        }
        cout << sum << endl;
        vecSufijos.clear();
        LCP.clear();
        sufijos.clear();
    }
    return 0;
}
