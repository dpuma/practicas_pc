#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> strs)
{
    unordered_map<string, vector<string>> map;
    int size = strs.size();

    for(int i = 0; i < size; i++)
    {
        string cadena = strs[i];
        char letras[cadena.size() + 1];

        strcpy(letras, cadena.c_str());

        sort(letras, letras + cadena.size() + 1);
        string nuevaCadena = "";

        for(int i = 0; i < cadena.size() + 1; i++)
            nuevaCadena += letras[i];

        if (map.find(nuevaCadena) != map.end()) {
            map[nuevaCadena].push_back(cadena);
        } else {
            vector<string> cadenas;
            cadenas.push_back(cadena);
            map[nuevaCadena] = cadenas;
        }
    }

    vector<vector<string>> matriz;
    unordered_map<string,vector<string>>::iterator it;

    for(it = map.begin(); it != map.end(); it++)
    {
        vector<string> vec = map[it->first];
        if (vec.size() > 0)
        {
            matriz.push_back(vec);
        }
    }
    return matriz;
}

int main()
{
    // Entrada: "eat","tea","tan","ate","nat","bat"
    // Salida : [bat,] [eat,tea,ate,] [tan,nat,]

    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

    vector<vector<string>> matriz = groupAnagrams(strs);
    for(int i = 0; i < matriz.size(); i++)
    {
        cout << "[";
        for(int j = 0; j < matriz[i].size(); j++)
        {
            cout << matriz[i][j] << ",";
        }
        cout << "] ";
    }
    return 0;
}
